#include <kernel/device.cpp>
#include <kernel/kernel_lib.h>
#include <kernel/memory.h>

device::device()
{  }

const char* device::get_name() const
{
        return name;
}

const char* device::get_description() const
{
        return description;
}

const char* device::get_author() const
{
        return author;
}

const char* device::get_license() const
{
        return license;
}

const char* device::get_type() const
{
        return type;
}

