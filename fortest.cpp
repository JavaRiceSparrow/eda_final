// fortest.cpp

#include <iostream>
#include <fstream>
#include <cstring>
#include "stringFunc.h"
#include "verRead.h"
// #include "module.h"
// #include <vector>

using namespace std;
int main()
{
    // for (gateType type = BUF; type != EOE; type = gateType(type + 1))
    // {
    //     cout << gTypeTest[type] << endl;
    // }
    // // cout << (' '!='a') << endl;
    string a = "a,  b, c,2,52,43958v ";
    string* str_arr = new string[25];
    deriveContain(a, str_arr, 25);
    for (int i = 0; i < 25; ++i)
    {
        string &str = str_arr[i];
        if (str.empty())
            break;
        cout << str << "__";
    }
    cout << endl;
    // string input_file_name = "inoutTest.txt";
    // ifstream input(input_file_name, ifstream::in);
    // string str[100];
    // string name;
    // string buffer;
    // input >> buffer;
    // vector<gate> _gate;
    // if (buffer != "module") return 300;
    // getModuleLine(input, name, str);
    
    // while (input >> buffer)
    // {
    //     if (buffer == "input")
    //     {
    //         string contain = readUntilSemic(input);
    //         deriveContain(contain, in_put);
    //     }
    //     else if (buffer == "output")
    //     {
    //         string contain = readUntilSemic(input);
    //         deriveContain(contain, out_put);
    //     }
    //     else if (buffer == "wire")
    //     {
    //         string contain = readUntilSemic(input);
    //         deriveContain(contain, wire);
    //     }
    //     else if (buffer == "reg")
    //     {
    //         string contain = readUntilSemic(input);
    //         deriveContain(contain, reg);
    //     }
    //     else break;
    // }

    // while (input >> buffer)
    // {
    //     if (buffer == "endmodule")
    //     {
    //         finish();
    //     }
    // }
    // cout << name << endl;
    
}