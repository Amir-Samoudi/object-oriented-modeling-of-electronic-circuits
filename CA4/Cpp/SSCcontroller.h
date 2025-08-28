#include "classVectorPrimitives.h"
#include <string>
using namespace std;

class SSCController{
	bus *start, *done;
	bus *clk, *rst;
	bus *enCounter1, *initCounter1, *co1;
	bus *enCounter2, *initCounter2, *loadCounter2, *co2;
	bus *loadMinAddrReg, *loadMinReg, *loadDataReg;
	bus *select_addr, *select_data, *select_min;
	bus *read, *write;
	bus *lt;
	int Nstate, Pstate;

	int i;

	public:
		SSCController(bus& start, bus& done,
			bus& clk, bus& rst,
			bus& enCounter1, bus& initCounter1, bus& co1,
			bus& enCounter2, bus& initCounter2, bus& loadCounter2, bus& co2,
			bus& loadMinAddrReg, bus& loadMinReg, bus& loadDataReg,
			bus& select_addr, bus& select_data, bus& select_min,
			bus& read, bus& write, bus& lt);
		~SSCController();
		void evl ();
};

