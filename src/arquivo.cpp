#include "arquivo.hpp"
#include <fstream>
#include <sstream>

// Formato: disciplina;descricao;data;prioridade;concluida
// Exemplo: PDS2;Entregar TP;25/06/2025;alta;false

bool ArquivoManager::salvarTarefas(const std::string& nomeArquivo, const std::vector<Tarefa>& tarefas) {
    std::ofstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) return false;

    for (const auto& tarefa : tarefas) {
        arquivo << tarefa.getDisciplina() << ";"
                << tarefa.getDescricao() << ";"
                << tarefa.getData() << ";"
                << tarefa.getPrioridade() << ";"
                << (tarefa.estaConcluida() ? "true" : "false") << "\n";
    }
    arquivo.close();
    return true;
}

std::vector<Tarefa> ArquivoManager::carregarTarefas(const std::string& nomeArquivo) {
    std::vector<Tarefa> tarefas;
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) return tarefas;

    std::string linha;
    while (std::getline(arquivo, linha)) {
        std::stringstream ss(linha);
        std::string disciplina, descricao, data, prioridade, concluidaStr;

        std::getline(ss, disciplina, ';');
        std::getline(ss, descricao, ';');
        std::getline(ss, data, ';');
        std::getline(ss, prioridade, ';');
        std::getline(ss, concluidaStr, ';');

        Tarefa tarefa(descricao, disciplina, data, prioridade);
        if (concluidaStr == "true") {
            tarefa.setConcluida(true);
        } else {
            tarefa.setConcluida(false);
        }
        tarefas.push_back(tarefa);
    }
    arquivo.close();
    return tarefas;
}
