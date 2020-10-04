#pragma once
#include <cfloat>
#include <cmath>
#include <iostream>

namespace cxx 
{
    class f64 
    {
        public:

            f64(): value(0) {
            }

            f64(double value): value(value) {
            }

            static f64 random() {
                return 0;
            }

            static f64 max() {
                return DBL_MAX;
            }

            static f64 min() {
                return DBL_MIN;
            }

            static f64 inf() {
                return HUGE_VAL;
            }
            
            static f64 nan() {
                return NAN;
            }

            static f64 epsilon() {
                return DBL_EPSILON;
            }

            static f64 e() {
                return M_E;
            }

            static f64 pi() {
                return M_PI;
            }

            bool isnan() const {
                return std::isnan(value);
            }

            bool isinf() const {
                return std::isinf(value);
            }

            double c() const {
                return value;
            }

        private:

            double value;
    };

    std::ostream & operator<<(std::ostream & stream, f64 value) {
        return stream << value.c();
    }

    f64 operator "" _f64(long double x) {
        return f64(x);
    }
}