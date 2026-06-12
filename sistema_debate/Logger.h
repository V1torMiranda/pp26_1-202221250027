#pragma once

#include <vector>
#include <string>


class Logger {

private:
    static Logger* instance;
    std::vector<std::string> logs;
    
public:
    static Logger* get_instance();

    void register_log(
        const std::string& msg
    );

    void show_logs();
};