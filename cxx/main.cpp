#include "console.hpp"
#include "platform.hpp"
#include "c8.hpp"
#include "i8.hpp"
#include "i32.hpp"
#include "f32.hpp"
#include "f64.hpp"
#include "f128.hpp"
#include "time.hpp"
#include "string.hpp"
#include <thread>
#include <chrono>
#include "args.hpp"
#include "../angle/angle.hpp"

#include <variant>

using namespace cxx;
using namespace angle;

template<class A, class ... As>
size_t lengthof(const A & a, As ... as) {
    return lengthof(a) + lengthof(as...);
}

template<class A, class ... As>
size_t lengthof(const A * a, As ... as) {
    return lengthof(a) + lengthof(as...);
}

template<>
size_t lengthof<std::string>(const std::string & s) {
    return s.length();
}

template<>
size_t lengthof<char>(const char * s) {
    return strlen(s);
}

template<class S, class ... Ss>
void insert(std::string & r, int i, const S & s, Ss ... ss) {
    insert(r, i, s);
    insert(r, i + lengthof(s), ss...);
}


template<class S, class ... Ss>
void insert(std::string & r, int i, const S * s, Ss ... ss) {
    insert(r, i, s);
    insert(r, i + lengthof(s), ss...);
}

template<>
void insert<std::string>(std::string & r, int i, const std::string & s) {
    std::copy(s.begin(), s.end(), r.begin() + i);
}


template<>
void insert<char>(std::string & r, int i, const char * s) {
    std::copy(s, s + lengthof(s), r.begin() + i);
}

template<class A, class ... As>
std::string strcat(A a, As ... as) {
    std::string s(lengthof(a, as...), ' ');
    insert(s, 0, a, as...);
    return s;
}

int main()
{
    auto sct = strcat("hello", " ", "i'm", " ", "lol", " ", std::string("max"));
    std::cerr << "catted: " << sct << std::endl;


    Model<int> model;

    struct S {
        int a;
        std::string b;
        float c;
    };

    auto s = Scene(
        Rectangle(
            Text("in rect 1"),
            Text("in rect 2")
              .color(0, 0, 0)
              .pixels(12)
        ) .width(10)
          .height(20),
        Row(
            Text("lol")
              .text("lolol")
              .pixels(12)
              .points(13.4)
              .font("Arial")
              .bold()
              .italic()
              .underline()
              .color(64, 64, 128),
            Image("bird.png")
              .width(100)
              .height(12)
              .transform(0)
              .filter(0),
            Oneof(
                Image("cat.png")
                  .width(100)
                  .height(44),
                Text("Image of cat"),
                Column(
                    Rectangle(),
                    Text("lelele"),
                    Image("hi.png")
                )
            ) .select(2)
        ),
        List(
            Text()
             .points(14.3)
             .font("Courier")
             .bold()
             .color(14, 44, 55),
            Text(),
            Rectangle()
        ),
        List(
            model,
            [](auto m) {
                return Text("hi");
            }
        ),
        Grid(
            Text("a"),
            Text("b"),
            Text("c"),
            Row(
                Text("d"),
                Text("f")
            )
        ),
        Grid(
            model,
            [](const int & m) {
                return Text("hi");
            }
        )
        .rows(2)
        .columns(2)
    );

    s.print();
    s.draw();

    std::cerr << "Hi " << arg.size() << " " << arg[0];

    std::cerr << platform::isAndroid() << std::endl;
    std::cerr << platform::isIos() << std::endl;
    std::cerr << platform::isLinux() << std::endl;
    std::cerr << platform::isMac() << std::endl;
    std::cerr << platform::isUnix() << std::endl;
    std::cerr << platform::isWindows() << std::endl;

    Console::redBold("hi");

    std::cerr << "max:" << f32::max() << std::endl;
    std::cerr << "min:" << f32::min() << std::endl;
    std::cerr << "nan:" << f32::nan() << std::endl;
    std::cerr << "inf:" << f32::inf() << std::endl;
    std::cerr << "epsilon:" << f32::epsilon() << std::endl;
    std::cerr << "e:" << f32::e() << std::endl;
    std::cerr << "pi:" << f32::pi() << std::endl;

    f32 a = 0.f;
    f32 b = 4.5f;
    f32 c = 12.f;
    auto x = 1.5_f32;
    auto y = f32::parse("jjjj");
    std::cerr << a + b + c << " " << x.floor() << std::endl;
    std::cerr << c % b << " vs " << b % c << std::endl;
    std::cerr << c + 18.f << std::endl;
    std::cerr << a.close(f32::epsilon()) << std::endl;
    std::cerr << f32(1.24f).floor() << std::endl;

    //auto s = String::format("hello {} lelele", 12);

    std::cerr << f64::nan().isnan() << std::endl;
    std::cerr << f64::inf().isinf() << std::endl;

    f128 t = -f128::max();
    std::cerr << t.isnan() << f128::inf().isinf() << std::endl;
    f32 t32 = t.f32();
    f64 t64 = t.f64();

    i32 it = i32::max();
    i32 g = 12;
    i32 h = 444_i32;

    std::cerr << it << " " << g << " " << h << std::endl;

    std::cerr << g + h * 55_i32 << std::endl;
    std::cerr << i8::max() << std::endl;
    std::cerr << 127_i8 + 127_i8 << i32::max().i8() << std::endl;

    return 0;
}