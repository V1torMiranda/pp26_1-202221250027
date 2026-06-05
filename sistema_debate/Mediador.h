#pragma once

class Configuracao;

class Mediador {

public:

    virtual void debate(
        Configuracao& config
    ) = 0;

    virtual ~Mediador() = default;
};