#include "i128.hpp"

namespace cxx 
{
    class Uuid {
        
        public:

        Uuid() {
        }

        bool operator==(const Uuid & other) {
            return value == other.value;
        }

        bool operator!=(const Uuid & other) {
            return value != other.value;
        }

        private:
        
        i128 value;
    };
}