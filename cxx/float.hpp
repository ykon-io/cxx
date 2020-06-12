/*
f16
f32
f64
f128
*/
#include <cfloat>
#include <cmath>
#include <iostream>

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

            // decimal()
            // integer()

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

    std::ostream & operator<<(std::ostream & stream, f32 value) {
        return stream << value.c();
    }
}