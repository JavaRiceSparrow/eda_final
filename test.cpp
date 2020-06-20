// #include<cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>

#include "module/module.h"
#include "module/modulePrinter.h"
#include "module/moduleTranser.h"
// #include "verRead.h"
// #include "stringFunc.h"

using namespace std;

// char c1[] = "asd";

// char c2[] = "asd";

// bool readFile(string path, module mod);

int main(int argc, char **argv)
{
    for (int i = 1;i<=9;++i)
    {
        string gf_path = "cases/case" + to_string(i) + "/gf.v";
        string rf_path = "cases/case" + to_string(i) + "/rf.v";
        string gfd_path = "output/case" + to_string(i) + "/gf.v";
        string rfd_path = "output/case" + to_string(i) + "/rf.v";
        module testM = module();
        module *gf_m = new module(), *rf_m = new module();

        if (!testM.readFile(gf_path))
            cout << "Reading " + gf_path + " failed!" << endl;

        moduleTranser *mTr = new moduleTranser(&testM, gf_m);
        modulePrinter* mPt = new modulePrinter(gf_m);
        // cout << "test1" << endl;
        // cout << &mTr << endl;
        // cout << gf_m->_port.size() << endl;
        mPt->setModule( mTr->getModule());
        ofstream gfd_output(gfd_path);

        mPt->normalWriteFile(gfd_output);
        cout << "test1" << endl;

        // if (!testM.readFile(gf_path))
        //     cout << "Reading " + gf_path + " failed!" << endl;

        module testM2 = module();
        if (!testM2.readFile(rf_path))
            cout << "Reading " + rf_path + " failed!" << endl;

        mTr->resetModule(&testM2, rf_m);
        // modulePrinter mPt = modulePrinter(0);
        mPt->setModule(mTr->getModule());
        ofstream rfd_output(rfd_path);
        mPt->normalWriteFile(rfd_output);

        delete gf_m, rf_m;
        delete mTr;
        delete mPt;
    }
    // string input_file_name = "ver/golden.v";
    // // string input_file_name = "ver/gf.v";
    // module testM = module();
    // // string out_file_name = ;
    // ofstream fout("output/data.txt");

    // if (!testM.readFile(input_file_name))
    //     cout << "Reading failed!" << endl;
    // else
    //     cout << "Success..." << endl;

    // modulePrinter mPt = modulePrinter(&testM);
    // // mPt.normalWriteFile(fout);
    // moduleTranser mTr = moduleTranser(&testM);
    // // module* newM = mTr.getmodule();
    // // mPt.setModule(mTr.getmodule());
    // ofstream fout2("output/golden_derived.v");
    // // ofstream fout2("output/gf_derived.v");
    // // cout << "Hi" << endl;
    // vector<string> &wire = mTr.getmodule()->_wire;
    // // // ofstream fout3("output/test1.txt");
    // // // for(int i = 0;i<wire.capacity();++i)
    // // // {
    // // //     fout3 << wire[i] << ", ";
    // // // }
    // // // fout3 << endl;

    // mPt.normalWriteFile(fout2);

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
