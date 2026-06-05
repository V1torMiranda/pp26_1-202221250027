#pragma once

#include "Mediador.h"
#include "PoliticoColaborador.h"
#include "Configuracao.h"
#include "Logger.h"

class MediadorDebate
: public Mediador {

private:

    PoliticoColaborador* inquiridor;
    PoliticoColaborador* inquirido;

public:

    void set_inquiridor(
        PoliticoColaborador* p
    ){
        inquiridor = p;
    }

    void set_inquirido(
        PoliticoColaborador* p
    ){
        inquirido = p;
    }

    void debate(
        Configuracao& config
    ) override {

        Logger::get_instance()
            ->register_log("Pergunta");

        inquiridor->falar(
            config.get_pergunta_tempo()
        );

        Logger::get_instance()
            ->register_log("Resposta");

        inquirido->falar(
            config.get_resposta_tempo()
        );

        Logger::get_instance()
            ->register_log("Replica");

        inquiridor->falar(
            config.get_replica_tempo()
        );

        Logger::get_instance()
            ->register_log("Treplica");

        inquirido->falar(
            config.get_treplica_tempo()
        );

        Logger::get_instance()
            ->register_log("Debate encerrado");
    }
};