#pragma once

#include "EstadoDebate.h"

class EstadoNormal
: public EstadoDebate {

public:

    void executar(
        MediadorDebate* mediador,
        Configuracao& config
    ) override;
};