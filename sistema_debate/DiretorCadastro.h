#pragma once

#include <string>

#include "PoliticoBuilder.h"
#include "EleitorBuilder.h"

class DiretorCadastro {

public:

    PoliticoColaborador*
    criar_politico(
        PoliticoBuilder& builder,
        const std::string& nome
    ){

        builder.reset();

        builder.set_nome(
            nome
        );

        return builder.build();
    }

    Eleitor*
    criar_eleitor(
        EleitorBuilder& builder,
        const std::string& nome
    ){

        builder.reset();

        builder.set_nome(
            nome
        );

        return builder.build();
    }
};