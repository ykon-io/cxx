#pragma once
#include "view.hpp"
#include "state.hpp"

namespace angle
{
    template<class ... Cs>
    struct List: View<Cs...> {
        List(Cs ... cs): View<Cs...>(cs...) {
        }

        const char * name() const {
            return "Static List";
        }
    };

    template<class M, class V>
    struct List<Model<M>, V>: View<> {
        List(Model<M> & m, V f): f(f) {
        }

        const char * name() const {
            return "Model List";
        }

        V f;
    };
}