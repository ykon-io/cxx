#pragma once
#include <cstdint>
#include <iostream>

namespace cxx 
{
    class i64
    {
        public: 

            i64(): value(0) {
            }

            template<typename T>
            i64(T value): value(value) {
                constexpr bool accept = std::is_same<T, int8_t>::value   ||
                                        std::is_same<T, int16_t>::value  ||
                                        std::is_same<T, int32_t>::value  ||
                                        std::is_same<T, int64_t>::value  ||
                                        std::is_same<T, uint8_t>::value  ||
                                        std::is_same<T, uint16_t>::value ||
                                        std::is_same<T, uint32_t>::value;
                static_assert(accept, "i64 only constructable from 8, 16, 32, 64 bit signed or 8, 16, 32 unsigned integer type.");
            }

            static i64 max() {
                return INT64_MAX;
            }

            static i64 min() {
                return INT64_MIN;
            }

            static i64 random() {
                return 0;
            }

            i64 operator-() const {
                return -value;
            }

            i64 operator+() const {
                return +value;
            }

            int64_t c() const {
                return value;
            }

            i8 i8() const {
                return i8::of(value);
            }

            // i16
            // i32
            // i128

            

        private:

            int64_t value;
    };

    i64 operator*(i64 a, i64 b) {
        return a.c() * b.c();
    }

    i64 operator/(i64 a, i64 b) {
        return a.c() / b.c();
    }

    i64 operator%(i64 a, i64 b) {
        return a.c() % b.c();
    }

    i64 operator+(i64 a, i64 b) {
        return a.c() + b.c();
    }

    i64 operator-(i64 a, i64 b) {
        return a.c() - b.c();
    }

    std::ostream & operator<<(std::ostream & stream, i64 value) {
        return stream << value.c();
    }

    i64 operator "" _i64(unsigned long long x) {
        return i64(int64_t(x));
    }
}