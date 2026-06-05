#pragma once

#include <vector>
#include <string>
#include <iostream>

class Logger {

private:

    static Logger* instance;

    std::vector<std::string> logs;

    Logger() {}

public:

    static Logger* get_instance() {

        if(instance == nullptr)
            instance = new Logger();

        return instance;
    }

    void register_log(
        const std::string& msg
    ){

        logs.push_back(msg);

        std::cout
            << "\n[LOG] "
            << msg
            << std::endl;
    }

    void show_logs() {

        std::cout
            << "\n===== LOGS =====\n";

        for(auto& log : logs)
            std::cout
                << log
                << std::endl;
    }
};

Logger* Logger::instance = nullptr;