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
         .depend(
             "protobuf:1.6.0",
             "qt:6.0.0",
             "pytorch:1.5.0",
             "tiff:0.9.0",
             "libpng:1.4.2",
             "onnx:1.5.0"
         )
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
         .source_if(true,
             "0.cpp",
             "1.cpp",
             "2.cpp"
         )
         .header(
             "a.hpp",
             "b.hpp",
             "src/*.hpp"
         )
         .header_if(true,
            "0.hpp",
            "1.hpp",
            "2.hpp"
         )
         .after(hello)
         .config(s);
    
auto e = build::Executable("cli")
         .source("c.cpp")
         .header("h.hpp")
         .depend(t);