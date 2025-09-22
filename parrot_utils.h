#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <mutex>
#include <string>
#include <chrono>
#include <iomanip>
#include <vector>

namespace parrot_utils {

inline std::string simple_format(const std::string& fmt) {
    return fmt; // base case for recursion
}

template<typename T, typename... Args>
std::string simple_format(const std::string& fmt, T value, Args... args) {
    std::ostringstream oss;
    size_t pos = fmt.find("{}");
    if (pos != std::string::npos) {
        oss << fmt.substr(0, pos) << value << simple_format(fmt.substr(pos + 2), args...);
        return oss.str();
    }
    return fmt; // no more placeholders
}

} // namespace parrot_utils
