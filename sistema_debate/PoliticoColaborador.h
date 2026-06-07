#pragma once

#include <vector>
#include <algorithm>

#include "Observer.h"
#include "Prototype.h"
#include "MicrofoneCronometro.h"

class Mediador;

class PoliticoColaborador : public Prototype {

protected:

    std::string nome;

    bool sorteado;

    Mediador* mediador;

    MicrofoneCronometro microfone;

    std::vector<Observer*> observadores;

public:

    PoliticoColaborador(
        std::string nome
    )
    : nome(nome),
      sorteado(false),
      mediador(nullptr) {}


      void set_nome(
    const std::string& novoNome
){
    nome = novoNome;
}
    std::string get_nome() {
        return nome;
    }

    void attach(
        Observer* obs
    ){
        observadores.push_back(obs);
    }

    void detach(
        Observer* obs
    ){

        observadores.erase(
            std::remove(
                observadores.begin(),
                observadores.end(),
                obs),
            observadores.end()
        );
    }

    void notify(){

        std::string msg =
            "Candidato "
            + nome
            + " esta falando";

        for(auto obs : observadores)
            obs->update(msg);
    }

    virtual void falar(
        int tempo
    ){

        notify();

        microfone.ativar();

        microfone.esperar_tempo(
            tempo
        );

        microfone.desativar();
    }

    void set_mediador(
        Mediador* med
    ){
        mediador = med;
    }

    bool get_sorteado(){
        return sorteado;
    }

    void set_sorteado(
        bool op
    ){
        sorteado = op;
    }

    PoliticoColaborador*
        clone() const override {

    return new
        PoliticoColaborador(
            nome
        );
}
};