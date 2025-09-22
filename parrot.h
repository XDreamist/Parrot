#pragma once
#include <iostream>
#include <string>
#include <mutex>

namespace Parrot {

    enum class Level {
        INFO,
        WARN,
        DANGER,
        DEBUG,
        SPEAK,
        ECHO
    };

    class Logger {
    public:
        static void log(Level level, const std::string& message, const char* file, int line);

        // Convenience wrappers
        static void INFO(const std::string& message, const char* file = __FILE__, int line = __LINE__);
        static void WARN(const std::string& message, const char* file = __FILE__, int line = __LINE__);
        static void DANGER(const std::string& message, const char* file = __FILE__, int line = __LINE__);
        static void DEBUG(const std::string& message, const char* file = __FILE__, int line = __LINE__);
        static void SPEAK(const std::string& message, const char* file = __FILE__, int line = __LINE__);
        static void ECHO(const std::string& message, const char* file = __FILE__, int line = __LINE__);

    private:
        static void printBannerOnce();
        static bool bannerPrinted;
        static std::mutex mtx;
    };
}