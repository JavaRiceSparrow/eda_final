// #include<cstdlib>
#include<iostream>
#include <fstream>
#include<cstring>

#include "module.h"
// #include "verRead.h"
// #include "stringFunc.h"

using namespace std;

// char c1[] = "asd";

// char c2[] = "asd";

// bool readFile(string path, module mod);

int main(int argc, char **argv)
{
    string input_file_name = "ver/gf.v";
    // string input_file_name = "case/case1/gf.v";
    // cout << strcmp(c1,c2) <<endl;
    // ifstream input (input_file_name, ifstream::in);
    module testM =  module();

    // cout << "test1" << endl;

    if (!testM.readFile(input_file_name))
        cout << "Failed!" << endl;
    // cout << "name: " << testM._name << endl;
    // cout << "input: ";
    // for (int i = 0; i < testM._in_put.size(); ++i)
    // {
    //     string &str = testM._input[i];
    //     if (str.empty()) break;
    //     cout << str << ' ';
    // }
    // cout << endl;
    // cout << "output: ";
    // for (int i = 0; i < testM.out_put.size(); ++i)
    // {
    //     string &str = testM.out_put[i];
    //     if (str.empty())
    //         break;
    //     cout << str << ' ';
    // }
    // cout << endl;
    // cout << "wire: ";
    // for (int i = 0; i < testM.wire.size(); ++i)
    // {
    //     string &str = testM.wire[i];
    //     if (str.empty())
    //         break;
    //     cout << str << ' ';
    // }
    // cout << endl;
    // cout << "gate: ";
    // for (int i = 0; i < testM._gateIdx; ++i)
    // {
    //     gate* gate1 = testM._gates[i];
    //     // if (str.empty())
    //     //     break;
    //     cout << gTypeText[gate1->type] << ' '
    //          << gate1->i1 << ' ' << gate1->i2 << ' '
    //          << gate1->i3 << ' ' << gate1->o1 << ' ' << endl;
    // }
    // cout << endl;
    // if (!input.is_open())
    // {
    //     cout << "Reading file " << input_file_name << " failed!" << endl;
    //     return 0;
    // }
    // char buffer[500];
    // string port[200];
    // if (!getModuleLine(input, port))
    // {
    //     cout << "" << endl;
    // }
    // string buffer;
    // size_t froPtr = 0, endPtr = 0;

    // input >> buffer;
    // if (buffer != "module")
    // {
    //     cout << buffer << endl;
    //     cout << "It's not a module!" << endl;
    // }
    // string port[100];

    // while (getline(input, buffer))
    // {
    //     ;
    // }
    // cout << buffer << endl;

    // while()

    // input.close();
    return 0;
}
