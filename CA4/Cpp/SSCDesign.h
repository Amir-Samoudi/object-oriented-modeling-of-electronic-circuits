#include "SSCController.h"
#include "SSCDatapath.h"

class SSCDesign
{
	bus *clk, *rst, *start;
	bus *done;

	// internal nodes
	bus enCounter1, initCounter1, co1;
	bus enCounter2, initCounter2, loadCounter2, co2;
	bus loadMinAddrReg, loadMinReg, loadDataReg;
	bus select_addr, select_data, select_min;
	bus read, write;
	bus lt;



	// module
	SSCDatapath* DP;
	SSCController* CT;
	public:
		SSCDesign ( bus &clk, bus &rst, bus &start ,bus &done);
		~SSCDesign();
		void evl();
		void initialize (const string& filename);
		void write_sorted_file();
};
