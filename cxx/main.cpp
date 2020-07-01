#include "console.hpp"
#include "platform.hpp"
#include "float.hpp"
#include "time.hpp"
#include "string.hpp"
#include <thread>
#include <chrono>

using namespace cxx;

int main()
{    
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

    f32 a = 0;
    f32 b = 4.5;
    f32 c = 12;

    std::cerr << a + b + c << std::endl;
    std::cerr << c % b << " vs " << b % c << std::endl;
    std::cerr << c + 18.0 << std::endl;
    std::cerr << a.close(f32::epsilon()) << std::endl;
    std::cerr << f32(1.24).floor() << std::endl;

    auto s = String::format("hello {} lelele", 12);
}