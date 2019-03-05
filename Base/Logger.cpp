#include "Logger.hpp"

void Logger::error(std::string err) {
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    char buf[255];
    strftime(buf, sizeof(buf), "[%H:%M %p] ERROR - ", now);
    std::string time(buf);
    fprintf(stderr, "%s", (time + err + "\n").c_str());
}

void Logger::warning(std::string warn) {
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    char buf[255];
    strftime(buf, sizeof(buf), "[%H:%M %p] - WARNING - ", now);
    std::string time(buf);
    fprintf(stderr, "%s", (time + warn + "\n").c_str());
}

void Logger::info(std::string inf) {
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);
    char buf[255];
    strftime(buf, sizeof(buf), "[%H:%M %p] - INFO - ", now);
    std::string time(buf);
    fprintf(stderr, "%s", (time + inf + "\n").c_str());
}

void Logger::plaintext(std::string pt) {
    fprintf(stderr, "%s", (pt + "\n").c_str());
}

