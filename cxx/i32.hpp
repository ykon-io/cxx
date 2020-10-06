#pragma once
#include <cstdint>

namespace cxx 
{
    class i32 
    {
        public: 

            i32(): value(0) {
            }

            template<typename T>
            i32(T value): value(value) {
                static_assert(std::is_same<T, int32_t>::value, "i32 only constructable from 32bit signed integer type.");
            }

            static i32 max() {
                return INT32_MAX;
            }

            static i32 min() {
                return INT32_MIN;
            }

            static i32 random() {
                return 0;
            }

            i32 operator-() const {
                return -value;
            }

            i32 operator+() const {
                return +value;
            }

            int32_t c() const {
                return value;
            }

            i8 i8() const {
                return i8::of(value);
            }

        private:

            int32_t value;
    };

    i32 operator*(i32 a, i32 b) {
        return a.c() * b.c();
    }

    i32 operator/(i32 a, i32 b) {
        return a.c() / b.c();
    }

    i32 operator%(i32 a, i32 b) {
        return a.c() % b.c();
    }

    i32 operator+(i32 a, i32 b) {
        return a.c() + b.c();
    }

    i32 operator-(i32 a, i32 b) {
        return a.c() - b.c();
    }

    std::ostream & operator<<(std::ostream & stream, i32 value) {
        return stream << value.c();
    }

    i32 operator "" _i32(unsigned long long x) {
        return i32(int32_t(x));
    }
}