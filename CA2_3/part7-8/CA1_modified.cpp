#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const string AND = "AND";
const string OR = "OR";
const string NOT = "NOT";
const string ASSIGN = "assign";
const char COMMA = ',';
const char SEMICOLON = ';';

struct logic_gate
{
    string name;
    string input1;
    string input2;
    string output;
};

string remove_comma_at_back(string s){
    if (s.back() == COMMA){
        s.pop_back();
    }
    return s;
}
string remove_semicolon_at_back(string s){
    if (s.back() == SEMICOLON){
        s.pop_back();
    }
    return s;
}

void read_multi_bits_wires(string range, string wire_name, vector<string>& wire_list){
    string one_bit_wire_name;
    wire_name = remove_comma_at_back(wire_name);
    size_t open_bracket_pos = range.find('[');
    size_t colon_pos = range.find(':');
    size_t close_bracket_pos = range.find(']');
    int high_index, low_index;
    high_index = stoi(range.substr(open_bracket_pos + 1, colon_pos - open_bracket_pos -1));
    low_index = stoi(range.substr(colon_pos + 1, close_bracket_pos - colon_pos -1));
    for (int i = low_index; i < high_index + 1; ++i){
        one_bit_wire_name = wire_name + "[" + to_string(i) + "]";
        wire_list.push_back(one_bit_wire_name);
    }
}

string Convert_to_Boolean(const vector<logic_gate> &gates_list, const vector<string> &primary_inputs,
                          const string &output)
{
    string boolean_string;
    for (auto input : primary_inputs)
    {
        if (output == input)
        {
            return input;
        }
    }

    for (auto gate : gates_list)
    {
        if (gate.output == output)
        {
            if (gate.name == NOT)
            {
                boolean_string = "(~(" + Convert_to_Boolean(gates_list, primary_inputs, gate.input1) + "))";
            }
            else if (gate.name == AND)
            {
                boolean_string = '(' + Convert_to_Boolean(gates_list, primary_inputs, gate.input1) +
                                 " & " + Convert_to_Boolean(gates_list, primary_inputs, gate.input2) + ')';
            }
            else if (gate.name == OR)
            {
                boolean_string = '(' + Convert_to_Boolean(gates_list, primary_inputs, gate.input1) +
                                 " | " + Convert_to_Boolean(gates_list, primary_inputs, gate.input2) + ')';
            }
            else if (gate.name == ASSIGN)
            {
                if (gate.input2 == "")
                {
                    boolean_string = '(' + Convert_to_Boolean(gates_list, primary_inputs, gate.input1) + ')';
                }
                else {
                    boolean_string = '{' + Convert_to_Boolean(gates_list, primary_inputs, gate.input1) +
                                    " , " + Convert_to_Boolean(gates_list, primary_inputs, gate.input2) + '}';
                }
            }
            break;
        }
    }
    return boolean_string;
}

void write_behavioral_code(vector<string>& primary_inputs, vector<string>& primary_outputs,
                           vector<logic_gate>& gates_list){

    string new_line;
    // Open files
    string input_file_path = "Mult_Combinational_Structural.v";
    string output_file_path = "Mult_Combinational_behavioral.v";

    ifstream Structural_code(input_file_path);
    ofstream Behavioral_code(output_file_path);
    

    while (getline(Structural_code, new_line))
    {
        string key_word;
        stringstream ss(new_line);
        ss >> key_word;
        string tmp;
        string input_name, output_name;

        if (key_word == "module")
        {
            Behavioral_code << key_word << " Behavioral(" << endl;
        }
        else if (key_word == "input")
        {
            Behavioral_code << new_line << endl;
            ss >> tmp;
            if (tmp.front() == '[' && tmp.back() == ']'){ // Handling multi bits wires
                ss >> input_name;
                read_multi_bits_wires(tmp, input_name, primary_inputs);
            }
            else {  // Handling single bit wire
                input_name =  remove_comma_at_back(tmp);
                primary_inputs.push_back(input_name);
            }
        }
        else if (key_word == "output")
        {
            Behavioral_code << new_line << endl;

            ss >> tmp;
            if (tmp.front() == '[' && tmp.back() == ']'){ // Handling multi bits wires
                ss >> output_name;
                read_multi_bits_wires(tmp, output_name, primary_outputs);
            }
            else {  // Handling single bit wire
                output_name =  remove_comma_at_back(tmp);
                primary_outputs.push_back(output_name);
            }
        }
        else if (key_word == ");")
        {
            Behavioral_code << new_line << endl;
        }

        else if (key_word == AND || key_word == OR)
        {
            logic_gate new_gate;
            string temp;

            new_gate.name = key_word;

            // Extract input1
            ss >> temp;
            size_t pos_open_parenthesis = temp.find('(');
            size_t pos_comma = temp.find(',');
            // Extract the substring between '(' and ','
            new_gate.input1 = temp.substr(pos_open_parenthesis + 1, pos_comma - pos_open_parenthesis - 1);

            // Extract input1
            ss >> temp;
            if (temp.back() == ',')
            {
                temp.pop_back();
            }
            new_gate.input2 = temp;

            // Extract output
            ss >> temp;
            size_t pos_close_parenthesis = temp.find(')');
            new_gate.output = temp.substr(0, pos_close_parenthesis);

            gates_list.push_back(new_gate);
        }

        else if (key_word == NOT)
        {
            logic_gate new_gate;
            string temp;

            new_gate.name = key_word;
            // Extract input1
            ss >> temp;
            size_t pos_open_parenthesis = temp.find('(');
            size_t pos_comma = temp.find(',');
            // Extract the substring between '(' and ','
            new_gate.input1 = temp.substr(pos_open_parenthesis + 1, pos_comma - pos_open_parenthesis - 1);
            new_gate.input2 = "";
            // Extract output
            ss >> temp;
            size_t pos_close_parenthesis = temp.find(')');
            new_gate.output = temp.substr(0, pos_close_parenthesis);

            gates_list.push_back(new_gate);
        }
        else if (key_word == ASSIGN){
            logic_gate new_gate;
            string temp;
            new_gate.name = key_word;
            ss >> output_name;
            new_gate.output = output_name;
            ss >> temp; // Equal sign
            ss >> temp;
            if (temp == "{"){ // Handling Concatenation
                ss >> temp;
                new_gate.input1 = remove_comma_at_back(temp); // input1
                ss >> temp;
                new_gate.input2 = temp; // input2
            }
            else{
                input_name = temp;
                new_gate.input1 = remove_semicolon_at_back(input_name);
                new_gate.input2 = "";
            }
            gates_list.push_back(new_gate);
        }

        else if (key_word == "endmodule")
        {

            for (auto output : primary_outputs)
            {
                string boolean_expression;
                boolean_expression = "assign " + output + " = " + Convert_to_Boolean(gates_list, primary_inputs, output);
                Behavioral_code << "    " << boolean_expression << ";" << endl;
            }
            Behavioral_code << endl << new_line << endl;
        }
    }
    // Close files
    Behavioral_code.close();
    Structural_code.close();
}


int main()
{
    vector<string> primary_inputs;
    vector<string> primary_outputs;
    vector<logic_gate> gates_list;

    write_behavioral_code(primary_inputs, primary_outputs, gates_list);
    
    return 0;
}