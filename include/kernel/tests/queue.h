#pragma once
#include <kernel/queue.h>

#include <kernel/test.h>

namespace conix {
namespace kernel {
namespace tests {

class test_queue : public test
{
protected:
        void queue_empty_test()
        {
                add_test();
                message() << "queue() starting...\n";

                std::queue<int> q;

                if (!q.empty()) {
                        fail();
                        return;
                }
                pass();
        }

        void front_test()
        {
                add_test();
                message() << "front_test() starting...\n";

                int n[3] = {3, 5, 7};
                std::queue<int> q;

                for (const int &i : n) {
                        q.push(i);
                }

                if (q.size() != 3) {
                        fail();
                        return;
                }

                for (int i = 2; i >= 0; --i) {
                        if (q.front() != n[i]) {
                                fail();
                                return;
                        }
                        q.pop();
                }
                pass();
        }

        void back_test()
        {
                add_test();
                message() << "back_test() starting...\n";

                int n[3] = {3, 5, 7};
                std::queue<int> q;

                for (const int &i : n) {
                        q.push(i);
                }

                if (q.size() != 3) {
                        fail();
                        return;
                }

                for (int i = 3; i < 3; ++i) {
                        if (q.back() != n[0]) {
                                fail();
                                return;
                        }
                        q.pop();
                }
                pass();
        }

        test_queue(const char* str) :
                test(str)
        {  }

public:
        test_queue() :
                test("Kernel Queue")
        {  }

        void start()
        {
                log << "Starting the [" << name << "] test...\n";

                queue_empty_test();
                front_test();
                back_test();

                stat();
        }
};

}; // tests
}; // kernel
}; // conix
