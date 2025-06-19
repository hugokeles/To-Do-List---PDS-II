#include "gerenciador.hpp"
#include <iostream>
#include <algorithm>
#include <ctime>
#include <iomanip>

// Implementações dos métodos (sem lógica de arquivo)

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

void GerenciadorTarefas::marcarComoConcluida(int indice) {
    if (indice >= 0 && indice < static_cast<int>(tarefas.size())) {
        tarefas[indice].setConcluida(true);
    } else {
        std::cerr << "Erro: Índice inválido!\n";
    }
}

std::vector<Tarefa> GerenciadorTarefas::gerarLembretes(int dias) const {
    std::vector<Tare
