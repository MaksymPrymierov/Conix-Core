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

                map_node(const K& k) :
                        key{k}
                {  }

                map_node(const K& k, const K& d) :
                        key{k},
                        data{d}
                {  }

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
                bt.insert(map_node(key, data));
        }

        void clear()
        {
                bt.clear();
        }

        void erase(const K& key)
        {
                bt.erase(map_node(key));
        }

        const T& at(const K& key)
        {
                return bt.extract(map_node(key))->data.data;
        }

        const T& operator[](const K& key)
        {
                return at[key];
        }

        bool contains(const T& item)
        {
                return this->extract(item) != nullptr ? true : false;
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
