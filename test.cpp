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
    // int i = 1;
    for (size_t i = 1; i <= 9; ++i, cout << i << endl)
    {
        // cout << "test3" << endl;
        string gf_path = "cases/case" + to_string(i) + "/gf.v";
        string rf_path = "cases/case" + to_string(i) + "/rf.v";
        string gfd_path = "output/case" + to_string(i) + "/gf.v";
        string rfd_path = "output/case" + to_string(i) + "/rf.v";
        module *testM = new module();
        module *gf_m = new module(), *rf_m = new module();

        if (!testM->readFile(gf_path))
            cout << "Reading " + gf_path + " failed!" << endl;

        moduleTranser *mTr = new moduleTranser(testM, gf_m);
        modulePrinter* mPt = new modulePrinter(gf_m);
        // cout << "test1" << endl;
        // cout << &mTr << endl;
        // cout << gf_m->_port.size() << endl;
        mPt->setModule(mTr->getModule());
        cout << "[test4] transing gf" << i << "" << endl;
        ofstream gfd_output(gfd_path);

        mPt->normalWriteFile(gfd_output);
        cout << "[test4] printed gf" << i << "" << endl;

        // if (!testM.readFile(gf_path))
        //     cout << "Reading " + gf_path + " failed!" << endl;

        // module testM2 = module();
        delete testM;
        cout << "Hi" << endl;
        testM = new module();
        if (!testM->readFile(rf_path))
            cout << "Reading " + rf_path + " failed!" << endl;

        mTr->resetModule(testM, rf_m);
        // modulePrinter mPt = modulePrinter(0);
        mPt->setModule(mTr->getModule());
        cout << "[test4] transing rf" << i << "" << endl;
        ofstream rfd_output(rfd_path);
        mPt->normalWriteFile(rfd_output);
        cout << "[test4] printed rf" << i << "" << endl;

        delete testM;
        delete gf_m, rf_m;
        delete mTr;
        delete mPt;
        cout << "[test4] finish and clean " << i << endl;
    }
    // i = 2;
    // cout << i << endl;
    // {
    //     cout << "test3" << endl;
    //     string gf_path = "cases/case" + to_string(i) + "/gf.v";
    //     string rf_path = "cases/case" + to_string(i) + "/rf.v";
    //     string gfd_path = "output/case" + to_string(i) + "/gf.v";
    //     string rfd_path = "output/case" + to_string(i) + "/rf.v";
    //     module testM = module();
    //     module *gf_m = new module(), *rf_m = new module();

    //     if (!testM.readFile(gf_path))
    //         cout << "Reading " + gf_path + " failed!" << endl;

    //     moduleTranser *mTr = new moduleTranser(&testM, gf_m);
    //     modulePrinter *mPt = new modulePrinter(gf_m);
    //     // cout << "test1" << endl;
    //     // cout << &mTr << endl;
    //     // cout << gf_m->_port.size() << endl;
    //     mPt->setModule(mTr->getModule());
    //     cout << "[test4] transing gf" << i << "" << endl;
    //     ofstream gfd_output(gfd_path);

    //     mPt->normalWriteFile(gfd_output);
    //     cout << "[test4] printed gf" << i << "" << endl;

    //     // if (!testM.readFile(gf_path))
    //     //     cout << "Reading " + gf_path + " failed!" << endl;

    //     module testM2 = module();
    //     if (!testM2.readFile(rf_path))
    //         cout << "Reading " + rf_path + " failed!" << endl;

    //     mTr->resetModule(&testM2, rf_m);
    //     // modulePrinter mPt = modulePrinter(0);
    //     mPt->setModule(mTr->getModule());
    //     cout << "[test4] transing rf" << i << "" << endl;
    //     ofstream rfd_output(rfd_path);
    //     mPt->normalWriteFile(rfd_output);
    //     cout << "[test4] printed rf" << i << "" << endl;

    //     delete gf_m, rf_m;
    //     delete mTr;
    //     delete mPt;
    //     cout << "[test4] finish and clean " << i << endl;
    // }

    // for (size_t i = 1; i <= 9; ++i, cout << i << endl)
    // {
    //     cout << "test3" << endl;
    //     string gf_path = "cases/case" + to_string(i) + "/gf.v";
    //     string rf_path = "cases/case" + to_string(i) + "/rf.v";
    //     string gfd_path = "output/case" + to_string(i) + "/gf.v";
    //     string rfd_path = "output/case" + to_string(i) + "/rf.v";
    //     module testM = module();
    //     module *gf_m = new module(), *rf_m = new module();

    //     if (!testM.readFile(gf_path))
    //         cout << "Reading " + gf_path + " failed!" << endl;

    //     moduleTranser *mTr = new moduleTranser(&testM, gf_m);
    //     modulePrinter *mPt = new modulePrinter(gf_m);
    //     // cout << "test1" << endl;
    //     // cout << &mTr << endl;
    //     // cout << gf_m->_port.size() << endl;
    //     mPt->setModule(mTr->getModule());
    //     cout << "[test4] transing gf" << i << "" << endl;
    //     ofstream gfd_output(gfd_path);

    //     mPt->normalWriteFile(gfd_output);
    //     cout << "[test4] printed gf" << i << "" << endl;

    //     // if (!testM.readFile(gf_path))
    //     //     cout << "Reading " + gf_path + " failed!" << endl;

    //     module testM2 = module();
    //     if (!testM2.readFile(rf_path))
    //         cout << "Reading " + rf_path + " failed!" << endl;

    //     mTr->resetModule(&testM2, rf_m);
    //     // modulePrinter mPt = modulePrinter(0);
    //     mPt->setModule(mTr->getModule());
    //     cout << "[test4] transing rf" << i << "" << endl;
    //     ofstream rfd_output(rfd_path);
    //     mPt->normalWriteFile(rfd_output);
    //     cout << "[test4] printed rf" << i << "" << endl;

    //     delete gf_m, rf_m;
    //     delete mTr;
    //     delete mPt;
    //     cout << "[test4] finish and clean " << i << endl;
    // }
    return 0;
}
