#include "partsLibrary.h"

void Comparator16::compare() {
	if (ain->read().to_uint() < bin->read().to_uint64())
		lt = SC_LOGIC_1;
	else
		lt = SC_LOGIC_0;

}


void nBitAdder::adding()
{
	sc_lv<9> res;
	res = ain->read().to_uint() + bin->read().to_uint()
								+ ci->read().value();
	addout->write(res.range(7, 0));
	co->write(res[8]);
}

void octalMux2to1::muxing() {
	if (sel->read() == '1') yout->write(bin); 
	else yout->write(ain);
}

void Mux2to1_16::muxing() {
	if (sel->read() == "1") yout->write(bin);
	else  yout->write(ain);
}

void Mux3to1_8::muxing() {
	if (sel->read() == "00") yout->write(ain);
	else if (sel->read() == "01") yout->write(bin);
	else if (sel->read() == "10") yout->write(cin);
	else yout->write("ZZZZZZZZ");
}


void octalTriState::selecting() {
	if (sel == '1') yout = ain; 
	else yout = "ZZZZZZZZ";
}

void dRegisterRaE::registering()
{
	if (rst == '1')
	{
		regout = "00000000";
	}
	else if (clk->event() && (clk == '1'))
	{
		if (cen == '1') regout = regin;
	}
}

void dRegisterRaEZ::registering()
{
	if (rst == '1')
	{
		regout = "00000000";
	}
	else if (clk->event() && (clk == '1'))
	{
		if (cen == '1') {
			if (zer == '1') regout = 0;
			else regout = regin;
		}
	}
}

void dRegisterRsE::registering() {
	if (rst == '1') {
		regout = 0;
	}
	else if (cen == '1') {
		regout = regin;
	}
}

void uCounterRaEL::counting()
{
	if (rst == '1')
	{
		cntout = 0;
	}
	else if (clk->event() && (clk == '1'))
	{
		if (pld == '1') cntout = parin;
		else if (cen == '1') cntout = cntout->read().to_uint() + 1;
	}
}


void uCounterRaELCo::counting()
{
	if (rst == '1')
	{
		cntout = "00000000";
	}
	else if (clk->event() && (clk == SC_LOGIC_1))
	{
		if (init == SC_LOGIC_1) 
			cntout = parin;
		else if (cen == '1')
		{
			if (cntout.read().to_uint() == 255)
				cntout = "00000000"; // Reset to 0 after reaching 255
			else
				cntout = sc_lv<8>(cntout.read().to_uint() + 1);
		}
	}
}


// void uCounterRaELCo::counting()
// {
// 	if (rst == '1')
// 	{
// 		cntout = "00000000";
// 	}
// 	else if (clk->event() && (clk == SC_LOGIC_1))
// 	{
// 		if (init == SC_LOGIC_1) 
// 			cntout = parin;
// 		else if (cen == '1')
// 			cntout = cntout->read().to_uint() + 1;
// 	}
// }

void uCounterRaELCo::carrying()
{
	if (cntout.read().to_uint() == 255) co = SC_LOGIC_1;
	else co = SC_LOGIC_0;
}

void rShifterRaEL::shifting()
{
	if (rst == '1')
	{
		shftout = "00000000";
	}
	else if (clk->event() && (clk == '1'))
	{
		if (pld == '1') shftout = parin;
		else if (sen == '1') 
			shftout = (sin, shftout->read().range(7, 1));
	}
}

void nBitAdder_channelSpecific::adding()
{
	sc_lv<9> res;
	res = ain.read().to_uint() + bin.read().to_uint()
								+ ci.read().value();
	addout = res.range(7, 0);
	co = res[8];
}

