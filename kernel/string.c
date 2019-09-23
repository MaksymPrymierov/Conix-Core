#include <kernel/string.h>
#include <heap.h>
#include <tty.h>

#include <kernel/kernel_lib.h>

int string_init(struct string* s, size_t size)
{
        int ret = 0;

        s->data = hkmalloc(size);
        if ((char*)NOMEM == s->data) {
                ret = -NOMEM;
                early_printk("string: out of memory\n");
                goto end;
        }
        s->size = size;

end:
        return ret;
};

int string_add_memory(struct string* s, size_t size) 
{
        int ret = 0;

        char* data = hkmalloc(s->size + size);
        if ((char*)NOMEM == data) {
                ret = NOMEM;
                early_printk("string: add_memory: out of memory\n");
                goto end;
        }

        memcpy(data, s->data, s->size);
        hkfree(s->data);
        s->data = data;

end:
        return ret;
}

int string_set(struct string* s, const char* string)
{
        int ret = 0;

        if (strlen(string) + 1 > s->size) {
                ret = string_add_memory(s, strlen(string) - s->size);
                if (-NOMEM == ret) {
                        early_printk("string: set: out of memory\n");
                        goto end;
                }
        }
        memcpy(s->data, (char*)string, strlen(string) + 1);
        
end:
        return ret;
}

void string_clear(struct string* s)
{
        memset(s->data, 0, s->size);
}

int string_append(struct string* s, const char* str)
{
        int ret = 0;
        size_t size = strlen(str);

        size_t offset = strlen(s->data);
        if (offset + size + 1 >= s->size) {
                ret = string_add_memory(s, offset + size - s->size);
                if (-NOMEM == ret) {
                        early_printk("string: append: out of memory\n");
                        goto end;
                }
        }
        memcpy(s->data + offset, (char*)str, size + 1);

end:
        return ret;
}

void string_prepend(struct string *s)
{
        size_t size = strlen(s->data);
        if (size) {
                s->data[size - 1] = '\0';
        }
}

int string_add(struct string* s, char c)
{
        int ret = 0;
        char string[2] = {c, '\0'};
        ret = string_append(s, string);
        return ret;
}

_Bool string_cmp_native(struct string* str1, const char* str2)
{
        _Bool ret = 1;
        size_t size = strlen(str1->data);

        if (size != strlen(str2)) {
                ret = 0;
                goto end;
        }

        for (size_t i = 0; i < size; ++i) {
                if (str1->data[i] != str2[i]) {
                        ret = 0;
                        goto end;
                }
        }

end:
        return ret;
}

_Bool string_cmp(struct string* str1, struct string* str2)
{
        return string_cmp_native(str1, str2->data);
}

void string_delete(struct string* s)
{
        hkfree(s->data);
        s->size = 0;
}

char string_get_last(struct string* s)
{
        return s->data[strlen(s->data) - 1];
}


