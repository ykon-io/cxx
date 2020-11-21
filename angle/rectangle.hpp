#pragma once
#include <iostream>
#include "view.hpp"

namespace angle
{
    template<class ... Cs>
    struct Rectangle : View<Cs...>
    {
        Rectangle(Cs ... cs): View<Cs...>(cs...) {
        }

        const char * name() const {
            return "Rectangle";
        }

        Rectangle & width(float w) {
            return *this;
        }

        Rectangle & height(float h) {
            return *this;
        }
    };
}