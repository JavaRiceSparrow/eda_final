
#include <iostream>
using namespace std;

enum gateType
{
    BUF,
    NOT,
    AND,
    OR,
    XOR,
    NAND,
    NOR,
    DC,
    MUX
};

class module
{
public:
    module();

    void add();
    string port[200];
    string input[100];
    string output[100];
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

private:
    gate *_gates;
};