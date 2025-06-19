#include "gerenciador.hpp"
#include <iostream>
#include <algorithm>
#include <ctime>
#include <fstream>
#include <sstream>
#include <iomanip>

// Métodos básicos de gerenciamento
void GerenciadorTarefas::adicionarTarefa(const Tarefa& tarefa) {
    tarefas.push_back(tarefa);
}

void GerenciadorTarefas::removerTarefa(int indice) {
    if (indice >= 0 && indice < static_cast<int>(tarefas.size())) {
        tarefas.erase(tarefas.begin() + indice);
    } else {
        std::cerr << "Erro: Índice inválido!\n";
    }
}

// Métodos de visualização
void GerenciadorTarefas::listarTarefas() const {
    if (tarefas.empty()) {
        std::cout << "Nenhuma tarefa cadastrada.\n";
        return;
    }

    for (size_t i = 0; i < tarefas.size(); ++i) {
        std::cout << "[" << i << "] " << tarefas[i].getResumo();
        std::cout << " - Prioridade: " << tarefas[i].getPrioridade();
        if (tarefas[i].estaConcluida()) {
            std::cout << " [CONCLUÍDA]";
        }
        std::cout << "\n";
    }
}

void GerenciadorTarefas::listarTarefasPendentes() const {
    bool encontrouPendentes = false;
    
    for (size_t i = 0; i < tarefas.size(); ++i) {
        if (!tarefas[i].estaConcluida()) {
            std::cout << "[" << i << "] " << tarefas[i].getResumo() 
                      << " - Prioridade: " << tarefas[i].getPrioridade() << "\n";
            encontrouPendentes = true;
        }
    }
    
    if (!encontrouPendentes) {
        std::cout << "Nenhuma tarefa pendente.\n";
    }
}

std::vector<Tarefa> GerenciadorTarefas::filtrarPorDisciplina(const std::string& disciplina) const {
    std::vector<Tarefa> filtradas;
    for (const auto& tarefa : tarefas) {
        if (tarefa.getDisciplina() == disciplina) {
            filtradas.push_back(tarefa);
        }
    }
    return filtradas;
}

// Métodos de organização
void GerenciadorTarefas::ordenarPorPrioridade() {
    auto compararPrioridades = [](const Tarefa& a, const Tarefa& b) {
        const std::string prioridades[] = {"alta", "media", "baixa"};
        int valorA = 3, valorB = 3; // Valor padrão para prioridades desconhecidas
        
        for (int i = 0; i < 3; ++i) {
            if (a.getPrioridade() == prioridades[i]) valorA = i;
            if (b.getPrioridade() == prioridades[i]) valorB = i;
        }
        return valorA < valorB;
    };
    
    std::sort(tarefas.begin(), tarefas.end(), compararPrioridades);
}

void GerenciadorTarefas::ordenarPorData() {
    auto converterData = [](const std::string& data) {
        struct tm tm = {0};
        strptime(data.c_str(), "%d/%m/%Y", &tm);
        return mktime(&tm);
    };
    
    auto compararDatas = [converterData](const Tarefa& a, const Tarefa& b) {
        return converterData(a.getData()) < converterData(b.getData());
    };
    
    std::sort(tarefas.begin(), tarefas.end(), compararDatas);
}

// Métodos de status
void GerenciadorTarefas::marcarComoConcluida(int indice) {
    if (indice >= 0 && indice < static_cast<int>(tarefas.size())) {
        tarefas[indice].setConcluida(true);
        std::cout << "Tarefa marcada como concluída: " 
                  << tarefas[indice].getResumo() << "\n";
    } else {
        std::cerr << "Erro: Índice inválido!\n";
    }
}

// Métodos de lembretes
std::vector<Tarefa> GerenciadorTarefas::gerarLembretes(int dias) const {
    std::vector<Tarefa> lembretes;
    time_t agora = time(nullptr);
    struct tm* tm_agora = localtime(&agora);
    tm_agora->tm_hour = 0;
    tm_agora->tm_min = 0;
    tm_agora->tm_sec = 0;
    agora = mktime(tm_agora);
    
    for (const auto& tarefa : tarefas) {
        if (!tarefa.estaConcluida()) {
            struct tm tm_tarefa = {0};
            strptime(tarefa.getData().c_str(), "%d/%m/%Y", &tm_tarefa);
            time_t time_tarefa = mktime(&tm_tarefa);
            
            double diferenca = difftime(time_tarefa, agora) / (60 * 60 * 24);
            
            if (diferenca >= 0 && diferenca <= dias) {
                lembretes.push_back(tarefa);
            }
        }
    }
    return lembretes;
}

// Métodos de persistência (privados)
bool GerenciadorTarefas::salvarParaArquivo(const std::string& nomeArquivo) const {
    std::ofstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir arquivo para escrita: " << nomeArquivo << "\n";
        return false;
    }

    for (const auto& tarefa : tarefas) {
        arquivo << tarefa.getDisciplina() << ";"
                << tarefa.getDescricao() << ";"
                << tarefa.getData() << ";"
                << tarefa.getPrioridade() << ";"
                << (tarefa.estaConcluida() ? "true" : "false") << "\n";
    }
    
    return true;
}

bool GerenciadorTarefas::carregarDoArquivo(const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        std::cerr << "Arquivo não encontrado: " << nomeArquivo << "\n";
        return false;
    }

    std::vector<Tarefa> temp;
    std::string linha;
    
    while (std::getline(arquivo, linha)) {
        std::stringstream ss(linha);
        std::string disciplina, descricao, data, prioridade, concluidaStr;

        std::getline(ss, disciplina, ';');
        std::getline(ss, descricao, ';');
        std::getline(ss, data, ';');
        std::getline(ss, prioridade, ';');
        std::getline(ss, concluidaStr);

        if (disciplina.empty() || descricao.empty() || data.empty() || prioridade.empty()) {
            continue; // Ignora linhas inválidas
        }

        Tarefa tarefa(descricao, disciplina, data, prioridade);
        tarefa.setConcluida(concluidaStr == "true");
        temp.push_back(tarefa);
    }

    tarefas = temp;
    return true;
}

// Métodos públicos de persistência
bool GerenciadorTarefas::salvarTarefas(const std::string& nomeArquivo) const {
    return salvarParaArquivo(nomeArquivo);
}

bool GerenciadorTarefas::carregarTarefas(const std::string& nomeArquivo) {
    return carregarDoArquivo(nomeArquivo);
}
