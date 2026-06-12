#include "EstadoNormal.h"
#include "Configuracao.h"
#include "MediadorDebate.h"
#include "EstadoAvaliandoDr.h"
#include "Logger.h"

void EstadoNormal::executar(
    MediadorDebate* mediador,
    Configuracao& config
){

    Logger::get_instance()
        ->register_log("Pergunta");

    mediador
        ->get_inquiridor()
        ->falar(
            config.get_pergunta_tempo()
        );

    Logger::get_instance()
        ->register_log("Resposta");

    mediador
        ->get_inquirido()
        ->falar(
            config.get_resposta_tempo()
        );

    Logger::get_instance()
        ->register_log("Replica");

    mediador
        ->get_inquiridor()
        ->falar(
            config.get_replica_tempo()
        );

    Logger::get_instance()
        ->register_log("Treplica");

    mediador
        ->get_inquirido()
        ->falar(
            config.get_treplica_tempo()
        );

    mediador->set_estado(
        new EstadoAvaliandoDR()
    );

    mediador
    ->get_estado()
    ->executar(
        mediador,
        config
    );
}