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


int main(int argc, char **argv)
{
    // int i = 3;
    if (argc != 3) 
    {
        cout << "Input parameter number is wrong!" << endl;
        return 689689;
    }
    // for (size_t i = 1; i <= 9; ++i)
    {
        // cout << "test3" << endl;
        string gf_path = argv[1];
        // string rf_path = "cases/case" + to_string(i) + "/rf.v";
        string gfd_path = argv[2];
        // string rfd_path = "output/case" + to_string(i) + "/rf.v";
        module *testM = new module();
        module *gf_m = new module(), *rf_m = new module();
        moduleTranser *mTr = new moduleTranser(testM, gf_m);
        modulePrinter *mPt = new modulePrinter(gf_m);

        if (!testM->readFile(gf_path))
            cout << "Reading " + gf_path + " failed!" << endl;
        else
            cout << "Reading " + gf_path + " success." << endl;

        // mTr = new moduleTranser(testM, gf_m);
        // mPt = new modulePrinter(gf_m);
        
        mPt->setModule(mTr->getModule());
        cout << "Transing file\"" << gf_path << "\"..." << endl;
        ofstream gfd_output(gfd_path);

        
        if (!mPt->normalWriteFile(gfd_output))
            cout << "Printed " << gfd_path << " failed!" << endl;
        else
            cout << "Printed " << gfd_path << "" << endl;
        delete testM;

        // cout << "Hi" << endl;
        // testM = new module();
        // if (!testM->readFile(rf_path))
        //     cout << "Reading " + rf_path + " failed!" << endl;
        // else
        //     cout << "Reading " + rf_path + " success." << endl;

        // mTr->resetModule(testM, rf_m);
        // mPt->setModule(mTr->getModule());
        // cout << "[test4] transing rf" << i << "" << endl;
        // // cout << "[test5] " << (mTr->getModule()) << endl;
        // // cout << "[test5] " << rf_m->_gates.size() << endl;
        // // cout << "[test5] " << rf_m->_gates.capacity() << endl;
        // ofstream rfd_output(rfd_path);
        // if (!mPt->normalWriteFile(rfd_output))
        //     cout << "[test4] printed rf" << i << " failed!" << endl;
        // else
        //     cout << "[test4] printed rf" << i << "" << endl;

        // delete testM;
        delete gf_m, rf_m;
        delete mTr;
        delete mPt;
        // cout << "[test4] finish and clean " << i << endl;
    }
    return 0;
}
