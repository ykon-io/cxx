/*
f16
f32
f64
f128
*/
#include <cfloat>
#include <cmath>
#include <iostream>
#include "int.hpp"

namespace cxx
{
    class f32 
    {
        public:

            f32(): value(0) {
            }

            f32(float value): value(value) {
            }

            static f32 random();
            
            static f32 max() {
                return FLT_MAX;
            }
            
            static f32 min() {
                return -FLT_MAX;
            }

            static f32 inf() {
                return INFINITY;
            }
            
            static f32 nan() {
                return NAN;
            }

            static f32 epsilon() {
                return FLT_EPSILON;
            }

            static f32 e() {
                return M_E;
            }

            static f32 pi() {
                return M_PI;
            }

        
            int sign() const {
                return value >= 0 ? 1 : -1;
            }

            int exponent() const {
                union {
                    float value;
                    struct Ieee {
                        int sign: 1;
                        int exponent: 8;
                        int mantissa: 23;
                    } ieee;
                } intospect;

                intospect.value = value;
                
                return intospect.ieee.exponent;
            }

            int mantissa() const {
                return 0;
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

            f32 log(f32 base = f32::e()) const {
                if(base.value == f32::e().value) return std::log(value);
                if(base.value == 2.f) return std::log2(value);
                if(base.value == 10.f) return std::log10(value);
                return std::log(value) / std::log(base.value);
            }

            bool close(f32 other, f32 error = f32::epsilon()) const {
                return std::abs(value - other.value) <= error.value;
            }

            // decimal()
            // integer()

            float c() {
                return value;
            }

        private:

            struct Ieee {
                int sign: 1;
                int exponent: 8;
                int mantissa: 23;
            };

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
}