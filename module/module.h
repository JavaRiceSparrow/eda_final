#ifndef __MODULE_H__
#define __MODULE_H__

#include <iostream>
///
#include <fstream>
#include <vector>

// #include "module.h"
#include "gate.h"
#include "stringFunc.h"
#include "verRead.h"
///

using namespace std;


/*
 * debug option 
*/
// #define DEBUG_OPT 
#ifdef DEBUG_OPT
#define DEBUG_OPT_SIMP
#endif

class module
{
public:
    string _name;
    vector<string> _port;
    vector<string> _input;
    vector<string> _output;
    vector<string> _wire;
    vector<gate *> _gates;
    vector<speGate *> _speGates;
    module()
    {
        is_read = false;
        _gateIdx = 0;
        _speGates.resize(0);
        // in_put = new string[100];
        // out_put = new string[100];
        // wire = new string[1000];
        // _gates = new gate *[1000];
    }
    ~module()
    {
        for(int i = 0;i<_gates.capacity();++i)
        {
            if (_gates[i]==0) break;
            delete _gates[i];
        }
        for (int i = 0; i < _speGates.capacity(); ++i)
        {
            if (_speGates[i] == 0)
                break;
            delete _speGates[i];
        }
    }
    // bool readFile(string path);
    // void add();
    size_t _gateIdx;
    bool readFile(string path);

    bool is_read;

private:
};

bool module::readFile(string path)
{
    if (is_read) return false;
    // string input_file_name = "inoutTest.txt";
    ifstream input(path, ifstream::in);
    if (!input) return false;
    // vector<string> strPort ;
    // port.resize(100);
    string name;
    string buffer;
    while (input >> buffer)
    {
        if (buffer == "module")
            break;
        if (buffer.size() < 2)
            return false;
        // cout << "," << endl;
        if (buffer[0] != '/' || buffer[1] != '/')
            return false;
        getline(input, buffer);
    }
    _port.resize(10);
    getModuleLine(input, name, _port);
    this->_name = name;
#ifdef DEBUG_OPT
    cout << "Name: " << this->_name << endl;
    cout << "Port: ";
    int n = 0;
    for (int i = 0; i < _port.size(); ++i)
    {
        string &str = this->_port[i];
        if (str.empty())
            break;
        ++n;
#ifndef DEBUG_OPT_SIMP
        cout << str << " ";
#endif
    }
    cout << "(" << n << ")";
    cout << endl;
#endif

    {
        bool w = false, i = false, o = false;
        int size_i = 0, size_o = 0, size_w = 0; //UODONE
        while (input >> buffer)
        {
#ifdef DEBUG_OPT
            cout << "Start " << buffer << " ...";
            cout << endl;
#endif

            if (buffer == "input")
            {
                if (i)
                    return false;
                string contain = readUntilSemic(input);
                // cout << this->in_put[10] << endl;
                int len = contain.size() / 10 + 1;
                this->_input.resize(len);
                deriveContain(contain, this->_input);
                i = true;
#ifdef DEBUG_OPT
                cout << "Input: ";
                int n = 0;
                for (int i = 0; i < _input.size(); ++i)
                {
                    string &str = this->_input[i];
                    if (str.empty())
                        break;
                    ++n;
#ifndef DEBUG_OPT_SIMP
                    cout << str << " ";
#endif
                }
                cout << "(" << n << ")";
                cout << endl;
#endif
            }
            else if (buffer == "output")
            {
                if (o)
                    return false;
                string contain = readUntilSemic(input);
                int len = contain.size() / 10 + 1;
                this->_output.resize(len);
                deriveContain(contain, this->_output);
                o = true;
#ifdef DEBUG_OPT
                cout << "Output: ";
                int n = 0;
                for (int i = 0; i < _output.size(); ++i)
                {
                    string &str = this->_output[i];
                    if (str.empty())
                        break;
                    ++n;
#ifndef DEBUG_OPT_SIMP
                    cout << str << " ";
#endif
                }
                cout << "(" << n << ")";
                cout << endl;
#endif
            }
            else if (buffer == "wire")
            {
                if (w)
                    return false;
                string contain = readUntilSemic(input);
                int len = contain.size() / 10 + 1;
                this->_wire.resize(len);
                deriveContain(contain, this->_wire);
                w = true;
#ifdef DEBUG_OPT
                cout << "Wire: ";
                int n = 0;
                for (int i = 0; i < _wire.size(); ++i)
                {
                    string &str = this->_wire[i];
                    if (str.empty())
                        break;
                    ++n;
#ifndef DEBUG_OPT_SIMP
                    cout << str << " ";
#endif
                }
                cout << "(" << n << ")";
                cout << endl;
#endif
            }
            else
                break;
        }

        if (!(i && o && w))
            return false;
    }
    _gates.resize(_output.size() + _wire.size());

    do
    {
        // cout << "buffer:" << buffer << endl;
        if (buffer == "endmodule" || input.eof())
        {
            input.close();
            return true;
        }
        if (buffer == "//")
        {
            getline(input, buffer);
#ifdef DEBUG_OPT
            cout << "comment: " << buffer << endl;
#endif
            buffer.clear();
            continue;
        }
        if ((buffer.size() > 1) && (buffer[0] == '/' && buffer[1] == '/'))
        {

            getline(input, buffer);
#ifdef DEBUG_OPT
            cout << "comment: " << buffer << endl;
#endif
            buffer.clear();
            continue;
        }
        // else
        {
            // cout << "[test1]get gate..." << endl;
            gateType gType;
            string name;
            vector<string> port;

            if (!getGateLine(input, buffer, name, gType, port))
            {
                // cout << "[test1]get s gate..." << endl;
                _speGates.push_back(new speGate(gType, name, port));
            }
            else
            {
                // cout << "[test1]get n gate..." << endl;
                // cout << _gates.size() << ',' << _gateIdx << endl;
                if (_gates.size() == _gateIdx)
                    _gates.resize(_gateIdx * 2);

                _gates[_gateIdx++] = new gate(gType, name, port);
            }
        }
#ifdef DEBUG_OPT
        // cout << buffer[0];
        cout << "New gate :" << buffer << endl;

#endif

        // cout << "test4" << endl;
    } while (input >> buffer);

    // adjust gate
    size_t len = _gates.size();

    int n = len;
    while (--n >= 0)
    {
        if (_gates[n])
            break;
        // --n;
    }
    _gates.resize(n + 1);
    is_read = true;
}

#endif //__MODULE_H__