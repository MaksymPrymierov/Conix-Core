#pragma once
#include <kernel/list.h>
#include <kernel/types.h>

namespace conix {
namespace kernel {
namespace std {

template <typename T>
class set
{
private:
        list<T> s;

        bool is_valid_item(T& item)
        {
                for (const auto& i : s) {
                        if (item == i) {
                                return false;
                        }
                }
                return true;
        }

public:

        set()
        {  }

        ~set() = default;

        void insert(T& item)
        {
                if (is_valid_item(item)) {
                        s.append(item);
                }
        }

        

};

}; // std
}; // kernel
}; // conix