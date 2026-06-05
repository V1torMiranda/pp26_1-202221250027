#pragma once

class Configuracao {

private:

    int pergunta;
    int resposta;
    int replica;
    int treplica;

public:

    void set_pergunta_tempo(int t){
        pergunta = t;
    }

    void set_resposta_tempo(int t){
        resposta = t;
    }

    void set_replica_tempo(int t){
        replica = t;
    }

    void set_treplica_tempo(int t){
        treplica = t;
    }

    int get_pergunta_tempo(){
        return pergunta;
    }

    int get_resposta_tempo(){
        return resposta;
    }

    int get_replica_tempo(){
        return replica;
    }

    int get_treplica_tempo(){
        return treplica;
    }
};