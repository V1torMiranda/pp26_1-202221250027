#pragma once

#include <string>

#include "PoliticoBuilder.h"
#include "PoliticoColaborador.h"

class PoliticoConcretoBuilder
: public PoliticoBuilder {

private:

    std::string nome;

public:

    void reset() override {

        nome = "";
    }

    void set_nome(
        const std::string& n
    ) override {

        nome = n;
    }

    PoliticoColaborador*
    build() override {

        return new
            PoliticoColaborador(
                nome
            );
    }
};