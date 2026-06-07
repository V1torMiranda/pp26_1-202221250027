#include "Facade.h"

#include "DiretorCadastro.h"
#include "PoliticoConcretoBuilder.h"
#include "EleitorConcretoBuilder.h"

int main() {

    auto facade =
        Facade::get_instance();

    DiretorCadastro diretor;

    PoliticoConcretoBuilder politicoBuilder;
    EleitorConcretoBuilder eleitorBuilder;

    // =========================
    // Politicos (Builder)
    // =========================

    auto lula =
        diretor.criar_politico(
            politicoBuilder,
            "Lula"
        );

    auto bolsonaro =
        diretor.criar_politico(
            politicoBuilder,
            "Bolsonaro"
        );

    auto vitor =
        diretor.criar_politico(
            politicoBuilder,
            "Vitor"
        );

    facade->cadastrar_politico(
        lula
    );

    facade->cadastrar_politico(
        bolsonaro
    );

    facade->cadastrar_politico(
        vitor
    );

    // =========================
    // Eleitores (Builder)
    // =========================

    auto joao =
        diretor.criar_eleitor(
            eleitorBuilder,
            "Joao"
        );

    auto maria =
        diretor.criar_eleitor(
            eleitorBuilder,
            "Maria"
        );

    auto carlos =
        diretor.criar_eleitor(
            eleitorBuilder,
            "Carlos"
        );

    auto filipe =
        diretor.criar_eleitor(
            eleitorBuilder,
            "Filipe"
        );

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

    facade->cadastrar_eleitor(
        filipe,
        "Vitor"
    );

    // =========================
    // Prototype
    // =========================

    auto lulaClone =
        lula->clone();

    lulaClone->set_nome(
        "Lula Clone"
    );

    facade->cadastrar_politico(
        lulaClone
    );

    // =========================
    // Configuracao
    // =========================

    facade->configuracao(
        3,
        3,
        2,
        2
    );

    // =========================
    // Sorteio automatico
    // =========================

    facade->sortear_participantes();

    // =========================
    // Debate
    // =========================

    std::cout
    << "\n=== TESTE PROTOTYPE ==="
    << std::endl;

    std::cout
    << "Original: "
    << lula->get_nome()
    << " | Endereco: "
    << lula
    << std::endl;

    std::cout
    << "Clone: "
    << lulaClone->get_nome()
    << " | Endereco: "
    << lulaClone
    << std::endl;

    facade->iniciar_debate();

    facade->mostrar_logs();

    return 0;
}