#pragma once

class MediadorDebate;
class Configuracao;

class EstadoDebate {

public:

    virtual void executar(
        MediadorDebate* mediador,
        Configuracao& config
    ) = 0;

    virtual ~EstadoDebate() = default;
};