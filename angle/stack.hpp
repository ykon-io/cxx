#pragma once

namespace angle 
{
    template<class ... Cs>
    struct Stack : View<Cs...>
    {
        Stack(Cs... cs): View<Cs...>(cs...) {
        }

        const char * name() const {
            return "Stack";
        }
    };

    template<class ... Cs>
    struct Row : View<Cs...>
    {
        Row(Cs ... cs): View<Cs...>(cs...) {
        }

        const char * name() const {
            return "Row";
        }
    };

    template<class ... Cs>
    struct Column : View<Cs...>
    {
        Column(Cs ... cs): View<Cs...>(cs...) {
        }

        const char * name() const {
            return "Column";
        }
    };
}