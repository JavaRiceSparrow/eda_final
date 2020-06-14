#ifndef __VER_READ_H__
#define __VER_READ_H__

// #include<cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

// #include "module.h"
#include "stringFunc.h"

using namespace std;

bool deriveContain(const string &contain, vector<string> &value);

string readUntilSemic(ifstream &input)
{
    string str("");
    string buffer;
    size_t froPtr = 0, endPtr = 0;
    // cout << input.eof() << endl;
    while (getline(input, buffer))
    {

        // cout << "[test2] buffer:\"" << buffer << "\"" << endl;
        froPtr = (endPtr = buffer.size());
        if (strReach(buffer, endPtr, ';', true))
        {
            // cout << froPtr;
            if (!strPassEmpty(buffer, --froPtr, true))
                cout << "WTF?" << endl;
            if (froPtr < endPtr)
                cout << "WTF?" << endl;
            if (froPtr != endPtr)
            {
                // cout << froPtr<< '\n' << endPtr;
                string str_t;
                str_t.assign(buffer, endPtr + 1, froPtr - endPtr);
                cout << "string \"" << str_t << "\" behind ';'!" << endl;
                return "Wrong!";
            }
            else
            {
                str.append(buffer, 0, endPtr);
                break;
                // deriveContain(contain, in);
                // return true;
            }
        }
        str.append(buffer, 0, froPtr);
        // cout << str.size() << endl;
    }

    // cout << "[test2] \"" << str << "\"" << endl;
    return str;
}

bool getModuleLine(ifstream &input, string &name, vector<string> &port)
{
    // string buffer;

    // input >> buffer;
    // if (buffer != "module")
    // {
    //     cout << buffer << endl;
    //     cout << "It's not a module!" << endl;
    //     return false;
    // }
    string para = removeHeadSpace(readUntilSemic(input));

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

    deriveContain(contain, port);
    return true;
}

// bool deriveContain(const string &contain, vector<string>& value)
// {
//     if (valueSize < 0)
//         return false;
//     else
//         return deriveContain(contain, value, size_t(valueSize));
// }

bool deriveContain(const string &contain, vector<string> &value)
{
    // cout << "[dC] starting..." << endl;
    // cout << "[dC] string:" << endl;
    // cout << contain << '\n' << endl;
    string str = contain;
    // size_t arraySize = sizeof(&value)/sizeof(value);
    // cout << arraySize << endl;
    for (int i = 0; i < str.size(); ++i)
        if (str[i] == '\t')
            str[i] = ' ';

    size_t froPtr = 0, endPtr = 0;
    // strPass(str, ptr, ' ', '\t');
    if (!strPass(str, froPtr, ' ', '\t'))
        cout << "froPtr: " << froPtr << endl;
    endPtr = froPtr + 1;
    size_t valueIdx = 0;

    if (value.size() == 0)
        cout << "[dC] Empty string vector!(It will crash)" << endl;
    // valueIdx = 0;
    // value.resize(10);
    strReach(str, endPtr, ' ', ',');
    // if (valueIdx == valueSize) {
    //     // cout << value[0] << endl;
    //     cout << "[deriveContain] Size of Array value is too small("
    //          << valueSize << ")!" << endl;

    //     return false;
    // }
    // cout << "t1" << endl;
    if (value.size() == valueIdx)
        value.resize(valueIdx * 2);
    value[valueIdx++].assign(str, froPtr, endPtr - froPtr);
    froPtr = endPtr;
    while (strPass(str, froPtr, ' ', ','))
    {
        string interval;
        interval.assign(str, endPtr, froPtr - endPtr);
        if (strCount(interval, ',') != 1)
        {
            cout << endPtr << ' ' << froPtr << endl;
            cout << "',' number wrong!" << endl;
            return false;
        }
        endPtr = froPtr;
        strReach(str, endPtr, ' ', ',');
        // if (valueIdx == valueSize)
        // {
        //     cout << "[deriveContain] Size of Array value is too small(full)!" << endl;
        //     return false;
        // }
        if (froPtr != endPtr)
        {
            if (value.size() == valueIdx)
                value.resize(valueIdx * 2);
            value[valueIdx++].assign(str, froPtr, endPtr - froPtr);
        }
        // cout << "[test1] Get " << value[valueIdx - 1]
        //      << " at (" << froPtr << "," << endPtr
        //      << ")." << endl;
        froPtr = endPtr + 1;
        // if (!)
        //     cout << "froPtr: " << froPtr << endl;
    }
    return true;
}

#endif //__VER_READ_H__