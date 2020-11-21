#pragma once

#include <iostream>
#include <functional>
#include <vector>
#include <unordered_set>
#include <string>

namespace build {

    struct Library;
    struct Executable;
    struct Package;
    struct Settings;

    struct Cache {

        Cache() {
        }

        void request(const Library & l, const Settings & s) {
            // check if Library exists
            // check if Settings were compiled for library
            // 
        }

        std::string path = "~";
    };

    struct Registry {

        static Registry & instance() {
            static Registry r;
            return r;
        }

        static void add(const Library * l) {
            instance().libraries.insert(l);
        }

        static void add(const Executable * e) {
            instance().executables.insert(e);
        }

        static void remove(const Library * l) {
            instance().libraries.erase(l);
        }

        static void remove(const Executable * e) {
            instance().executables.erase(e);
        }

        std::unordered_set<const Library *> libraries;
        std::unordered_set<const Executable *> executables;
    };

    struct Settings {
        Settings() {
            data.c = 17;
            data.cxx = 20;
            data.o = 3;
            data.debug = false;
        }

        Settings & c89() { 
            data.c = 89;
            return *this;
        }

        Settings & c90() { 
            data.c = 90;
            return *this;
        }

        Settings & c99() { 
            data.c = 99;
            return *this;
        }

        Settings & c11() { 
            data.c = 11;
            return *this;
        }

        Settings & c17() {
            data.c = 17; 
            return *this;
        }

        Settings & cxx98() {
            data.cxx = 98; 
            return *this;
        }

        Settings & cxx03() {
            data.cxx = 3;
            return *this;
        }

        Settings & cxx11() {
            data.cxx = 11;
            return *this;
        }

        Settings & cxx14() {
            data.cxx = 14;
            return *this; 
        }

        Settings & cxx17() {
            data.cxx = 17;
            return *this; 
        }

        Settings & cxx20() {
            data.cxx = 20;
            return *this; 
        }
        
        Settings & o0() { 
            data.o = 0;
            return *this; 
        }

        Settings & o1() {
            data.o = 1;
            return *this;
        }

        Settings & o2() {
            data.o = 2;
            return *this;
        }
        
        Settings & o3() {
            data.o = 3;
            return *this;
        }

        Settings & release();
        Settings & debug();
        Settings & include();
        Settings & link();
        Settings & compiler(const std::string & c) {
            data.compiler = c;
            return *this;
        }

        Settings & linker();

        static Settings clang() {
            Settings s;
            s.data.ccompiler = "clang";
            s.data.compiler = "clang++";
            return s;
        }

        static Settings gcc() { return {}; }
        static Settings msvc() { return {}; }
        static Settings native() { return {}; }

        struct Data {
            char c;
            char cxx;
            char o; 
            bool debug;
            std::string ccompiler;
            std::string compiler;
            std::string linker;
        } data;
    };

    std::ostream & operator<<(std::ostream & stream, const Settings & s) {
        stream << s.data.compiler;

        switch(s.data.o) {
            case 0: stream << " -O0"; break;
            case 1: stream << " -O1"; break;
            case 2: stream << " -O2"; break;
            case 3: stream << " -O3"; break;
            default: break;
        }

        switch(s.data.c) {
            case 89: stream << " -std=c89"; break;
            case 90: stream << " -std=c90"; break;
            case 99: stream << " -std=c99"; break;
            case 11: stream << " -std=c11"; break;
            case 17: stream << " -std=c17"; break;
            default: break;
        }
        
        switch(s.data.cxx) {
            case 89: stream << " -std=c++98"; break;
            case 3:  stream << " -std=c++03"; break;
            case 11: stream << " -std=c++11"; break;
            case 14: stream << " -std=c++14"; break;
            case 17: stream << " -std=c++17"; break;
            case 20: stream << " -std=c++20"; break;
            default: break;
        }

        if(s.data.debug) {
            stream << " -g";
        }

        return stream;
    }

    template<class Derived>
    struct Target {

        std::string name;
        std::vector<std::string> sources;
        std::vector<std::string> headers;
        std::vector<std::string> objects;
        std::vector<std::function<void()>> before_functions;
        std::vector<std::function<void()>> after_functions;
        Settings settings;

        Target(const std::string & name): name(name) {
            Registry::add(static_cast<Derived*>(this));
        }

        Target(const Target & l): name(l.name),
                                    sources(l.sources),
                                    headers(l.headers),
                                    objects(l.objects),
                                    before_functions(l.before_functions),
                                    after_functions(l.after_functions),
                                    settings(l.settings) {
            Registry::add(static_cast<Derived*>(this));
        }

        ~Target() {
            Registry::remove(static_cast<Derived*>(this));
        }

        template<class F, class... Fs>
        Derived & source(F f, Fs... fs) {
            sources.push_back(f);
            if constexpr (sizeof...(fs) > 0) source(fs...);
            return *static_cast<Derived*>(this);
        }
        
        template<class F, class... Fs>
        Derived & source_if(bool c, F f, Fs... fs) {
            if(c) source(f, fs...);
            return *static_cast<Derived*>(this);
        }

        template<class F, class... Fs>
        Derived & header(F f, Fs... fs) {
            headers.push_back(f);
            if constexpr (sizeof...(fs) > 0) header(fs...);
            return *static_cast<Derived*>(this);
        }

        template<class F, class... Fs>
        Derived & header_if(bool c, F f, Fs... fs) {
            if(c) header(f, fs...);
            return *static_cast<Derived*>(this);
        }

        template<class F, class... Fs>
        Derived & object(F f, Fs... fs) {
            objects.push_back(f);
            if constexpr (sizeof...(fs) > 0) objects(fs...);
            return *static_cast<Derived*>(this);
        }

        template<class F, class... Fs>
        Derived & object_if(bool c, F f, Fs... fs) {
            if(c) objects(f, fs...);
            return *static_cast<Derived*>(this);
        }

        Derived & config(const Settings & s) {
            settings = s;
            return *static_cast<Derived*>(this);
        }

        template<class F, class... Fs>
        Derived & before(F f, Fs... fs) {
            before_functions.push_back(f);
            if constexpr (sizeof...(fs) > 0) before(fs...);
            return *static_cast<Derived*>(this);
        }

        template<class F, class... Fs>
        Derived & before_if(bool c, F f, Fs... fs) {
            if(c) before(f, fs...);
            return *static_cast<Derived*>(this);
        }

        template<class F, class... Fs>
        Derived & after(F f, Fs... fs) {
            after_functions.push_back(f);
            if constexpr (sizeof...(fs) > 0) after(fs...);
            return *static_cast<Derived*>(this);
        }

        template<class F, class... Fs>
        Derived & after_if(bool c, F f, Fs... fs) {
            if(c) after(f, fs...);
            return *static_cast<Derived*>(this);
        }

        template<class F, class... Fs>
        Derived & depend(F f, Fs... fs) {
            return *static_cast<Derived*>(this);
        }
    };

    struct Library: Target<Library> {
        Library(const std::string & name): Target(name) {
        }
    };

    struct Executable: Target<Executable> {
        Executable(const std::string & name): Target(name) {
        }
    };

    struct Options {
        Options(int argc, char ** argv): 
            argc(argc),
            argv(argv) {
        }

        bool contains(const char * name) const {
            for(int i = 0; i < argc; i++) {
                if(is(i, name)) {
                    return true;
                }
            }

            return false;
        }

        char * operator[](int i) const {
            return i < argc ? argv[i] : nullptr;
        }

        bool is(int i, const char * name) const {
            return i >= argc ? false : strcmp(argv[i], name) == 0;
        }

        int argc;
        char ** argv;
    };

    class Graph {
        
    };

    std::string include_string(const std::vector<std::string> & includes) {
        std::string s;
        for(const std::string & i : includes) {
            s += " -include " + i;
        }

        return s;
    }

    std::string link_string(const std::vector<std::string> & links) {
        return "";
    }

    bool pass(const Library & l) {
        auto includes = build::include_string(l.headers);
        std::cerr << "building " << l.name 
                  << " with " << l.settings << includes << std::endl;
        for(const auto & b : l.before_functions) {
            b();
        }

        for(const std::string & s : l.sources) {
            std::cerr << "* " << s << std::endl;
        }

        for(const auto & a : l.after_functions) {
            a();
        }
        return true;
    }

    bool pass(const Executable & e) {
        return true;
    }

    bool pass(const Package & p) {
        return true;
    }
}



int main(int argc, char* argv[]) {

    auto o = build::Options(argc, argv);

    bool verbose = o.contains("-v");
    bool silent = o.contains("-s");

    if(o.contains("build")) {
        
        for(const build::Library * l : build::Registry::instance().libraries) {
            pass(*l);
        }

        for(const build::Executable * e : build::Registry::instance().executables) {
            pass(*e);
        }

        return 0;
    }

    if(o.is(1, "run")) {
        std::cerr << "building + running" << std::endl;
        return 0;
    }

    if(o.is(1, "publish")) {
        std::cerr << "building + publishing" << std::endl;
        return 0;
    }

    return 1;
}
