#include "Convolution.h"
#include "Memory.h"

using namespace std;

// const int BIAS = -2;
// const int KERNEL[9] = {1, 1, 1, 1, 0, 0 ,1, 1, 1};


SC_MODULE(ConvolutionalTB)
{
    sc_signal<sc_logic> clk, rst, start_conv;
    sc_signal<sc_lv<8> > data_rd;

    sc_signal<sc_logic> read, done_conv;
    sc_signal<sc_lv<4> > addr_rd;
    sc_signal<sc_lv<8> > val0, val1, val2, val3;

    sc_signal<sc_logic> write;
    sc_signal<sc_lv<8> > data_write;

    Convolution<BIAS, KERNEL>* conv;
    Memory<4, 8>* mem;

    SC_CTOR(ConvolutionalTB)
    {
        write.write(SC_LOGIC_0);
        conv = new Convolution<BIAS, KERNEL> ("Conv_instance");
            conv->clk(clk);
            conv->rst(rst);
            conv->start_conv(start_conv);
            conv->data_rd(data_rd);
            conv->read(read);
            conv->done_conv(done_conv);
            conv->addr_rd(addr_rd);
            conv->val0(val0);
            conv->val1(val1);
            conv->val2(val2);
            conv->val3(val3);
        
        mem = new Memory<4, 8> ("Memory_instance");
            mem->clk(clk);
            mem->rst(rst);
            mem->read(read);
            mem->write(write);
            mem->Addr(addr_rd);
            mem->Din(data_write);
            mem->Dout(data_rd);


        SC_THREAD(inputing); 
		SC_THREAD(reseting); 
		SC_THREAD(clocking);
    }
    void inputing(); 
	void reseting(); 
	void clocking();
};

void ConvolutionalTB::inputing()
{
    start_conv = SC_LOGIC_0;
	wait(10, SC_NS);
	start_conv = SC_LOGIC_1;
	wait(13, SC_NS);
	start_conv = SC_LOGIC_0;
}

void ConvolutionalTB::clocking()
{
	clk = sc_logic('1'); 
	for (int i=0; i <=100; i++)   
	{
		clk = sc_logic('0');
		wait (2, SC_NS); 
		clk = sc_logic('1');
		wait (2, SC_NS); 
	}
}

void ConvolutionalTB::reseting()
{
    rst = (sc_logic)'0';  
	wait (3, SC_NS);
	rst = (sc_logic)'1';
	wait (3, SC_NS);
	rst = (sc_logic)'0'; 
}