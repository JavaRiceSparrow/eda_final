
#include <iostream>
#include <fstream>
#include <vector>

#include "module.h"
#include "stringFunc.h"
#include "verRead.h"

using namespace std;

// class module{
//     public:
//     module(){

//     }
//     string name;
//     string port [200];
//     string input[100];
//     string output[100];
//     string wire[1000];
//     // void add()
//     // {

//     // }
// };

bool module::readFile(string path)
{
    string input_file_name = "inoutTest.txt";
    ifstream input(input_file_name, ifstream::in);
    string str[100];
    string name;
    string buffer;
    input >> buffer;
    vector<gate> _gate;
    if (buffer != "module")
        return 300;
    getModuleLine(input, name, str);

    while (input >> buffer)
    {
        if (buffer == "input")
        {
            string contain = readUntilSemic(input);
            deriveContain(contain, in_put);
        }
        else if (buffer == "output")
        {
            string contain = readUntilSemic(input);
            deriveContain(contain, out_put);
        }
        else if (buffer == "wire")
        {
            string contain = readUntilSemic(input);
            deriveContain(contain, wire);
        }
        else if (buffer == "reg")
        {
            string contain = readUntilSemic(input);
            deriveContain(contain, reg);
        }
        else
            break;
    }

    while (input >> buffer)
    {
        if (buffer == "endmodule")
        {
            finish();
        }
    }
}