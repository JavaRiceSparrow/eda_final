
#include <iostream>
#include <fstream>
#include <vector>

#include "module.h"
#include "stringFunc.h"
#include "verRead.h"

using namespace std;

bool 
module::readFile(string path)
{
    string input_file_name = "inoutTest.txt";
    ifstream input(input_file_name, ifstream::in);
    string str[100];
    string name;
    string buffer;
    input >> buffer;
    // vector<gate> _gate;
    if (buffer != "module")
        return 300;
    getModuleLine(input, name, str);
    this->name = name;

    {
        bool w = false, i = false, o = false;

        while (input >> buffer)
        {
            if (buffer == "input")
            {
                if (i)
                    return false;
                string contain = readUntilSemic(input);
                // cout << this->in_put[10] << endl;
                deriveContain(contain, this->in_put);
                i = true;
            }
            else if (buffer == "output")
            {
                if (o)
                    return false;
                string contain = readUntilSemic(input);
                deriveContain(contain, this->out_put);
                o = true;
            }
            else if (buffer == "wire")
            {
                if (w)
                    return false;
                string contain = readUntilSemic(input);
                deriveContain(contain, this->wire);
                w = true;
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

    while (input >> buffer)
    {

        if (buffer == "endmodule")
        {

            input.close();
            return true;
        }
        this->_gates[this->_gateIdx++] = getGateLine(input, buffer);
    }
}

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



