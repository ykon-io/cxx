#pragma once

namespace cxx
{
    struct arguments {
        int c;
        char ** v;

        int size() { return c; }
        char* operator[](size_t index) { return v[index]; }
    };

    static arguments arg;
}

int __implemented_main();

#define main main(int argc, char** argv) { cxx::arg = cxx::arguments{argc, argv}; return __implemented_main(); } int __implemented_main