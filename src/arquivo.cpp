#include "arquivo.hpp"
#include <fstream>
#include <sstream>

/*
 * Salva as tarefas no formato: disciplina;descricao;data;prioridade;concluida
 */
bool ArquivoManager::salvarTarefas(const std::string& nomeArquivo, const std::vector<Tarefa>& tarefas) {
    std::ofstream arquivo(nomeArquivo);
    
    if (!arquivo.is_open()) {
        // Em vez de só retornar false, poderíamos também lançar exceção se preferir
        return false;
    }

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

/*
 * Lê o arquivo e reconstrói os objetos Tarefa.
 * Lança std::runtime_error se o arquivo não puder ser aberto.
 * Ignora linhas inválidas e continua lendo as próximas.
 */
std::vector<Tarefa> ArquivoManager::carregarTarefas(const std::string& nomeArquivo) {
    std::vector<Tarefa> tarefas;
    std::ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        throw std::runtime_error("Não foi possível abrir o arquivo para leitura.");
    }

    std::string linha;
    int linhaNum = 0;

    while (std::getline(arquivo, linha)) {
        ++linhaNum;

        std::stringstream ss(linha);
        std::string disciplina, descricao, data, prioridade, concluidaStr;

        // Lê os 5 campos separados por ponto e vírgula
        if (!std::getline(ss, disciplina, ';') ||
            !std::getline(ss, descricao, ';') ||
            !std::getline(ss, data, ';') ||
            !std::getline(ss, prioridade, ';') ||
            !std::getline(ss, concluidaStr, ';')) {
            
            std::cerr << "Linha " << linhaNum << " ignorada (formato inválido).\n";
            continue;
        }

        try {
            Tarefa tarefa(descricao, disciplina, data, prioridade);
            tarefa.setConcluida(concluidaStr == "true");
            tarefas.push_back(tarefa);
        } catch (const std::exception& e) {
            std::cerr << "Erro ao processar linha " << linhaNum << ": " << e.what() << "\n";
            // continua lendo as próximas linhas
        }
    }

    arquivo.close();
    return tarefas;
}
