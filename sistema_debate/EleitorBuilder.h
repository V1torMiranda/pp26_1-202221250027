#pragma once

#include <string>

#include "Builder.h"

class Eleitor;

class EleitorBuilder
: public Builder {

public:

    virtual void set_nome(
        const std::string& nome
    ) = 0;

    virtual Eleitor*
    build() = 0;

    virtual ~EleitorBuilder() = default;
};