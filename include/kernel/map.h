#pragma once
#include <kernel/types.h>
#include <kernel/memory.h>

namespace conix {
namespace kernel {
namespace std {

template <typename K, typename T>
class map   
{
private:
        struct map_node {
                K key;
                T data;

                bool operator==(const map_node& rd)
                {
                        return key == rd.key;
                }

                bool operator!=(const map_node& rd)
                {
                        return key != rd.key;
                }

                bool operator>(const map_node& rd)
                {
                        return key > rd.key;
                }

                bool operator>=(const map_node& rd)
                {
                        return key >= rd.key;
                }

                bool operator<(const map_node& rd)
                {
                        return key < rd.key;
                }

                bool operator<=(const map_node& rd)
                {
                        return key <= rd.key;
                }
        };

        binary_tree<map_node> bt;

public:
        map()
        {  }

        ~map() = default;

        void insert(const K& key, const T& data)
        {
                map_node n;

                n.key = key;
                n.data = data;

                bt.insert(n);
        }

        void clear()
        {
                bt.clear();
        }

        void erase(const K& key)
        {
                map_node n;

                n.key = key;

                bt.erase(n);
        }

        const T& at(const K& key)
        {
                map_node n;

                n.key = key;

                auto b = bt.extract(n);

                if (b) {
                        return b->data.data;
                }

                return bt.extract(n)->data.data;
        }

        const T& operator[](const K& key)
        {
                return at(key);
        }

        bool contains(const K& key)
        {
                map_node n;

                n.key = key;

                return this->extract(n) != nullptr ? true : false;
        }

        size_t size() const
        {
                return bt.size();
        }

        bool empty() const
        {
                return bt.empty();
        }
};

}; // std
}; // kernel
}; // conix
