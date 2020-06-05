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
            if (str[ptr] != k1)
                return true;
            if (is_k2 && str[ptr] != k2)
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
            if (str[ptr] != k1)
                return true;
            if (is_k2 && str[ptr] != k2)
                return true;
            --ptr;
        }
        // if (ptr != neg_1)
        //     return true;
        // return false;
    }
}

bool strPassEmpty(const string &str, size_t &ptr)
{
    return strPass(str, ptr, ' ', '\t');
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
            if (str[ptr] == k1)
                return true;
            if (is_k2 && str[ptr] == k2)
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
            if (str[ptr] == k1)
                return true;
            if (is_k2 && str[ptr] == k2)
                return true;
            --ptr;
        }
        // if (ptr != neg_1)
        //     return true;
        // return false;
    }
}

bool strPassEmpty(const string &str, size_t &ptr)
{
    return strPass(str, ptr, ' ', '\t');
}

bool deriveContain(const string &str, string value[])
{
    size_t froPtr = 0, endPtr = 0;
    // strPass(str, ptr, ' ', '\t');
    if (!strPass(str, froPtr, ' ', '\t'))
        cout << froPtr << endl;
    endPtr = froPtr;
    size_t valueIdx = 0;
    while (strReach(str, endPtr, ' ', ','))
    {
        value[valueIdx].assign(str, froPtr, endPtr-froPtr);
        froPtr = endPtr;
        if (!strPassEmpty(str, froPtr))
            cout << froPtr << endl;
        string interval;
        interval.assign(str, endPtr, froPtr-endPtr);
        if (strCount(interval, ',') != 1)
        {
            cout << endPtr << ' ' << froPtr << endl;
            cout << "No ','!" << endl;
            return false;
        }
        endPtr = froPtr;
    }
    return true;
}
