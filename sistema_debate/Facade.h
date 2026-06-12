#pragma once

#include "Logger.h"
#include "Configuracao.h"
#include "GerenciadorPoliticos.h"
#include "MediadorDebate.h"
#include "Eleitor.h"

class Facade {

private:

    static Facade* instance;

    Configuracao config;

    GerenciadorPoliticos gerencia;

    MediadorDebate mediador;

    Logger* logger;

    Facade(){

        logger =
            Logger::get_instance();

        logger->register_log(
            "Facade iniciada"
        );
    }

public:

    static Facade*
    get_instance(){

        if(instance == nullptr)
            instance = new Facade();

        return instance;
    }

    void configuracao(
        int p,
        int r,
        int rep,
        int trep
    ){

        config.set_pergunta_tempo(p);
        config.set_resposta_tempo(r);
        config.set_replica_tempo(rep);
        config.set_treplica_tempo(trep);
    }

    void cadastrar_politico(
        PoliticoColaborador* p
    ){

        p->set_mediador(&mediador);

        p->configurar_microfone(&mediador);

        gerencia.criar_politico(p);

        logger->register_log(
            "Politico cadastrado"
        );
    }

    void cadastrar_eleitor(
        Eleitor* eleitor,
        const std::string& candidato
    ){

        auto politico =
            gerencia.obter_politico(
                candidato
            );

        if(politico){

            politico->attach(
                eleitor
            );

            logger->register_log(
                "Eleitor cadastrado"
            );
        }
    }

    void sortear_inquiridor(){

        auto sorteado =
            gerencia.sortear();

        mediador.set_inquiridor(
            sorteado
        );

        logger->register_log(
            "Inquiridor sorteado: "
            + sorteado->get_nome()
        );
    }

    void sortear_participantes()
{
    auto inquiridor =
        gerencia.sortear();

    auto inquirido =
        gerencia.sortear_diferente(
            inquiridor
        );

    mediador.set_inquiridor(
        inquiridor
    );

    mediador.set_inquirido(
        inquirido
    );

    logger->register_log(
        "Inquiridor sorteado: "
        + inquiridor->get_nome()
    );

    logger->register_log(
        "Inquirido sorteado: "
        + inquirido->get_nome()
    );
}

    void escolher_inquirido(
        const std::string& nome
    ){

        auto politico =
            gerencia.obter_politico(
                nome
            );

        mediador.set_inquirido(
            politico
        );

        logger->register_log(
            "Inquirido escolhido: " + nome
        );
    }

    void iniciar_debate(
    int rodadas = 1
){

    logger->register_log(
        "Debate iniciado"
    );

    for(
        int i = 0;
        i < rodadas;
        i++
    ){

        logger->register_log(
    "========== RODADA "
    + std::to_string(i + 1)
    + " =========="
);

        sortear_participantes();

        mediador.debate(
            config
        );
    }
}

//     void solicitar_direito_resposta(
//     const std::string& nome
// );

    void mostrar_logs(){

        logger->show_logs();
    }

};

Facade* Facade::instance = nullptr;