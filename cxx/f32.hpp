#pragma once
#include <cfloat>
#include <cmath>
#include <iostream>
#include "i32.hpp"

namespace cxx
{
    class f32 
    {
        public:

            f32(): value(0) {
            }

            template<typename T>
            f32(T value): value(value) {
                static_assert(std::is_same<T, float>::value, "f32 only constructable from float.");
            }

            static f32 random() {
                return 0.f;
            }
            
            static f32 parse(const void * v) {
                return 0.f;
            }

            static f32 max() {
                return FLT_MAX;
            }
            
            static f32 min() {
                return -FLT_MAX;
            }

            static f32 inf() {
                return HUGE_VALF;
            }
            
            static f32 nan() {
                return NAN;
            }

            static f32 epsilon() {
                return FLT_EPSILON;
            }

            static f32 e() {
                return float(M_E);
            }

            static f32 pi() {
                return float(M_PI);
            }

            struct IEEE {
                int sign: 1;
                int exponent: 8;
                int mantissa: 23;
            };

            IEEE ieee() const {
                return *reinterpret_cast<const IEEE*>(&value);
            }

            bool is_conformant() const {
                return true;
            }

            f32 round() const {
                return std::round(value);
            }

            f32 floor() const {
                return std::floor(value);
            }

            f32 ceil() const {
                return std::ceil(value);
            }

            f32 abs() const {
                return std::abs(value);
            }

            f32 pow(f32 power) const {
                return std::pow(value, power.value);
            }

            f32 exp() const {
                return std::exp(value);
            }

            f32 log() const {
                return std::log(value);
            }

            f32 log(f32 base) const {
                if(base.value == f32::e().value) return std::log(value);
                if(base.value == 2.f) return std::log2(value);
                if(base.value == 10.f) return std::log10(value);
                return std::log(value) / std::log(base.value);
            }

            bool close(f32 other, f32 error = f32::epsilon()) const {
                return std::abs(value - other.value) <= error.value;
            }

            float c() {
                return value;
            }

        private:

            float value;
    };

    f32 operator+(f32 left, f32 right) {
        return left.c() + right.c();
    }

    f32 operator-(f32 left, f32 right) {
        return left.c() - right.c();
    }

    f32 operator*(f32 left, f32 right) {
        return left.c() * right.c();
    }

    f32 operator/(f32 left, f32 right) {
        return left.c() / right.c();
    }

    f32 operator%(f32 left, f32 right) {
        return fmodf(left.c(), right.c());
    }

    bool operator==(f32 left, f32 right) {
        return left.c() == right.c();
    }

    bool operator!=(f32 left, f32 right) {
        return left.c() != right.c();
    }

    bool operator<(f32 left, f32 right) {
        return left.c() < right.c();
    }

    std::ostream & operator<<(std::ostream & stream, f32 value) {
        return stream << value.c();
    }

    f32 operator "" _f32(long double x) {
        return f32(float(x));
    }
}