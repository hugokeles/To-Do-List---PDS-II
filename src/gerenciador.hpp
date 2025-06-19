#ifndef GERENCIADOR_HPP
#define GERENCIADOR_HPP

#include <vector>
#include <string>
#include "tarefa.hpp"

class GerenciadorTarefas {
private:
    std::vector<Tarefa> tarefas;

public:
    // Gerenciamento básico
    void adicionarTarefa(const Tarefa& tarefa);
    void removerTarefa(int indice);
    
    // Visualização
    void listarTarefas() const;
    void listarTarefasPendentes() const;
    std::vector<Tarefa> filtrarPorDisciplina(const std::string& disciplina) const;
    
    // Organização
    void ordenarPorPrioridade();
    void ordenarPorData();
    
    // Status
    void marcarComoConcluida(int indice);
    
    // Lembretes
    std::vector<Tarefa> gerarLembretes(int dias = 3) const;
    
};

#endif
