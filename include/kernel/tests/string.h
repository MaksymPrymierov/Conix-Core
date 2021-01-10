#pragma once
#include <kernel/tests/vector.h>
#include <kernel/string.h>

namespace conix {
namespace kernel {
namespace tests {

class test_string : public test_vector
{
protected:
        void string_entity_test()
        {
                add_test();
                message() << "string() string...\n";

                std::string str;

                if (!assert_eq<size_t>(str.size(), 0)) {
                        fail();
                        return;
                }
                pass();
        }

        void string_size_data_test()
        {
                add_test();
                message() << "string(size_t, char c) starting...\n";

                std::string str(3, 'a');

                if (!assert_eq<size_t>(str.size(), 3)) {
                        fail();
                        return;
                }

                for (size_t i = 0; i < str.size(); ++i) {
                        if (!assert_eq<char>(str[i], 'a')) {
                                fail();
                                return;        
                        }
                }
                pass();
        }

        void string_char_array_test()
        {
                add_test();
                message() << "string(const char* str) starting...\n";

                const char* test = "Test string";
                std::string str = test;

                if (!assert_eq<size_t>(str.size(), strlen(test))) {
                        fail();
                        return;
                }

                for (size_t i = 0; i < str.size(); ++i) {
                        if (!assert_eq<char>(str[i], test[i])) {
                                fail();
                                return;
                        }
                }
                pass();
        }

        void string_string_test()
        {
                add_test();
                message() << "string(const string &_string) starting...\n";

                const char* test = "Test string";
                std::string str0 = test;
                std::string str1 = str0;

                if (!assert_eq<size_t>(str1.size(), strlen(test))) {
                        fail();
                        return;
                }

                for (size_t i = 0; i < strlen(test); ++i) {
                        if (!assert_eq<char>(str1[i], test[i])) {
                                fail();
                                return;
                        }
                }
                pass();
        }

        void string_logic_test()
        {
                add_test();
                message() << "logic operations test starting...\n";

                std::string test("Test");

                if (test == "Test" && test != "test") {
                        fail();
                        return;
                }
                pass();
        }

public:
        test_string() :
                test_vector("Kernel String")
        {  }

        void start()
        {
                log << "Starting the [" << name << "] test...\n";

                string_entity_test();
                string_size_data_test();
                string_char_array_test();
                string_string_test();
                append_test();
                insert_test();
                remove_test();
                iterator_test();
                iterator_insert_test();
                iterator_remove_test();
                string_logic_test();

                stat();
        }
};

}; // tests
}; // kernel
}; // conix
