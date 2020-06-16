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
    string a = "a,  b, c,2,52,43958v";

    string b = "1234";
    string c = a+b;
    cout << c << endl;
    
}