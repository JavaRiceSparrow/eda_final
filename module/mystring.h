#ifndef __MYSTRING_H__
#define __MYSTRING_H__

#include <iostream>
#include <vector>
using namespace std;


// abandan


class MyString
{
public:
    char* _str;
    vector<size_t> _idx;
    size_t _str_size;
    size_t _str_len;
    size_t _idx_size;
    size_t _idx_len;
    MyString(size_t char_size)
    {
        _str_size = char_size;
        _str_len = 0;
        // _idx = new size_t[_size + 1];
        _idx_size = 10;
        _idx.resize(_idx_size+1);
        _idx[0] = 0;
        _idx[1] = 0;
        _idx_len = 0;
    }
    bool append(const string& str)
    {
        size_t size = str.size();
        if ((size+_str_len) > _str_size )
        {
            cout << "No enough space in MyString!" << endl;
            return false;
        }
        if ()
        return true;
    }
    string &operator[](int i)
    {
        if (i > _idx_len)
        {
            cout << "Index out of bounds!" << endl;
            // return first element.
            return "";
        }

        return _str[i];
    }
    // bool readFile(string path);
    // void add();
    size_t _gateIdx;
    bool readFile(string path);

    private:
};

#endif //__MYSTRING_H__