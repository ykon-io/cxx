#include <ctime>

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
            static Time since(int timepoint);

            static Time ns(int nanoseconds);
            static Time ms(int milliseconds);
            static Time s(int seconds);
            static Time m(int minutes);
            static Time h(int hours);
            static Time days(int days);
            static Time weeks(int weeks);
            static Time months(int months);
            static Time years(int years);

            // getYear()
            // setYear()
            // getMonth()
            // setMonth()
            // getWeek()
            // setWeek()
            // getDay()
            // setDay()
            // getHour()
            // setHour()
            // getMinute()
            // setMinute()
            // getSecond()
            // setSecond()
            // getMillisecond()
            // getNanosecond()

        // operators

            time_t c() const {
                return value;
            }

            // ... std() const
    
        private:

            time_t value;  
    };

    Time operator+(Time left, Time right) {
        return left.c() + right.c();
    }

    Time operator-(Time left, Time right) {
        return left.c() - right.c();
    }
}