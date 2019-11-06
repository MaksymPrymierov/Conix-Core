#pragma once

class device
{
public:
        device();
        ~device();

        virtual void write(void* data, size_t length);
        virtual void* read();

        const char* get_name() const;
        const char* get_description() const;
        const char* get_author() const;
        const char* get_license() const;
        const char* get_type() const;

protected:
        void set_name(const char* _name);
        void set_description(const char* _description);
        void set_author(const char* _author);
        void set_license(const char* _license);
        void set_type(const char* _type);

private:
        char* name;
        char* description;
        char* author;
        char* license;
        char* type;
};
