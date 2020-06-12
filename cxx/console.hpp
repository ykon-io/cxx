#include <iostream>
#include <cstring>

namespace cxx
{
    class Console
    {
        private: 

            static Console & instance() {
                static Console console;
                return console;
            }

            enum class Color {
                unchanged,
                black,
                red,
                green,
                yellow,
                blue,
                magenta,
                cyan,
                light_gray,
                dark_gray,
                light_red,
                light_green,
                light_yellow,
                light_blue,
                light_magenta,
                light_cyan,
                white
            };

            enum class Foreground {
                unchanged = 39,
                black = 30,
                red = 31,
                green = 32,
                yellow = 33,
                blue = 34,
                magenta = 35,
                cyan = 36,
                light_gray = 37,
                dark_gray = 90,
                light_red = 91,
                light_green = 92,
                light_yellow = 93,
                light_blue = 94,
                light_magenta = 95,
                light_cyan = 96,
                white = 97
            };

            enum class Background {
                unchanged = 49,
                black = 40,
                red = 41,
                green = 42,
                yellow = 43,
                blue = 44,
                magenta = 45,
                cyan = 46,
                light_gray = 47,
                dark_gray = 100,
                light_red = 101,
                light_green = 102,
                light_yellow = 103,
                light_blue = 104,
                light_magenta = 105,
                light_cyan = 106,
                white = 107
            };

            enum class Format {
                unchanged, // set: 0, reset: 0
                bold, // set: 1, reset: 21
                underline, // set: 4, reset: 24
                bold_underline
            };

            struct AnsiFormat
            {
                AnsiFormat(): text("/033[031;049m") {
                }

                union {
                    char text[17];
                    struct {
                        char start[5];
                        char foreground[4];
                        char background[4];
                        char format[4];
                    };
                };

                void setForeground(Color color) {
                    // foreground[0] = '0';
                    switch(color) {
                        case Color::unchanged:     foreground[1] = '3'; foreground[2] = '9'; break;
                        case Color::black:         foreground[1] = '3'; foreground[2] = '0'; break;
                        case Color::red:           foreground[1] = '3'; foreground[2] = '1'; break;
                        case Color::green:         foreground[1] = '3'; foreground[2] = '2'; break;
                        case Color::yellow:        foreground[1] = '3'; foreground[2] = '3'; break;
                        case Color::blue:          foreground[1] = '3'; foreground[2] = '4'; break;
                        case Color::magenta:       foreground[1] = '3'; foreground[2] = '5'; break;
                        case Color::cyan:          foreground[1] = '3'; foreground[2] = '6'; break;
                        case Color::light_gray:    foreground[1] = '3'; foreground[2] = '7'; break;
                        case Color::dark_gray:     foreground[1] = '9'; foreground[2] = '0'; break;
                        case Color::light_red:     foreground[1] = '9'; foreground[2] = '1'; break;
                        case Color::light_green:   foreground[1] = '9'; foreground[2] = '2'; break;
                        case Color::light_yellow:  foreground[1] = '9'; foreground[2] = '3'; break;
                        case Color::light_blue:    foreground[1] = '9'; foreground[2] = '4'; break;
                        case Color::light_magenta: foreground[1] = '9'; foreground[2] = '5'; break;
                        case Color::light_cyan:    foreground[1] = '9'; foreground[2] = '6'; break;
                        case Color::white:         foreground[1] = '9'; foreground[2] = '7'; break;
                    }
                    //foreground[3] = ';'; 
                }
            };

            AnsiFormat format;

        public:

            static Console & write(const char * text) {
                std::cerr << instance().format.text << text << "\033[0m" << std::endl;
                instance().format.setForeground(Color::light_yellow);
                std::cerr << "\033[093;049mhi" << "\033[0m" << std::endl;
                return instance();
            }

            static Console & red(const char * text) {
                std::cerr << "\033[031m" << text << "\033[0m" << std::endl;
                return Console::instance();
            }

            static Console & redBold(const char * text) {
                std::cerr << "\033[031;001m" << text << "\033[0m" << std::endl;
                return Console::instance();
            }
    };
}