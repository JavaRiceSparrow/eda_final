// #include<cstdlib>
#include<iostream>
#include <fstream>
#include<cstring>

// #include "module.h"
#include "stringFunc.h"

using namespace std;

char c1[] = "asd";

char c2[] = "asd";

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

bool getModuleLine(ifstream & input, string port[]){
    /*
    * "module module1(i1,i2,i3...);"
    * |
    * V
    * "module1(i1,i2,i3...);"
    */
    string buffer;

    input >> buffer;
    if (buffer != "module")
    {
        cout << buffer << endl;
        cout << "It's not a module!" << endl;
        return false;
    }

    
    /*
    * " module1(i1,i2,i3...);"
    * |
    * V
    * "i1,i2,i3..."
    */

    size_t froPtr = 0, endPtr = 0;
    getline(input, buffer);
    string str1, contain;
    strPassEmpty(buffer, froPtr);
    str1.assign(buffer, froPtr, buffer.size()-froPtr);

    froPtr = 0, endPtr = str1.size()-2;
    if (!strReach(str1,froPtr,'(',false) || !strReach(str1,endPtr,')',true))
    {
        cout << buffer << '\n';
        cout << "() is missing!" << endl;
    }
    else if (froPtr >= endPtr)
    {
        cout << "() is wrong!" << endl;
    }
    else{
        contain.assign(str1,++froPtr, --endPtr-froPtr);
        if (strCount(contain, '(') || strCount(contain, ')'))
        {
            cout << "() is too many!" << endl;
        }
    }

    deriveContain(contain, port);
}

bool getInput(ifstream &input, string in[], string port[])
{
    string buffer;

    input >> buffer;
    if (buffer != "input")
    {
        cout << buffer << endl;
        cout << "It should be a input!" << endl;
        return false;
    }
    string contain("");
    size_t froPtr, endPtr;
    while(getline(input, buffer))
    {
        froPtr = (endPtr = buffer.size());
        if (strReach(buffer, endPtr, ';', true))
        {
            strPassEmpty(buffer, froPtr, true);
            if (froPtr != endPtr)
            {
                string str_t;
                str_t.assign(buffer,endPtr,  froPtr-endPtr);
                cout << "string " << str_t << " behind ';'!" << endl;
                return false;
            }
            else{
                contain.append(buffer,0,endPtr);
                deriveContain(contain, in);
                return true;
            }
        }
        contain.append(buffer, 0, endPtr);
    }
    cout << "Why wryyyyyyyy~" << endl;
    return false;
    

}
