 #include "SSCDatapath.h"

SSCDatapath::SSCDatapath(bus& clk_, bus& rst_,
	bus& enCounter1_, bus& initCounter1_, bus& co1_,
	bus& enCounter2_, bus& initCounter2_, bus& loadCounter2_, bus& co2_,
	bus& loadMinAddrReg_, bus& loadMinReg_, bus& loadDataReg_,
	bus& select_addr_, bus& select_data_, bus& select_min_,
	bus& read_, bus& write_,bus& lt_)
					:
	clk(&clk_), rst(&rst_), 
	enCounter1(&enCounter1_), initCounter1(&initCounter1_), co1(&co1_), 
	enCounter2(&enCounter2_), initCounter2(&initCounter2_), loadCounter2(&loadCounter2_), co2(&co2_),
	loadMinAddrReg(&loadMinAddrReg_), loadMinReg(&loadMinReg_), loadDataReg(&loadDataReg_),
	select_addr(&select_addr_), select_data(&select_data_), select_min(&select_min_),
	read(&read_), write(&write_), lt(&lt_)

{
	// internal buses:
	loadCounter1 = "0";
	Counter1Value = "00000000";
	Counter1PI = "00000000";
	Counter2Value = "XXXXXXXX";
	Counter2PI    = "00000000";
	AddressBus    = "XXXXXXXX";
	writeData = "XXXXXXXXXXXXXXXX";
	readData  = "XXXXXXXXXXXXXXXX";
	MinAddrRegValue = "XXXXXXXX";
	MinRegIn = "XXXXXXXXXXXXXXXX";
	MinRegValue  = "XXXXXXXXXXXXXXXX";
	DataRegValue = "XXXXXXXXXXXXXXXX";
	addCi = "1";
	addCo = "X";
	addB = "00000000";
	eq = "X";
	gt = "X";

	MinReg = new dRegisterRaE(MinRegIn, *clk, *rst, *loadMinReg, MinRegValue);

	MinAddrReg = new dRegisterRaE(AddressBus, *clk, *rst, *loadMinAddrReg, MinAddrRegValue);

	DataReg = new dRegisterRaE(readData, *clk, *rst, *loadDataReg, DataRegValue);

	Counter1 = new upCounterRaE(Counter1PI, *clk, *rst, *initCounter1, *enCounter1, Counter1Value);

	Counter2 = new upCounterRaE(Counter2PI, *clk, *rst, *loadCounter2, *enCounter2, Counter2Value);

	comp = new Comparator(DataRegValue, MinRegValue, *lt, eq, gt);

	Add1 = new Adder(Counter1Value, addB, addCi, addCo, Counter2PI);

	mux_data = new Mux(MinRegValue, DataRegValue, *select_data, writeData);

	mux_minReg = new Mux(readData, DataRegValue, *select_min, MinRegIn);

	mux_addr = new Mux3(Counter1Value, Counter2Value, MinAddrRegValue, *select_addr, AddressBus);

	RegisterFile = new Memory(*rst, *clk, *read, *write, writeData, AddressBus, readData, 256);


}

void SSCDatapath::evl()
{
	Counter1->evl();
	*co1 = ((Counter1Value == "11111111") ? "1" : "0");	

	Add1->evl();

	Counter2->evl();
	*co2 = ((Counter2Value == "11111111") ? "1" : "0");

	mux_addr->evl();

	mux_data->evl();

	RegisterFile->evl();

	mux_minReg->evl();

	MinReg->evl();

	DataReg->evl();

	MinAddrReg->evl();

	comp->evl();
}
