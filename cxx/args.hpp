#pragma once

namespace cxx
{
    struct arguments {
        int c;
        char ** v;

        int size() { 
            return c; 
        }

        char* operator[](size_t index) { 
            return v[index]; 
        }

        template<size_t S>
        bool contains(const char(&name)[S]) const {
            for(int i = 0; i < c; i++) {
                if(is(i, name)) {
                    return true;
                }
            }

            return false;
        }

        bool is(int i, const char * name) const {
            return i >= c ? false : strcmp(v[i], name) == 0;
        }
    };

    static arguments arg;
}

int __implemented_main();

#define main main(int argc, char** argv) { cxx::arg = cxx::arguments{argc, argv}; return __implemented_main(); } int __implemented_main