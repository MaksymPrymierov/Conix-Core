#pragma once
#include <kernel/types.h>
#include <kernel/memory.h>
#include <kernel/kernel_lib.h>
#include <kernel/base_container.h>

template <typename T>
class vector : public base_container<T>
{
private:
        T* mdata;

        void check_memory()
        {
                if (this->mmemory_size < this->msize + 1) {
                        T* tmp = new T[this->mmemory_size * 2];
                        memcpy(tmp, mdata, this->msize * sizeof(T));
                        delete mdata;
                        mdata = tmp;
                        this->mmemory_size *= 2;
                }
        }

public:
        vector() :
                base_container<T>(),
                mdata(nullptr)
        {  }

        vector(size_t size) :
                base_container<T>(size)
        {
                mdata = new T[size];
        }

        vector(size_t size, const T &data) :
                base_container<T>(size, data)
        {
                mdata = new T[size];
                for (size_t i = 0; i < size; ++i) {
                        mdata[i] = data;
                }
        }

        vector(size_t size, T* data) :
                base_container<T>(size, data)
        {
                mdata = new T[size];
                memcpy(mdata, data, size * sizeof(T));
        }

        vector(const vector &_vector) :
                base_container<T>(_vector)
        {
                mdata = new T[this->mmemory_size];
                memcpy(mdata, _vector.mdata, this->msize * sizeof(T));
        }

        ~vector()
        {
                mdata = 0;
                this->mmemory_size = 0;
                delete mdata;
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
                mdata[this->msize] = item;
                ++this->msize;
        }

        void insert(size_t index, const T& item)
        {
                check_memory();
                T* tmp = new T[this->msize - index];
                if (tmp != nullptr) {
                        memcpy(tmp, mdata + index, (this->msize - index) * 
                                sizeof(T));
                        mdata[index] = item;
                        memcpy(mdata + index + 1, tmp, (this->msize - index) *
                                sizeof(T));
                        delete tmp;
                } else {
                        mdata[index] = item;
                }
                ++this->msize;
        }

        void remove(size_t index)
        {
                if (index < this->msize - 1) {
                        memmove(mdata + index, mdata + index + 1,
                                (this->msize - index - 1) * sizeof(T));
                }
                --this->msize;
        }

        class iterator : public base_container<T>::iterator
        {
        protected:
                iterator(T* data) : base_container<T>::iterator(data) {  }
        public:
                iterator(const iterator& iter) : iterator(iter.data) {  }

                iterator& operator++()
                {
                        ++this->data;
                        return *this;
                }

                iterator& operator--()
                {
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

        typename base_container<T>::iterator begin()
        {
                return iterator(mdata);
        }

        typename base_container<T>::iterator end()
        {
                return iterator(mdata + this->msize + 1);
        }
};
