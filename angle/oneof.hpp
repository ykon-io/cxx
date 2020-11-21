#pragma once
#include "view.hpp"

namespace angle
{
    template<class C, class ... Cs>
    struct Oneof : View<C, Cs...>
    {
        Oneof(C c, Cs ... cs): View<C, Cs...>(c, cs...), i(0) {
        }

        const char * name() const {
            return "Oneof";
        }

        void print(int offset = 0) const {
            int counter = 0;
            auto conditional_print = [&](auto & a) {
                if (counter++ == i) a.print(offset);
            };

            std::apply([&](auto & ... x){ (..., conditional_print(x)); } , View<C, Cs...>::cs);
        }

        size_t which() const {
            return i;
        }

        Oneof & select(size_t w) {
            size_t max = std::tuple_size<std::tuple<C, Cs...>>() - 1;
            i = std::min(w, max);
            return *this;
        }

        size_t i;
    };
}