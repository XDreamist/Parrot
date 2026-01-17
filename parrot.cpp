#include "parrot.h"

#include <fstream>
#include <iostream>

namespace Parrot
{

    // Initialize
    bool Config::hasDisplayedInitialMessage = false;

    std::string   Config::logFileName          = "parrot.log";
    bool          Config::isFileLoggingEnabled = false;
    std::ofstream Config::logFileStream;

    void Config::displayInitialMessage()
    {
        if (hasDisplayedInitialMessage) return;
        std::cout << "========== 🦜 Using Parrot Logger ==========\n";
        hasDisplayedInitialMessage = true;
    }

    /**
 * Used for basic logging functionalities
 */
    void Config::log(const std::string& message, const std::string& color, Utils::LogLevel level,
                     const std::string& prefix, const std::string& file_name, int line_no)
    {
        displayInitialMessage();

        std::string logLocation;
        if (!file_name.empty())
        {
            logLocation = "(" + file_name + ":" + std::to_string(line_no) + ")";
        }
        std::string logToDisplay = "[" + Utils::getTimeStamp() + "]" + color + " " + prefix + message + " " + COLORS::DEFAULT + logLocation;
        std::cout << logToDisplay << "\n";

        // File fileLogging
        if (isFileLoggingEnabled && logFileStream.is_open())
        {
            logFileStream << "[" << Utils::getTimeStamp() << "] " << prefix << message << " " << logLocation << "\n";
            logFileStream.flush();
        }
    }

    void Config::enableFileLogging(const std::string& log_file_name, bool append_logs)
    {
        if (isFileLoggingEnabled) return;

        logFileStream = std::ofstream(log_file_name, append_logs ? std::ios::app : std::ios::out);
        if (!logFileStream.is_open())
        {
            error("Failed to create or open log file: " + log_file_name);
            return;
        }
        isFileLoggingEnabled = true;
        logFileName          = log_file_name;
    }

    void Config::disableFileLogging()
    {
        if (!isFileLoggingEnabled) return;
        if (logFileStream.is_open()) logFileStream.close();

        isFileLoggingEnabled = false;
    }

    void Config::speak(const std::string& message, const std::string& color)
    {
        log(message, color, Utils::LogLevel::INFO, "SPEAK: ", __FILE__, __LINE__);
    }

}; // namespace Parrot
