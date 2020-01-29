#pragma once
#include <kernel/vector.h>

class string : public vector<char>
{
public:
        string() :
                vector<char>()
        {  }

        string(size_t size) :
                vector<char>(size)
        {  }

        string(size_t size, char c) :
                vector<char>(size, c)
        {  }

        string(const char* str) :
                vector<char>(strlen(str), data)
        {  }

        string(const string& str) :
                vector<char>(str)
        {  }
};
