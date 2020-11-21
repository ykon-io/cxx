#pragma once
#include "../cxx/build.hpp"

auto o = build::Library("other")
         .source("other.cpp")
         .header("other.hpp");

auto t = build::Library("third")
         .source("third.cpp")
         .header("third.hpp");
