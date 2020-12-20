#pragma once
#include <kernel/test.h>
#include <kernel/list.h>

namespace conix {
namespace kernel {
namespace tests {

class test_list : public test
{
protected:
        void list_entity_test()
        {
                add_test();
                message() << "list() starting...\n";
                
                std::list<int> l;
                
                if (!assert_eq<size_t>(l.size(), 0)) {
                        fail();
                        return;
                } 
                pass();
        }

        void append_test()
        {
                add_test();
                message() << "append(const T&) starting...\n";

                std::list<int> l;
                int data[6] = {0, 1, 2, 3, 4, 5};

                for (size_t i = 0; i < 6; ++i) {
                        l.append(data[i]);
                }

                if (!assert_eq<size_t>(l.size(), 6)) {
                        fail();
                        return;
                }

                for (size_t i = 0; i < l.size(); ++i) {
                        if (!assert_eq<int>(l[i], data[i])) {
                                fail();
                                return;
                        }
                }
                pass();
        }

        void insert_test()
        {
                add_test();
                message() << "insert(size_t, const T&) starting...\n";

                std::list<size_t> l;

                for (size_t i = 0; i < 6; ++i) {
                        l.insert(i, i);
                }

                if (!assert_eq<size_t>(l.size(), 6)) {
                        fail();
                        return;
                }

                for (size_t i = 0; i < l.size(); ++i) {
                        if (!assert_eq(l[i], i)) {
                                fail();
                                return;
                        }
                }
                pass();
        }

        void remove_test()
        {
                add_test();
                message() << "remove(size_t) starting...\n";

                int data0[6] = {0, 1, 2, 3, 4, 5};
                int data1[3] = {1, 2, 4};
                std::list<int> l;

                for (size_t i = 0; i < 6; ++i) {
                        l.append(data0[i]);
                }

                l.remove(5);
                l.remove(0);
                l.remove(2);

                if (!assert_eq<size_t>(l.size(), 3)) {
                        fail();
                        return;
                }

                for (size_t i = 0; i < l.size(); ++i) {
                        if (!assert_eq<int>(l[i], data1[i])) {
                                fail();
                                return;
                        }
                }
                pass();
        }

        void iterator_test()
        {
                add_test();
                message() << "iterator starting...\n";

                int data[6] = {0, 1, 2, 3, 4, 5};
                std::list<int> l;

                for (size_t i = 0; i < 6; ++i) {
                        l.append(data[i]);
                }
                
                size_t i = 0;
                for (auto iter = l.begin(); iter != l.end(); ++iter) {
                        if (!assert_eq(*iter, data[i])) {
                                fail();
                                return;
                        }
                        if (i < 6) {
                                ++i;
                        }
                }
                pass();
        };

        void iterator_insert_test()
        {
                add_test();
                message() << "insert(const iterator&, const T&) starting...\n";

                std::list<size_t> l;
                std::list<size_t>::iterator iter = l.begin();

                for (int i = 0; i < 6; ++i) {
                        l.insert(iter, i);
                        ++iter;
                }

                if (!assert_eq<size_t>(l.size(), 6)) {
                        fail();
                        return;
                }

                for (size_t i = 0; i < l.size(); ++i) {
                        if (!assert_eq(l[i], i)) {
                                fail();
                                return;
                        }
                }
                pass();
        }

        void iterator_remove_test()
        {
                add_test();
                message() << "remove(const iterator&) starting...\n";

                int data0[6] = {0, 1, 2, 3, 4, 5};
                int data1[4] = {1, 2, 3, 4};
                std::list<int> l;

                for (size_t i = 0; i < 6; ++i) {
                        l.append(data0[i]);
                }

                l.remove(l.begin());
                l.remove(l.end());

                if (!assert_eq<size_t>(l.size(), 4)) {
                        fail();
                        return;
                }

                for (size_t i = 0; i < l.size(); ++i) {
                        if (!assert_eq<int>(l[i], data1[i])) {
                                fail();
                                return;
                        }
                }
                pass();
        }

protected:
        test_list(const char* str) :
                test(str)
        {  }

public:
        test_list() :
                test("Kernel Linked List")
        {  }

        void start()
        {
                log << "Starting the [" << name << "] test...\n";

                list_entity_test();
                append_test();
                insert_test();
                remove_test();
                iterator_test();
                iterator_insert_test();
                iterator_remove_test();

                stat();
        }
};

}; // tests
}; // kernel
}; // conix
