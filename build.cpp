#include "cxx/build.hpp"

namespace build {
    Settings s = Settings::clang()
                .o3()
                .cxx11();

    Library l = {
        .name = "lib",
        .sources = {
            "a.cpp",
            "b.cpp",
            when {
                true,
                "c.cpp",
                "d.cpp"
            }
        },
        .include = {
            "a.hpp",
            "b.hpp"
        },
        .settings = s
    };

    Executable e = {
        .name = "exe",
        .sources = {
            "exe.cpp"
        },
        .objects = {
            l.objects
        }
    };

    Package p = { 
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
}