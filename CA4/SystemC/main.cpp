#include "SSCTB.h"

int sc_main (int argc, char **argv){
	
	SSCTB TB1 ("testbench1");  

	sc_trace_file* vcdfile;
	vcdfile = sc_create_vcd_trace_file("SSC_test");
	sc_trace(vcdfile, TB1.SSC1->DP->clk, "clk");
	sc_trace(vcdfile, TB1.SSC1->DP->rst, "rst");
	sc_trace(vcdfile, TB1.SSC1->CNTRL->start, "start"); 
	sc_trace(vcdfile, TB1.SSC1->CNTRL->done, "done");
	//Control Signals
	sc_trace(vcdfile, TB1.SSC1->CNTRL->n_state, "ns");
	sc_trace(vcdfile, TB1.SSC1->DP->cs, "cs");
	sc_trace(vcdfile, TB1.SSC1->DP->rwbar, "rwbar");
	sc_trace(vcdfile, TB1.SSC1->DP->enCounter1, "enCounter1");
	sc_trace(vcdfile, TB1.SSC1->DP->enCounter2, "enCounter2");
	sc_trace(vcdfile, TB1.SSC1->DP->initCounter1, "initCounter1");
	sc_trace(vcdfile, TB1.SSC1->DP->initCounter2, "initCounter2");
	sc_trace(vcdfile, TB1.SSC1->DP->select_Addr, "select_Addr");
	sc_trace(vcdfile, TB1.SSC1->DP->select_Data, "select_Data");
	sc_trace(vcdfile, TB1.SSC1->DP->loadMinReg, "loadMinReg");
	sc_trace(vcdfile, TB1.SSC1->DP->loadMinAddrReg, "loadMinAddrReg");
	sc_trace(vcdfile, TB1.SSC1->DP->loadDataReg, "loadDataReg");
	sc_trace(vcdfile, TB1.SSC1->DP->lt, "lt");
	// DataPath
	sc_trace(vcdfile, TB1.SSC1->DP->Counter1Value, "Counter1Value");
	sc_trace(vcdfile, TB1.SSC1->DP->Counter2Value, "Counter2Value");

	sc_trace(vcdfile, TB1.SSC1->DP->MinAddrRegValue, "MinAddrRegValue");
	sc_trace(vcdfile, TB1.SSC1->DP->MinRegValue, "MinRegValue");
	sc_trace(vcdfile, TB1.SSC1->DP->DataRegValue, "DataRegValue");
	sc_trace(vcdfile, TB1.SSC1->DP->AddressBus, "AddressBus");
	sc_trace(vcdfile, TB1.SSC1->DP->ReadData, "ReadData");
	sc_trace(vcdfile, TB1.SSC1->DP->WriteData, "WriteData");
	sc_trace(vcdfile, TB1.SSC1->DP->Counter2PI, "Counter2PI");

	sc_start (1000000, SC_NS);
	return 0; 
}

