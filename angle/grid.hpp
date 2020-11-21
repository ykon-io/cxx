#pragma once
#include "view.hpp"

namespace angle
{
    template<class ... Cs>
    struct Grid: View<Cs...> {
        Grid(Cs ... cs) : View<Cs...>(cs...) {
        }

        const char * name() const {
            return "Static Grid";
        }

        Grid & columns(int c) {
            this->c = c;
            return *this;
        } 

        Grid & rows(int r) {
            this->r = r;
            return *this;
        }

        int c;
        int r;
    };

    template<class M, class V>
    struct Grid<Model<M>, V> : View<> {
        Grid(Model<M> & m, V f): f(f) {
        }

        const char * name() const {
            return "Model Grid";
        }

        Grid & columns(int c) {
            this->c = c;
            return *this;
        } 

        Grid & rows(int r) {
            this->r = r;
            return *this;
        }

        V f;
        
        int c;
        int r;
    };
}