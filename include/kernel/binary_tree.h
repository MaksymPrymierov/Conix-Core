#pragma once
#include <kernel/types.h>
#include <kernel/memory.h>

namespace conix {
namespace kernel {
namespace std {

template <typename T>
class binary_tree   
{
private:
        struct binary_tree_node
        {
                T data;
                binary_tree_node* priv = nullptr;
                binary_tree_node* left = nullptr;
                binary_tree_node* right = nullptr;
        };

        binary_tree_node* root;
        size_t msize;

        binary_tree_node* get_max_node(binary_tree_node* node)
        {
                binary_tree_node* ret = nullptr;

                while (!ret) {
                        if (node->right) {
                                node = node->right;
                        } else {
                                ret = node;
                        }
                }

                return ret;
        }

public:
        binary_tree() :
                root{nullptr},
                msize{0}
        {  }

        ~binary_tree()
        {
                clear();
        }

        void insert(const T& data)
        {
                binary_tree_node* curent_node;

                if (root == nullptr) {
                        root = new binary_tree_node;
                        root->data = data;
                        ++msize;
                        return;
                }

                curent_node = root;
                while (curent_node) {
                        if (curent_node->data > data) {
                                if (curent_node->left == nullptr) {
                                        curent_node->left = new binary_tree_node;
                                        curent_node->left->data = data;
                                        curent_node->left->priv = curent_node;
                                        curent_node = nullptr;
                                        ++msize;
                                } else {
                                        curent_node = curent_node->left;
                                }
                        } else if (curent_node->data < data) {
                                if (curent_node->right == nullptr) {
                                        curent_node->right = new binary_tree_node;
                                        curent_node->right->data = data;
                                        curent_node->right->priv = curent_node;
                                        curent_node = nullptr;
                                        ++msize;
                                } else {
                                        curent_node = curent_node->right;
                                }
                        } else {
                                curent_node = nullptr;
                        }
                }
        }

        void clear()
        {
                binary_tree_node* curent_node = root;
                binary_tree_node* priv_node = nullptr;

                while (curent_node) {
                        if (curent_node->left != nullptr) {
                                curent_node = curent_node->left;
                        } else if (curent_node->right != nullptr) {
                                curent_node = curent_node->right;
                        } else {
                                priv_node = curent_node;
                                curent_node = curent_node->priv;
                                if (curent_node && curent_node->left == priv_node) {
                                        curent_node->left = nullptr;
                                } else if (curent_node && curent_node->right == priv_node) {
                                        curent_node->right = nullptr;
                                }
                                delete priv_node;
                        }
                }
                msize = 0;
                root = nullptr;
        }

        binary_tree_node* extract(const T& item)
        {
                binary_tree_node* curent_node = root;
                binary_tree_node* ret = nullptr;

                while (!ret) {
                        if (curent_node->data > item && curent_node->left) {
                                curent_node = curent_node->left;
                        } else if (curent_node->data < item && curent_node->right) {
                                curent_node = curent_node->right;
                        } else if (curent_node->data == item) {
                                ret = curent_node;
                        } else {
                                return nullptr;
                        }
                }

                return ret;
        }

        void erase(const T& item)
        {
                binary_tree_node* curent_node = extract(item);
                binary_tree_node* delete_node = curent_node;

                if (root == nullptr || curent_node == nullptr) {
                        return;
                }

                if (delete_node->left) {
                        curent_node = delete_node->left;
                        curent_node->priv = delete_node->priv;

                        if (!curent_node->priv) {
                                root = curent_node;
                        } else if (curent_node->priv->left == delete_node) {
                                curent_node->priv->left = curent_node;
                        } else {
                                curent_node->priv->right = curent_node;
                        }

                        delete_node->right->priv = get_max_node(curent_node);
                        delete_node->right->priv->right = delete_node->right;
                } else if (delete_node->right) {
                        curent_node = delete_node->right;
                        curent_node->priv = delete_node->priv;

                        if (!curent_node->priv) {
                                root = curent_node;
                        } else if (curent_node->priv->left == delete_node) {
                                curent_node->priv->left = curent_node;
                        } else {
                                curent_node->priv->right = curent_node;
                        }

                } else if (delete_node->priv) {
                        curent_node = delete_node->priv;
                        if (delete_node == curent_node->left) {
                                curent_node->left = nullptr;
                        } else {
                                curent_node->right = nullptr;
                        }
                } else {
                        root = nullptr;
                }

                --msize;
                delete delete_node;
        }

        bool contains(const T& item)
        {
                return this->extract(item) != nullptr ? true : false;
        }

        size_t size() const
        {
                return msize;
        }

        bool empty() const
        {
                return !root;
        }
};

}; // std
}; // kernel
}; // conix
