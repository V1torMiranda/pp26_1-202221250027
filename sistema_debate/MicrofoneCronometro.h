#pragma once

class PoliticoColaborador;
class MediadorDebate;

class MicrofoneCronometro {

private:

    bool ligado;

    MediadorDebate* mediador;

public:

    MicrofoneCronometro();

    void ativar();

    void desativar();
    void esperar_tempo(int tempo);
    void set_mediador(
        MediadorDebate* m
    );

    void solicitar_dr(
        PoliticoColaborador* politico
    );
};