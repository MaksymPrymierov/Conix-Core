#pragma once
#include <kernel/types.h>

template <typename T>
class list   
{
private:
        struct list_node
        {
                list_node* next;
                list_node* priv;
                T data;
        };

        list_node* top;
        list_node* bottom;
        size_t msize;

        list_node* search_node(size_t n)
        {
                list_node *node = top;
                for (size_t i = 0; i < n; ++i) {
                        node = node->next;
                }
                return node;
        }

public:

        list() :
                top(nullptr),
                bottom(nullptr),
                msize(0)
        {  }

        ~list()
        {
                item_node* node = top;
                for (item_node* i = top; i != nullptr; i = top) {
                        top = top->next;
                        delete i;
                }
        }

        class iterator 
        {
        private:
                list_node *current;
        public:
                iterator() : 
                        current(nullptr)
                {  }

                iterator(list_node* p) :
                        current(p)
                {  }

                iterator& operator ++()
                {
                        current = current->next;
                        return *this;
                }

                iterator& operator --()
                {
                        current = current->priv;
                        return *this;
                }

                T& operator *()
                {
                        return current->data;
                }

                void operator =(const iterator& iter)
                {
                        current = iter.current;
                }

                bool operator !=(const iterator &iter)
                {
                        return current != iter.current ? true : false;
                }

                bool operator ==(iterator iter)
                {
                        return current == iter.current ? true : false;
                }
        };

        void append(const T &data)
        {
                if (msize == 0) {
                        top = new list_node;
                        bottom = top;
                        
                        top->next = nullptr;
                        top->priv = nullptr;
                        top->data = data;
                        msize = 1;
                } else {
                        bottom->next = new list_node;
                        bottom->next->next = nullptr;
                        bottom->next->priv = bottom;
                        bottom->next->data = data;
                        bottom = bottom->next;
                        ++msize;
                }
        }

        T& at(unsigned int number)
        {
                return search_node(number)->data;
        }

        T& operator [](unsigned int number)
        {
                return at(number);
        }

        iterator begin()
        {
                return iterator(top);
        }

        iterator end()
        {
                return iterator(bottom->next);
        }

        size_t get_size() const
        {
                return msize;
        }

        void remove(size_t n)
        {
                list_node* node = search_node(n);

                if (node != top && node != bottom) {
                        node->priv->next = node->next;
                        node->next->priv = node->priv;
                } else if (node == top) {
                        top = top->next;
                        top->priv = nullptr;
                } else {
                        bottom = bottom->priv;
                        bottom->next = nullptr;
                }

                --msize;
                delete node;
        }

        void insert(size_t n, const T &data)
        {
                list_node* node = search_node(n);

                if (node == top) {
                        top->priv = new list_node;
                        top->priv->next = top;
                        top = top->priv;
                        top->data = data;
                } else if (node == nullptr) {
                        bottom->next = new list_node;
                        bottom = bottom->next;
                        bottom->data = data;
                } else {
                        list_node* tmp = new list_node;
                        tmp->priv = node->priv;
                        tmp->next = node;
                        node->priv->next = tmp;
                        node->priv = tmp;
                        tmp->data = data;
                }

                ++msize;
        }
};

