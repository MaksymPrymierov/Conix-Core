#pragma once
#include <kernel/test.h>
#include <kernel/vector.h>

class test_vector : public test
{
private:
        void vector_entity_test()
        {
                add_test();
                message() << "vector() starting...\n";
                
                vector<int> vec;
                
                if (!assert_eq<size_t>(vec.size(), 0)) {
                        fail();
                        return;
                } 
                pass();
        }

        void vector_size_test()
        {
                add_test();
                message() << "vector(size_t) starting...\n";

                vector<int> vec(5);
                
                if (!assert_eq<size_t>(vec.size(), 0)) {
                        fail();
                        return;
                }
                pass();
        }

        void vector_size_data_test()
        {
                add_test();
                message() << "vector(size_t, const T &data) starting...\n";

                vector<int> vec(3, 3);
                
                if (!assert_eq<size_t>(vec.size(), 3)) {
                        fail();
                        return;
                }

                for (size_t i = 0; i < vec.size(); ++i) {
                        if (!assert_eq<int>(vec[i], 3)) {
                                fail();
                                return;
                        }
                }
                pass();
        }

        void vector_size_data_array_test()
        {
                add_test();
                message() << "vector(size_t, T* data) starting...\n";
                
                int tmp[6] = {0, 1, 2, 3, 4, 5};
                vector<int> vec(6, tmp);
                
                if (!assert_eq<size_t>(vec.size(), 6)) {
                        fail();
                        return;
                }

                for (size_t i = 0; i < vec.size(); ++i) {
                        if (!assert_eq<int>(vec[i], tmp[i])) {
                                fail();
                                return;
                        }
                }
                pass();
        }

        void vector_vector_test()
        {
                add_test();
                message() << "vector(const vector &_vector) starting...\n";

                int data[6] = {0, 1, 2, 3, 4, 5};
                vector<int> vec0(6, data);
                vector<int> vec1(vec0);

                if (!assert_eq<size_t>(vec1.size(), 6)) {
                        fail();
                        return;
                }

                for (size_t i = 0; i < vec1.size(); ++i) {
                        if (!assert_eq<int>(vec1[i], data[i])) {
                                fail();
                                return;
                        }
                }
                pass();
        }

        void append_test()
        {
                add_test();
                message() << "append(const T&) starting...\n";

                vector<int> vec;
                int data[6] = {0, 1, 2, 3, 4, 5};

                for (size_t i = 0; i < 6; ++i) {
                        vec.append(data[i]);
                }

                if (!assert_eq<size_t>(vec.size(), 6)) {
                        fail();
                        return;
                }

                for (size_t i = 0; i < vec.size(); ++i) {
                        if (!assert_eq<int>(vec[i], data[i])) {
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

                vector<size_t> vec;

                for (size_t i = 0; i < 6; ++i) {
                        vec.insert(i, i);
                }

                if (!assert_eq<size_t>(vec.size(), 6)) {
                        fail();
                        return;
                }

                for (size_t i = 0; i < vec.size(); ++i) {
                        if (!assert_eq(vec[i], i)) {
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
                vector<int> vec(6, data0);

                vec.remove(5);
                vec.remove(0);
                vec.remove(2);

                if (!assert_eq<size_t>(vec.size(), 3)) {
                        fail();
                        return;
                }

                for (size_t i = 0; i < vec.size(); ++i) {
                        if (!assert_eq<int>(vec[i], data1[i])) {
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
                vector<int> vec(6, data);
                
                size_t i = 0;
                for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
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

                vector<size_t> vec;
                vector<size_t>::iterator iter = vec.begin();

                for (int i = 0; i < 6; ++i) {
                        vec.insert(iter, i);
                        ++iter;
                }

                if (!assert_eq<size_t>(vec.size(), 6)) {
                        fail();
                        return;
                }

                for (size_t i = 0; i < vec.size(); ++i) {
                        if (!assert_eq(vec[i], i)) {
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
                vector<int> vec(6, data0);

                vec.remove(vec.begin());
                vec.remove(vec.end());

                if (!assert_eq<size_t>(vec.size(), 4)) {
                        fail();
                        return;
                }

                for (size_t i = 0; i < vec.size(); ++i) {
                        if (!assert_eq<int>(vec[i], data1[i])) {
                                fail();
                                return;
                        }
                }
                pass();
        }
public:
        test_vector() :
                test("Kernel Vector")
        {  }

        void start()
        {
                log << "Starting the [" << name << "] test...\n";

                vector_entity_test();
                vector_size_test();
                vector_size_data_test();
                vector_size_data_array_test();
                vector_vector_test();
                append_test();
                insert_test();
                remove_test();
                iterator_test();
                iterator_insert_test();
                iterator_remove_test();

                stat();
        }
};
