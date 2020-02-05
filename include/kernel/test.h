#pragma once
#include <tty.h>

namespace conix {
namespace kernel {
namespace tests {

class test {
        size_t tests_failed;
        size_t tests_passed;
        size_t test_count;

protected:
        tty log;
        const char* name;

        auto message()
        {
                return log << "\tTest[" << name << "]:[" << test_count
                        << "] ";
        }

        void fail()
        {
                message() << "is FAIL\n"; 
                ++tests_failed;
        }

        void pass()
       {
                message() << "is PASS\n";
                ++tests_passed;
        }

        void add_test()
        {
                ++test_count;
        }

public:
        test(const char* _name) :
                tests_failed(0),
                tests_passed(0),
                test_count(0),
                name(_name) 
        {  }

        virtual void start() {  }
        
        template <typename T>
        bool assert_eq(T actual, T expected)
        {
                if (actual != expected) {
                        return false;
                } else {
                        return true;
                }
        }

        template <typename T>
        bool assert_memory_ok(T* memory)
        {
                if (memory != reinterpret_cast<T*>(ENOMEM)) {
                        return true;
                }
                return false;
        }

        void stat()
        {
                log << "\tTest [" << name << "] has been";
                if (tests_passed != test_count) {
                        log << " failures";        
                } else {
                        log << " successful";
                }
                log << " finished.\n";

                log << "\t" << "Total tests: " << test_count << 
                        " Tests passed: " << tests_passed <<
                        " Tests failed: " << tests_failed << ".\n";
        }
};

}; // tests
}; // kernel
}; // conix
