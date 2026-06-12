#include "EstadoDireitoResposta.h"

#include "MediadorDebate.h"
#include "EstadoNormal.h"
#include "Logger.h"

void EstadoDireitoResposta::executar(
    MediadorDebate* mediador,
    Configuracao& config
){

    Logger::get_instance()
        ->register_log(
            "Inicio dos Direitos de Resposta"
        );

    auto& gerenciador =
        mediador->get_gerenciador_dr();

    while(
        gerenciador
            .possui_solicitacoes()
    ){

        auto politico =
            gerenciador.proximo();

        Logger::get_instance()
            ->register_log(
                "Direito de Resposta: "
                + politico->get_nome()
            );

        politico->falar(
            1
        );
    }

    Logger::get_instance()
        ->register_log(
            "Fim dos Direitos de Resposta"
        );

    mediador->set_estado(
        new EstadoNormal()
    );
}