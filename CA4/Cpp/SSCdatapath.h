#include "classVectorPrimitives.h"
#include <string>
using namespace std;

class SSCDatapath
{
	bus *clk, *rst;
	bus *enCounter1, *initCounter1, *co1;
	bus *enCounter2, *initCounter2, *loadCounter2, *co2;
	bus *loadMinAddrReg, *loadMinReg, *loadDataReg;
	bus *select_addr, *select_data, *select_min;
	bus *read, *write;
	bus *lt;

	dRegisterRaE* MinReg;
	dRegisterRaE* MinAddrReg;
	dRegisterRaE* DataReg;

	upCounterRaE* Counter1;
	upCounterRaE* Counter2;

	Mux* mux_data;
	Mux* mux_minReg;
	Mux3* mux_addr;

	Comparator* comp;
	Adder* Add1;

	Memory* RegisterFile;

	// Internal Busses
	bus Counter1Value, Counter1PI, loadCounter1;
	bus	Counter2Value, Counter2PI;
	bus AddressBus;
	bus writeData, readData;
	bus MinAddrRegValue;
	bus MinRegIn, MinRegValue;
	bus DataRegValue;
	bus addCi, addCo, addB;
	bus eq, gt;

public:
	SSCDatapath(bus &clk, bus &rst,
		bus& enCounter1, bus &initCounter1, bus& co1,
		bus& enCounter2, bus& initCounter2, bus& loadCounter2, bus& co2,
		bus& loadMinAddrReg, bus& loadMinReg, bus& loadDataReg,
		bus& select_addr, bus& select_data, bus& select_min,
		bus& read, bus& write, bus& lt
	);
	~SSCDatapath();
	void evl();
	void evlMemory() { RegisterFile-> evl(); }
	void initMemory (string filename) { RegisterFile-> init(filename); }
	void dumpMemory (string filename) { RegisterFile-> dump(filename); }
};


