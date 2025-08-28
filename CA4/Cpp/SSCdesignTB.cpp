#include "SSCDesign.h"

int main ()
{
	string filename("RandomNumbers.txt");

	bus clk, rst, start, done;
	//bus x(8);
	//bus result(10);

	// module instantiation
	SSCDesign *SSC = new SSCDesign(clk, rst, start, done);

	SSC -> initialize(filename);

	
	start ="1";
	do{
		clk = "P";
		SSC -> evl();
		start ="0";
	} while (done == "0");

	SSC->write_sorted_file();
	cout << "DONE!\n";
	
		
}
