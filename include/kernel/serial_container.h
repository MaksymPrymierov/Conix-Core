#pragma once
#include <kernel/types.h>

namespace conix {
namespace kernel {
namespace std {

template <typename T>
class serial_container
{
protected:
        size_t msize;
        size_t mmemory_size;

public:
        serial_container() :
                msize(0),
                mmemory_size(0)
        {  }

        explicit serial_container(size_t size) :
                msize(0),
                mmemory_size(size)
        {  }

        serial_container(size_t size, const T &data) :
                msize(size),
                mmemory_size(size)
        {  }

        serial_container(size_t size, const T* data) :
                msize(size),
                mmemory_size(size)
        {  }

        serial_container(const serial_container &_serial_container) :
                msize(_serial_container.msize),
                mmemory_size(_serial_container.mmemory_size)
        {  }

        ~serial_container() = default;

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

                friend class serial_container;
        };

        virtual void insert(const iterator& iter, const T& item) {  }
        virtual void remove(const iterator& iter) {  }
};

}; // std
}; // kernel
}; // conix
