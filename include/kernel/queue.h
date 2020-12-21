#pragma once
#include <kernel/list.h>
#include <kernel/types.h>

namespace conix {
namespace kernel {
namespace std {

template <typename T>
class queue
{
private:
        list<T> q;

public:

        queue()
        {  }

        ~queue() = default;

        T& front() {
                return q[q.size() - 1];
        }

        T& back() {
                return q[0];
        }

        bool empty() const {
                return !q.size();
        }

        size_t size() const {
                return q.size();
        }

        void push(const T &data)
        {
                q.append(data);
        }

        void pop()
        {
                q.remove(q.end());
        }
};

}; // std
}; // kernel
}; // conix
