#pragma once
#include <kernel/types.h>
#include <kernel/memory.h>
#include <kernel/kernel_lib.h>
#include <kernel/serial_container.h>

namespace conix {
namespace kernel {
namespace std {

template <typename T>
class vector : public serial_container<T>
{
protected:
        T* mdata;

        void check_memory()
        {
                if ((this->get_memory_size() < this->size() + 1) && mdata != nullptr) {
                        T* tmp = new T[this->get_memory_size() * 2];
                        memcpy(tmp, mdata, this->size() * sizeof(T));
                        delete mdata;
                        mdata = tmp;
                        this->get_memory_size_value() *= 2;
                } else if (mdata == nullptr) {
                        mdata = new T;
                        this->get_memory_size_value() = 1;
                }
        }

public:
        vector() :
                serial_container<T>(),
                mdata(nullptr)
        {  }

        vector(size_t size) :
                serial_container<T>(size)
        {
                mdata = new T[size];
        }

        vector(size_t size, const T &data) :
                serial_container<T>(size, data)
        {
                mdata = new T[size];
                for (size_t i = 0; i < size; ++i) {
                        mdata[i] = data;
                }
        }

        vector(size_t size, const T* data) :
                serial_container<T>(size, data)
        {
                mdata = new T[size];
                memcpy(mdata, data, size * sizeof(T));
        }

        vector(const vector &_vector) :
                serial_container<T>(_vector)
        {
                mdata = new T[this->get_memory_size()];
                memcpy(mdata, _vector.mdata, this->size() * sizeof(T));
        }

        void clear()
        {
                this->set_size(0);
                this->set_memory_size(0);
                delete mdata;
                mdata = nullptr;
        }

        ~vector()
        {
                clear();
        }

        T& at(size_t n)
        {
                return mdata[n];
        }

        T& operator[](size_t n)
        {
                return at(n);
        }

        void append(const T& item)
        {
                check_memory();
                mdata[this->size()] = item;
                this->inc_size();
        }

        void insert(size_t index, const T& item)
        {
                check_memory();
                T* tmp = new T[this->size() - index];
                if (tmp != nullptr) {
                        memcpy(tmp, mdata + index, (this->size() - index) * 
                                sizeof(T));
                        mdata[index] = item;
                        memcpy(mdata + index + 1, tmp, (this->size() - index) *
                                sizeof(T));
                        delete tmp;
                } else {
                        mdata[index] = item;
                }
                this->inc_size();
        }

        void remove(size_t index)
        {
                if (index < this->size() - 1) {
                        memmove(mdata + index, mdata + index + 1,
                                (this->size() - index - 1) * sizeof(T));
                }
                this->dec_size();
        }

        class iterator : public serial_container<T>::iterator
        {
        private:
                size_t current_index;
        protected:
                iterator(T* data) : serial_container<T>::iterator(data) {  }
        public:
                iterator& operator++()
                {
                        ++current_index;
                        ++this->data;
                        return *this;
                }

                iterator& operator--()
                {
                        --current_index;
                        --this->data;
                        return *this;
                }

                bool operator!=(const iterator& iter)
                {
                        return this->data != iter.data;
                }

                bool operator==(const iterator& iter)
                {
                        return this->data == iter.data;
                }

                friend class vector;
        };

        iterator begin()
        {
                iterator iter(mdata);
                iter.current_index = 0;
                return iter;
        }

        iterator end()
        {
                iterator iter(mdata + this->size());
                iter.current_index = this->size() - 1;
                return iter;
        }

        void insert(const iterator& iter, const T& item)
        {
                insert(iter.current_index, item);
        }

        void remove(const iterator& iter)
        {
                remove(iter.current_index);
        }

        T* data() const
        {
                return mdata;
        }
};

}; // std
}; // kernel
}; // conix
