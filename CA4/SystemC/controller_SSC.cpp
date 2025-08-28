#include "controller_SSC.h"

void controller::comb_O_function()
{
	// Inactive output values
	rwbar = SC_LOGIC_0;
	cs = SC_LOGIC_0;
	enCounter1 = SC_LOGIC_0;
	initCounter1 = SC_LOGIC_0;
	enCounter2 = SC_LOGIC_0;
	initCounter2 = SC_LOGIC_0;
	select_Addr = sc_lv<2>("00");
	select_Data = SC_LOGIC_0;
	select_Min = SC_LOGIC_0;
	loadMinReg = SC_LOGIC_0; 
	loadMinAddrReg = SC_LOGIC_0;
	loadDataReg = SC_LOGIC_0;
	done = SC_LOGIC_0;
	
	switch( p_state ){
		case S0:
			break;
		case S1: 
			break;
		case S2: 
			initCounter1 = SC_LOGIC_1;
			initCounter2 = SC_LOGIC_1;
			break;
		case S3: 
			initCounter2 = SC_LOGIC_1;
			break;
		case S4: 
			select_Addr = sc_lv<2>("00");
			rwbar = SC_LOGIC_1;
			cs = SC_LOGIC_1;
			loadMinReg = SC_LOGIC_1;
			loadMinAddrReg = SC_LOGIC_1;
			select_Min = SC_LOGIC_0;
			break;
		case S5: 
			select_Addr = sc_lv<2>("01");
			rwbar = SC_LOGIC_1;
			cs = SC_LOGIC_1;
			loadDataReg = SC_LOGIC_1;
			break;
		case S6: 
			break;
		case S7: 
			select_Addr = sc_lv<2>("01");
			loadMinReg = SC_LOGIC_1;
			loadMinAddrReg = SC_LOGIC_1;
			select_Min = SC_LOGIC_1;
			break;
		case S8: 
			break;
		case S9: 
			enCounter2 = SC_LOGIC_1;
			break;
		case S10: 
			select_Addr = sc_lv<2>("00");
			rwbar = SC_LOGIC_1;
			cs = SC_LOGIC_1;
			loadDataReg = SC_LOGIC_1;
			break;
		case S11: 
			select_Addr = sc_lv<2>("00");
			rwbar = SC_LOGIC_0;
			cs = SC_LOGIC_1;
			select_Data = SC_LOGIC_0;
			break;
		case S12: 
			select_Addr = sc_lv<2>("10");
			rwbar = SC_LOGIC_0;
			cs = SC_LOGIC_1;
			select_Data = SC_LOGIC_1;
			enCounter1 = SC_LOGIC_1;
			break;
		case S13: 
			done = SC_LOGIC_1;
			break;
		default:
			rwbar = SC_LOGIC_0;
			cs = SC_LOGIC_0;
			enCounter1 = SC_LOGIC_0;
			initCounter1 = SC_LOGIC_0;
			enCounter2 = SC_LOGIC_0;
			initCounter2 = SC_LOGIC_0;
			select_Addr = sc_lv<2>("00");
			select_Data = SC_LOGIC_0;
			select_Min = SC_LOGIC_0;
			loadMinReg = SC_LOGIC_0; 
			loadMinAddrReg = SC_LOGIC_0;
			loadDataReg = SC_LOGIC_0;
			done = SC_LOGIC_0;
			break;
	}
}
void controller::comb_S_function(){
	n_state = S0;
	switch( p_state ){
		case S0:
			if (start == '0')  n_state = S0;
			else n_state = S1;
			break;
		case S1:
			if (start == '0')  n_state = S2;
			else n_state = S1;
			break;
		case S2: 
			n_state = S3;
			break;
		case S3: 
			if (co1 == "1") n_state = S13;
			else n_state = S4;
			break;
		case S4: 
			n_state = S5;
			break;
		case S5: 
			n_state = S6;
			break;
		case S6: 
			if (lt == "1") n_state = S7;
			else n_state = S8;
			break;
		case S7: 
			n_state = S8;
			break;
		case S8: 
			n_state = S9;
			break;
		case S9: 
			if (co2 == "1") n_state = S10;
			else n_state = S5;
			break;
		case S10: 
			n_state = S11;
			break;
		case S11: 
			n_state = S12;
			break;
		case S12: 
			n_state = S3;
			break;
		case S13: 
			n_state = S0;
			break;
		default:
			n_state = S0;
			break;
	}
}

void controller::seq_function(){
	if (rst == SC_LOGIC_1)
		p_state = S0;
	else if (clk->event() &&(clk == SC_LOGIC_1))
		p_state = n_state;

}
