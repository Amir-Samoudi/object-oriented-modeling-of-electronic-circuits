#pragma once

#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <systemc.h>

using namespace std;

const string MEM_FILE_PATH = "memdata/mem6.txt";


template<int ADDRESS, int WORD_LENGTH>
class Memory : public sc_module {
public:
	sc_in<sc_logic> clk, rst, read, write;
	sc_in<sc_lv<ADDRESS> > Addr;
	sc_in<sc_lv<WORD_LENGTH> > Din;
	sc_out<sc_lv<WORD_LENGTH> > Dout;

	int addrSpace;
	sc_uint <WORD_LENGTH> *mem;

	void meminit();
	void resetting();
	void memread();
	void memwrite();
	void memdump();

	SC_HAS_PROCESS(Memory);
	Memory(sc_module_name);
};

template<int ADDRESS, int WORD_LENGTH>
Memory<ADDRESS, WORD_LENGTH>::Memory(sc_module_name) 
{
	addrSpace = int(pow(2.0, ADDRESS));
	mem = new sc_uint<WORD_LENGTH>[addrSpace];

	SC_THREAD(meminit);
	SC_METHOD(memread);
	sensitive << Addr << read;
	SC_THREAD(memwrite);
	sensitive << Addr << Din << write << clk.pos();
	SC_METHOD(memdump);
    sensitive << clk;
}

template<int ADDRESS, int WORD_LENGTH>
void Memory<ADDRESS, WORD_LENGTH>::meminit() {
    // cout << "MEM INIT Starts\n";
    ifstream in(MEM_FILE_PATH);
    int i;
    sc_lv<WORD_LENGTH> data;

    for (i = 0; i<addrSpace; i++) {
        in >> data;
        mem[i] = data;
    }
    // cout << "MEM INIT finished\n";
}

template<int ADDRESS, int WORD_LENGTH>
void Memory<ADDRESS, WORD_LENGTH>::memwrite() {
	sc_uint<ADDRESS> ad;
    while (true)
    {
        if (clk == '1') {
                if (write == '1') {
                    ad = Addr; 
                    mem[ad] = Din;
                }
        }
        wait();
    }
}

template<int ADDRESS, int WORD_LENGTH>
void Memory<ADDRESS, WORD_LENGTH>::memread() {
	sc_uint<ADDRESS> ad;
    if (read == '1') {
        ad = Addr; 
        Dout = mem[ad];
    }
    // cout << "Address = " << ad << " , data = " << mem[ad] << endl;
    // cout << "memread finishes\n";
}

template<int ADDRESS, int WORD_LENGTH>
void Memory<ADDRESS, WORD_LENGTH>::memdump() {
	int i;
	sc_lv<WORD_LENGTH> data;
	ofstream out("out.txt");
	for (i = 0; i<addrSpace; i++) {
		data = mem[i];
		out << data << "\n";
	}
}