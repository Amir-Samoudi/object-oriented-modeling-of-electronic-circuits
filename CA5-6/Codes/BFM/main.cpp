#include "PatternFinderTB.h"

int sc_main (int argc, char *argv[]){
	
	//ResultTB* TOP = new ResultTB("Result_Instance"); 
    // MaxPoolTB* TOP = new MaxPoolTB("MaxPo0l_Instance");
    //ReLUTB* TOP = new ReLUTB("ReLU_Instance");
    // ConvolutionalTB* TOP = new ConvolutionalTB("Convolution_Instance");
    PatternFinderTB* TOP = new PatternFinderTB("Pattern_Finder_TB");

	sc_trace_file* VCDFile;
	VCDFile = sc_create_vcd_trace_file("PatternFinder");

	sc_trace(VCDFile, TOP->clk, "clk");
	sc_trace(VCDFile, TOP->rst, "rst");
	sc_trace(VCDFile, TOP->start, "start");
	sc_trace(VCDFile, TOP->done, "done");
	sc_trace(VCDFile, TOP->PF->pattern, "Pattern");
	// sc_trace(VCDFile, TOP->conv->val1, "output1");
	// sc_trace(VCDFile, TOP->conv->val2, "output2");
	// sc_trace(VCDFile, TOP->conv->val3, "output3");

	sc_start (1500, SC_NS);
	return 0; 
}