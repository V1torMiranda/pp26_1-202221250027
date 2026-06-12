#include "MediadorDebate.h"

#include "PoliticoColaborador.h"
#include "Configuracao.h"
#include "EstadoDebate.h"
#include "EstadoNormal.h"

MediadorDebate::MediadorDebate()
: inquiridor(nullptr),
  inquirido(nullptr)
{
    estadoAtual =
        new EstadoNormal();
}

void MediadorDebate::set_inquiridor(
    PoliticoColaborador* p
){
    inquiridor = p;
}

void MediadorDebate::set_inquirido(
    PoliticoColaborador* p
){
    inquirido = p;
}

PoliticoColaborador*
MediadorDebate::get_inquiridor(){

    return inquiridor;
}

PoliticoColaborador*
MediadorDebate::get_inquirido(){

    return inquirido;
}

void MediadorDebate::set_estado(
    EstadoDebate* estado
){

    estadoAtual = estado;
}

EstadoDebate*
MediadorDebate::get_estado(){

    return estadoAtual;
}

GerenciadorDireitoResposta&
MediadorDebate::get_gerenciador_dr(){

    return gerenciadorDR;
}

void MediadorDebate::debate(
    Configuracao& config
){

    if(estadoAtual){

        estadoAtual->executar(
            this,
            config
        );
    }
}