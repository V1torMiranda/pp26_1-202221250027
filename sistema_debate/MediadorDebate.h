#pragma once

#include "Mediador.h"
#include "GerenciadorDireitoResposta.h"

class PoliticoColaborador;
class Configuracao;
class EstadoDebate;

class MediadorDebate
: public Mediador {

private:

    PoliticoColaborador* inquiridor;

    PoliticoColaborador* inquirido;

    EstadoDebate* estadoAtual;

    GerenciadorDireitoResposta gerenciadorDR;

public:

    MediadorDebate();

    void set_inquiridor(
        PoliticoColaborador* p
    );

    void set_inquirido(
        PoliticoColaborador* p
    );

    PoliticoColaborador*
    get_inquiridor();

    PoliticoColaborador*
    get_inquirido();

    void set_estado(
        EstadoDebate* estado
    );

    EstadoDebate*
    get_estado();

    GerenciadorDireitoResposta&
    get_gerenciador_dr();

    void debate(
        Configuracao& config
    ) override;
};