#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const string AND = "AND";
const string OR = "OR";
const string NOT = "NOT";

struct logic_gate
{
    string type;
    string name;
    string input1;
    string input2;
    string output;
};

void read_unsorted_gates(vector<logic_gate>& gates_list){

    string new_line;
    // Open files
    ifstream unsorted_gates("input.txt");
    while (getline(unsorted_gates, new_line)){

        string key_word;
        stringstream ss(new_line);
        ss >> key_word;

        if (key_word == AND || key_word == OR){
            string temp;
            logic_gate new_gate;
            new_gate.type = key_word;  //type
            ss >> new_gate.name;   //gate's name
            //input1
            getline(unsorted_gates, new_line);
            stringstream ss(new_line);
            ss >> temp;
            size_t open_par_pos = temp.find('(');
            size_t close_par_pos = temp.find(')');
            new_gate.input1 = temp.substr(open_par_pos + 1, close_par_pos - open_par_pos - 1);
            //input2
            getline(unsorted_gates, new_line);
            ss.str(new_line);
            ss.clear();
            ss >> temp;
            open_par_pos = temp.find('(');
            close_par_pos = temp.find(')');
            new_gate.input2 = temp.substr(open_par_pos + 1, close_par_pos - open_par_pos - 1);
            //output
            getline(unsorted_gates, new_line);
            ss.str(new_line);
            ss.clear();
            ss >> temp;
            open_par_pos = temp.find('(');
            close_par_pos = temp.find(')');
            new_gate.output = temp.substr(open_par_pos + 1, close_par_pos - open_par_pos - 1);

            gates_list.push_back(new_gate);
        }
        else if (key_word == NOT){
            string temp;
            logic_gate new_gate;
            new_gate.type = key_word;  //type
            ss >> new_gate.name;   //gate's name
            //input1
            getline(unsorted_gates, new_line);
            stringstream ss(new_line);
            ss >> temp;
            size_t open_par_pos = temp.find('(');
            size_t close_par_pos = temp.find(')');
            new_gate.input1 = temp.substr(open_par_pos + 1, close_par_pos - open_par_pos - 1);
            //input2
            new_gate.input2 = "";
            //output
            getline(unsorted_gates, new_line);
            ss.str(new_line);
            ss.clear();
            ss >> temp;
            open_par_pos = temp.find('(');
            close_par_pos = temp.find(')');
            new_gate.output = temp.substr(open_par_pos + 1, close_par_pos - open_par_pos - 1);

            gates_list.push_back(new_gate);
        }
    }
    unsorted_gates.close();
}

void swap_gates(vector<logic_gate>& gates_list, int gate1_index, int gate2_index){
    logic_gate tmp;
    tmp = gates_list[gate1_index];
    gates_list[gate1_index] = gates_list[gate2_index];
    gates_list[gate2_index] = tmp;
}

void sort_gates(vector<logic_gate>& gates_list){
    for (int i = 0; i < gates_list.size(); ++i){
        for (int j = i + 1; j < gates_list.size(); ++j){
            if (gates_list[i].input1 == gates_list[j].output || gates_list[i].input2 == gates_list[j].output){
                swap_gates(gates_list, i ,j);
                j = i;  // Check all the gates below it again
            }
        }
    }
}

void write_sorted_gates(vector<logic_gate>& gates_list){
    // Open files
    ofstream sorted_gates("output.txt");
    for (const auto gate : gates_list){
        if (gate.type == NOT){
            sorted_gates << gate.type << ' ' <<gate.name << "(" << gate.input1
                         << ", " << gate.output << ");" << endl;
        }
        else {
            sorted_gates << gate.type << ' ' << gate.name << "(" << gate.input1
                         << ", " << gate.input2 << ", " << gate.output << ");" << endl;
        }
    }
    sorted_gates.close();
}


int main(){
    
    vector<logic_gate> gates_list;
    read_unsorted_gates(gates_list);
    sort_gates(gates_list);
    write_sorted_gates(gates_list);
}