#pragma once

#include "MaxPool.h"

SC_MODULE(MaxPoolTB)
{
    sc_signal<sc_lv<8> > input0;
    sc_signal<sc_lv<8> > input1;
    sc_signal<sc_lv<8> > input2;
    sc_signal<sc_lv<8> > input3;
    
    sc_signal<sc_lv<8> > output;

    MaxPool* MP;

    SC_CTOR(MaxPoolTB)
    {
        MP = new MaxPool("MaxPool_Module");
            MP->val0(input0);
            MP->val1(input1);
            MP->val2(input2);
            MP->val3(input3);
            MP->out(output);

        SC_THREAD(inGenerating);
    }
    void inGenerating();
};


void MaxPoolTB::inGenerating()
{
    while(true)
    {
        wait(10, SC_NS);

        input0 = "00000000";
        input1 = "00000000";
        input2 = "00100001";
        input3 = "00000111"; 
        ///

        wait(10, SC_NS);
        input0 = "00011000";
        input1 = "00000000";
        input2 = "00000001";
        input3 = "00000111"; 
        ///001
        wait(10, SC_NS);

        input0 = "00001100";
        input1 = "01000000";
        input2 = "00000011";
        input3 = "00000011";
        //100
        wait(10, SC_NS);

        input0 = "00000000";
        input1 = "00010100";
        input2 = "01000001";
        input3 = "01000111";
        //010
        wait(10, SC_NS);

        input0 = "00000110";
        input1 = "01100100";
        input2 = "00000100";
        input3 = "00000001";
        //100
        wait(50, SC_NS);

    }
}