//THIS IS ONLY AN EXAMPLE TO HELP YOU GET STARTED WITH THIS ASSIGNMENT


//EXAMPLE OF PROGRAM HEADER
/************************************************************************************************************************

Name: Joshua Henry                                Z#: 23587940
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date:  2/23/2022               Due Time: 11:59 pm
Total Points: 10
Assignment #: henry_amazon_orders.cpp

Description: The purpose of this program is to record customer purchases made on Amazon. Using variables such
as a type string of cell number and quantity hold both the user's phone number, as well as the amount of a particular
amount that was ordered. A class known as order record houses different types of user information such as price of an item
, the tax rate, and the net cost of that item.


*************************************************************************************************************************/

//Include the following

#include <iostream> //specifies the stream from insertion and extraction operators ex : cin >> and coout <<
#include <string> //required to use strings of any functionality
#include <iomanip> //formats and manipulates the output
#include <fstream>  //you must include this library if you wish to do file i/o
using namespace std;

/*********************************************************
//Following is the declaration of a order record
**********************************************************/
class order_record{
public:
	string cell_number;
	string item_number;
	double quantity;
	double price;
	int processing_plant;
	double tax_rate;
	double order_tax;
	double net_cost;
	double total_cost;
};


//Prototypes for your functions: input, output, and process will go here

void input(ifstream &, order_record &);
void output(ofstream &, const order_record &);
void process(order_record &);

//Function Implementations will go here

///*************************************************************************************
//Name:  input
//Precondition: The formal parameters of ifstream, in, order_record, & p_record have not
//yet been initialized due to the fact that the condition must first be checked, and then the function prototype
//will be called and excute afterwards.
//Postcondition: For the function prototype of input, call by reference is being used to read the initial paramers of
// for ifstream, order_record, and p_record.
//Description:  
// To obtain the input from the following fields (values of cell_number, item_number, quantity, price, processing_plant ) 
//from data file order record (p_record).

//PURPOSE: SHOW ME THAT YOU KNOW HOW TO READ INPUT AND USE INPUT (CALL BY VALUE) & OUTPUT (CALL BY VALUE) PARAMETERS

//*************************************************************************************

void input(ifstream & in, order_record & p_record) // example using the call by reference mechanism in C++ -- call record is passed by reference --note & operator
{
	//add more code to read the rest of the fields (item_number, quantity, price and processing_plant) into the 
	//order record, p_record.
	in >> p_record.cell_number; //records and reads  the cell phone number field
	
	in>> p_record.item_number; //records and reads the item number field
	
	in >> p_record.quantity; //records and reads the quantity field
	
	in>> p_record.price; //records and reads the price field
	
	in >> p_record.processing_plant; //records and reads the processing plant field
}

///*************************************************************************************
//Name:  output
//Precondition: The constant of order_record and p_record have not been referenced yet until conditional if
//called.
//Postcondition: Since the function has been properly invoked, the screen will not output the correct and 
//expected output.
//Description:  This prototype does as the function header describes- it correctly displays output from the function
//data file being called.
//*************************************************************************************

void output(ofstream & out, const order_record & p_record)
{
	//Use thee following statement to help you format you our output. These statements are called the magic formula.
	cout.setf(ios::showpoint); //shows decimal point
	cout.precision(2); //precision in rounding of the decimal point
	cout.setf(ios::fixed); // a fixed/set number of decimal value
	/********************************************/

	//add more code to print all the fields in the order record
	out << setw(15) << right << p_record.cell_number << "\t" ;
	
	out <<  setw(10) << right<< p_record.item_number << "\t" ; 
	 
	out << setw(10) << right << p_record.quantity << "\t" ;

	out << setw(10) << right << p_record.price << "\t" ;

	out <<  setw(10) << right << p_record.processing_plant << "\t" ;

	out << setw(10) << right << p_record.tax_rate << "\t" ;

	out <<  setw(10) << right << p_record.order_tax << "\t" ;

	out << setw(10) << right << p_record.net_cost << "\t" ;

	out << setw(10) << right<< p_record.total_cost << "\t" ;


}

///*************************************************************************************
//Name:  process
//Precondition: The values of net_cost,total_cost,order_tax, and total costs are expected to be correctly processed.
//Postcondition: The tax_rate has been determined by the conditional statements as well as the final distinct
//calculation of net_cost, order_tax, and total_cost have been done.
//Description:  This function prototype simply calculates the required net_cost, order_tax, and total_cost of the tax_rate
//of the customer's current order information along with their tax rate.
//*************************************************************************************

//Note: there is one 1 input/output parameter
void process(order_record & p_record)
{
	//put your code here to process/calculate the tax_rate, order_tax, net_cost, and total_cost
	//the p_record
	if (p_record.processing_plant >= 0 && p_record.processing_plant <= 50)
	{
		p_record.tax_rate = 6.0;
	}
		else if (p_record.processing_plant >= 51 && p_record.processing_plant <= 110)
		{
			p_record.tax_rate = 7.0;
		}
			else if (p_record.processing_plant >= 111 && p_record.processing_plant <= 200)
			{
				p_record.tax_rate = 8.0;
			}
		else if (p_record.processing_plant >= 201 && p_record.processing_plant <= 500)
			{
				p_record.tax_rate = 9.0;
			}
	else if	(p_record.processing_plant > 500)
	{
		p_record.tax_rate = 11.0;
	}
	p_record.order_tax = p_record.quantity * p_record.price * (p_record.tax_rate/100);
	
	p_record.net_cost = p_record.quantity * p_record.price;

	p_record.total_cost = p_record.net_cost + p_record.order_tax;
}

//Here is your driver to test the program
int main()
{

	order_record customer_record;

	ifstream in;    //declaring an input file stream
	ofstream out;	//declaring an output file stream

	in.open("Purchase_data_Assignment5.txt"); //this opens the data from the file purchase_data.txt
	out.open("amazon_inventoryoutput.txt");

	if (in.fail() || out.fail()) //condition failure alternative if input or output file does not open correctly as intended, hence the need for the or logical operator
	{
		cout << "Input file did not open correctly" << endl;
	}
	else
	{
		while (!in.eof() && !out.eof()) //while loop primarily testing the condition to see if file will open, afterwards then proceeds to display the file data.
		{
			input(in, customer_record);
			process(customer_record);
			output(out, customer_record);
		}
	}

	in.close(); //closes the input file properly
    out.close(); // closes the output file properly
	return 0;
}



