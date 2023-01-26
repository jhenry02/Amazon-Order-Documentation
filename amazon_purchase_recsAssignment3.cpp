//THIS IS ONLY AN EXAMPLE TO HELP YOU GET STARTED WITH THIS ASSIGNMENT


//EXAMPLE OF PROGRAM HEADER
/************************************************************************************************************************

Name: Joshua Henry                                Z#: 23587940
Course: Foundations of Computer Science (COP3014)
Professor: Dr. Lofton Bullard
Due Date:  2/9/2022               Due Time: 11:59 pm
Total Points: 20
Assignment #: amazon_orders.cpp

Description: The purpose of this program is to record customer purchases made on Amazon, using variables such
as a type string of cell number and quantity hold both the user's phone number, as well as the amount of a particular amount that was ordered. A class known as order record houses different types of user information such as price of an item , the tax rate, and the net cost of that item.

*************************************************************************************************************************/

//Include the following

#include <iostream> //identifies the stream of file input and file output.
#include <string> //necessary for string use
#include <fstream>  //you must include this library if you wish to do file i/o
#include <iomanip> //formating output correction
using namespace std;


//Prototypes for your functions: input, output, and process will go here

void input(ifstream &, string &, string &, double &, double &, int &);
void output(string, string, double, double, int, double, double, double, double);
void process(double, double, int, double &, double &, double &, double &);


//Function Implementations will go here

///*************************************************************************************
//Name:  input
//Precondition: State what is true before the function is called.
// Example: the variables (formal parameters) have not been initialized
//Postcondition: State what is true after the function has executed.
// Example: the variables (formal parameters) have been initialized
//Description:  
// Example:Get input (values of cell_number, item_number, quantity, price, processing_plant ) 
//from data file.

//PURPOSE: SHOW ME THAT YOU KNOW HOW TO READ INPUT AND USE INPUT (CALL BY VALUE) & OUTPUT (CALL BY VALUE) PARAMETERS

//*************************************************************************************

void input(ifstream & in, string & cell_number, string & item_number, double & quantity, double & price, int & processing_plant) // example using the call by reference mechanism in C++ -- call record is passed by reference --note & operator
{
	in >> cell_number; //records and reads  the cell phone number field
	
	in>> item_number; //records and reads the item number field
	
	in >>quantity; //records and reads the quantity field
	
	in>> price; //records and reads the price field
	
	in >> processing_plant; //records and reads the processing plant field
	//add more code to read the rest of the variables (item_number, quantity, price and processing_plant)
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


void output(string cell_number, string item_number, double quantity, double price, int processing_plant, double tax_rate, double order_tax, double net_cost, double total_cost)
{

	//Use thee following statement to help you format you our output. These statements are called the magic formula.
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout.setf(ios::fixed);
	/********************************************/


	//cout << cell_number << "\t";
	//add more code to print all the variables
	cout << setw(12) << left << cell_number << "\t" << 
	
	  setw(8) << right<< item_number << "\t" << 
	 
	 setw(10) << right << quantity << "\t" << 

	 setw(10) << right << price << "\t" << 

	 setw(5) << right << processing_plant << "\t" <<

	 setw(12) << right << tax_rate << "\t" <<

	  setw(8) << right <<order_tax << "\t" <<

	 setw(10) << right << net_cost << "\t" <<

	 setw(5) << right<< total_cost << "\t" << endl;


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
void process(double quantity, double price, int processing_plant, double & tax_rate, double & order_tax, double & net_cost, double & total_cost)
{
		
	//put your code here to process/calculate the tax_rate, order_tax, net_cost, and total_cost
	if (processing_plant >= 0 && processing_plant <= 50)
	{
		tax_rate = 6.0;
	}
		else if (processing_plant >= 51 && processing_plant <= 110)
		{
			tax_rate = 7.0;
		}
			else if (processing_plant >= 111 && processing_plant <= 200)
			{
				tax_rate = 8.0;
			}
		else if (processing_plant >= 201 && processing_plant <= 500)
			{
				tax_rate = 9.0;
			}
	else if	(processing_plant > 500)
	{
		tax_rate = 11.0;
	}
	order_tax = quantity * price * (tax_rate/100);
	
	net_cost = quantity * price;

	total_cost = net_cost + order_tax;
}


//Here is your driver to test the program
int main()
{
	string cell_number;
	string item_number;
	double quantity;
	double price;
	int processing_plant;
	double tax_rate;
	double order_tax;
	double net_cost;
	double total_cost;

	ifstream in;    //declaring an input file stream
	in.open("purchase_dataAssignment4.txt");

	if (in.fail()) //conditional that expects failure if file does not open as it should.
	{
		cout << "Input file did not open correctly" << endl;
	}
	else
	{
		while (!in.eof()) //checks first if file opens successfully.
		{

			input(in, cell_number, item_number, quantity, price, processing_plant);
			process( quantity, price, processing_plant,tax_rate,order_tax,net_cost,total_cost );
		 	output(cell_number, item_number, price, processing_plant,quantity,tax_rate,order_tax,net_cost,total_cost );
		}
	}

	in.close();

	return 0;
}


