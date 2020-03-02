#pragma once
#include <kernel/types.h>
#include <kernel/base_container.h>

namespace conix {
namespace kernel {
namespace std {

template <typename T>
class serial_container : base_container<T>
{
protected:
        inline void set_memory_size(size_t s)
        {
                this->mmemory_size = s;
        }

        inline void inc_size()
        {
                ++this->msize;
        }

        inline void dec_size()
        {
                --this->msize;
        }

        inline size_t& get_memory_size_value()
        {
                return this->mmemory_size;
        }

public:
        serial_container() :
                base_container<T>()
        {  }

        explicit serial_container(size_t size) :
                base_container<T>(size)
        {  }

        serial_container(size_t size, const T &data) :
                base_container<T>(size, data)
        {  }

        serial_container(size_t size, const T* data) :
                base_container<T>(size, data)
        {  }

        serial_container(const serial_container &_serial_container) :
                base_container<T>(_serial_container)
        {  }

        ~serial_container() = default;

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

        inline size_t size() const
        {
                return this->msize;
        }

        inline size_t get_memory_size() const
        {
                return this->mmemory_size;
        }
};

}; // std
}; // kernel
}; // conix
