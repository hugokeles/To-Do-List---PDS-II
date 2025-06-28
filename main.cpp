#include <iostream>
#include <string>
#include "tarefa.hpp"
#include "gerenciador.hpp"
#include "arquivo.hpp"

int main() {
    GerenciadorTarefas gerenciador;

    std::string nomeArquivo = "tarefas.csv";
    auto tarefasCarregadas = ArquivoManager::carregarTarefas(nomeArquivo);

    for (const auto& tarefa : tarefasCarregadas) {
        gerenciador.adicionarTarefa(tarefa);
    }

    int opcao = 0;
    while (opcao != 7) {
        std::cout << "\n===== To-Do List Universitário =====\n";
        std::cout << "1 - Adicionar tarefa\n";
        std::cout << "2 - Listar todas as tarefas\n";
        std::cout << "3 - Listar tarefas pendentes\n";
        std::cout << "4 - Filtrar por disciplina\n";
        std::cout << "5 - Marcar tarefa como concluída\n";
        std::cout << "6 - Salvar tarefas\n";
        std::cout << "7 - Sair\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;
     
        //Adicionar nova tarefa
        if (opcao == 1) {
            std::string desc, disc, data, prioridade;
            std::cout << "Descrição (sem espaços): ";
            std::cin >> desc;
            std::cout << "Disciplina (sem espaços): ";
            std::cin >> disc;
            std::cout << "Data (DD/MM/AAAA): ";
            std::cin >> data;
            std::cout << "Prioridade (alta/media/baixa): ";
            std::cin >> prioridade;

            Tarefa nova(desc, disc, data, prioridade);
            gerenciador.adicionarTarefa(nova);
            std::cout << "Tarefa adicionada!\n";

        } else if (opcao == 2) {
            gerenciador.listarTarefas();


        } else if (opcao == 3) {
            gerenciador.listarTarefasPendentes();

        } else if (opcao == 4) {
            std::string filtro;
            std::cout << "Digite a disciplina (sem espaços): ";
            std::cin >> filtro;

            auto filtradas = gerenciador.filtrarPorDisciplina(filtro);

            if (filtradas.empty()) {
                std::cout << "Nenhuma tarefa encontrada para essa disciplina.\n";
            } else {
                for (const auto& t : filtradas) {
                    std::cout << t.getResumo() << "\n";
                }
            }

        } else if (opcao == 5) {
            int indice;
            std::cout << "Digite o número da tarefa para marcar como concluída: ";
            std::cin >> indice;
            gerenciador.marcarComoConcluida(indice);

        } else if (opcao == 6) {
            bool sucesso = ArquivoManager::salvarTarefas(nomeArquivo, gerenciador.obterTarefas());

            if (sucesso) {
                std::cout << "Tarefas salvas com sucesso!\n";
            } else {
                std::cout << "Erro ao salvar tarefas!\n";
            }

        } else if (opcao == 7) {
            std::cout << "Encerrando o programa. Até logo!\n";
        } else {
            std::cout << "Opção inválida. Tente novamente.\n";
        }
    }

    return 0;
}