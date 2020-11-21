#pragma once
#include <iostream>
#include "view.hpp"

namespace angle 
{
    struct Image : View<>
    {
        Image(const std::string & path): w(0), h(0), m(0) {
        }

        const char * name() const {
            return "Image";
        }

        Image & width(int w) {
            this->w = w;
            return *this;
        }

        Image & height(int h) {
            this->h = h;
            return *this;
        }

        Image & transform(int m) {
            this->m = m;
            return *this;
        }

        Image & filter(int f) {
            return *this;
        } 

        int m;
        int w;
        int h;
    };
}