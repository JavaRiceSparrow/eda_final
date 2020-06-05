#include <iostream>
// #include <fstream>
#include <cstring>

// #include "module.h"

using namespace std;
#define size_t_max numeric_limits<size_t>::max()

bool strPassEmpty(const string &str, size_t &ptr)
{
    return strPass(str, ptr, ' ', '\t');
}

bool strPass(const string &str, size_t &ptr, const char &keyword1, const char &keyword2, bool back = false)
{
    /*
    * usage: Find the first char in str
    * after the (ptr)th char
    * which is not equal to char keyword.
    * Change ptr to the idx of object.
    */
    size_t length = str.size();
    size_t neg_1 = 0;
    --neg_1;

    if (!back)
    {
        if (ptr >= length)
            return false;

        while (ptr < length)
        {
            if (str[ptr] != keyword1 || str[ptr] != keyword2)
                break;
            ++ptr;
        }
        if (ptr != length)
            return true;
        return false;
    }
    else
    {
        if (ptr > length)
            return false;

        while (ptr >=0)
        {
            if (ptr == neg_1)
                return false;
            if (str[ptr] != keyword1 || str[ptr] != keyword2)
                return true;
            --ptr;
        }
        // if (ptr != neg_1)
        //     return true;
        // return false;
    }
}
bool strPass(const string &str, size_t &ptr, const char &keyword1, bool back = false)
{
    /*
    * usage: Find the first char in str
    * after the (ptr)th char
    * which is not equal to char keyword.
    * Change ptr to the idx of object.
    */
    size_t length = str.size();

    if (ptr >= length)
        return false;

    while (ptr < length)
    {
        if (str[ptr] != keyword1 )
            break;
        ++ptr;
    }
    if (ptr != length)
        return true;
    return false;
}

bool strReach(const string &str, size_t &ptr, const char &keyword1, const char &keyword2)
{
    /*
    * usage: Find the first char in str
    * after the (ptr)th char
    * which is equal to char keyword.
    * Change ptr to the idx of object.
    */
    size_t length = str.size();

    if (ptr >= length)
        return false;

    while (ptr < length)
    {
        if (str[ptr] == keyword1 || str[ptr] == keyword2)
            break;
        ++ptr;
    }
    if (ptr != length)
        return true;
    return false;
}
bool strpReach(const string &str, size_t &ptr, const char &keyword1 = ' ')
{
    /*
    * usage: Find the first char in str
    * after the (ptr)th char
    * which is equal to char keyword.
    * Change ptr to the idx of object.
    */
    size_t length = str.size();

    if (ptr >= length)
        return false;

    while (ptr < length)
    {
        if (str[ptr] == keyword1)
            break;
        ++ptr;
    }
    if (ptr != length)
        return true;
    return false;
}

size_t strCount(const string &str, const char &keyword)
{
    /*
    * usage: Count the number of chars in str
    * return number.
    */
    size_t num = 0;

    for (size_t i = 0;i < str.size(); ++i)
    {
        if (str[i]==keyword) ++num;
    }
    return num;
}
size_t strfind(const string *str, const string *keywords)
{
    // if
    size_t str_size = (sizeof(str) / sizeof(*str));
    return 0;
}
