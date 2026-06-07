#pragma once

#include <string>

#include "EleitorBuilder.h"
#include "Eleitor.h"

class EleitorConcretoBuilder
: public EleitorBuilder {

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

    Eleitor*
    build() override {

        return new
            Eleitor(
                nome
            );
    }
};