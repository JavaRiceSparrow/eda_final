#ifndef __MODULE_H__
#define __MODULE_H__
#include <iostream>
using namespace std;

///
#include <fstream>
// #include <vector>

#include "module.h"
#include "stringFunc.h"
#include "verRead.h"
///

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
int gParamNum[] = {2, 2, 3, 3, 3, 3, 3, 3, 4};

class gate
{
public:
    gate(gateType gatetype, string io[])
    {
        type = gatetype;
        int ioLen = sizeof(io) / sizeof(*io);
        if (ioLen > gParamNum[type])
            cout << "[gate] TOO many io port!" << endl;
        if (ioLen < 2 || ioLen > 4)
        {
            cout << "[gate] How do U turn this on!" << endl;
        }
        i1 = io[0];
        o1 = io[ioLen - 1];
        if (ioLen > 2)
        {
            i2 = io[1];
            if (ioLen > 3)
            {
                i3 = io[2];
            }
        }
    }

    // void add();
    string i1, i2, i3, o1;
    string name;
    gateType type;

private:
    // gate *_gates;
};

class module
{
public:
    module()
    {
        _gateIdx = 0;
        _gates = new gate *[2000];
    }
    // bool readFile(string path);
    // void add();
    string name;
    string port[200];
    string in_put[100];
    string out_put[100];
    string wire[1000];
    gate **_gates;
    size_t _gateIdx;
    bool readFile(string path);

    private:
};

gate *getGateLine(ifstream &input, string gTypeTxt)
{
    string name;
    gate *newgate = 0;

    // input >> buffer;
    gateType gType = EOE;
    for (gateType iter = BUF; iter != EOE; iter = gateType(iter + 1))
    {
        if (gTypeTxt == gTypeTest[iter])
        {
            gType = iter;
            break;
        }
    }
    string para;
    getline(input, para);
    para = removeHeadSpace(para);
    // string para = removeHeadSpace(readUntilSemic(input));

    size_t froPtr = 0, endPtr = para.size();
    string contain;
    if (!strReach(para, froPtr, '(', false) || !strReach(para, endPtr, ')', true))
    {
        cout << froPtr << ' ' << endPtr << '\n';
        cout << "() is missing!" << endl;
    }
    else if (froPtr >= endPtr)
    {
        cout << "() is wrong!" << endl;
    }
    else
    {
        name.assign(para, 0, froPtr);
        contain.assign(para, ++froPtr, --endPtr - froPtr);
        if (strCount(contain, '(') || strCount(contain, ')'))
        {
            cout << "() is too many!" << endl;
        }
    }

    string port[gParamNum[gType]];

    deriveContain(contain, port);
    gate *ptr = new gate(gType, port);
    return ptr;
}

#endif //__MODULE_H__