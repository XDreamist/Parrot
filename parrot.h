#pragma once

#include <fstream>
#include <string>

#include "utils.h"

namespace COLORS
{
    static constexpr const char *DEFAULT = "\033[0m";
    static constexpr const char *RED = "\033[31m";
    static constexpr const char *GREEN = "\033[32m";
    static constexpr const char *YELLOW = "\033[33m";
    static constexpr const char *BLUE = "\033[34m";
    static constexpr const char *PURPLE = "\033[35m";
    static constexpr const char *CYAN = "\033[36m";
    static constexpr const char *WHITE = "\033[37m";
};  // namespace COLORS

class Parrot
{

private:
    static bool hasDisplayedInitialMessage;

    static std::string logFileName;
    static bool isFileLoggingEnabled;
    static std::ofstream logFileStream;

    static void displayInitialMessage();

public:
    static void log(const std::string &message, const std::string &color, Utils::LogLevel level,
                    const std::string &prefix, const std::string &file_name, int line_no);

    static void setLevel(Utils::LogLevel level);

    static void enableFileLogging(const std::string &log_file_name, bool should_continue);
    static void enableFileLogging(bool should_continue);
    static void enableFileLogging();
    static void disableFileLogging();

    static void speak(const std::string &message, const std::string &color = COLORS::DEFAULT);

    static void info(const std::string &info_message);
    static void warn(const std::string &warn_message);
    static void error(const std::string &error_message);
};
