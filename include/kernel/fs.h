#ifndef FS_H
#define FS_H

#include <kernel/types.h>

struct fs_file
{
        int fd; /* file descriptor */
        u16 permissions_and_type; /* permissions and type */
        size_t count_of_links; /* number of links */
        u64 owner; /* owner of the file */
        size_t size; /* total size of the file */
        char* name; /* name of the file */
};

struct file_stat
{
        int fd;
        u16 permissions_and_type;
        size_t count_of_links;
        u64 owner;
        size_t size;
        char* name;
};

struct fs
{
        struct fs_file* root; /* root of the filesystem */
        int (*open)(const char* path_name, int flags);
        int (*mkdir)(const char* path_name, mode_t mode);
        int (*stat)(const char* path_name, struct file_stat* stat_buffer);      
};


#endif /* FS_H */
