namespace cxx {
    namespace platform {
        constexpr bool isWindows() {
            #ifdef _WIN32
                return true;
            #else
                return false;
            #endif
        }

        constexpr bool isAndroid() {
            #ifdef __ANDROID__ 
                return true;
            #else 
                return false;
            #endif
        }

        constexpr bool isLinux() {
            #ifdef __linux__ 
                return true;
            #else
                return false;
            #endif
        }

        constexpr bool isUnix() {
            #if defined(__unix__) && !defined(__linux__)
                return true;
            #else 
                return false;
            #endif
        }

        constexpr bool isMac() {
            #ifdef __APPLE__
                #include "TargetConditionals.h" 
                #if TARGET_OS_IPHONE
                    return false;
                #else
                    return true;
                #endif
            #else
                return false;
            #endif
        }

        constexpr bool isIos() {
            #ifdef __APPLE__
                #include "TargetConditionals.h" 
                #if TARGET_OS_IPHONE
                    return true;
                #else
                    return false;
                #endif
            #else
                return false;
            #endif

        }
    }
}