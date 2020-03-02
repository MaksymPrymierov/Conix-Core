#pragma once
#include <kernel/types.h>

namespace conix {
namespace kernel {
namespace std {

template <typename T>
class base_container
{
protected:
        size_t msize;
        size_t mmemory_size;

        void set_memory_size(size_t size)
        {
                mmemory_size = size;
        }

public:
        base_container() :
                msize(0),
                mmemory_size(0)
        {  }

        explicit base_container(size_t size) :
                msize(0),
                mmemory_size(size)
        {  }

        base_container(size_t size, const T &data) :
                msize(size),
                mmemory_size(size)
        {  }

        base_container(size_t size, const T *data) :
                msize(size),
                mmemory_size(size)
        {  }

        base_container(const base_container &_base_container) :
                msize(_base_container.msize),
                mmemory_size(_base_container.mmemory_size)
        {  }

        ~base_container() = default;

        size_t size() const
        {
                return msize;
        }

        size_t get_memeory_size() const
        {
                return mmemory_size;
        }
}; // base_container

}; // std
}; // kernel
}; // conix
