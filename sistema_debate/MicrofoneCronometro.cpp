#include "MicrofoneCronometro.h"
#include "MediadorDebate.h"
#include "PoliticoColaborador.h"

#include <iostream>
#include <thread>
#include <chrono>

MicrofoneCronometro::MicrofoneCronometro()
: ligado(false),
  mediador(nullptr)
{
}

void MicrofoneCronometro::ativar(){

    ligado = true;

    std::cout
        << "Microfone ativado"
        << std::endl;
}

void MicrofoneCronometro::desativar(){

    ligado = false;

    std::cout
        << "Microfone desativado"
        << std::endl;
}

void MicrofoneCronometro::esperar_tempo(
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


void MicrofoneCronometro::solicitar_dr(
    PoliticoColaborador* politico
){

    std::cout
        << "Entrou em solicitar_dr"
        << std::endl;

    if(mediador == nullptr){

        std::cout
            << "Mediador nulo!"
            << std::endl;

        return;
    }

    std::cout
        << "Mediador OK"
        << std::endl;

    mediador
        ->get_gerenciador_dr()
        .solicitar(
            politico
        );

    std::cout
        << "Solicitacao enviada"
        << std::endl;
}

void MicrofoneCronometro::set_mediador(
    MediadorDebate* med
){

    mediador = med;
}