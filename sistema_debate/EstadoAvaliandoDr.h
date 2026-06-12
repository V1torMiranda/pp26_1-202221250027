#pragma once

#include "EstadoDebate.h"

class EstadoAvaliandoDR
: public EstadoDebate {

public:

    void executar(
        MediadorDebate* mediador,
        Configuracao& config
    ) override;
};