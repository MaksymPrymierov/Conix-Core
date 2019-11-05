#ifndef TEST_H
#define TEST_H

#include <tty.h>

#define ASSERT_EQ(expected, actual) \
        if (expected != actual) { \
                early_printk("ERROR: expected %d, actual %d\n", expected, actual); \
                early_printk("ERROR: file %s, line %d, function %s\n", __FILE__, __LINE__, __FUNCTION__); \
        } else { \
                early_printk("OK: file %s, line %d, function %s\n", __FILE__, __LINE__, __FUNCTION__); \
        }

extern bool ASSERT_OK(int n);

extern void run_string_test(void);
extern void run_queue_test(void);

#endif /* TEST_H */
