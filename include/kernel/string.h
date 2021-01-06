#pragma once
#include <kernel/vector.h>
#include <kernel/kernel_lib.h>

namespace conix {
namespace kernel {
namespace std {

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
                vector<char>(strlen(str), str)
        {  }

        string(const string& str) :
                vector<char>(str)
        {  }

        bool operator==(const string& str)
        {
                return !strcmp(this->mdata, str.mdata);
        }

        bool operator==(const char* str)
        {
                return !strcmp(this->mdata, str);
        }

        bool operator!=(const string& str)
        {
                return strcmp(this->mdata, str.mdata);
        }

        bool operator!=(const char* str)
        {
                return strcmp(this->mdata, str);
        }

        const char* c_str() const 
        {
                return this->data();
        }
};

}; // std
}; // kernel
}; // conix
