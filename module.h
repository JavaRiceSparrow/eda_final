#ifndef __MODULE_H__
#define __MODULE_H__
#include <iostream>
using namespace std;

class gate;

enum gateType
{
    BUF = 0,
    NOT,
    AND,
    OR,
    XOR,
    NAND,
    NOR,
    DC,
    MUX,
    EOE
};

string gTypeTest[] = {"buf", "not", "and", "or", "xor", "nand", "nor", "_DC", "_HMUX"};

class module
{
public:
    module();
    bool readFile(string path);
    void add();
    string name;
    string port[200];
    string in_put[100];
    string out_put[100];
    string wire[1000];

private:
    gate* _gates;

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

#endif //__MODULE_H__