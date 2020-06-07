// #include<cstdlib>
#include<iostream>
#include <fstream>
#include<cstring>

#include "module.h"
#include "stringFunc.h"

using namespace std;

bool deriveContain(const string &contain, string value[]);

/*
int main(int argc, char **argv)
{
string input_file_name = "ver/g1.v";
// string input_file_name = "case/case1/gf.v";
// cout << strcmp(c1,c2) <<endl;
ifstream input (input_file_name, ifstream::in);
if (!input.is_open())
{
    cout << "Reading file " << input_file_name << " failed!" << endl;
    return 0;
}
// char buffer[500];
string port[200];
if (!getModuleLine(input, port))
{
    cout << "" << endl;
}
// string buffer;
// size_t froPtr = 0, endPtr = 0;

// input >> buffer;
// if (buffer != "module")
// {
//     cout << buffer << endl;
//     cout << "It's not a module!" << endl;
// }
// string port[100];

// while (getline(input, buffer))
// {
//     ;
// }
// cout << buffer << endl;

// while()

input.close();
    return 0;
}
*/

string readUntilSemic(ifstream &input)
{
    string str("");
    string buffer;
    size_t froPtr = 0, endPtr = 0;
    while (getline(input, buffer))
    {
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
                str_t.assign(buffer, endPtr+1, froPtr - endPtr);
                cout << "string \"" << str_t << "\" behind ';'!" << endl;
                return "Wrong!";
            }
            else
            {
                str.append(buffer, 0, endPtr );
                break;
                // deriveContain(contain, in);
                // return true;
            }
        }
        str.append(buffer, 0, froPtr);
        // cout << str.size() << endl;
    }
    return str;
}

bool getModuleLine(ifstream &input, string &name, string port[])
{
    // string buffer;

    // input >> buffer;
    // if (buffer != "module")
    // {
    //     cout << buffer << endl;
    //     cout << "It's not a module!" << endl;
    //     return false;
    // }
    string para =  removeHeadSpace(readUntilSemic(input));
    
    size_t froPtr = 0, endPtr = para.size();
    string contain;
    if (!strReach(para,froPtr,'(',false) || !strReach(para,endPtr,')',true))
    {
        cout << froPtr << ' ' << endPtr << '\n';
        cout << "() is missing!" << endl;
    }
    else if (froPtr >= endPtr)
    {
        cout << "() is wrong!" << endl;
    }
    else{
        name.assign(para, 0, froPtr);
        contain.assign(para,++froPtr, --endPtr-froPtr);
        if (strCount(contain, '(') || strCount(contain, ')'))
        {
            cout << "() is too many!" << endl;
        }
    }

    deriveContain(contain, port);
    return true;
}

gate* getGateLine(ifstream &input, string &name, string port[])
{
    string buffer;
    gate* newgate = 0;

    input >> buffer;
    gateType type = EOE;
    for (gateType iter = BUF; iter != EOE; iter = gateType(iter + 1))
    {
        if (buffer == gTypeTest[iter]) {
            type = iter;
            break;
        }
    }
    string para ;
    getline(input,para);
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

    deriveContain(contain, port);
}

bool deriveContain(const string &contain, string value[])
{
    string str = contain;
    for (int i = 0; i < str.size(); ++i)
        if (str[i] == '\t')
            str[i] = ' ';

    size_t froPtr = 0, endPtr = 0;
    // strPass(str, ptr, ' ', '\t');
    if (!strPass(str, froPtr, ' ', '\t'))
        cout << "froPtr: " << froPtr << endl;
    endPtr = froPtr + 1;
    size_t valueIdx = 0;

    strReach(str, endPtr, ' ', ',');
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
        value[valueIdx++].assign(str, froPtr, endPtr - froPtr);
        froPtr = endPtr + 1;
        // if (!)
        //     cout << "froPtr: " << froPtr << endl;
    }
    return true;
}

// bool getInput(ifstream &input, string in[])
// {
//     string buffer;

//     input >> buffer;
//     if (buffer != "input")
//     {
//         cout << buffer << endl;
//         cout << "It should be a input!" << endl;
//         return false;
//     }
//     string contain = readUntilSemic(input);
//     deriveContain(contain, in);
// }

// bool getOutput(ifstream &input, string out[])
// {
//     string buffer;

//     input >> buffer;
//     if (buffer != "output")
//     {
//         cout << buffer << endl;
//         cout << "It should be a output!" << endl;
//         return false;
//     }
//     string contain = readUntilSemic(input);
//     deriveContain(contain, out);
// }
// bool getWire(ifstream &input, string wire[])
// {
//     string buffer;

//     input >> buffer;
//     if (buffer != "output")
//     {
//         cout << buffer << endl;
//         cout << "It should be a output!" << endl;
//         return false;
//     }
//     string contain = readUntilSemic(input);
//     deriveContain(contain, wire);
// }
