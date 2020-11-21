#pragma once
#include "view.hpp"

namespace angle
{
    template<class ... Vs>
    struct Scene : View<Vs...>
    {
        Scene(Vs ... vs): View<Vs...>(vs...) {
        }

        const char * name() const {
            return "Scene";
        }
    };
}