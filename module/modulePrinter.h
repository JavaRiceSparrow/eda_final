#ifndef __MODULE_PRINTER_H__
#define __MODULE_PRINTER_H__
#include <iostream>
#include <vector>
#include <fstream>
#include "module.h"
using namespace std;

// class gate;
class modulePrinter
{
public:
    modulePrinter(module *mod)
    {
        this->_module = mod;
    }

    // bool show();
    bool show(ofstream &fout);
    bool normalWriteFile(ofstream &fout, bool noname = false);
    bool writeFile(string path);
    void setModule(module *mod)
    {
        this->_module = mod;
    }

private:
    module *_module;
};

bool modulePrinter::show(ofstream &fout)
{
    if (!_module) return false;
    // ofstream fout(path);
    if (!fout)
    {
        cout << "ofstream is not open!" << endl;
        return false;
    }
    fout << "name: " << _module->_name << endl;
    // cout << "test1" << endl;
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

bool modulePrinter::normalWriteFile(ofstream &fout, bool noname)
{
    if (!_module)
        return false;
    if (!fout)
    {
        cout << "ofstream is not open!" << endl;
        return false;
    }
    /// comment here...
    fout << "// ..." << endl;

    int counter = 0;

    /// First line...
    fout << "module " << _module->_name;
    fout << "(";
    vector<string> &portRef = _module->_port;
    counter = 0;
    for (int i = 0; i < portRef.size() - 1; ++i)
    {
        fout << portRef[i] << " ,";
        ++counter;
        if (counter == 9)
        {
            counter = 0;
            fout << endl;
            fout << "\t\t";
        }
    }
    fout << portRef[portRef.size() - 1] << " );" << endl;

    /// input
    fout << "input ";
    vector<string> &inputRef = _module->_input;
    counter = 0;
    for (int i = 0; i < inputRef.size() - 1; ++i)
    {
        fout << inputRef[i] << " ,";
        ++counter;
        if (counter == 9)
        {
            counter = 0;
            fout << endl;
            fout << "\t\t";
        }
    }
    fout << inputRef[inputRef.size() - 1] << " ;" << endl;

    /// output
    fout << "output ";
    vector<string> &outputRef = _module->_output;
    counter = 0;
    for (int i = 0; i < outputRef.size() - 1; ++i)
    {
        fout << outputRef[i] << " ,";
        ++counter;
        if (counter == 9)
        {
            counter = 0;
            fout << endl;
            fout << "\t\t";
        }
    }
    fout << outputRef[outputRef.size() - 1] << " ;" << endl;

    fout << endl;

    /// wire
    fout << "wire ";
    vector<string> &wireRef = _module->_wire;
    counter = 0;
    for (int i = 0; i < wireRef.size() - 1; ++i)
    {
        fout << wireRef[i] << " , ";
        ++counter;
        if (counter == 10)
        {
            counter = 0;
            fout << endl;
            fout << "\t\t";
        }
    }
    fout << wireRef[wireRef.size() - 1] << " ;" << endl;

    /// gate
    // _module->_gates
    vector<gate *> &gateRef = _module->_gates;
    // cout << "t1 " << gateRef.size() << endl;
    for (int i = 0; i < gateRef.size(); ++i)
    {
        if (!gateRef[i]) break;
        // cout << "t1: " << i << endl;
        fout << gTypeText[gateRef[i]->type] << ' ';
        if (!noname)
            fout << gateRef[i]->name;
        fout << "( ";
        if (gateRef[i]->type != EOE)
        {
            switch (gParamNum[gateRef[i]->type])
            {
            case 2:
                fout << gateRef[i]->i1 << " , ";
                fout << gateRef[i]->o1;
                break;
            case 3:
                fout << gateRef[i]->i1 << " , ";
                fout << gateRef[i]->i2 << " , ";
                fout << gateRef[i]->o1;
                break;
            case 4:
                fout << gateRef[i]->i1 << " , ";
                fout << gateRef[i]->i2 << " , ";
                fout << gateRef[i]->i3 << " , ";
                fout << gateRef[i]->o1;
                break;
            default:
                fout << "Wrong";
                break;
            }
            fout << " );" << endl;
            // if ()
        }
        else
        {
            fout << "Wrong);" << endl;
            continue;
        }
    }

    /// speGate
    vector<speGate *> &sgateRef = _module->_speGates;
    // cout << "t1s " << sgateRef.size() << endl;
    for (int i = 0; i < sgateRef.size(); ++i)
    {
        if (!sgateRef[i])
            break;
        fout << gTypeText[sgateRef[i]->type] << ' ';
        if (!noname)
            fout << sgateRef[i]->name;
        fout << "( ";
        if (sgateRef[i]->type != EOE)
        {
            for (int j = 0; j < sgateRef[i]->io.size() - 1; ++j)
            {
                fout << sgateRef[i]->io[j] << " , ";
            }
            fout << sgateRef[i]->io[sgateRef[i]->io.size() - 1] ;
            fout << " );" << endl;
            
        }
        else
        {
            fout << "Wrong);" << endl;
            continue;
        }
    }

    fout << "endmodule" << endl;
    // {
    //     gate *gate1 = _module->_gates[i];
    //     // if (str.empty())
    //     //     break;
    //     fout << gate1->name << "("
    //          << gTypeText[gate1->type] << ")\t"
    //          << gate1->i1 << ' ' << gate1->i2 << ' '
    //          << gate1->i3 << ' ' << gate1->o1 << ' ' << endl;
    // }
    // fout << endl;
    // fout << "special gate: " << endl;
    // for (int i = 0; i < _module->_speGates.size(); ++i)
    // {
    //     speGate *gate1 = _module->_speGates[i];
    //     // if (str.empty())
    //     //     break;
    //     fout << gTypeText[gate1->type] << ' ';
    //     for (int i = 0; i < gate1->io.size(); ++i)
    //         fout << gate1->io[i] << ' ';
    //     fout << endl;
    // }
    fout << endl;
    return true;
    return false;
}

bool modulePrinter::writeFile(string path)
{
    return false;
}

#endif //__MODULE_PRINTER_H__