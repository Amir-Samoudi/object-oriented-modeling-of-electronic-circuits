#include "datapath_SSC.h"
#include "controller_SSC.h"

SC_MODULE(SSC){

	// Port Declaration
	sc_in <sc_logic> clk, rst, start; 
	sc_out <sc_logic> done;

	// Signal Declaration
	sc_signal <sc_logic>co1, co2, lt;
	sc_signal <sc_logic> enCounter1, initCounter1;
	sc_signal <sc_logic> enCounter2, initCounter2;
	sc_signal <sc_lv<2>> select_Addr;
	sc_signal <sc_logic> select_Data, select_Min;
	sc_signal <sc_logic> loadMinReg, loadMinAddrReg, loadDataReg;
	sc_signal <sc_logic> rwbar, cs;
	
	datapath* DP; 
	controller* CNTRL; 

	SC_CTOR(SSC){
		DP = new datapath("Datapath"); 

			(*DP) (clk, rst, enCounter1, initCounter1, enCounter2, initCounter2, select_Addr, select_Data, select_Min,
					loadMinReg, loadMinAddrReg, loadDataReg, cs, rwbar, co1, co2, lt);	

		CNTRL = new controller ("Controller"); 
			(*CNTRL) (clk, rst, start, co1, co2, lt, rwbar, cs, enCounter1, initCounter1, enCounter2, initCounter2,
					select_Addr, select_Data, select_Min, loadMinReg, loadMinAddrReg, loadDataReg,done);
		}
};

