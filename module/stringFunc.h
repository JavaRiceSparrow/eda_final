#ifndef __STRING_FUNC_H__
#define __STRING_FUNC_H__

#include <iostream>
// #include <fstream>
#include <cstring>




// #include "module.h"

using namespace std;
// #define size_t_max numeric_limits<size_t>::max()


bool _strpass(const string &str, size_t &ptr, const char &k1, const char &k2, bool input_k2, bool back) ;
bool strPass(const string &str, size_t &ptr, const char &keyword1, const char &keyword2, bool back = false)
{
    return _strpass(str,ptr,keyword1,keyword2,true,back);
}
bool strPass(const string &str, size_t &ptr, const char &keyword1, bool back = false)
{
    return _strpass(str, ptr, keyword1, ' ', false, back);
}
bool _strpass(const string &str, size_t &ptr, const char &k1, const char &k2, bool input_k2, bool back)
{
    // cout << "'" << k1 << "','" << k2 << "'" << endl;
    size_t length = str.size();

    bool is_k2 = input_k2;
    if (is_k2) if (k1 == k2) is_k2 = false;

    if (!back)
    {
        if (ptr >= length)
            return false;

        while (ptr < length)
        {
            // cout << "test:" << (str[ptr] != k1) << is_k2 << (str[ptr] != k2) << endl;
            if (is_k2)
            {
                // cout << "FUCK!" << endl;
                if (str[ptr] != k1 && str[ptr] != k2)
                    return true;
            }
            else
            {
                if (str[ptr] != k1)
                    return true;
            }

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
        if (ptr >= length)
            return false;

        while (ptr >= 0)
        {
            // cout << ptr << ", " << (str[ptr] != k1) << endl;
            if (ptr == neg_1)
            {

                // cout <<"三小啦" << endl;
                return false;
            }
            if (is_k2)
            {
                // cout << "FUCK!" << endl;
                if (str[ptr] != k1 && str[ptr] != k2)
                    return true;
            }
            else 
            {
                if (str[ptr] != k1)
                    return true;
            }
            --ptr;
        }
        ptr == length;
        // if (ptr != neg_1)
        //     return true;
        return false;
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

string removeHeadSpace(string str)
{
    size_t ptr = 0;
    strPassEmpty(str, ptr);
    string str2;
    str2.assign(str, ptr);
    return str2;
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



#endif //__STRING_FUNC_H__
