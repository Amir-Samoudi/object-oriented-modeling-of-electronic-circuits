#pragma once

#include <iostream>
#include <vector>
#include <systemc.h>

using namespace std;

template<const int BIAS, const int* KERNEL>
SC_MODULE(Convolution)
{
    sc_in<sc_logic> clk, rst, start_conv;
    sc_in<sc_lv<8> > data_rd;

    sc_out<sc_logic> read, done_conv;
    sc_out<sc_lv<4> > addr_rd;
    sc_out<sc_lv<8> > val0, val1, val2, val3;

    int ADDR[4][9] = {{0, 1, 2, 4, 5, 6, 8, 9, 10},
                {1, 2, 3, 5, 6, 7, 9, 10, 11},
                {4, 5, 6, 8, 9, 10, 12, 13, 14},
                {5, 6, 7, 9, 10, 11, 13, 14, 15}};

    

    SC_CTOR(Convolution)
    {
        SC_THREAD(operation)
            sensitive << clk << rst;
    }
    void operation();
};


template<const int BIAS, const int* KERNEL>
void Convolution<BIAS, KERNEL>::operation()
{
    while (true){
        if (rst == '1'){
            done_conv->write(SC_LOGIC_1);
        }

        else if ((clk == '1') && (clk->event())){

            // cout << "Start Process:\n";

            int Val_int[4] = {BIAS, BIAS, BIAS, BIAS};

            while (start_conv == '0') {wait();}
            done_conv->write(SC_LOGIC_0);
            while (start_conv == '1') {wait();}

            for (int i = 0; i < 4; i++){
                // cout << "Iteration:" << (i+1) << endl; ///////////
                for (int j = 0; j < 9; j++){
                    // cout << "it:" << (j+1) << endl; //////////////
                    read->write(SC_LOGIC_1);
                    sc_lv<4> addr_val = ADDR[i][j];
                    addr_rd.write(addr_val);
                    wait(clk->posedge_event());
                    int read_data = data_rd->read().to_int();
                    // cout << "Mem data : " << data_rd->read().to_int() << ", KERNEL :" << KERNEL[j]; //////
                    Val_int[i] += KERNEL[j] * read_data;
                    // cout << ",  Val_int : " << Val_int[i] << endl;////////////
                    // read = '0';
                    // wait(clk->posedge_event());
                }
            }
            sc_lv<8> val0_lv = Val_int[0];
            sc_lv<8> val1_lv = Val_int[1];
            sc_lv<8> val2_lv = Val_int[2];
            sc_lv<8> val3_lv = Val_int[3];
            read->write(SC_LOGIC_0);
            val0->write(val0_lv);
            val1->write(val1_lv);
            val2->write(val2_lv);
            val3->write(val3_lv);
            // cout  << "DONE!" << " Val0 : " << Val_int[0] << ", Val1 : " << Val_int[1]
            //     << ", Val2 : " << Val_int[2] << ", Val3 : " << Val_int[3] << endl;
            done_conv->write(SC_LOGIC_1);
        }
        wait();
    }
}