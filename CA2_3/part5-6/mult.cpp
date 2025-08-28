#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

const char COMMA_DELIMETER = ',';

void AND(char a, char b, char& w)
{
    if ((a == '0') || (b == '0'))
        w = '0';
    else if ((a == '1') && (b == '1'))
        w = '1';
    else
        w = 'X';
}

void OR(char a, char b, char& w)
{
    if ((a == '1') || (b == '1'))
        w = '1';
    else if ((a == '0') && (b == '0'))
        w = '0';
    else
        w = 'X';
}

void NOT(char a, char& w)
{
    if (a == '1')
        w = '0';
    else if (a == '0')
        w = '1';
    else
        w = 'X';
}

void DFF_PP0 ( char clk, char D, char&Q, char reset)
// Posedge, Asynch, active-Low
{
	if (reset=='1') Q='0';
	else if (clk=='P') Q=D;
}

string reverse_bits(string s){
    reverse(s.begin(), s.end());
    return s;
}

void Mult_Combinational_Sorted(
    string ABus, string BBus,
    string Areg, string Breg, string Preg,
    string ps,// input [5:1] ps,
    char _192_, char start,

    char& _193_, char& _024_, 
    string& _000_, string& _001_, string& _002_,
    char& ready,
    string& resultBus
){

  char _003_;
  char _004_;
  char _005_;
  char _006_;
  char _007_;
  char _008_;
  char _009_;
  char _010_;
  char _011_;
  char _012_;
  char _013_;
  char _014_;
  char _015_;
  char _016_;
  char _017_;
  char _018_;
  char _019_;
  char _020_;
  char _021_;
  char _022_;
  char _023_;
  char _025_;
  char _026_;
  char _027_;
  char _028_;
  char _029_;
  char _030_;
  char _031_;
  char _032_;
  char _033_;
  char _034_;
  char _035_;
  char _036_;
  char _037_;
  char _038_;
  char _039_;
  char _040_;
  char _041_;
  char _042_;
  char _043_;
  char _044_;
  char _045_;
  char _046_;
  char _047_;
  char _048_;
  char _049_;
  char _050_;
  char _051_;
  char _052_;
  char _053_;
  char _054_;
  char _055_;
  char _056_;
  char _057_;
  char _058_;
  char _059_;
  char _060_;
  char _061_;
  char _062_;
  char _063_;
  char _064_;
  char _065_;
  char _066_;
  char _067_;
  char _068_;
  char _069_;
  char _070_;
  char _071_;
  char _072_;
  char _073_;
  char _074_;
  char _075_;
  char _076_;
  char _077_;
  char _078_;
  char _079_;
  char _080_;
  char _081_;
  char _082_;
  char _083_;
  char _084_;
  char _085_;
  char _086_;
  char _087_;
  char _088_;
  char _089_;
  char _090_;
  char _091_;
  char _092_;
  char _093_;
  char _094_;
  char _095_;
  char _096_;
  char _097_;
  char _098_;
  char _099_;
  char _100_;
  char _101_;
  char _102_;
  char _103_;
  char _104_;
  char _105_;
  char _106_;
  char _107_;
  char _108_;
  char _109_;
  char _110_;
  char _111_;
  char _112_;
  char _113_;
  char _114_;
  char _115_;
  char _116_;
  char _117_;
  char _118_;
  char _119_;
  char _120_;
  char _121_;
  char _122_;
  char _123_;
  char _124_;
  char _125_;
  char _126_;
  char _127_;
  char _128_;
  char _129_;
  char _130_;
  char _131_;
  char _132_;
  char _133_;
  char _134_;
  char _135_;
  char _136_;
  char _137_;
  char _138_;
  char _139_;
  char _140_;
  char _141_;
  char _142_;
  char _143_;
  char _144_;
  char _145_;
  char _146_;
  char _147_;
  char _148_;
  char _149_;
  char _150_;
  char _151_;
  char _152_;
  char _153_;
  char _154_;
  char _155_;
  char _156_;
  char _157_;
  char _158_;
  char _159_;
  char _160_;
  char _161_;
  char _162_;
  char _163_;
  char _164_;
  char _165_;
  char _166_;
  char _167_;
  char _168_;
  char _169_;
  char _170_;
  char _171_;
  char _172_;
  char _173_;
  char _174_;
  char _175_;
  char _176_;
  char _177_;
  char _178_;
  char _179_;
  char _180_;
  char _181_;
  char _182_;
  char _183_;
  char _184_;
  char _185_;
  char _186_;
  char _187_;
  char _188_;
  char _189_;
  char _190_;
  char _191_;
  char A0;
  char initP;
  char loadA;
  char loadB;

  A0 = Areg[0];
  initP = ps[3];
  loadA = ps[3];
  loadB = ps[3];
  resultBus = reverse_bits(Preg) + reverse_bits(Areg);
  _109_ = start;
  _129_ = Preg[0];
  _165_ = ps[4];
  _182_ = ps[5];
  _062_ = ps[1];
  _071_ = ps[2];
  _095_ = Breg[1];
  _101_ = Areg[0];
  _103_ = Preg[1];
  _104_ = Breg[0];
  _105_ = ps[3];
  _107_ = Preg[2];
  _108_ = Breg[2];
  _113_ = Breg[3];
  _114_ = Preg[3];
  _134_ = BBus[0];
  _138_ = BBus[1];
  _142_ = BBus[2];
  _146_ = BBus[3];
  _150_ = Areg[1];
  _153_ = ABus[0];
  _157_ = Areg[2];
  _160_ = ABus[1];
  _164_ = Areg[3];
  _167_ = ABus[2];
  _173_ = ABus[3];
  _179_ = _192_;

NOT(_165_, _110_);
OR (_179_, _109_, _112_);
AND(_112_, _110_, _051_);
NOT(_179_, _102_);
NOT(_182_, _115_);
NOT(_062_, _116_);
AND(_116_, _115_, _117_);
NOT(_071_, _118_);
AND(_118_, _110_, _119_);
AND(_119_, _117_, _120_);
OR (_062_, _182_, _122_);
OR (_071_, _165_, _123_);
OR (_123_, _122_, _124_);
AND(_124_, _101_, _125_);
AND(_125_, _104_, _126_);
AND(_126_, _129_, _127_);
NOT(_127_, _128_);
NOT(_103_, _130_);
NOT(_095_, _131_);
NOT(_101_, _133_);
OR (_120_, _133_, _135_);
OR (_135_, _131_, _137_);
AND(_137_, _130_, _139_);
AND(_125_, _095_, _141_);
AND(_141_, _103_, _143_);
OR (_143_, _139_, _145_);
OR (_145_, _128_, _147_);
OR (_141_, _103_, _149_);
OR (_137_, _130_, _151_);
AND(_151_, _149_, _152_);
OR (_152_, _127_, _154_);
AND(_154_, _147_, _156_);
OR (_156_, _120_, _158_);
NOT(_105_, _159_);
OR (_124_, _129_, _161_);
AND(_161_, _159_, _163_);
AND(_163_, _158_, _106_);
AND(_152_, _127_, _166_);
OR (_166_, _143_, _168_);
AND(_125_, _108_, _170_);
AND(_170_, _107_, _171_);
NOT(_171_, _172_);
OR (_170_, _107_, _174_);
AND(_174_, _172_, _176_);
OR (_176_, _168_, _178_);
AND(_147_, _151_, _180_);
NOT(_176_, _181_);
OR (_181_, _180_, _183_);
AND(_183_, _178_, _184_);
OR (_184_, _120_, _185_);
OR (_124_, _103_, _186_);
AND(_186_, _159_, _187_);
AND(_187_, _185_, _111_);
AND(_183_, _172_, _188_);
AND(_125_, _113_, _189_);
OR (_189_, _114_, _190_);
AND(_189_, _114_, _191_);
NOT(_191_, _052_);
AND(_052_, _190_, _053_);
NOT(_053_, _054_);
OR (_054_, _188_, _055_);
AND(_176_, _168_, _056_);
OR (_056_, _171_, _057_);
OR (_053_, _057_, _058_);
AND(_058_, _055_, _059_);
OR (_059_, _120_, _060_);
OR (_124_, _107_, _061_);
AND(_061_, _159_, _063_);
AND(_063_, _060_, _121_);
AND(_053_, _057_, _064_);
OR (_191_, _120_, _065_);
OR (_065_, _064_, _066_);
OR (_124_, _114_, _067_);
AND(_067_, _159_, _068_);
AND(_068_, _066_, _132_);
OR (_105_, _104_, _069_);
OR (_134_, _159_, _070_);
AND(_070_, _069_, _136_);
OR (_105_, _095_, _072_);
OR (_138_, _159_, _073_);
AND(_073_, _072_, _140_);
OR (_108_, _105_, _074_);
OR (_142_, _159_, _075_);
AND(_075_, _074_, _144_);
OR (_113_, _105_, _076_);
OR (_146_, _159_, _077_);
AND(_077_, _076_, _148_);
AND(_120_, _101_, _078_);
AND(_124_, _150_, _079_);
OR (_079_, _078_, _080_);
AND(_080_, _159_, _081_);
AND(_153_, _105_, _082_);
OR (_082_, _081_, _155_);
AND(_120_, _150_, _083_);
AND(_124_, _157_, _084_);
OR (_084_, _083_, _085_);
AND(_085_, _159_, _086_);
AND(_160_, _105_, _087_);
OR (_087_, _086_, _162_);
AND(_120_, _157_, _088_);
AND(_124_, _164_, _089_);
OR (_089_, _088_, _090_);
AND(_090_, _159_, _091_);
AND(_167_, _105_, _092_);
OR (_092_, _091_, _169_);
OR (_173_, _159_, _093_);
OR (_126_, _129_, _094_);
AND(_128_, _124_, _096_);
AND(_096_, _094_, _097_);
AND(_120_, _164_, _098_);
OR (_098_, _105_, _099_);
OR (_099_, _097_, _100_);
AND(_100_, _093_, _175_);
AND(_102_, _109_, _177_);

ps[0] = _102_;
ready = ps[0];
_193_ = _051_;
_002_[0] = _106_;
_002_[1] = _111_;
_002_[2] = _121_;
_002_[3] = _132_;
_001_[0] = _136_;
_001_[1] = _140_;
_001_[2] = _144_;
_001_[3] = _148_;
_000_[0] = _155_;
_000_[1] = _162_;
_000_[2] = _169_;
_000_[3] = _175_;
_024_ = _177_;

}

void Mult_Sequential(
    char clk, char rst,
    char _193_, char _024_, 
    string _000_, string _001_, string _002_,
    string& Areg, string& Breg, string& Preg,
    string& ps,
    char& _192_
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

int main(){
    // Primary Inputs and Outputs
    char clk('0'), rst('0'), start('0'), ready('X') ;
    string ABus("XXXX"), BBus("XXXX"), resultBus("XXXXXXXX");

    // Combinational and Sequential parts Connections
    char _192_('X'), _193_('X'), _024_('X');
    string Areg("XXXX"), Breg("XXXX"), Preg("XXXX"), ps("XXXXXXX");
    string _000_("XXXX"), _001_("XXXX"), _002_("XXXX");

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
        string clk_str, rst_str, start_str;
        getline(ss, clk_str, COMMA_DELIMETER);
        getline(ss, rst_str, COMMA_DELIMETER);
        getline(ss, start_str, COMMA_DELIMETER);
        getline(ss, ABus, COMMA_DELIMETER);
        getline(ss, BBus);
        clk = clk_str[0];
        rst = rst_str[0];
        start = start_str[0];
        ABus = reverse_bits(ABus);
        BBus = reverse_bits(BBus);

        Mult_Combinational_Sorted(ABus, BBus, Areg, Breg, Preg, ps, _192_, start,
                                  _193_, _024_, _000_, _001_, _002_, ready, resultBus);


        Mult_Sequential(clk, rst, _193_, _024_, _000_, _001_, _002_,
                        Areg, Breg, Preg, ps, _192_);

        output_file << "C.C = " << clock_cycle<< " : " << "Clock = "<< clk 
                    << "  ,Reset = "<< rst <<"  ,start = " << start
                    << "  ,Mult Result = " << resultBus << ",  ready = " << ready << endl;

    }
    input_file.close();
    output_file.close();
}