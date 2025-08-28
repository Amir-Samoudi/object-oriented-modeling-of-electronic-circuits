#include "SSCDesign.h"

SSCDesign::SSCDesign(bus &clk_, bus &rst_, bus &start_, bus &done_) :
			clk(&clk_), rst(&rst_), start(&start_), done(&done_)
{
	DP = new SSCDatapath(*clk, *rst,
				enCounter1, initCounter1, co1,
				enCounter2, initCounter2, loadCounter2, co2,
				loadMinAddrReg, loadMinReg, loadDataReg,
				select_addr, select_data, select_min,
				read, write, lt);

	CT = new SSCController(*start, *done, *clk, *rst,
				enCounter1, initCounter1, co1,
				enCounter2, initCounter2, loadCounter2, co2,
				loadMinAddrReg, loadMinReg, loadDataReg,
				select_addr, select_data, select_min,
				read, write, lt);

}
void SSCDesign::evl()
{
	DP -> evl();
	CT -> evl();
}
void SSCDesign::initialize(const string& filename)
{
	//resetting
	*rst = "1";
	DP -> evlMemory();
	DP -> evl();
	CT -> evl();
	*rst = "0";
	//Initialize RegisterFile
	DP -> initMemory (filename);
	//DP -> dumpMemory ("beforeFile.txt");
}

void SSCDesign::write_sorted_file()
{
	DP -> dumpMemory ("SortedFile.txt");
}




