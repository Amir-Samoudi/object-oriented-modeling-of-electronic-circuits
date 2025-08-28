#include "SSCController.h"

SSCController::SSCController (bus& start_, bus& done_, bus& clk_, bus& rst_,
	bus& enCounter1_, bus& initCounter1_, bus& co1_,
	bus& enCounter2_, bus& initCounter2_, bus& loadCounter2_, bus& co2_,
	bus& loadMinAddrReg_, bus& loadMinReg_, bus& loadDataReg_,
	bus& select_addr_, bus& select_data_, bus& select_min_,
	bus& read_, bus& write_, bus& lt_)
			:
	start(&start_), done(&done_),
	clk(&clk_), rst(&rst_),
	enCounter1(&enCounter1_), initCounter1(&initCounter1_), co1(&co1_),
	enCounter2(&enCounter2_), initCounter2(&initCounter2_), loadCounter2(&loadCounter2_), co2(&co2_),
	loadMinAddrReg(&loadMinAddrReg_), loadMinReg(&loadMinReg_), loadDataReg(&loadDataReg_),
	select_addr(&select_addr_), select_data(&select_data_), select_min(&select_min_),
	read(&read_), write(&write_), lt(&lt_)
	{
		Nstate = 0;
		Pstate= 0;

		i = 1;
	}

void SSCController::evl () {
	 
	 *enCounter1 = "0";
	 *initCounter1 = "0";
	 *enCounter2 = "0";
	 *initCounter2 = "0";
	 *loadCounter2 = "0";
	 *loadMinAddrReg = "0";
	 *loadMinReg = "0";
	 *loadDataReg = "0";
	 *select_addr = "00";
	 *select_data = "0";
	 *select_min = "0";
	 *read = "0";
	 *write = "0";
	 *done = "0";

	switch (Pstate){
		case 0: //INITIALIZE
			if( *start == "0" )	Nstate = 0;
			else Nstate = 1;
			break;
		case 1: //WAIT_ON_START
			if( *start == "0" ) Nstate = 2;
			else Nstate = 1;
			break;
		case 2: //
			Nstate = 3;
			break;
		case 3: //
			//Debug
			cout << "Itereation :" << i << endl;
			i++;

			if (*co1 == "0") Nstate = 4;
			else Nstate = 13;
			break;
		case 4: //
			Nstate = 5;
			break;
		case 5: //
			Nstate = 6;
			break;
		case 6: //
			if(*lt == "0") Nstate = 8;
			else Nstate = 7;
			break;
		case 7: //
			Nstate = 8;
			break;
		case 8:
			Nstate = 9;
			break;
		case 9: //
			if (*co2 == "0") Nstate = 5;
			else Nstate = 10;
			break;
		case 10: // Update0
			Nstate = 11;
			break;
		case 11: // Update1
			Nstate = 12;
			break;
		case 12: // Update2
			Nstate = 3;
			break;
		case 13: // Done
			Nstate = 0;
			break;
	 }
	 
	switch (Pstate){
		case 0 : //INITIALIZE
			 break;
		case 1: //WAIT_ON_START
			break;
		case 2: //
			*initCounter1 = "1";
			*enCounter1 = "1";
			*initCounter2 = "1";
			*enCounter2 = "1";

			break;
		case 3 : //
			*enCounter2 = "1";
			*loadCounter2 = "1";
			break;
		case 4: //
			*select_addr = "00";
			*read = "1";
			*loadMinReg = "1";
			*loadMinAddrReg = "1";
			*select_min = "0";
			break;
		case 5: //
			*select_addr = "01";
			*read = "1";
			*loadDataReg = "1";
			break;
		case 6: //
			break;

		case 7: //
			*select_addr = "01";
			*read = "1";
			*loadMinReg = "1";
			*loadMinAddrReg = "1";
			*select_min = "1";
			break;
		case 8: //
			break;
		case 9: //
			*enCounter2 = "1";
			break;
		case 10: // Update0
			*select_addr = "00";
			*read = "1";
			*loadDataReg = "1";
			break;
		case 11: // Update1
			*write = "1";
			*select_data = "0";
			*select_addr = "00";
			break;
		case 12: // Update2
			*write = "1";
			*select_data = "1";
			*select_addr = "10";
			*enCounter1 = "1";
			break;
		case 13: // Done
			*done = "1";
			break;
	 }
	 
	//cout << "PS = " << Pstate << endl;

	 if (*rst == "1") Pstate = 0;
	 else if (*clk == "P") Pstate = Nstate;
}
