// fortest.cpp

#include <iostream>
// #include <fstream>
#include <cstring>
#include "stringFunc.h"
using namespace std;
int main()
{
    // string str("a1, a2, a5, 23,fs,a ");
    // string ans[10];
    // bool su = deriveContain(str, ans);
    // cout << su << endl;
    // cout << "ans:" << endl;
    // for (int i = 0;i<10;++i)
    // {
    //     if (ans[i].empty()) break;
    //     cout << ans[i] << endl;
    // }
    string str("111122333");
    size_t ptr = 0;
    bool su = strReach(str, ptr, '3',false);
    cout << su << ptr << endl;
    su = strPass(str, ptr, '2', false);
    cout << su << ptr << endl;
    su = strPass(str, ptr, '3', false);
    cout << su << ptr << endl;
    su = strPass(str, ptr, '2', false);
    cout << su << ptr << endl;
    cout << str << endl;
}