#pragma once
#include <tuple>

namespace angle
{
    std::string prefix(int offset) {
        std::string prefix;
        for(int s = 0; s < offset; s++) {
            prefix.append("  ");
        }
        return prefix;
    }

    struct Relative 
    {
        struct Size {};
        Size width;
        Size height;
    };

    /* size by
        .width(0.5) (50% of parents width)
        .height(20) (20 px)
    */

    /* anchoring by
        .left(x) (parents left, x optional default 0)
        .right(x) (parents right, x optional default 0)
        .top(x) (parents top, x optional default 0)
        .bottom(x) (parents bottom, x optional default 0)
    */

    Relative parent;
    Relative children;

    template<class ... Cs>
    struct View
    {
        View(Cs ... c): cs(c...) {
        }

        bool leaf() const {
            return sizeof...(Cs) == 0;
        }

        std::tuple<Cs...> & childs() {
            return cs;
        }

        const std::tuple<Cs...> & childs() const {
            return cs;
        }

        virtual void print(int offset = 0) const {
            std::cerr << prefix(offset) << (sizeof...(Cs) > 0 ? "+ " : "- ") << name() << std::endl;
            std::apply([&](auto ... args){ (..., args.print(offset + 1)); }, cs);            
        }

        virtual const char * name() const {
            return "View";
        };
        
        virtual void draw() const {
            // draw children
        };

        std::tuple<Cs...> cs;
    };
}