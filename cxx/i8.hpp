#pragma once
#include <cstdint>
#include <iostream>

namespace cxx
{
    class i8
    {
        static_assert(sizeof(int8_t)==1, "i8 underlying type int8_t has to be 8bits.");

        public:

            i8(): value(0) {
            }

            template<typename T>
            i8(T value): value(value) {
                static_assert(std::is_same<T, int8_t>::value, "i8 only constructable from 8bit integer (int8_t).");
            }

            template<typename T>
            static i8 of(T value) {
                return int8_t(value);
            }

            static i8 max() {
                return int8_t(INT8_MAX);
            }

            static i8 min() {
                return int8_t(INT8_MIN);
            }

            static i8 random() {
                return (int8_t)0;
            }

            int8_t c() const {
                return value;
            }

        private:

            int8_t value;
    };
    
    i8 operator-(i8 a) {
        return int8_t(-a.c());
    }

    i8 operator+(i8 a) {
        return int8_t(+a.c());
    }

    i8 operator*(i8 a, i8 b) {
        return int8_t(a.c() * b.c());
    }

    i8 operator/(i8 a, i8 b) {
        return int8_t(a.c() / b.c());
    }

    i8 operator%(i8 a, i8 b) {
        return int8_t(a.c() % b.c());
    }

    i8 operator+(i8 a, i8 b) {
        return int8_t(a.c() + b.c());
    }

    i8 operator-(i8 a, i8 b) {
        return int8_t(a.c() - b.c());
    }

    std::ostream & operator<<(std::ostream & stream, i8 value) {
        return stream << int32_t(value.c());
    }

    i8 operator "" _i8(unsigned long long x) {
        return i8(int8_t(x));
    }
}