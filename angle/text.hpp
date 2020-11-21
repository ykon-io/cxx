#pragma once
#include <iostream>
#include "view.hpp"

namespace angle 
{
    struct Text : View<>
    {
        Text() {
        }

        Text(const std::string & text): t(text) {
        }

        const char * name() const { 
            return "Text";
        }

        Text & text(const std::string & t) {
            this->t = t;
            return *this;
        }

        Text & font(const std::string & f) {
            return *this;
        }

        Text & bold() {
            return *this;
        }

        Text & underline() {
            return *this;
        }

        Text & italic() {
            return *this;
        }

        Text & color(int r, int g, int b, int a = 255) {
            return *this;
        }

        Text & points(float s) {
            pixels_size = NAN;
            points_size = s;
            return *this;
        }

        Text & pixels(float s) {
            points_size = NAN;
            pixels_size = s;
            return *this;
        }

        std::string t;
        float points_size;
        float pixels_size;
    };
};