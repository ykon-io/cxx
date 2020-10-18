#include "cxx/build.hpp"
#include "other/build.cpp"
#include <iostream>

void hello() {
    std::cout << "hello" << std::endl;
}

auto s = build::Settings::clang()
         .o3()
         .cxx11();

auto l = build::Library("compute")
         .before(
             hello,
             hello
         )
         .source(
             "src/*.cpp",
             "a.cpp",
             "b.cpp",
             "c.cpp",
             "d.cpp",
             "e.cpp"
         )
         .header(
             "a.hpp",
             "b.hpp",
             "include/",
             "src/*.hpp"
         )
         .after(hello)
         .config(s);
    
auto e = build::Executable("cli")
         .source()
         .header()
         .depend(t);