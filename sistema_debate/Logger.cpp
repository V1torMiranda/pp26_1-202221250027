#include "Logger.h"
#include <iostream>

Logger* Logger::instance = nullptr;

Logger* Logger::get_instance() {

    if(instance == nullptr)
        instance = new Logger();

    return instance;
}

void Logger::register_log(
    const std::string& msg
){

    logs.push_back(msg);

    std::cout
        << "\n[LOG] "
        << msg
        << std::endl;
}

void Logger::show_logs() {

    std::cout
        << "\n===== LOGS =====\n";

    for(auto& log : logs)
        std::cout
            << log
            << std::endl;
}