#ifndef __STRING_FUNC_H__
#define __STRING_FUNC_H__

#include <iostream>
// #include <fstream>
#include <cstring>




// #include "module.h"

using namespace std;
// #define size_t_max numeric_limits<size_t>::max()

bool _strpass(const string &str, size_t &ptr, const char &k1, const char &k2, bool is_k2, bool back) ;
bool strPass(const string &str, size_t &ptr, const char &keyword1, const char &keyword2, bool back = false)
{
    return _strpass(str,ptr,keyword1,keyword2,true,back);
}
bool strPass(const string &str, size_t &ptr, const char &keyword1, bool back = false)
{
    return _strpass(str, ptr, keyword1, ' ', false, back);
}
bool _strpass(const string &str, size_t &ptr, const char &k1, const char &k2, bool is_k2, bool back)
{
    size_t length = str.size();

    if (!back)
    {
        if (ptr >= length)
            return false;

        while (ptr < length)
        {
            // cout << "test:" << (str[ptr] != k1) << is_k2 << (str[ptr] != k2) << endl;
            if (str[ptr] != k1 && !(is_k2 && str[ptr] == k2))
                return true;
            // if (str[ptr] != k1 && str[ptr] != k2)
            //     return true;
                // if
                //     return true;
                ++ptr;
        }
        // if (ptr != length)
        //     return true;
        return false;
    }
    else
    {
        size_t neg_1 = 0;
        --neg_1;
        if (ptr > length)
            return false;

        while (ptr >= 0)
        {
            if (ptr == neg_1)
                return false;
            if (str[ptr] != k1 && (is_k2 && str[ptr] != k2))
                return true;
            --ptr;
        }
        // if (ptr != neg_1)
        //     return true;
        // return false;
    }
}

bool strPassEmpty(const string &str, size_t &ptr, bool back = false)
{
    // return strPass(str, ptr, ' ', '\t', back);
    return strPass(str, ptr, ' ', back);
}

bool _strreach(const string &str, size_t &ptr, const char &k1, const char &k2, bool is_k2, bool back);
bool strReach(const string &str, size_t &ptr, const char &keyword1, const char &keyword2, bool back = false)
{
    return _strreach(str, ptr, keyword1, keyword2, true, back);
}
bool strReach(const string &str, size_t &ptr, const char &keyword1, bool back = false)
{
    return _strreach(str, ptr, keyword1, ' ', false, back);
}
bool _strreach(const string &str, size_t &ptr, const char &k1, const char &k2, bool is_k2, bool back)
{
    size_t length = str.size();

    if (!back)
    {
        if (ptr >= length)
            return false;

        while (ptr < length)
        {
            if (str[ptr] == k1 || (is_k2 && str[ptr] == k2))
                return true;
            ++ptr;
        }
        // if (ptr != length)
        //     return true;
        return false;
    }
    else
    {
        size_t neg_1 = 0;
        --neg_1;
        if (ptr > length)
            return false;

        while (ptr >= 0)
        {
            if (ptr == neg_1)
                return false;
            if (str[ptr] == k1 || (is_k2 && str[ptr] == k2))
                return true;
            --ptr;
        }
        // if (ptr != neg_1)
        //     return true;
        // return false;
    }
}

size_t strCount(const string &str, const char &key)
{
    size_t num = 0;
    for(int i = 0;i< str.size();++i)
    {
        if (str[i] == key)
            ++num;
    }
    return num;
}

bool deriveContain(const string &contain, string value[])
{
    string str = contain;
    for (int i = 0; i < str.size() ; ++i)
        if (str[i] == '\t') str[i] = ' ';

    size_t froPtr = 0, endPtr = 0;
    // strPass(str, ptr, ' ', '\t');
    if (!strPass(str, froPtr, ' ', '\t'))
        cout << "froPtr: " << froPtr << endl;
    endPtr = froPtr+1;
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
        value[valueIdx++].assign(str, froPtr, endPtr-froPtr);
        froPtr = endPtr+1;
        // if (!)
        //     cout << "froPtr: " << froPtr << endl;
        
    }
    return true;
}

#endif //__STRING_FUNC_H__
