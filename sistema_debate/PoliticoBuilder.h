#pragma once

#include <string>

#include "Builder.h"

class PoliticoColaborador;

class PoliticoBuilder
: public Builder {

public:

    virtual void set_nome(
        const std::string& nome
    ) = 0;

    virtual PoliticoColaborador*
    build() = 0;

    virtual ~PoliticoBuilder() = default;
};