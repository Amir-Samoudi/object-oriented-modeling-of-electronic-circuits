#pragma once
#include <systemc.h>

SC_MODULE (controller){

	sc_in <sc_logic> clk, rst, start, co1, co2, lt;

	sc_out <sc_logic> rwbar, cs;
	sc_out <sc_logic> enCounter1, initCounter1;
	sc_out <sc_logic> enCounter2, initCounter2;
	sc_out <sc_lv<2>> select_Addr;
	sc_out <sc_logic> select_Data, select_Min;
	sc_out <sc_logic> loadMinReg, loadMinAddrReg, loadDataReg;
	sc_out <sc_logic> done;
		
	enum states {S0, S1, S2, S3, S4, S5, S6, S7, S8, S9, S10, S11, S12, S13};
	sc_signal <states> p_state, n_state; 

	SC_CTOR(controller)
	{

		SC_METHOD (comb_S_function);
		sensitive << start << co1 << co2 << lt << p_state;
		SC_METHOD (comb_O_function);
		sensitive << p_state;
		SC_METHOD (seq_function); 
		sensitive << clk << rst;
	};

	void comb_S_function();
	void comb_O_function();
	void seq_function();
};

