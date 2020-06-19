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
    // string input_file_name = "ver/golden.v";
    string input_file_name = "ver/gf.v";
    module testM = module();
    // string out_file_name = ;
    ofstream fout("output/data.txt");

    if (!testM.readFile(input_file_name))
        cout << "Reading failed!" << endl;
    else
        cout << "Success..." << endl;

    modulePrinter mPt = modulePrinter(&testM);
    // mPt.normalWriteFile(fout);
    moduleTranser mTr = moduleTranser(&testM);
    // module* newM = mTr.getmodule();
    mPt.setModule(mTr.getmodule());
    // ofstream fout2("output/golden_derived.v");
    ofstream fout2("output/gf_derived.v");
    // cout << "Hi" << endl;
    vector<string> &wire = mTr.getmodule()->_wire;
    ofstream fout3("output/test1.txt");
    for(int i = 0;i<wire.capacity();++i)
    {
        fout3 << wire[i] << ", ";
    }
    fout3 << endl;
    fout3 << endl;
    for (int i = 0; i < wire.size(); ++i)
    {
        fout3 << wire[i] << ", ";
    }
    fout3 << endl;

    mPt.normalWriteFile(fout2);

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
