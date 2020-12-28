#pragma once
#include <kernel/map.h>
#include <kernel/test.h>

namespace conix {
namespace kernel {
namespace tests {

class test_map : public test
{
protected:
        void map()
        {
                ADD_TEST();
                
                std::map<int, int> m;
                
                if (!assert_eq<size_t>(m.size(), 0) || !m.empty()) {
                        fail();
                        return;
                } 
                pass();
        }

        void insert()
        {
                ADD_TEST();
                
                int numbers[10] = {3, 4, 12, 56, 1, 23, 5, -1, 66, -20}; // binary tree must have 9 elements
                std::map<int, int> m;

                for (int i = 0; i < 10; ++i) {
                        m.insert(numbers[i], i);
                }

                if (!assert_eq<size_t>(m.size(), 10) || m.empty()) {
                        fail();
                        return;
                }

                for (int i = 0; i < 10; ++i) {
                        if (m[numbers[i]] != i) {
                                fail();
                                return;
                        }
                }
                pass();
        }

        void erase()
        {
                ADD_TEST();

                int numbers0[10] = {3, 4, 12, 56, 1, 23, 5, -1, 66, -20};
                int numbers1[7] = {4, 12, 56, 1, 5, -1, 66};
                int saved_data[7] = {1, 2, 3, 4, 6, 7, 8};
                int removed_numbers[3] = {3, 23, -20};
                std::map<int, int> m;

                for (int i = 0; i < 10; ++i) {
                        m.insert(numbers0[i], i);
                }

                for (int i = 0; i < 3; ++i) {
                        m.erase(removed_numbers[i]);
                }

                if (!assert_eq<size_t>(m.size(), 7) || m.empty()) {
                        fail();
                        return;
                }

                for (int i = 0; i < 7; ++i) {
                        if (m[numbers1[i]] != saved_data[i]) {
                                fail();
                                return;
                        }
                }
                pass();
        }

protected:
        test_map(const char* str) :
                test(str)
        {  }

public:
        test_map() :
                test("Kernel Map")
        {  }

        void start()
        {
                log << "Starting the [" << name << "] test...\n";

                map();
                insert();
                erase();

                stat();
        }
};

}; // tests
}; // kernel
}; // conix
