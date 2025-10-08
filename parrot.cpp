#include "parrot.h"

#include <fstream>
#include <iostream>

// Initialize
bool Parrot::hasDisplayedInitialMessage = false;

std::string Parrot::logFileName = "parrot.log";
bool Parrot::isFileLoggingEnabled = false;
std::ofstream Parrot::logFileStream;

void Parrot::displayInitialMessage()
{
    if (hasDisplayedInitialMessage)
        return;
    std::cout << "========== 🦜 Using Parrot Logger ==========\n";
    hasDisplayedInitialMessage = true;
}

/**
 * Used for basic logging functionalities
 */
void Parrot::log(const std::string &message, const std::string &color, Utils::LogLevel level, const std::string &prefix,
                 const std::string &file_name, int line_no)
{
    displayInitialMessage();

    std::string logLocation;
    if (!file_name.empty())
    {
        logLocation = "(" + file_name + ":" + std::to_string(line_no) + ")";
    }

    std::string logToDisplay =
        "[" + Utils::getTimeStamp() + "]" + color + " " + prefix + message + " " + COLORS::DEFAULT + logLocation;

    std::cout << logToDisplay << std::endl;

    // File fileLogging

    if (isFileLoggingEnabled && logFileStream.is_open())
    {
        logFileStream << "[" << Utils::getTimeStamp() << "] " << prefix << message << " " << logLocation << std::endl;
        logFileStream.flush();
    }
}

void Parrot::enableFileLogging(const std::string &log_file_name, bool should_coninue = false)
{
    if (isFileLoggingEnabled)
        return;

    logFileStream = std::ofstream(log_file_name, should_coninue ? std::ios::app : std::ios::out);
    if (!logFileStream.is_open())
    {
        error("Failed to create or open log file: " + log_file_name);
        return;
    }
    isFileLoggingEnabled = true;
    logFileName = log_file_name;
}
void Parrot::enableFileLogging(bool should_coninue) { enableFileLogging(logFileName, should_coninue); }
void Parrot::enableFileLogging() { enableFileLogging(logFileName); }

void Parrot::disableFileLogging()
{
    if (!isFileLoggingEnabled)
        return;

    if (logFileStream.is_open())
        logFileStream.close();

    isFileLoggingEnabled = false;
}

void Parrot::speak(const std::string &message, const std::string &color)
{
    log(message, color, Utils::LogLevel::INFO, "SPEAK: ", __FILE__, __LINE__);
}

void Parrot::info(const std::string &info_message)
{
    log(info_message, COLORS::CYAN, Utils::LogLevel::INFO, "INFO: ", __FILE__, __LINE__);
}

void Parrot::warn(const std::string &warn_message)
{
    log(warn_message, COLORS::YELLOW, Utils::LogLevel::WARN, "WARN: ", __FILE__, __LINE__);
}

void Parrot::error(const std::string &error_message)
{
    log(error_message, COLORS::RED, Utils::LogLevel::ERROR, "ERROR: ", __FILE__, __LINE__);
}
