#pragma once
#include <string>
#include <ctime>

class Logger {
public:
    Logger() {}

    void error(std::string err);
    void warning(std::string warn);
    void info(std::string inf);
    void plaintext(std::string pt);
};
