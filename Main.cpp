// Reads InputFile.txt and writes manipulated data to OutputFile.txt

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
	// Declaring fstream objects
	ifstream iData;
	ofstream oData;

	// Declaring input variables
	int ticketPrice[4];
	int ticketsSold[4];

	// Declaring output variables
	int totalSold = 0;
	float totalSales = 0;

	// Opening data files
	iData.open("InputFile.txt");
	oData.open("OutputFile.txt");
	
	// Reads data from InputFile.txt
	for (int i = 0; i < 4; i++)
	{
		iData >> ticketPrice[i] >> ticketsSold[i];
		iData.ignore();
	}

	// Calculates totalSold
	for (int i = 0; i < 4; i++)
	{
		totalSold += ticketsSold[i];
	}

	// Calculates totalSales
	for (int i = 0; i < 4; i++)
	{
		totalSales += ticketPrice[i] * ticketsSold[i];
	}

	// Writes data to OutputFile.txt
	oData << "Total Tickets Sold = " << totalSold << endl
		  << "Total Ticket Sales = $" << fixed << showpoint << setprecision(2) << totalSales << endl;

	// Closing data files
	iData.close();
	oData.close();
	
	return 0;
}
