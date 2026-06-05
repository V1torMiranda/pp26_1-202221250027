#include "Facade.h"

int main() {

    auto facade =
        Facade::get_instance();

    auto lula =
        new PoliticoColaborador(
            "Lula"
        );

    auto bolsonaro =
        new PoliticoColaborador(
            "Bolsonaro"
        );

    auto vitor = 
        new PoliticoColaborador("Vitor");

    facade->cadastrar_politico(
        lula
    );

    facade->cadastrar_politico(
        bolsonaro
    );

    facade->cadastrar_politico(vitor);

    auto joao =
        new Eleitor("Joao");

    auto maria =
        new Eleitor("Maria");

    auto carlos =
        new Eleitor("Carlos");

    auto filipe =
        new Eleitor("Filipe");



    facade->cadastrar_eleitor(
        joao,
        "Lula"
    );

    facade->cadastrar_eleitor(
        maria,
        "Lula"
    );

    facade->cadastrar_eleitor(
        carlos,
        "Bolsonaro"
    );

    facade->cadastrar_eleitor(filipe, "Vitor");

    facade->configuracao(
        3,
        3,
        2,
        2
    );

    // facade->sortear_inquiridor();

    facade->sortear_participantes();

    facade->iniciar_debate();

    facade->mostrar_logs();

    return 0;
}