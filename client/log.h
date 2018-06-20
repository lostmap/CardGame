#ifndef LOG_H
#define LOG_H

#include <string>

class Log
{
private:
    Log(const std::string& filename, const std::string& errorFileName);
    Log(Log const&) = delete;
    Log& operator= (Log const&) = delete;

public:
    static Log& Instance(const std::string& filename = "", const std::string& errorFileName = "") {
        static Log instance(filename, errorFileName);
        return instance;
    }

    void log(std::string message);
    void error(std::string message);

};

#endif // LOG_H
