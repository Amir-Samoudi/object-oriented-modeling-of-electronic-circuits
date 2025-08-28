#include "SSCTB.h"

void SSCTB::inputing(){
		start = SC_LOGIC_0;
		wait(10, SC_NS);
		start = SC_LOGIC_1;
		wait(13, SC_NS);
		start = SC_LOGIC_0;

}

void SSCTB::clocking(){
	int i; 
	clk = sc_logic('1'); 
	for (i=0; i <=1000; i++)   
	{
		clk = sc_logic('0');
		wait (1, SC_NS); 
		clk = sc_logic('1');
		wait (1, SC_NS); 
	}
}

void SSCTB::reseting(){
	rst = (sc_logic)'0';  
	wait (3, SC_NS);
	rst = (sc_logic)'1';
	wait (3, SC_NS);
	rst = (sc_logic)'0'; 
};

// void SSCTB::displaying(){
// 	cout << " x = " << x.read() << "  result = " << result.read() <<endl; 
// }


