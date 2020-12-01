#include "cxx/build.hpp"

auto s = build::Settings::clang()
         .o3()
         .cxx11();

build::Library l = {
    .name = "lib",
    .sources = {
        "a.cpp",
        "b.cpp",
        build::when {
            true,
            "c.cpp"
            "d.cpp"
        }
    },
    .include = {
        "a.hpp",
        "b.hpp"
    },
    .settings = s
};

build::Executable e = {
    .name = "exe",
    .sources = {
        "exe.cpp"
    },
    .objects = {
        l.objects
    }
};

build::Package p = { 
    .name = "package", 
    .version = "1.0.0",
    .authors = { 
        "Author Name <example@mail.com>"
    },
    .license = "MIT/Apache-2.0",
    .readme = "README.md",
    .keywords = { 
        "build",
        "example", 
        "test"
    },
    .description = "stuff"
};