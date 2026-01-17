#pragma once

#include <fstream>
#include <string>

#include "utils.h"

namespace COLORS
{
    static constexpr const char* DEFAULT = "\033[0m";
    static constexpr const char* RED     = "\033[31m";
    static constexpr const char* GREEN   = "\033[32m";
    static constexpr const char* YELLOW  = "\033[33m";
    static constexpr const char* BLUE    = "\033[34m";
    static constexpr const char* PURPLE  = "\033[35m";
    static constexpr const char* CYAN    = "\033[36m";
    static constexpr const char* WHITE   = "\033[37m";
}; // namespace COLORS

namespace Parrot
{
    class Config
    {
    private:
        static bool hasDisplayedInitialMessage;

        static std::string   logFileName;
        static bool          isFileLoggingEnabled;
        static std::ofstream logFileStream;

        static void displayInitialMessage();

    public:
        static void log(const std::string& message, const std::string& color, Utils::LogLevel level,
                        const std::string& prefix, const std::string& file_name, int line_no);

        static void setLevel(Utils::LogLevel level);

        static void enableFileLogging(const std::string& log_file_name = logFileName, bool append_logs = false);
        static void disableFileLogging();

        static void speak(const std::string& message, const std::string& color = COLORS::DEFAULT);
    };

#define info(message)  Config::log(message, COLORS::CYAN, Utils::LogLevel::INFO, "INFO: ", __FILE__, __LINE__)
#define warn(message)  Config::log(message, COLORS::YELLOW, Utils::LogLevel::WARN, "WARN: ", __FILE__, __LINE__)
#define error(message) Config::log(message, COLORS::RED, Utils::LogLevel::ERROR, "ERROR: ", __FILE__, __LINE__)
}; // namespace Parrot
