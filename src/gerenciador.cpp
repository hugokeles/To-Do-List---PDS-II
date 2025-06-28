#include "gerenciador.hpp"
#include <iostream>
#include <algorithm>
#include <ctime>
#include <iomanip>

// Implementações dos métodos (sem lógica de arquivo)

void GerenciadorTarefas::adicionarTarefa(const Tarefa& tarefa) {
    tarefas.push_back(tarefa);
}

/*
 * Remove a tarefa do vetor usando índice.
 * Lança exceção se o índice for inválido.
 */
void GerenciadorTarefas::removerTarefa(int indice) {
    if (indice >= 0 && indice < static_cast<int>(tarefas.size())) {
        tarefas.erase(tarefas.begin() + indice);
    } else {
        throw std::out_of_range("Índice inválido para remoção de tarefa.");
    }
}

void GerenciadorTarefas::listarTarefas() const {
    for (size_t i = 0; i < tarefas.size(); ++i) {
        std::cout << "[" << i << "] " << tarefas[i].getResumo();
        if (tarefas[i].estaConcluida()) {
            std::cout << " [CONCLUÍDA]";
        }
        std::cout << " - Prioridade: " << tarefas[i].getPrioridade() << "\n";
    }
}

void GerenciadorTarefas::listarTarefasPendentes() const {
    for (size_t i = 0; i < tarefas.size(); ++i) {
        if (!tarefas[i].estaConcluida()) {
            std::cout << "[" << i << "] " << tarefas[i].getResumo() 
                      << " - Prioridade: " << tarefas[i].getPrioridade() << "\n";
        }
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

void GerenciadorTarefas::ordenarPorPrioridade() {
    auto compararPrioridades = [](const Tarefa& a, const Tarefa& b) {
        const std::string prioridades[] = {"alta", "media", "baixa"};
        int valorA = 3, valorB = 3;
        
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
    std::sort(tarefas.begin(), tarefas.end(), [converterData](const Tarefa& a, const Tarefa& b) {
        return converterData(a.getData()) < converterData(b.getData());
    });
}

/*
 * Marca a tarefa como concluída.
 * Lança exceção se o índice for inválido.
 */
void GerenciadorTarefas::marcarComoConcluida(int indice) {
    if (indice >= 0 && indice < static_cast<int>(tarefas.size())) {
        tarefas[indice].setConcluida(true);
    } else {
        throw std::out_of_range("Índice inválido ao marcar tarefa como concluída.");
    }
}

std::vector<Tarefa> GerenciadorTarefas::gerarLembretes(int dias) const {
    std::vector<Tarefa> lembretes;
    time_t agora = time(nullptr);
    struct tm* tm_agora = localtime(&agora);
    tm_agora->tm_hour = tm_agora->tm_min = tm_agora->tm_sec = 0;
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
