#ifndef __MODULE_PRINTER_H__
#define __MODULE_PRINTER_H__
#include <iostream>
#include "module.h"
using namespace std;

// class gate;
class module
{
public:
    module(){
        _gateIdx = 0;
        _gates = new gate*[2000];
    }
    bool readFile(string path);
    void add();
    string name;
    string port[200];
    string in_put[100];
    string out_put[100];
    string wire[1000];

private:
    gate** _gates;
    size_t _gateIdx;

};

class gate
{
public:
    gate(gateType gatetype, size_t i1, size_t o);
    gate(gateType gatetype, size_t i1, size_t i2, size_t o);
    gate(gateType gatetype, size_t i1, size_t i2, size_t i3, size_t o);

    void add();
    size_t i1, i2, i3, o1;
    string name;
    gateType type;
    

private:
    // gate *_gates;
};

#endif //__MODULE_PRINTER_H__