#include <ctime>
#include "f32.hpp"

namespace cxx 
{
    class Time
    {
        public:

            Time(time_t value): value(value) {
            }
     
            static Time now() {
                return time(NULL);
            }

            static Time epoch();
            static Time since(Time t);

            static Time ns(int nanoseconds);
            static Time ms(int milliseconds);
            static Time s(int seconds);
            static Time m(int minutes);
            static Time h(int hours);
            static Time days(int days);
            static Time weeks(int weeks);
            static Time months(int months);
            static Time years(int years);
            static Time date(int years, int months, int days, int hours, int minutes, int seconds);

            f32 ns() const {
                return 0;
            }
            
            f32 us() const {
                return 0;
            }
            
            f32 ms() const {
                return 0;
            }
            
            f32 s() const {
                return 0;
            }

            f32 m() const {
                return 0;
            }

            f32 h() const {
                return 0;
            }

            f32 d() const {
                return 0;
            }

            f32 w() const {
                return 0;
            }

            f32 y() const {
                return 0;
            }


            
        // operators

            time_t c() const {
                return value;
            }
    
        private:

            time_t value;  
    };

    Time operator+(Time left, Time right) {
        return left.c() + right.c();
    }

    Time operator-(Time left, Time right) {
        return left.c() - right.c();
    }

    void format(const Time & t);
    void print(const Time & t);
}