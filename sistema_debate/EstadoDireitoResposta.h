#pragma once

#include "EstadoDebate.h"

class EstadoDireitoResposta
: public EstadoDebate {

public:

    void executar(
        MediadorDebate* mediador,
        Configuracao& config
    ) override;
};