#include "gerenciador.hpp"
#include <iostream>

void GerenciadorTarefas::adicionarTarefa(const Tarefa& tarefa) {
  tarefas.push_back(tarefa);
}

void GerenciadorTarefas::removerTarefa(int indice) {
  if (indice >= 0 && indice < tarefas.size()) {
    tarefas.erase(tarefas.begin() + indice);
  } else {
      std::cerr << "Erro: Índice inválido!\n";
    }
  }

void GerenciadorTarefas::listarTarefas(bool apenasPendentes) const {
  for (const auto& tarefa : tarefa) {
    if (!apenasPendentes || !tarefa.estaConcluida()) {
      std::cout << tarefa.getResumo() << "\n";
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
    
