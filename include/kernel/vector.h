#pragma once
#include <kernel/types.h>
#include <kernel/memory.h>
#include <kernel/kernel_lib.h>

template <typename T>
class vector
{
private:
        T* mdata;
        size_t msize;
        size_t mmemory_size;

        void check_memory()
        {
                if (mmemory_size < msize + 1) {
                        T* tmp = new T[mmemory_size * 2];
                        memcpy(tmp, mdata, msize * sizeof(T));
                        delete mdata;
                        mdata = tmp;
                        mmemory_size *= 2;
                }
        }

public:
        vector() :
                mdata(nullptr),
                msize(0),
                mmemory_size(0)
        {  }

        vector(size_t size) :
                msize(0),
                mmemory_size(size)
        {
                mdata = new T[msize];
        }

        vector(size_t size, const T &data) :
                msize(size),
                mmemory_size(size)
        {
                mdata = new T[msize];
                memset(mdata, data, sizeof(T));
        }

        vector(size_t size, const T* data) :
                msize(size),
                mmemory_size(size)
        {
                mdata = new T[msize];
                memcpy(mdata, data, msize);
        }

        vector(const vector &_vector) :
                msize(_vector.msize),
                mmemory_size(_vector.mmemory_size)
        {
                mdata = new T[mmemory_size];
                memcpy(mdata, _vector.data, msize);
        }

        ~vector()
        {
                mdata = 0;
                mmemory_size = 0;
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
                mdata[msize] = item;
                ++msize;
        }

        void insert(size_t index, const T& item)
        {
                check_memory();
                T* tmp = new T[msize - index];
                if (tmp != nullptr) {
                        memcpy(tmp, mdata + index, (msize - index) * 
                                sizeof(T));
                        mdata[index] = item;
                        memcpy(mdata + index + 1, tmp, (msize - index) *
                                sizeof(T));
                        delete tmp;
                } else {
                        mdata[index] = item;
                }
                ++msize;
        }

        size_t size() const
        {
                return msize;
        }
};
