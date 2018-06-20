#include "log.h"

#include <iostream>
#include <cstdio>

Log::Log(const std::string& fileName, const std::string& errorFileName)
{
    freopen(fileName.c_str(), "w", stdout);
    freopen(errorFileName.c_str(), "w", stderr);
}


void Log::log(std::string message)
{
    std::cout<< message <<std::endl;
}

void Log::error(std::string message)
{
    std::cerr<< message <<std::endl;
}
