#ifndef __MODULE_H__
#define __MODULE_H__

#include <iostream>
using namespace std;

#define DEBUG_OPT

///
#include <fstream>
#include <vector>

// #include "module.h"
#include "gate.h"
#include "stringFunc.h"
#include "verRead.h"
///

class module
{
public:
    string name;
    vector<string> port;
    vector<string> in_put;
    vector<string> out_put;
    vector<string> wire;
    vector<gate *> _gates;
    module()
    {

        _gateIdx = 0;
        // in_put = new string[100];
        // out_put = new string[100];
        // wire = new string[1000];
        // _gates = new gate *[1000];
    }
    // bool readFile(string path);
    // void add();
    size_t _gateIdx;
    bool readFile(string path);

private:
};

bool module::readFile(string path)
{
    // string input_file_name = "inoutTest.txt";
    ifstream input(path, ifstream::in);
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
    port.resize(10);
    getModuleLine(input, name, port);
    this->name = name;
#ifdef DEBUG_OPT
    cout << "Name: " << this->name << endl;
    cout << "Port: ";
    for (int i = 0; i < port.size(); ++i)
    {
        string &str = this->port[i];
        if (str.empty())
            break;
        cout << str << " ";
    }
    cout << endl;
#endif

    {
        bool w = false, i = false, o = false;

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
                this->in_put.resize(len);
                deriveContain(contain, this->in_put);
                i = true;
#ifdef DEBUG_OPT
                cout << "Input: ";
                for (int i = 0; i < in_put.size(); ++i)
                {
                    string &str = this->in_put[i];
                    if (str.empty())
                        break;
                    cout << str << " ";
                }
                cout << endl;
#endif
            }
            else if (buffer == "output")
            {
                if (o)
                    return false;
                string contain = readUntilSemic(input);
                int len = contain.size() / 10 + 1;
                this->out_put.resize(len);
                deriveContain(contain, this->out_put);
                o = true;
#ifdef DEBUG_OPT
                cout << "Output: ";
                for (int i = 0; i < out_put.size(); ++i)
                {
                    string &str = this->out_put[i];
                    if (str.empty())
                        break;
                    cout << str << " ";
                }
                cout << endl;
#endif
            }
            else if (buffer == "wire")
            {
                if (w)
                    return false;
                string contain = readUntilSemic(input);
                int len = contain.size() / 10 + 1;
                this->wire.resize(len);
                deriveContain(contain, this->wire);
                w = true;
#ifdef DEBUG_OPT
                cout << "Wire: ";
                for (int i = 0; i < wire.size(); ++i)
                {
                    string &str = this->wire[i];
                    if (str.empty())
                        break;
                    cout << str << " ";
                }
                cout << endl;
#endif
            }
            // else if (buffer == "reg")
            // {
            //     string contain = readUntilSemic(input);
            //     deriveContain(contain, reg);
            // }
            else
                break;
        }

        if (!(i && o && w))
            return false;
    }

    do
    {
        cout << "buffer:" << buffer << endl;
        if (buffer == "endmodule" || input.eof())
        {
            input.close();
            return true;
        }
        if (buffer == "//")
        {
            getline(input, buffer);
            cout << "comment: " << buffer << endl;
            buffer.clear();
            continue;
        }
        if (buffer.size() > 1)
        {
            if (buffer[0] == '/' && buffer[1] == '/')
                continue;
        }
#ifdef DEBUG_OPT
        // cout << buffer[0];
        cout << "New gate :" << buffer << endl;
        ;

#endif
        if (_gates.size() == _gateIdx)
            _gates.resize(_gateIdx * 2);

        _gates[_gateIdx++] = getGateLine(input, buffer);
    } while (input >> buffer);
}

#endif //__MODULE_H__