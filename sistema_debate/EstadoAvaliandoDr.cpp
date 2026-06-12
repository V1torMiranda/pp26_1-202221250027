#include "EstadoAvaliandoDr.h"

#include "MediadorDebate.h"
#include "EstadoDireitoResposta.h"
#include "EstadoNormal.h"
#include "Logger.h"

void EstadoAvaliandoDR::executar(

    
    MediadorDebate* mediador,
    Configuracao& config
){

    Logger::get_instance()
        ->register_log(
            "Avaliando pedidos de DR"
        );

    if(
        mediador
            ->get_gerenciador_dr()
            .possui_solicitacoes()
    ){

        Logger::get_instance()
            ->register_log(
                "Pedidos encontrados"
            );

        mediador->set_estado(
            new EstadoDireitoResposta()
        );

        mediador
        ->get_estado()
        ->executar(
            mediador,
            config
        );
    }
    else{

        Logger::get_instance()
            ->register_log(
                "Nenhum pedido encontrado"
            );

        mediador->set_estado(
            new EstadoNormal()
        );
    }

   
}