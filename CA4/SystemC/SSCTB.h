#pragma once
#include "SSCDesign.h"
#include "partsLibrary.h"

SC_MODULE(SSCTB){
	sc_signal <sc_logic> clk, rst, start; 
	sc_signal <sc_logic> done;
	
	SSC* SSC1;

	SC_CTOR (SSCTB){
		SSC1= new SSC ("SSC_1"); 
			SSC1->clk(clk); 
			SSC1->rst(rst); 
			SSC1->start(start);
			SSC1->done(done);

		//
		SC_THREAD(inputing); 
		SC_THREAD(reseting); 
		SC_THREAD(clocking); 
		// SC_METHOD(displaying);
		// 	sensitive <<done.posedge_event();
	}
	void inputing(); 
	void reseting(); 
	void clocking(); 
	//void displaying(); 
}; 
