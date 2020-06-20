#ifndef __MODULE_TRANSER_H__
#define __MODULE_TRANSER_H__
#include <iostream>
#include <vector>
#include "module.h"
using namespace std;

const string str_bit1 = "_b1";
const string str_bit0 = "_b0";
const string wireHead = "w_";

// #define DEBUG_OPT

struct bus2
{
    string bit1;
    string bit0;
};

bus2 getBusFromStr(string wire)
{
    bus2 b1;
    b1.bit1 = wire + str_bit1;
    b1.bit0 = wire + str_bit0;
    return b1;
}

void vectorAdj(vector<gate *> &vec);
void vectorAdj(vector<speGate *> &vec);
void vectorAdj(vector<gate *> &vec)
{
    size_t len = vec.size();
    int n = len;

    while (--n >= 0)
    {
        // string &str = vec[n];
        if (!vec[n])
            break;
        // --n;
    }
    vec.resize(n + 1);
}
void vectorAdj(vector<speGate *> &vec)
{
    size_t len = vec.size();
    int n = len;

    while (--n >= 0)
    {
        // string &str = vec[n];
        if (!vec[n])
            break;
        // --n;
    }
    vec.resize(n + 1);
}

class moduleTranser
{
public:
    moduleTranser(module *oldM, module *newM)
    {
        resetModule(oldM, newM);
    }

    bool transModule();
    bool start, finish;
    module *getModule()
    {
        if (_module_old==0)
        return 0;
        if (!finish)
        {
            if (!transModule())
                return 0;
            else
                return _module;
        }
        return _module;
    };

    void resetModule(module *oldM, module *newM)
    {
        start = false;
        finish = false;
        wireNum = 0;
        gateSize = 0;
        // if (_module!=0)
        //     delete _module;
        _module = newM;
        this->_module_old = oldM;
    }

private:
    int wireNum;
    int wireSize;
    int gateSize;
    string getNewWire()
    {

// #ifdef DEBUG_OPT
//         cout << "New Wire " << wireSize << endl;
//         int n = 0;
//         for(;n<_module->_wire.capacity();++n)
//         {
//             if (_module->_wire[n]=="")
//             break;
//         }
//         cout << "Wire size: " << n << " capacity: " << _module->_wire.capacity() << endl;
// #endif
        if (!start)
            return "";
//         if (wireSize == _module->_wire.capacity())
//         {
//             _module->_wire.resize(wireSize + 100);
// #ifdef DEBUG_OPT
//             cout << "Wires resize to " << _module->_wire.size() << endl;
// #endif
//             if (_module->_wire.capacity() > 20000)
//             {
//                 cout << "WTF" << endl;
//                 exit(1);
//             }
//         }
        string wire = wireHead + to_string(wireNum++);
        // _module->_wire[wireSize++] = wire;
        // _module->_wire.resize(wireSize+1);
        return wire;
    }
    module *_module;
    module *_module_old;

    void addFilter(bus2 i, bus2 o)
    {
        // string i1 = i.bit1, a0 = a + str_bit0,
        //        b1 = b + str_bit1, b0 = b + str_bit0,
        //        c1 = c + str_bit1, c0 = c + str_bit0;
        string i1n = getNewWire();
        // addBaseOR(a1, b1, c1);
        addBaseNOT(i.bit1, i1n);
        addBaseBUF(i.bit1, o.bit1);
        addBaseAND(i1n, i.bit0, o.bit0);
    };
    void addEqual(bus2 a, bus2 b, string o)
    {
        // a0b0+a1a0'+a0b1'b0'
        string w1 = getNewWire(),
               w2 = getNewWire(),
               w3 = getNewWire(),
               w4 = getNewWire(),
               w5 = getNewWire(),
               a0n = getNewWire(),
               b1n = getNewWire(),
               b0n = getNewWire();
        // addBaseOR(a1, b1, c1);
        addBaseNOT(a.bit0, a0n);
        addBaseNOT(b.bit1, b1n);
        addBaseNOT(b.bit0, b0n);
        addBaseAND(a.bit0, b.bit0, w1);
        addBaseAND(a.bit1, a0n, w2);
        addBaseOR(w1,w2,w3);
        addBaseAND(b1n, b0n, w4);
        addBaseAND(w4, a.bit0, w5);
        addBaseAND(w3, w5, o);

        // addBaseBUF(i.bit1, o.bit1);
        // addBaseAND(i1n, i.bit0, o.bit0);
    };

    void addBUF(string i1, string o1);
    void addNOT(string i1, string o1);
    void addAND(string i1, string i2, string o1);
    void addOR(string i1, string i2, string o1);
    void addXOR(string i1, string i2, string o1);
    void addNAND(string i1, string i2, string o1);
    void addNOR(string i1, string i2, string o1);
    void addDC(string i1, string i2, string o1);
    void addMUX(string i1, string i2, string i3, string o1);
    void addXNOR(string i1, string i2, string o1);

    void addOR(bus2 i1, bus2 i2, bus2 o1);
    void addNOT(bus2 i1, bus2 o1);

    void addGate(gateType type, string io1, string io2, string io3 = "")
    {
        vector<string> io;
        io.push_back(io1);
        io.push_back(io2);
        if (io3 != "")
            io.push_back(io3);
            // _module->_gates.push_back(new gate(type, "", io));
#ifdef DEBUG_OPT
        cout << "New Gate " << gateSize << "(" << getTypeText(type) << ")" << endl;
#endif
        // size_t size = _module->_gates.size();
        if (!gateSize)
            _module->_gates.resize(10);
        else if (gateSize == _module->_gates.capacity())
        {
            _module->_gates.resize(gateSize * 2);
#ifdef DEBUG_OPT
            cout << "Gates resize to " << _module->_gates.size() << endl;
#endif
            if (_module->_gates.capacity() > 20000)
            {
                cout << "WTF" << endl;
                exit(1);
            }
        }
        _module->_gates[gateSize++] = new gate(type, "", io);
    }
    void addBaseAND(string i1, string i2, string o1) { addGate(AND, i1, i2, o1); }
    void addBaseOR(string i1, string i2, string o1) { addGate(OR, i1, i2, o1); }
    void addBaseXOR(string i1, string i2, string o1) { addGate(XOR, i1, i2, o1); }
    void addBaseNOT(string i1, string o1) { addGate(NOT, i1, o1); }
    void addBaseBUF(string i1, string o1) { addGate(BUF, i1, o1); }

    void addSpeOR(speGate *gate);
    void addSpeNOR(speGate *gate);
};

bool moduleTranser::transModule()
{
    cout << "test1" << endl;
    if (_module->is_read) return false;
    start = true;
#ifdef DEBUG_OPT
    cout << "Deriving name ..." << endl;
#endif
    _module->_name = _module_old->_name;
#ifdef DEBUG_OPT
    cout << "Deriving port ..." << endl;
#endif
    _module->_port.resize(_module_old->_port.size() * 2);
    for (int i = 0; i < _module_old->_port.size(); ++i)
    {
        _module->_port[i * 2] = _module_old->_port[i] + str_bit1;
        _module->_port[i * 2 + 1] = _module_old->_port[i] + str_bit0;
    }
#ifdef DEBUG_OPT
    cout << "Deriving input ..." << endl;
#endif
    _module->_input.resize(_module_old->_input.size() * 2);
    for (int i = 0; i < _module_old->_input.size(); ++i)
    {
        _module->_input[i * 2] = _module_old->_input[i] + str_bit1;
        _module->_input[i * 2 + 1] = _module_old->_input[i] + str_bit0;
    }
#ifdef DEBUG_OPT
    cout << "Deriving output ..." << endl;
#endif
    _module->_output.resize(_module_old->_output.size() * 2);
    for (int i = 0; i < _module_old->_output.size(); ++i)
    {
        _module->_output[i * 2] = _module_old->_output[i] + str_bit1;
        _module->_output[i * 2 + 1] = _module_old->_output[i] + str_bit0;
    }

#ifdef DEBUG_OPT
    cout << "Deriving original wire ..." << endl;
#endif
    _module->_wire.resize(_module_old->_wire.size() * 2);
    wireSize = _module->_wire.size();

    for (int i = 0; i < _module_old->_wire.size(); ++i)
    {
        _module->_wire[i * 2] = _module_old->_wire[i] + str_bit1;
        _module->_wire[i * 2 + 1] = _module_old->_wire[i] + str_bit0;
    }

#ifdef DEBUG_OPT
    cout << "Deriving new gate and wire from gates..." << endl;
#endif
    vector<gate *> &gatesRef = _module_old->_gates;
    // _module_old->_gates;
    for (int i = 0; i < gatesRef.size(); ++i) //, cout << "[testi] " << i << endl
    {

        if (!gatesRef[i])
            break;
#ifdef DEBUG_OPT
        cout << "Dealing gate " << gatesRef[i]->name;
        cout << "(" << getTypeText(gatesRef[i]->type) << ") ..." << endl;
#endif

        switch (gatesRef[i]->type)
        {
        case BUF:
            addBUF(gatesRef[i]->i1, gatesRef[i]->o1);
            break;
        case NOT:
            addNOT(gatesRef[i]->i1, gatesRef[i]->o1);
            break;
        case AND:
            addAND(gatesRef[i]->i1, gatesRef[i]->i2, gatesRef[i]->o1);
            break;
        case OR:
            addOR(gatesRef[i]->i1, gatesRef[i]->i2, gatesRef[i]->o1);
            break;
        case XOR:
            addXOR(gatesRef[i]->i1, gatesRef[i]->i2, gatesRef[i]->o1);
            break;
        case NAND:
            addNAND(gatesRef[i]->i1, gatesRef[i]->i2, gatesRef[i]->o1);
            break;
        case NOR:
            addNOR(gatesRef[i]->i1, gatesRef[i]->i2, gatesRef[i]->o1);
            break;
        case DC:
            addDC(gatesRef[i]->i1, gatesRef[i]->i2, gatesRef[i]->o1);
            break;
        case MUX:
            addMUX(gatesRef[i]->i1, gatesRef[i]->i2, gatesRef[i]->i3, gatesRef[i]->o1);
            break;
        case XNOR:
            addXNOR(gatesRef[i]->i1, gatesRef[i]->i2, gatesRef[i]->o1);
            break;

        default:
        {
            return false;
            break;
        }
        }

    }

#ifdef DEBUG_OPT
    cout << "Deriving new gate and wire from special gates..." << endl;
#endif
    vector<speGate *> &sgatesRef = _module_old->_speGates;
    for (int i = 0; i < sgatesRef.size(); ++i)
    {
        if (!sgatesRef[i])
            break;
#ifdef DEBUG_OPT
        cout << "Dealing gate " << sgatesRef[i]->name;
        cout << "(" << getTypeText(sgatesRef[i]->type) << ") size:";
        cout << "(" << sgatesRef[i]->io.size() << " ..." << endl;
#endif

        switch (sgatesRef[i]->type)
        {
        case OR:
        {
            addSpeOR(sgatesRef[i]);
            break;
        }
        case NOR:
        {
            addSpeNOR(sgatesRef[i]);
            break;
        }

        default:
            return false;
            break;
        }
    }
    vectorAdj(_module->_gates);
    vectorAdj(_module->_speGates);

    size_t w_size = _module->_wire.size();
    _module->_wire.resize(w_size+wireNum);
    

    for (int i = 0; i < wireNum; ++i)
    {
        _module->_wire[w_size+i] = wireHead + to_string(i);
    }

    // sVectorAdj(_module->_wire);
    

    return true;
}

void moduleTranser::addBUF(string i1, string o1)
{
    addBaseBUF(i1 + str_bit1, o1 + str_bit1);
    addBaseBUF(i1 + str_bit0, o1 + str_bit0);
}
void moduleTranser::addNOT(string i1, string o1)
{
    addBaseBUF(i1 + str_bit1, o1 + str_bit1);
    // addBaseNOT(i1 + str_bit0, o1 + str_bit0);
    string w1n = getNewWire();
    string w0n = getNewWire();
    addBaseNOT(i1 + str_bit1, w1n);
    addBaseNOT(i1 + str_bit0, w0n);
    addBaseAND(w1n, w0n, o1 + str_bit0);
}
void moduleTranser::addAND(string a, string b, string c)
{
    string a1 = a + str_bit1, a0 = a + str_bit0,
           b1 = b + str_bit1, b0 = b + str_bit0,
           c1 = c + str_bit1, c0 = c + str_bit0;
    string c1n = getNewWire(),
           w0 = getNewWire();
    addBaseOR(a1, b1, c1);
    addBaseNOT(c1, c1n);
    addBaseAND(a0, b0, w0);
    addBaseAND(c1n, w0, c0);
}
void moduleTranser::addOR(string a, string b, string c)
{
    string a1 = a + str_bit1, a0 = a + str_bit0,
           b1 = b + str_bit1, b0 = b + str_bit0,
           c1 = c + str_bit1, c0 = c + str_bit0;
    string w1 = getNewWire(),
           c0n = getNewWire();
    addBaseOR(a1, b1, w1);
    addBaseOR(a0, b0, c0);
    addBaseNOT(c0, c0n);
    addBaseAND(c0n, w1, c1);
}
void moduleTranser::addXOR(string a, string b, string c)
{
    string a1 = a + str_bit1, a0 = a + str_bit0,
           b1 = b + str_bit1, b0 = b + str_bit0,
           c1 = c + str_bit1, c0 = c + str_bit0;
    string w0x = getNewWire(),
           w0xn = getNewWire();
    addBaseOR(a1, b1, c1);
    addBaseXOR(a0, b0, w0x);
    addBaseNOT(w0x, w0xn);
    addBaseAND(w0xn, c1, c0);
}

void moduleTranser::addNAND(string a, string b, string c)
{
    string a1 = a + str_bit1, a0 = a + str_bit0,
           b1 = b + str_bit1, b0 = b + str_bit0,
           c1 = c + str_bit1, c0 = c + str_bit0;
    string c1n = getNewWire(),
           w0 = getNewWire(),
           n1 = getNewWire(),
           n0 = getNewWire();
    addBaseOR(a1, b1, n1);
    addBaseNOT(c1, c1n);
    addBaseAND(a0, b0, w0);
    addBaseAND(c1n, w0, n0);
    addBaseNOT(n1, c1);
    addBaseNOT(n0, c0);
}
void moduleTranser::addNOR(string a, string b, string c)
{
    string a1 = a + str_bit1, a0 = a + str_bit0,
           b1 = b + str_bit1, b0 = b + str_bit0,
           c1 = c + str_bit1, c0 = c + str_bit0;
    string w1 = getNewWire(),
           c0n = getNewWire(),
           n1 = getNewWire(),
           n0 = getNewWire();
    addBaseOR(a1, b1, w1);
    addBaseOR(a0, b0, n0);
    addBaseNOT(c0, c0n);
    addBaseAND(c0n, w1, n1);
    addBaseNOT(n1, c1);
    addBaseNOT(n0, c0);
}
// void moduleTranser::addNOR(bus2 a, bus2 b, bus2 c)
// {
//     string a1 = a.bit1, a0 = a.bit0,
//            b1 = b.bit1, b0 = b.bit0,
//            c1 = c.bit1, c0 = c.bit0;
//     string w1 = getNewWire(),
//            c0n = getNewWire(),
//            n1 = getNewWire(),
//            n0 = getNewWire();
//     addBaseOR(a1, b1, w1);
//     addBaseOR(a0, b0, n0);
//     addBaseNOT(c0, c0n);
//     addBaseAND(c0n, w1, n1);
//     addBaseNOT(n1, c1);
//     addBaseNOT(n0, c0);
// }
void moduleTranser::addDC(string a, string b, string c)
{
    string a1 = a + str_bit1, a0 = a + str_bit0,
           b1 = b + str_bit1, b0 = b + str_bit0,
           c1 = c + str_bit1, c0 = c + str_bit0;
    string w1 = getNewWire(),
           c1n = getNewWire();
    addBaseAND(a1, b1, w1);
    addBaseXOR(w1, b0, c1);
    addBaseNOT(c1, c1n);
    addBaseAND(a0, c1n, c0);
}

void moduleTranser::addMUX(string a, string b, string s, string c)
{
    //     c0 = a0s0 + a0b0 + s1's0'b0
    //     c1 = (s0'b1 + a1s0 + s1a1' + s0'b0 + a1a0)*c0'
    //   a:
    //          1      2      3 35
    //          (4      5      6          7       8 )9
    //   o:
    //               1      2
    //                 3      4       5       6
    //   n:
    //                           1   2
    //              3                4     5             6

    string a1 = a + str_bit1, a0 = a + str_bit0,
           b1 = b + str_bit1, b0 = b + str_bit0,
           s1 = s + str_bit1, s0 = s + str_bit0,
           c1 = c + str_bit1, c0 = c + str_bit0;
    string d1 = getNewWire(),
           d2 = getNewWire(),
           d3 = getNewWire(),
           d35 = getNewWire(),
           d4 = getNewWire(),
           d5 = getNewWire(),
           d6 = getNewWire(),
           d7 = getNewWire(),
           d8 = getNewWire(),
           //    d9 = getNewWire(), == c1
        o1 = getNewWire(),
           //    o2 = getNewWire(), == c0
        o3 = getNewWire(),
           o4 = getNewWire(),
           o5 = getNewWire(),
           o6 = getNewWire(),
           n1 = getNewWire(),
           n2 = getNewWire(),
           //    n3 = getNewWire(), == n2
        n4 = getNewWire(),
           //    n5 = getNewWire(), == n2
        n6 = getNewWire();
    addBaseAND(a0, s0, d1);
    addBaseAND(a0, b0, d2);
    addBaseAND(n1, n2, d3);
    addBaseAND(d3, b0, d35);
    addBaseAND(n2, b1, d4); //n3
    addBaseAND(a1, s0, d5);
    addBaseAND(s1, n4, d6);
    addBaseAND(n2, b0, d7); //n5
    addBaseAND(a1, a0, d8);
    addBaseAND(o6, n6, c1);
    addBaseOR(d1, d2, o1);
    addBaseOR(o1, d35, c0);
    addBaseOR(d4, d5, o3);
    addBaseOR(o3, d6, o4);
    addBaseOR(o4, d7, o5);
    addBaseOR(o5, d8, o6);
    addBaseNOT(s1, n1);
    addBaseNOT(s0, n2);
    // addBaseNOT(a0, n3);
    addBaseNOT(a1, n4);
    // addBaseNOT(a0, n5);
    addBaseNOT(c0, n6);
}
void moduleTranser::addXNOR(string a, string b, string c)
{
    string a1 = a + str_bit1, a0 = a + str_bit0,
           b1 = b + str_bit1, b0 = b + str_bit0,
           c1 = c + str_bit1, c0 = c + str_bit0;
    string w1 = getNewWire(),
           c1n = getNewWire();
    addBaseAND(a1, b1, w1);
    addBaseXOR(w1, b0, c1);
    addBaseNOT(c1, c1n);
    addBaseAND(a0, c1n, c0);
}

void moduleTranser::addOR(bus2 a, bus2 b, bus2 c)
{
    string a1 = a.bit1, a0 = a.bit0,
           b1 = b.bit1, b0 = b.bit0,
           c1 = c.bit1, c0 = c.bit0;
    string w1 = getNewWire(),
           c0n = getNewWire();
    addBaseOR(a1, b1, w1);
    addBaseOR(a0, b0, c0);
    addBaseNOT(c0, c0n);
    addBaseAND(c0n, w1, c1);
}
void moduleTranser::addNOT(bus2 a, bus2 b)
{
    addBaseBUF(a.bit1, b.bit1);
    // addBaseNOT(i1 + str_bit0, o1 + str_bit0);
    string w1n = getNewWire();
    string w0n = getNewWire();
    addBaseNOT(a.bit1, w1n);
    addBaseNOT(a.bit0, w0n);
    addBaseAND(w1n, w0n, b.bit0);
}

void moduleTranser::addSpeOR(speGate *gate)
{
    if (!start)
        return;
    size_t ioSize = gate->io.size();
    if (ioSize <= 3)
    {
        cout << "This shouldn't happen..." << endl;
    }
    bus2 io_bus[ioSize];
    for (int idx = 0; idx < ioSize; ++idx)
        io_bus[idx] = getBusFromStr(gate->io[idx]);
    // i_port.pop_back();
    bus2 w_bus[ioSize - 1];

    w_bus[0] = io_bus[0];
    w_bus[ioSize - 2] = io_bus[ioSize - 1];
    for (int idx = 1; idx < ioSize - 2; ++idx)
    {
        w_bus[idx].bit1 = getNewWire();
        w_bus[idx].bit0 = getNewWire();
    }
    for (int idx = 0; idx < ioSize - 2; ++idx)
    {
        addOR(w_bus[idx], io_bus[idx + 1], w_bus[idx + 1]);
    }
}

void moduleTranser::addSpeNOR(speGate *gate)
{
    if (!start)
        return;
    size_t ioSize = gate->io.size();
    if (ioSize <= 3)
    {
        cout << "This shouldn't happen..." << endl;
    }
    bus2 io_bus[ioSize];
    for (int idx = 0; idx < ioSize; ++idx)
        io_bus[idx] = getBusFromStr(gate->io[idx]);
    // i_port.pop_back();
    bus2 w_bus[ioSize - 1];

    w_bus[0] = io_bus[0];
    // w_bus[ioSize - 2] = io_bus[ioSize - 1];
    for (int idx = 1; idx < ioSize - 1; ++idx)
    {
        w_bus[idx].bit1 = getNewWire();
        w_bus[idx].bit0 = getNewWire();
    }
    for (int idx = 0; idx < ioSize - 2; ++idx)
    {
        addOR(w_bus[idx], io_bus[idx + 1], w_bus[idx + 1]);
    }
    addNOT(w_bus[ioSize - 2], io_bus[ioSize - 1]);
}
#endif //__MODULE_TRANSER_H__