#pragma once

#include <iostream>
#include <algorithm>
#include <systemc.h>

using namespace std;

SC_MODULE(MaxPool)
{
    sc_in<sc_lv<8> > val0, val1, val2, val3;
    sc_out<sc_lv<8> > out;

    SC_CTOR(MaxPool)
    {
        SC_THREAD(evl)
            sensitive << val0 << val1 << val2 << val3;
    }

    void evl();
};

void MaxPool::evl()
{
    while(true)
    {   
        // Read input values and convert to integers
        int val0_int = val0->read().to_uint();
        int val1_int = val1->read().to_uint();
        int val2_int = val2->read().to_uint();
        int val3_int = val3->read().to_uint();

        // Find the maximum value
        int max_val = max({val0_int, val1_int, val2_int, val3_int});

        // Convert the maximum value back to sc_lv<8> and assign to output
        sc_lv<8> out_value = max_val;

        // Print the input and output values for debugging
        // cout << "Inputs : " << val0_int << ' ' << val1_int << ' ' << val2_int << ' ' << val3_int;
        // cout << " --> output : " << out_value.to_uint() << endl;

        // Write the output value
        out->write(out_value);

        wait();
    }
}
