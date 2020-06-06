// fortest.cpp

#include <iostream>
#include <fstream>
#include <cstring>
#include "stringFunc.h"
#include "test.cpp"

using namespace std;
int main()
{
    // cout << (' '!='a') << endl;
    string input_file_name = "inoutTest.txt";
    ifstream input(input_file_name, ifstream::in);
    // string str[100];
    string str = readUntilSemic(input);
    cout << str << endl;
    // getModuleLine(input, str);
    // for (int i = 0;i<10;++i)
    // {
    //     if (str[i].empty())
    //         break;
    //     cout << str[i] << endl;
    // }

    // string str("a1, a2, a5, 23 ,  fs,a ");
    // string ans[10];
    // bool su;
    // bool su = deriveContain(str, ans);
    // cout << su << endl;
    // cout << "ans:" << endl;
    // for (int i = 0;i<10;++i)
    // {
    //     if (ans[i].empty()) break;
    //     cout << ans[i] << endl;
    // }
    // string str(" \t 111122333");
    // size_t ptr = str.size();
    // bool su;

    // // cout << (str[0]==' ') << endl;
    // su = strPassEmpty(str, --ptr, true);

    //     // su = strReach(str, ptr, '3', false);
    // cout << su << ptr << endl;
    // su = strReach(str, ptr, '1', true);
    // cout << su << ptr << endl;
    // // su = strReach(str, ptr, '1', false);
    // // cout << su << ptr << endl;
    // su = strReach(str, ptr, '2', false);
    // cout << su << ptr << endl;
    // su = strPass(str, ptr, '2', false);
    // cout << su << ptr << endl;
    // // su = strPass(str, ptr,',', ' ', false);
    // su = strPassEmpty(str, ptr);
    // cout << su << ptr << endl;
    // su = strPass(str, ptr, '1', false);
    // cout << su << ptr << endl;
    // cout << str << endl;
}