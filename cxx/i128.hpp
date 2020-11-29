#pragma once
#include <cstdint>
#include <iostream>

namespace cxx 
{
    class i128
    {
        static_assert(sizeof(__int128_t) == 16, "platform i128 is not 128bit.");

        public:


            i128(): value(0) {
            }

            template<typename T>
            i128(T value): value(value) {
                constexpr bool accept = std::is_same<T, int8_t>::value   ||
                                        std::is_same<T, int16_t>::value  ||
                                        std::is_same<T, int32_t>::value  ||
                                        std::is_same<T, int64_t>::value  ||
                                        std::is_same<T, uint8_t>::value  ||
                                        std::is_same<T, uint16_t>::value ||
                                        std::is_same<T, uint32_t>::value ||
                                        std::is_same<T, uint64_t>::value;
                static_assert(accept, "i128 only constructable from 8, 16, 32, 64, 128 bit signed or 8, 16, 32, 64 unsigned integer type.");
            }

            static i128 max() {
                return 0;
            }

            static i128 min() {
                return 0;
            }

            static i128 random() {
                return 0;
            }

            i128 operator-() const {
                return -value;
            }

            i128 operator+() const {
                return +value;
            }

            __int128_t c() const {
                return value;
            }

            // i16
            // i32
            // i128

            

        private:

            __int128_t value;
    };

    i128 operator*(i128 a, i128 b) {
        return a.c() * b.c();
    }

    i128 operator/(i128 a, i128 b) {
        return a.c() / b.c();
    }

    i128 operator%(i128 a, i128 b) {
        return a.c() % b.c();
    }

    i128 operator+(i128 a, i128 b) {
        return a.c() + b.c();
    }

    i128 operator-(i128 a, i128 b) {
        return a.c() - b.c();
    }

    std::ostream & operator<<(std::ostream & stream, i128 value) {
        return stream << value.c();
    }

    i128 operator "" _i128(unsigned long long x) {
        return i128(__int128_t(x));
    }
}