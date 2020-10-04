#pragma once
#include <cstdint>
#include <iostream>

namespace cxx 
{
    class c8 
    {
        static_assert(sizeof(char) == 1, "char required to be 8bit.");

        public: 

            c8(): value(0) {
            }

            template<typename T>
            c8(T value): value(value) {
                static_assert(std::is_same_v<char, T>, "c8 can only be constructed from 8bit character.");
            }

            static c8 max() {
                return c8(char(127));
            }

            static c8 min() {
                return c8(char(-128));
            }

            static c8 a() {
                return c8('a');
            }

            static c8 A() {
                return c8('A');
            }
            
            char c() const {
                return value;
            }

        private:

            char value;
    };

    std::ostream & operator<<(std::ostream & stream, c8 value) {
        return stream << value.c();
    }

    c8 operator "" _c8(char x) {
        return c8(char(x));
    }
}