#pragma once

#include <queue>

#include "PoliticoColaborador.h"

class PoliticoColaborador;

class GerenciadorDireitoResposta {

private:

    std::queue<
        PoliticoColaborador*
    > filaSolicitacoes;

    bool bloqueado;

public:

    GerenciadorDireitoResposta()
    : bloqueado(false) {}

    void solicitar(
        PoliticoColaborador* politico
    ){

        if(
            !bloqueado
            &&
            politico
        ){

            filaSolicitacoes.push(
                politico
            );
        }
    }

    bool possui_solicitacoes(){

        return
            !filaSolicitacoes.empty();
    }

    PoliticoColaborador*
    proximo(){

        if(
            filaSolicitacoes.empty()
        )
            return nullptr;

        auto politico =
            filaSolicitacoes.front();

        filaSolicitacoes.pop();

        return politico;
    }

    void bloquear(){

        bloqueado = true;
    }

    void desbloquear(){

        bloqueado = false;
    }

    bool esta_bloqueado(){

        return bloqueado;
    }

    void limpar(){

        while(
            !filaSolicitacoes.empty()
        ){

            filaSolicitacoes.pop();
        }
    }
};