#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const string AND = "and";
const string OR = "or";
const string NOT = "not";

struct logic_gate
{
    string name;
    string input1;
    string input2;
    string output;
};

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
            break;
        }
    }
    return boolean_string;
}

void write_behavioral_code(vector<string>& primary_inputs, vector<string>& primary_outputs,
                           vector<logic_gate>& gates_list){

    string new_line;
    // Open files
    ofstream Behavioral_code("expected_output.v");
    ifstream Structural_code("input_test3.v");

    while (getline(Structural_code, new_line))
    {
        string key_word;
        stringstream ss(new_line);
        ss >> key_word;

        if (key_word == "module")
        {
            Behavioral_code << key_word << " Behavioral(" << endl;
        }
        else if (key_word == "input")
        {
            Behavioral_code << new_line << endl;
            string input_name;
            ss >> input_name;
            // Remove the comma if present
            if (input_name.back() == ',')
            {
                input_name.pop_back();
            }
            primary_inputs.push_back(input_name);
        }
        else if (key_word == "output")
        {
            Behavioral_code << new_line << endl;
            string output_name;
            ss >> output_name;
            // Remove the comma if present
            if (output_name.back() == ',')
            {
                output_name.pop_back();
            }
            primary_outputs.push_back(output_name);
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

            // Extract output
            ss >> temp;
            size_t pos_open_parenthesis = temp.find('(');
            size_t pos_comma = temp.find(',');
            // Extract the substring between '(' and ','
            new_gate.output = temp.substr(pos_open_parenthesis + 1, pos_comma - pos_open_parenthesis - 1);

            // Extract input1
            ss >> temp;
            if (temp.back() == ',')
            {
                temp.pop_back();
            }
            new_gate.input1 = temp;

            // Extract input2
            ss >> temp;
            size_t pos_close_parenthesis = temp.find(')');
            new_gate.input2 = temp.substr(0, pos_close_parenthesis);

            gates_list.push_back(new_gate);
        }

        else if (key_word == NOT)
        {
            logic_gate new_gate;
            string temp;

            new_gate.name = key_word;
            // Extract output
            ss >> temp;
            size_t pos_open_parenthesis = temp.find('(');
            size_t pos_comma = temp.find(',');
            // Extract the substring between '(' and ','
            new_gate.output = temp.substr(pos_open_parenthesis + 1, pos_comma - pos_open_parenthesis - 1);

            // Extract input1
            ss >> temp;
            size_t pos_close_parenthesis = temp.find(')');
            new_gate.input1 = temp.substr(0, pos_close_parenthesis);

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

void write_TestBench(vector<string>& primary_inputs, vector<string>& primary_outputs,
                           vector<logic_gate>& gates_list){
    ofstream testBench_code("test_data.v");

    testBench_code << "module test_data();\n" << endl;

    // behavioral1
    for (const auto & input_b : primary_inputs){
        testBench_code << "reg " << "b_"<< input_b << ';' << endl;
    }
    for (const auto & output_b : primary_outputs){
        testBench_code << "wire " << "b_"<< output_b << ';' << endl;
    }
    // structural1
    for (const auto & input_s : primary_inputs){
        testBench_code << "reg " << "s_"<< input_s << ';' << endl;
    }
    for (const auto & output_s : primary_outputs){
        testBench_code << "wire " << "s_"<< output_s << ';' << endl;
    }

    // instance behavioral1
    testBench_code << "\nBehavioral B_UUT(" << endl;
    for (const auto & input_b : primary_inputs){
        testBench_code << "\tb_"<< input_b << ',' << endl;
    }
    for (int i = 0; i < primary_outputs.size(); ++i){
        if (i < primary_outputs.size() - 1)
            testBench_code << "\tb_"<< primary_outputs[i] << ',' << endl;
        else
            testBench_code << "\tb_"<< primary_outputs[i] << endl;

    }
    testBench_code << ");" << endl;

    // instance structural1
    testBench_code << "\nStructural S_UUT(" << endl;
    for (const auto & input_s : primary_inputs){
        testBench_code << "\ts_"<< input_s << ',' << endl;
    }
    for (int i = 0; i < primary_outputs.size(); ++i){
        if (i < primary_outputs.size() - 1)
            testBench_code << "\ts_"<< primary_outputs[i] << ',' << endl;
        else
            testBench_code << "\ts_"<< primary_outputs[i] << endl;

    }
    testBench_code << ");" << endl;

    // Testing
    testBench_code << "\ninitial begin\n\trepeat(10) begin\n\t\t#10" << endl;

    for (const auto & input : primary_inputs){
        testBench_code << "\t\ts_"<< input << " = $random();" << endl;
        testBench_code << "\t\tb_" << input << " = s_"<< input << ';' << endl;
    }
    testBench_code << "\tend\n\t#20 $stop();\nend" << endl;

    testBench_code << "\nendmodule" << endl;    

    testBench_code.close();
}

int main()
{
    vector<string> primary_inputs;
    vector<string> primary_outputs;
    vector<logic_gate> gates_list;

    write_behavioral_code(primary_inputs, primary_outputs, gates_list);
    write_TestBench(primary_inputs, primary_outputs, gates_list);
    
    return 0;
}