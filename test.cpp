// #include<cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>

#include "module.h"
#include "modulePrinter.h"
#include "moduleTranser.h"
// #include "verRead.h"
// #include "stringFunc.h"

using namespace std;

// char c1[] = "asd";

// char c2[] = "asd";

// bool readFile(string path, module mod);

int main(int argc, char **argv)
{
    string input_file_name = "ver/gf.v";
    module testM = module();
    // string out_file_name = ;
    ofstream fout("output/data.txt");

    if (!testM.readFile(input_file_name))
        cout << "Reading failed!" << endl;
    else
        cout << "Success..." << endl;

    modulePrinter mPt = modulePrinter(&testM);
    mPt.normalWriteFile(fout);
    moduleTranser mTr = moduleTranser(&testM);
    module* newM = mTr.getmodule();
    mPt._module = &testM;
    ofstream fout2("output/derived_data.txt");
    mPt.normalWriteFile(fout);

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
