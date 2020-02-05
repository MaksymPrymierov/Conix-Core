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

        base_container(size_t size, const T* data) :
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

        virtual T& at(size_t n);
        virtual void append(const T& item) {  }
        virtual void insert(size_t index, const T& item) {  }
        virtual void remove(size_t index) {  }

        class iterator
        {
        protected:
                T* data;
                iterator(T* _data) : data(_data) {  }
        public:
                virtual iterator& operator++() { return *this; }
                virtual iterator& operator--() { return *this; }
                virtual T& operator*() { return *data; }
                virtual bool operator!=(const iterator& iter) { return false; }
                virtual bool operator==(const iterator& iter) { return false; }

                friend class base_container;
        };

        virtual void insert(const iterator& iter, const T& item);
        virtual void remove(const iterator& iter);
};

}; // std
}; // kernel
}; // conix
