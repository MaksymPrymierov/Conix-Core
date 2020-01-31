#pragma once
#include <kernel/tests/vector.h>
#include <kernel/string.h>

class test_string : public test_vector
{
protected:
        void string_entity_test()
        {
                add_test();
                message() << "string() string...\n";

                string str;

                if (!assert_eq<size_t>(str.size(), 0)) {
                        fail();
                        return;
                }
                pass();
        }

public:
        test_string()
        {  
                test_vector::test("Kernel String");
        }

        void start()
        {
                log << "Starting the [" << name << "] test...\n";

                string_entity_test();

                stat();
        }
};
