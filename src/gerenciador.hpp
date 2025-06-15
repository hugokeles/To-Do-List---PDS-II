#ifndef GERENCIADOR_HPP
#define GERENCIADOR_HPP

#include <vector>

#include "tarefa.hpp"

class GerenciadorTarefas {
private:
  std::vector<Tareda> tarefas;

public:
   // Método para adicionar tarefas
  void adicionarTarefa(const Tarefa& tarefa);

  // Método para remover por índice
  void removerTarefa(int indice);

  //Método para listar tarefas
  void listarTarefas(bool apenasPendentes = false) const;

  //Filtra tarefas por disciplina
  std::vector<Tarefa> filtrarPorDisciplina(cont std::string& disciplina) const;
}
#endif
  
