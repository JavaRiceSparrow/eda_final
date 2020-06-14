#ifndef __GATE_H__
#define __GATE_H__

#include <fstream>
#include <vector>

#include "module.h"
#include "stringFunc.h"
#include "verRead.h"

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
int gParamNum[] = {2, 2, 3, 3, 3, 3, 3, 3, 4};

gate *getGateLine(ifstream &input, string gTypeTxt);

class gate
{
public:
    gate(gateType gatetype, string name, vector<string> io)
    {
        int i = 0;
        while (i<io.size())
        {
            cout << "\"" << io[i++] << "\" ";
        }
        cout << endl;
        
        this->name = name;
        size_t ioLen = io.size();
        type = gatetype;
        // int ioLen = sizeof(io) / sizeof(*io);
        if (ioLen > gParamNum[type])
        {
            cout << "[gate] TOO many io port!" << endl;
            cout << "       Expect (" << gParamNum[type]
                 << "), but it's (" << ioLen <<")." << endl;
        }
        if (ioLen < 2 || ioLen > 4)
        {
            cout << "[gate] How do U turn this on!" << endl;
            return;
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

gate *getGateLine(ifstream &input, string gTypeTxt)
{

    // cout << input.peek() << endl;
    string name;
    gate *newgate = 0;

    // input >> buffer;
    gateType gType = EOE;
    bool su = false;
    for (gateType iter = BUF; iter != EOE; iter = gateType(iter + 1))
    {
        if (gTypeTxt == gTypeTest[iter])
        {
            gType = iter;
            su = true;
            break;
        }
    }
    if (!su)
    {
        cout << "[getGateLine] Wrong input \"" << gTypeTxt << "\" !" << endl;
    }
    string para;
    getline(input, para);
    cout << "[getGateLine] Input \"" << para << "\"" << endl;
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

    vector<string> port;
    port.resize(gParamNum[gType]);
    cout << "[test3] "  << gParamNum[gType] << "" << endl;

    deriveContain(contain, port);
    gate *ptr = new gate(gType, name, port);
    return ptr;
}

#endif //__GATE_H__
