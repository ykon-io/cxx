#include "console.hpp"
#include "platform.hpp"
#include "c8.hpp"
#include "f32.hpp"
#include "f64.hpp"
#include "f128.hpp"
#include "time.hpp"
#include "string.hpp"
#include <thread>
#include <chrono>
#include "args.hpp"

using namespace cxx;

int main()
{
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

  
    return 0;
}