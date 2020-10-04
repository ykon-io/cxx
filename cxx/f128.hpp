#pragma once
#include <cfloat>
#include <cmath>
#include <iostream>
namespace cxx 
{
    class f128 
    {
        static_assert(sizeof(long double) == 16, "platform long double is not 128bit.");
     
        public:

            f128(): value(0) {
            }

            f128(long double value): value(value) {
            }

            static f128 max() {
                return LDBL_MAX;
            }

            static f128 min() {
                return LDBL_MIN;
            }

            static f128 inf() {
                return HUGE_VALL;
            }

            static f128 nan() {
                return NAN;
            }

            static f128 epsilon() {
                return LDBL_EPSILON;
            }

            static f128 e() {
                return (long double)M_E;
            }

            static f128 pi() {
                return (long double)M_PI;
            }

            bool isnan() const {
                return std::isnan(value);
            }

            bool isinf() const {
                return std::isinf(value);
            }

            f128 operator-() const {
                return -value;
            }

            f128 operator+() const {
                return +value;
            }

            f32 f32() const {
                return float(value);
            }

            f64 f64() const {
                return double(value);
            }

            long double c() const {
                return value;
            }

        private:

            long double value;
    };

    std::ostream & operator<<(std::ostream & stream, f128 value) {
        return stream << value.c();
    }

    f128 operator "" _f128(long double x) {
        return f128(x);
    }
}