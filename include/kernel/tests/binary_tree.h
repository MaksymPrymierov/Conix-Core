#pragma once
#include <kernel/test.h>
#include <kernel/binary_tree.h>

namespace conix {
namespace kernel {
namespace tests {

class test_binary_tree : public test
{
protected:
        void binary_tree()
        {
                ADD_TEST();
                
                std::binary_tree<int> bt;
                
                if (!assert_eq<size_t>(bt.size(), 0) || !bt.empty()) {
                        fail();
                        return;
                } 
                pass();
        }

        void insert()
        {
                ADD_TEST();
                
                int numbers[10] = {3, 4, 12, 56, 1, 23, 5, -1, 1, -20}; // binary tree must have 9 elements
                std::binary_tree<int> bt;

                for (const auto& i : numbers) {
                        bt.insert(i);
                }

                if (!assert_eq<size_t>(bt.size(), 9) || bt.empty()) {
                        fail();
                        return;
                }

                for (const auto& i : numbers) {
                        if (!bt.contains(i)) {
                                fail();
                                return;
                        }
                }
                pass();
        }

        void erase()
        {
                ADD_TEST();

                int number0[10] = {3, 4, 12, 56, 1, 23, 5, -1, 1, -20}; // binary tree must have 9 elements
                int number1[5] = {4, 12, 23, 5, -1}; // binary tree must have 5 elements
                int remove_numbers[6] = {3, 56, 1, -20, 100, 20};
                std::binary_tree<int> bt;

                for (const auto& i : number0) {
                        bt.insert(i);
                }

                for (const auto& i : remove_numbers) {
                        bt.erase(i);
                }

                if (!assert_eq<size_t>(bt.size(), 5) || bt.empty()) {
                        fail();
                        return;
                }

                for (const auto& i : number1) {
                        if (!bt.contains(i)) {
                                fail();
                                return;
                        }
                }
                pass();
        }

protected:
        test_binary_tree(const char* str) :
                test(str)
        {  }

public:
        test_binary_tree() :
                test("Kernel Binary Tree")
        {  }

        void start()
        {
                log << "Starting the [" << name << "] test...\n";

                binary_tree();
                insert();
                erase();

                stat();
        }
};

}; // tests
}; // kernel
}; // conix
