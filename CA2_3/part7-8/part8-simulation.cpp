#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

const char COMMA_DELIMETER = ',';

struct Wire {
	char logic;
};

Wire operator& (Wire a, Wire b)
{
	Wire tl;
	if ((a.logic=='0')||(b.logic=='0')) {
		tl.logic = '0';
	}
	else if ((a.logic=='1')&&(b.logic=='1')) {
		tl.logic = '1';
	}
	else {
		tl.logic = 'X';
	};
	return tl;
}

Wire operator| (Wire a, Wire b)
{
	Wire tl;
	if ((a.logic=='1')||(b.logic=='1')) {
		tl.logic = '1';
	}
	else if ((a.logic=='0')&&(b.logic=='0')) {
		tl.logic = '0';
	}
	else {
		tl.logic = 'X';
	};
	return tl;
}

Wire operator~ (Wire a)
{
	Wire tl;
	if (a.logic=='1') tl.logic = '0';
	else if (a.logic=='0') tl.logic = '1';
	else tl.logic=='X';
	return tl;
}

void AND(Wire a, Wire b, Wire& w)
{
    if ((a.logic == '0') || (b.logic == '0'))
        w.logic = '0';
    else if ((a.logic == '1') && (b.logic == '1'))
        w.logic = '1';
    else
        w.logic = 'X';
}

void OR(Wire a, Wire b, Wire& w)
{
    if ((a.logic == '1') || (b.logic == '1'))
        w.logic = '1';
    else if ((a.logic == '0') && (b.logic == '0'))
        w.logic = '0';
    else
        w.logic = 'X';
}

void NOT(Wire a, Wire& w)
{
    if (a.logic == '1')
        w.logic = '0';
    else if (a.logic == '0')
        w.logic = '1';
    else
        w.logic = 'X';
}

void DFF_PP0 ( Wire clk, Wire D, Wire& Q, Wire reset)
// Posedge, Asynch, active-Low
{
	if (reset.logic =='1') Q.logic='0';
	else if (clk.logic=='P') Q.logic=D.logic;
}

string reverse_bits(string s){
    reverse(s.begin(), s.end());
    return s;
}




void Mult_Combinational_Behavioral(
    Wire ABus[],
    Wire BBus[],
    Wire Areg[], 
    Wire Breg[], 
    Wire Preg[],
    Wire ps[],
    Wire _192_, 
    Wire start,
    Wire& _193_, 
    Wire& _024_, 
    Wire _000_[], 
    Wire _001_[], 
    Wire _002_[],
    Wire& ready,
    Wire resultBus[]){
    _193_ = ((((_192_) | (start)) & (~((ps[4])))));
    _024_ = (((~((_192_))) & (start)));
    _000_[0] = ((((ABus[0]) & (ps[3])) | ((((((ps[2]) | (ps[4])) | ((ps[1]) | (ps[5]))) & (Areg[1])) | ((((~((ps[2]))) & (~((ps[4])))) & ((~((ps[1]))) & (~((ps[5]))))) & (Areg[0]))) & (~((ps[3]))))));
    _000_[1] = ((((ABus[1]) & (ps[3])) | ((((((ps[2]) | (ps[4])) | ((ps[1]) | (ps[5]))) & (Areg[2])) | ((((~((ps[2]))) & (~((ps[4])))) & ((~((ps[1]))) & (~((ps[5]))))) & (Areg[1]))) & (~((ps[3]))))));
    _000_[2] = ((((ABus[2]) & (ps[3])) | ((((((ps[2]) | (ps[4])) | ((ps[1]) | (ps[5]))) & (Areg[3])) | ((((~((ps[2]))) & (~((ps[4])))) & ((~((ps[1]))) & (~((ps[5]))))) & (Areg[2]))) & (~((ps[3]))))));
    _000_[3] = ((((((((~((ps[2]))) & (~((ps[4])))) & ((~((ps[1]))) & (~((ps[5]))))) & (Areg[3])) | (ps[3])) | (((~(((((((ps[2]) | (ps[4])) | ((ps[1]) | (ps[5]))) & (Areg[0])) & (Breg[0])) & (Preg[0])))) & (((ps[2]) | (ps[4])) | ((ps[1]) | (ps[5])))) & ((((((ps[2]) | (ps[4])) | ((ps[1]) | (ps[5]))) & (Areg[0])) & (Breg[0])) | (Preg[0])))) & ((ABus[3]) | (~((ps[3]))))));
    _001_[0] = ((((BBus[0]) | (~((ps[3])))) & ((ps[3]) | (Breg[0]))));
    _001_[1] = ((((BBus[1]) | (~((ps[3])))) & ((ps[3]) | (Breg[1]))));
    _001_[2] = ((((BBus[2]) | (~((ps[3])))) & ((Breg[2]) | (ps[3]))));
    _001_[3] = ((((BBus[3]) | (~((ps[3])))) & ((Breg[3]) | (ps[3]))));
    _002_[0] = (((((((ps[2]) | (ps[4])) | ((ps[1]) | (ps[5]))) | (Preg[0])) & (~((ps[3])))) & ((((((((((~((ps[2]))) & (~((ps[4])))) & ((~((ps[1]))) & (~((ps[5]))))) | (~((Areg[0])))) | (~((Breg[1])))) | (~((Preg[1])))) & ((((((ps[2]) | (ps[4])) | ((ps[1]) | (ps[5]))) & (Areg[0])) & (Breg[1])) | (Preg[1]))) | ((((((ps[2]) | (ps[4])) | ((ps[1]) | (ps[5]))) & (Areg[0])) & (Breg[0])) & (Preg[0]))) & ((((((((ps[2]) | (ps[4])) | ((ps[1]) | (ps[5]))) & (Areg[0])) & (Breg[1])) & (Preg[1])) | ((((((~((ps[2]))) & (~((ps[4])))) & ((~((ps[1]))) & (~((ps[5]))))) | (~((Areg[0])))) | (~((Breg[1])))) & (~((Preg[1]))))) | (~(((((((ps[2]) | (ps[4])) | ((ps[1]) | (ps[5]))) & (Areg[0])) & (Breg[0])) & (Preg[0])))))) | (((~((ps[2]))) & (~((ps[4])))) & ((~((ps[1]))) & (~((ps[5]))))))));
    _002_[1] = (((((((ps[2]) | (ps[4])) | ((ps[1]) | (ps[5]))) | (Preg[1])) & (~((ps[3])))) & ((((~((((((((ps[2]) | (ps[4])) | ((ps[1]) | (ps[5]))) & (Areg[0])) & (Breg[2])) | (Preg[2])) & (~(((((((ps[2]) | (ps[4])) | ((ps[1]) | (ps[5]))) & (Areg[0])) & (Breg[2])) & (Preg[2]))))))) | (((((((((ps[2]) | (ps[4])) | ((ps[1]) | (ps[5]))) & (Areg[0])) & (Breg[1])) & (Preg[1])) | ((((((~((ps[2]))) & (~((ps[4])))) & ((~((ps[1]))) & (~((ps[5]))))) | (~((Areg[0])))) | (~((Breg[1])))) & (~((Preg[1]))))) | (~(((((((ps[2]) | (ps[4])) | ((ps[1]) | (ps[5]))) & (Areg[0])) & (Breg[0])) & (Preg[0]))))) & ((((((~((ps[2]))) & (~((ps[4])))) & ((~((ps[1]))) & (~((ps[5]))))) | (~((Areg[0])))) | (~((Breg[1])))) | (~((Preg[1])))))) & ((((((((ps[2]) | (ps[4])) | ((ps[1]) | (ps[5]))) & (Areg[0])) & (Breg[2])) | (Preg[2])) & (~(((((((ps[2]) | (ps[4])) | ((ps[1]) | (ps[5]))) & (Areg[0])) & (Breg[2])) & (Preg[2]))))) | (((((((((~((ps[2]))) & (~((ps[4])))) & ((~((ps[1]))) & (~((ps[5]))))) | (~((Areg[0])))) | (~((Breg[1])))) | (~((Preg[1])))) & ((((((ps[2]) | (ps[4])) | ((ps[1]) | (ps[5]))) & (Areg[0])) & (Breg[1])) | (Preg[1]))) & ((((((ps[2]) | (ps[4])) | ((ps[1]) | (ps[5]))) & (Areg[0])) & (Breg[0])) & (Preg[0]))) | ((((((ps[2]) | (ps[4])) | ((ps[1]) | (ps[5]))) & (Areg[0])) & (Breg[1])) & (Preg[1]))))) | (((~((ps[2]))) & (~((ps[4])))) & ((~((ps[1]))) & (~((ps[5]))))))));
    _002_[2] = (((((((ps[2]) | (ps[4])) | ((ps[1]) | (ps[5]))) | (Preg[2])) & (~((ps[3])))) & (((((~(((((((ps[2]) | (ps[4])) | ((ps[1]) | (ps[5]))) & (Areg[0])) & (Breg[3])) & (Preg[3])))) & ((((((ps[2]) | (ps[4])) | ((ps[1]) | (ps[5]))) & (Areg[0])) & (Breg[3])) | (Preg[3]))) | (((((((((ps[2]) | (ps[4])) | ((ps[1]) | (ps[5]))) & (Areg[0])) & (Breg[2])) | (Preg[2])) & (~(((((((ps[2]) | (ps[4])) | ((ps[1]) | (ps[5]))) & (Areg[0])) & (Breg[2])) & (Preg[2]))))) & (((((((((~((ps[2]))) & (~((ps[4])))) & ((~((ps[1]))) & (~((ps[5]))))) | (~((Areg[0])))) | (~((Breg[1])))) | (~((Preg[1])))) & ((((((ps[2]) | (ps[4])) | ((ps[1]) | (ps[5]))) & (Areg[0])) & (Breg[1])) | (Preg[1]))) & ((((((ps[2]) | (ps[4])) | ((ps[1]) | (ps[5]))) & (Areg[0])) & (Breg[0])) & (Preg[0]))) | ((((((ps[2]) | (ps[4])) | ((ps[1]) | (ps[5]))) & (Areg[0])) & (Breg[1])) & (Preg[1])))) | ((((((ps[2]) | (ps[4])) | ((ps[1]) | (ps[5]))) & (Areg[0])) & (Breg[2])) & (Preg[2])))) & ((~(((~(((((((ps[2]) | (ps[4])) | ((ps[1]) | (ps[5]))) & (Areg[0])) & (Breg[3])) & (Preg[3])))) & ((((((ps[2]) | (ps[4])) | ((ps[1]) | (ps[5]))) & (Areg[0])) & (Breg[3])) | (Preg[3]))))) | (((~((((((((ps[2]) | (ps[4])) | ((ps[1]) | (ps[5]))) & (Areg[0])) & (Breg[2])) | (Preg[2])) & (~(((((((ps[2]) | (ps[4])) | ((ps[1]) | (ps[5]))) & (Areg[0])) & (Breg[2])) & (Preg[2]))))))) | (((((((((ps[2]) | (ps[4])) | ((ps[1]) | (ps[5]))) & (Areg[0])) & (Breg[1])) & (Preg[1])) | ((((((~((ps[2]))) & (~((ps[4])))) & ((~((ps[1]))) & (~((ps[5]))))) | (~((Areg[0])))) | (~((Breg[1])))) & (~((Preg[1]))))) | (~(((((((ps[2]) | (ps[4])) | ((ps[1]) | (ps[5]))) & (Areg[0])) & (Breg[0])) & (Preg[0]))))) & ((((((~((ps[2]))) & (~((ps[4])))) & ((~((ps[1]))) & (~((ps[5]))))) | (~((Areg[0])))) | (~((Breg[1])))) | (~((Preg[1])))))) & (~(((((((ps[2]) | (ps[4])) | ((ps[1]) | (ps[5]))) & (Areg[0])) & (Breg[2])) & (Preg[2]))))))) | (((~((ps[2]))) & (~((ps[4])))) & ((~((ps[1]))) & (~((ps[5]))))))));
    _002_[3] = (((((((ps[2]) | (ps[4])) | ((ps[1]) | (ps[5]))) | (Preg[3])) & (~((ps[3])))) & ((((((((ps[2]) | (ps[4])) | ((ps[1]) | (ps[5]))) & (Areg[0])) & (Breg[3])) & (Preg[3])) | (((~((ps[2]))) & (~((ps[4])))) & ((~((ps[1]))) & (~((ps[5])))))) | (((~(((((((ps[2]) | (ps[4])) | ((ps[1]) | (ps[5]))) & (Areg[0])) & (Breg[3])) & (Preg[3])))) & ((((((ps[2]) | (ps[4])) | ((ps[1]) | (ps[5]))) & (Areg[0])) & (Breg[3])) | (Preg[3]))) & (((((((((ps[2]) | (ps[4])) | ((ps[1]) | (ps[5]))) & (Areg[0])) & (Breg[2])) | (Preg[2])) & (~(((((((ps[2]) | (ps[4])) | ((ps[1]) | (ps[5]))) & (Areg[0])) & (Breg[2])) & (Preg[2]))))) & (((((((((~((ps[2]))) & (~((ps[4])))) & ((~((ps[1]))) & (~((ps[5]))))) | (~((Areg[0])))) | (~((Breg[1])))) | (~((Preg[1])))) & ((((((ps[2]) | (ps[4])) | ((ps[1]) | (ps[5]))) & (Areg[0])) & (Breg[1])) | (Preg[1]))) & ((((((ps[2]) | (ps[4])) | ((ps[1]) | (ps[5]))) & (Areg[0])) & (Breg[0])) & (Preg[0]))) | ((((((ps[2]) | (ps[4])) | ((ps[1]) | (ps[5]))) & (Areg[0])) & (Breg[1])) & (Preg[1])))) | ((((((ps[2]) | (ps[4])) | ((ps[1]) | (ps[5]))) & (Areg[0])) & (Breg[2])) & (Preg[2])))))));
    ready = ((~((_192_))));
    resultBus[0] = (Areg[0]);
    resultBus[1] = (Areg[1]);
    resultBus[2] = (Areg[2]);
    resultBus[3] = (Areg[3]);
    resultBus[4] = (Preg[0]);
    resultBus[5] = (Preg[1]);
    resultBus[6] = (Preg[2]);
    resultBus[7] = (Preg[3]);
}


void Mult_Sequential(
    Wire clk, Wire rst,
    Wire _193_, Wire _024_, 
    Wire _000_[], Wire _001_[], Wire _002_[],
    Wire Areg[], Wire Breg[], Wire Preg[],
    Wire ps[],
    Wire& _192_
){

    DFF_PP0 (
    clk,
    _193_,
    _192_,
    rst
  );
  DFF_PP0 (
    clk,
    ps[1],
    ps[4],
    rst
  );
  DFF_PP0 (
    clk,
    ps[5],
    ps[1],
    rst
  );
   
  DFF_PP0 (
    clk,
    ps[2],
    ps[5],
    rst
  );

  DFF_PP0 (
    clk,
    ps[3],
    ps[2],
    rst
  );

  DFF_PP0 (
    clk,
    _024_,
    ps[3],
    rst
  );
 
  DFF_PP0 (
    clk,
    _002_[0],
    Preg[0],
    rst
  );
  DFF_PP0 (
    clk,
    _002_[1],
    Preg[1],
    rst
  );
  DFF_PP0 (
    clk,
    _002_[2],
    Preg[2],
    rst
  );
  DFF_PP0 (
    clk,
    _002_[3],
    Preg[3],
    rst
  );
  DFF_PP0  (
    clk,
    _001_[0],
    Breg[0],
    rst
  );
  DFF_PP0  (
    clk,
    _001_[1],
    Breg[1],
    rst
  );
  DFF_PP0 (
    clk,
    _001_[2],
    Breg[2],
    rst
  );
  DFF_PP0 (
    clk,
    _001_[3],
    Breg[3],
    rst
  );
  DFF_PP0 (
    clk,
    _000_[0],
    Areg[0],
    rst
  );
  DFF_PP0 (
    clk,
    _000_[1],
    Areg[1],
    rst
  );
  DFF_PP0 (
    clk,
    _000_[2],
    Areg[2],
    rst
  );
  DFF_PP0 (
    clk,
    _000_[3],
    Areg[3],
    rst
  );
}

void getVect (string value_str, Wire values[])
{ //order according to bit significance
	value_str = reverse_bits(value_str);
	for (int i=0; i < value_str.size() ; i++) {
		values[i].logic = value_str[i];
	}
}

string print_resultBus( Wire values[])
{
    string result1 = "", result2 = "";
    for (int i = 0; i < 4; i++){
      result1 += values[i].logic;
    }
    for (int i = 4; i < 8; i++){
      result2 += values[i].logic;
    }
    return reverse_bits(result2) + reverse_bits(result1);
    
}

int main(){
    // Primary Inputs and Outputs
    Wire clk, rst, start, ready;
    Wire *ABus, *BBus, *resultBus;

    ABus = new Wire[4];
    BBus = new Wire[4];
    resultBus = new Wire[8];


    // Combinational and Sequential parts Connections
    Wire _192_, _193_, _024_;
    Wire *Areg, *Breg, *Preg, *ps, *_000_, *_001_,* _002_;

    Areg = new Wire[4];
    Breg = new Wire[4];
    Preg = new Wire[4];
    ps = new Wire[6];
    _000_ = new Wire[4];
    _001_ = new Wire[4];
    _002_ = new Wire[4];


    string input_file_path = "input_data.txt";
    string output_file_path = "output_data.txt";

    ifstream input_file(input_file_path);
    ofstream output_file(output_file_path);

    string line;
    getline(input_file, line);

    int clock_cycle = 0;
    while (getline(input_file, line))
    {
        clock_cycle++;
        stringstream ss(line);
        string clk_str, rst_str, start_str, ABus_str, BBus_str;
        getline(ss, clk_str, COMMA_DELIMETER);
        getline(ss, rst_str, COMMA_DELIMETER);
        getline(ss, start_str, COMMA_DELIMETER);
        getline(ss, ABus_str, COMMA_DELIMETER);
        getline(ss, BBus_str);
        clk.logic = clk_str[0];
        rst.logic = rst_str[0];
        start.logic = start_str[0];
        getVect(ABus_str, ABus);
        getVect(BBus_str, BBus);
        //cout << "A = " << print_vect(ABus, 4) << ",  B = " << print_vect(BBus, 4) << endl;

        Mult_Combinational_Behavioral(ABus, BBus, Areg, Breg, Preg, ps, _192_, start,
                                  _193_, _024_, _000_, _001_, _002_, ready, resultBus);


        Mult_Sequential(clk, rst, _193_, _024_, _000_, _001_, _002_,
                        Areg, Breg, Preg, ps, _192_);

        output_file << "C.C = " << clock_cycle<< " : " << "Clock = "<< clk.logic 
                    << "  ,Reset = "<< rst.logic<<"  ,start = " << start.logic
                    << "  ,Mult Result = " << print_resultBus(resultBus) << ",  ready = " << ready.logic << endl;

    }
    input_file.close();
    output_file.close();
}