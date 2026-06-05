#pragma once

#include <iostream>
#include <thread>
#include <chrono>

class MicrofoneCronometro {

public:

    void ativar(){

        std::cout
            << "Microfone ativado\n";
    }

    void desativar(){

        std::cout
            << "Microfone desativado\n";
    }

    void esperar_tempo(
        int tempo
    ){

        std::cout
            << "Tempo de fala: "
            << tempo
            << "s\n";

        std::this_thread::sleep_for(
            std::chrono::seconds(tempo)
        );
    }
};