#pragma once

#include <chrono>
#include <iomanip>
#include <iostream>

namespace Utils
{
    enum class LogLevel
    {
        INFO = 0,
        WARN = 1,
        ERROR = 2
    };

    static std::string getTimeStamp()
    {
        auto now = std::chrono::system_clock::now();
        auto in_time_t = std::chrono::system_clock::to_time_t(now);
        std::stringstream string_stream;
        string_stream << std::put_time(std::localtime(&in_time_t), "%d-%m-%Y %H:%M:%S");
        return string_stream.str();
    }
};  // namespace Utils
