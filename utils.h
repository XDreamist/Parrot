#pragma once

#include <cstdint>
#include <sstream>
#include <chrono>
#include <ctime>
#include <string>
#include <iomanip>

namespace Utils
{
    enum class LogLevel : uint8_t
    {
        INFO  = 0,
        WARN  = 1,
        ERROR = 2
    };

    static std::string getTimeStamp()
    {
        auto        now      = std::chrono::system_clock::now();
        std::time_t now_time = std::chrono::system_clock::to_time_t(now);

        // Convert to local time safely
        std::tm local_tm{};
#if defined(_WIN32)
        localtime_s(&local_tm, &now_time);
#else
        localtime_r(&now_time, &local_tm);
#endif

        // Determine AM/Pm and convert to 12-hour format
        int         hour  = local_tm.tm_hour;
        std::string am_pm = (hour >= 12) ? "PM" : "AM";
        if (hour == 0)
            hour = 12;
        else if (hour > 12)
            hour -= 12;

        // Format the time string
        std::ostringstream oss;
        oss << std::put_time(&local_tm, "%d-%m-%Y %H:%M:%S") << ' ' << am_pm;

        return oss.str();
    }

}; // namespace Utils
