#ifndef __MODULE_PRINTER_H__
#define __MODULE_PRINTER_H__
#include <iostream>
#include <fstream>
#include "module.h"
using namespace std;

// class gate;
class modulePrinter
{
public:
    modulePrinter(module* mod)
    {
        this->_module = mod;
    }

    // bool show();
    bool showFile(ofstream &fout);
    bool normalWriteFile(string path);
    bool writeFile(string path);
    module* _module;

private:
    void addAND();
    // void addAND();
    // void addAND();
    // void addAND();
    // void addAND();
    // void addAND();
};

/*
bool modulePrinter::show()
{
    cout << "name: " << _module->_name << endl;
    cout << "input: ";
    for (int i = 0; i < _module->_input.size(); ++i)
    {
        string &str = _module->_input[i];
        if (str.empty())
            break;
        cout << str << ' ';
    }
    cout << endl;
    cout << "output: " << endl;
    for (int i = 0; i < _module->_output.size(); ++i)
    {
        string &str = _module->_output[i];
        if (str.empty())
            break;
        cout << str << ' ';
    }
    cout << endl;
    cout << "wire: ";
    for (int i = 0; i < _module->_wire.size(); ++i)
    {
        string &str = _module->_wire[i];
        if (str.empty())
            break;
        cout << str << ' ';
    }
    cout << endl;
    cout << "gate: " << endl;
    for (int i = 0; i < _module->_gateIdx; ++i)
    {
        gate *gate1 = _module->_gates[i];
        // if (str.empty())
        //     break;
        cout << gate1->name << "("
             << gTypeText[gate1->type] << ")\t"
             << gate1->i1 << ' ' << gate1->i2 << ' '
             << gate1->i3 << ' ' << gate1->o1 << ' ' << endl;
    }
    cout << endl;
    cout << "special gate: " << endl;
    for (int i = 0; i < _module->_speGates.size(); ++i)
    {
        speGate *gate1 = _module->_speGates[i];
        // if (str.empty())
        //     break;
        cout << gTypeText[gate1->type] << ' ';
        for (int i = 0; i < gate1->io.size(); ++i)
            cout << gate1->io[i] << ' ';
        cout << endl;
    }
    cout << endl;
}
*/

bool modulePrinter::showFile(ofstream& fout)
{
    // ofstream fout(path);
    if (!fout ) 
    {
        cout << "ofstream is not open!" << endl;
        return false;
    }
    fout << "name: " << _module->_name << endl;
    fout << "input: ";
    for (int i = 0; i < _module->_input.size(); ++i)
    {
        string &str = _module->_input[i];
        if (str.empty())
            break;
        fout << str << ' ';
    }
    fout << endl;
    fout << "output: " << endl;
    for (int i = 0; i < _module->_output.size(); ++i)
    {
        string &str = _module->_output[i];
        if (str.empty())
            break;
        fout << str << ' ';
    }
    fout << endl;
    fout << "wire: ";
    for (int i = 0; i < _module->_wire.size(); ++i)
    {
        string &str = _module->_wire[i];
        if (str.empty())
            break;
        fout << str << ' ';
    }
    fout << endl;
    fout << "gate: " << endl;
    for (int i = 0; i < _module->_gateIdx; ++i)
    {
        gate *gate1 = _module->_gates[i];
        // if (str.empty())
        //     break;
        fout << gate1->name << "("
             << gTypeText[gate1->type] << ")\t"
             << gate1->i1 << ' ' << gate1->i2 << ' '
             << gate1->i3 << ' ' << gate1->o1 << ' ' << endl;
    }
    fout << endl;
    fout << "special gate: " << endl;
    for (int i = 0; i < _module->_speGates.size(); ++i)
    {
        speGate *gate1 = _module->_speGates[i];
        // if (str.empty())
        //     break;
        fout << gTypeText[gate1->type] << ' ';
        for (int i = 0; i < gate1->io.size(); ++i)
            fout << gate1->io[i] << ' ';
        fout << endl;
    }
    fout << endl;
    return true;
}
bool modulePrinter::normalWriteFile(string path)
{
    ofstream file(path);
    return false;
}

bool modulePrinter::writeFile(string path)
{
    return false;
}

#endif //__MODULE_PRINTER_H__