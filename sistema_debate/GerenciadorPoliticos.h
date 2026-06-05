#pragma once

#include <vector>
#include <cstdlib>
#include <ctime>

#include "PoliticoColaborador.h"

class GerenciadorPoliticos {

private:

    std::vector<PoliticoColaborador*> politicos;

public:

    GerenciadorPoliticos(){

        srand(time(nullptr));
    }

    void criar_politico(
        PoliticoColaborador* p
    ){
        politicos.push_back(p);
    }

    PoliticoColaborador*
    obter_politico(
        const std::string& nome
    ){

        for(auto p : politicos){

            if(
                p->get_nome() == nome
            )
                return p;
        }

        return nullptr;
    }

    PoliticoColaborador*
    sortear(){

        int pos =
            rand()
            % politicos.size();

        return politicos[pos];
    }

    PoliticoColaborador*
sortear_diferente(
    PoliticoColaborador* excluido
){
    std::vector<
        PoliticoColaborador*
    > candidatos;

    for(auto p : politicos){

        if(p != excluido)
            candidatos.push_back(p);
    }

    if(candidatos.empty())
        return nullptr;

    int pos =
        rand()
        % candidatos.size();

    return candidatos[pos];
}
};