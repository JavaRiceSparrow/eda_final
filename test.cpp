// #include<cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>

#include "module.h"
#include "modulePrinter.h"
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
    module testM = module();
    // string out_file_name = ;
    fstream fout("output/data.txt");
    // if (!fout)
    // {
    //     cout << "Failed to open \"" << out_file_name << "\"!" << endl;
    //     return false;
    // }

    // cout << "test1" << endl;

    if (!testM.readFile(input_file_name))
        cout << "Reading failed!" << endl;
    else
        cout << "Success..." << endl;

    modulePrinter mPt = modulePrinter(&testM);
    mPt.show();
    // mPt.showFile("output/data.txt");
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
