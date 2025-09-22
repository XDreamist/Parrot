#include "parrot.h"

namespace Parrot {

bool Logger::bannerPrinted = false;
std::mutex Logger::mtx;

void Logger::printBannerOnce() {
    std::lock_guard<std::mutex> lock(mtx);
    if (!bannerPrinted) {
        std::cout << "🦜 Using Parrot Logger\n";
        bannerPrinted = true;
    }
}

void Logger::log(Level level, const std::string& message, const char* file, int line) {
    printBannerOnce(); // ensure banner appears only once

    std::string levelStr;
    switch (level) {
        case Level::INFO:   levelStr = "[INFO]"; break;
        case Level::WARN:   levelStr = "[WARN]"; break;
        case Level::DANGER: levelStr = "[DANGER]"; break;
        case Level::DEBUG:  levelStr = "[DEBUG]"; break;
        case Level::SPEAK:  levelStr = "[SPEAK]"; break;
        case Level::ECHO:   levelStr = "[ECHO]"; break;
    }

    std::cout << levelStr << " (" << file << ":" << line << ") " << message << "\n";
}

void Logger::INFO(const std::string& message, const char* file, int line)   { log(Level::INFO, message, file, line); }
void Logger::WARN(const std::string& message, const char* file, int line)   { log(Level::WARN, message, file, line); }
void Logger::DANGER(const std::string& message, const char* file, int line) { log(Level::DANGER, message, file, line); }
void Logger::DEBUG(const std::string& message, const char* file, int line)  { log(Level::DEBUG, message, file, line); }
void Logger::SPEAK(const std::string& message, const char* file, int line)  { log(Level::SPEAK, message, file, line); }
void Logger::ECHO(const std::string& message, const char* file, int line)   { log(Level::ECHO, message, file, line); }
}