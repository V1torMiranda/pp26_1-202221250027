#pragma once

#include "Observer.h"
#include <iostream>

class Eleitor : public Observer {

private:

    std::string nome;

public:

    Eleitor(
        const std::string& nome
    ) : nome(nome) {}

    void update(
        const std::string& msg
    ) override {
        
        std::cout
            << "\n[NOTIFICACAO] "
            << nome
            << ": "
            << msg
            << std::endl;
    }
};