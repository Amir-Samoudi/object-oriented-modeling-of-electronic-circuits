#pragma once
#include <systemc.h>
#include "partsLibrary.h"
#include "Register.h"
#include "Adder.h"

SC_MODULE(datapath){
	
	// Port Declaration
	sc_in <sc_logic> clk, rst;
	sc_in <sc_logic> enCounter1, initCounter1;
	sc_in <sc_logic> enCounter2, initCounter2;
	sc_in <sc_lv<2>> select_Addr;
	sc_in <sc_logic> select_Data, select_Min;
	sc_in <sc_logic> loadMinReg, loadMinAddrReg, loadDataReg;
	sc_in <sc_logic> cs, rwbar;
	sc_out <sc_logic> co1, co2, lt;


	
	// Signal Declaration
	sc_signal <sc_lv<8>> Counter1Value, Counter1PI;
	sc_signal <sc_lv<8>> Counter2Value, Counter2PI;
	sc_signal <sc_lv<8>> MinAddrRegValue;
	sc_signal <sc_lv<16>> MinRegIn, MinRegValue;
	sc_signal <sc_lv<16>> DataRegValue;
	sc_signal <sc_lv<8>> addB;

	sc_signal <sc_lv<16>> ReadData;
	sc_signal <sc_lv<16>> WriteData;
	sc_signal <sc_lv<8>> AddressBus;
	
	// Instantiation
	dRegister<16>* DataReg; 
	dRegister<16>* MinReg;
	dRegister<8>* MinAddrReg;
	Adder <8>* Add1;
	Comparator16* comp;
	uCounterRaELCo* Counter1;  
	uCounterRaELCo* Counter2;
	Mux3to1_8* Mux_Addr;
	Mux2to1_16* Mux_Data;  
	Mux2to1_16* Mux_MinReg; 
	Memory<8, 16>* RF;

	
	SC_CTOR(datapath){

		DataReg = new dRegister<16> ("Data Register");
			DataReg->clk(clk);
			DataReg->rst(rst);
			DataReg->cen(loadDataReg);
			DataReg->regin(ReadData);
			DataReg->regout(DataRegValue);
		
		MinReg = new dRegister<16> ("Min Register");
			MinReg->clk(clk);
			MinReg->rst(rst);
			MinReg->cen(loadMinReg);
			MinReg->regin(MinRegIn);
			MinReg->regout(MinRegValue);

		MinAddrReg = new dRegister<8> ("Min Address Register");
			MinAddrReg->clk(clk);
			MinAddrReg->rst(rst);
			MinAddrReg->cen(loadMinAddrReg);
			MinAddrReg->regin(AddressBus);
			MinAddrReg->regout(MinAddrRegValue);

		
		Add1 = new Adder<8> ("Adder");
			Add1->in1(Counter1Value);
			Add1->in2(addB);
			Add1->out(Counter2PI);
		
		comp = new Comparator16 ("Comparator");
			comp->ain(DataRegValue);
			comp->bin(MinRegValue);
			comp->lt(lt);

		Counter1 = new uCounterRaELCo("Counter1");
			Counter1->clk(clk);
			Counter1->rst(rst);
			Counter1->cen(enCounter1);
			Counter1->init(initCounter1);
			Counter1->co(co1);
			Counter1->parin(Counter1PI);
			Counter1->cntout(Counter1Value);

		Counter2 = new uCounterRaELCo("Counter2");
			Counter2->clk(clk);
			Counter2->rst(rst);
			Counter2->cen(enCounter2);
			Counter2->init(initCounter2);
			Counter2->co(co2);
			Counter2->parin(Counter2PI);
			Counter2->cntout(Counter2Value);

		Mux_Addr = new Mux3to1_8 ("Mux Address");
			Mux_Addr->ain(Counter1Value);
			Mux_Addr->bin(Counter2Value);
			Mux_Addr->cin(MinAddrRegValue);
			Mux_Addr->sel(select_Addr);
			Mux_Addr->yout(AddressBus);


		Mux_Data = new Mux2to1_16 ("Mux Data");
			Mux_Data->ain(MinRegValue);
			Mux_Data->bin(DataRegValue);
			Mux_Data->sel(select_Data);
			Mux_Data->yout(WriteData);

		Mux_MinReg = new Mux2to1_16 ("Mux MinRegister");
			Mux_MinReg->ain(ReadData);
			Mux_MinReg->bin(DataRegValue);
			Mux_MinReg->sel(select_Min);
			Mux_MinReg->yout(MinRegIn);

		RF = new Memory<8, 16> ("RegisterFile");
			RF->addr(AddressBus);
			RF->datain(WriteData);
			RF->dataout(ReadData);
			RF->cs(cs);
			RF->rwbar(rwbar);


		SC_METHOD(datapath_assign);
		sensitive << enCounter1 << initCounter1 << enCounter2 << initCounter2;

	}

	void datapath_assign(){
		Counter1PI = sc_lv<8>("00000000");
		addB = sc_lv<8>("00000001");

	}
	
};




