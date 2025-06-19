#ifndef GERENCIADOR_HPP
#define GERENCIADOR_HPP

#include <vector>
#include <string>
#include "tarefa.hpp"

class GerenciadorTarefas {
private:
    std::vector<Tarefa> tarefas;

public:
    // Métodos básicos
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
    
    // Acesso às tarefas (para uso com ArquivoManager)
    const std::vector<Tarefa>& obterTarefas() const { return tarefas; }
    void definirTarefas(const std::vector<Tarefa>& novasTarefas) { tarefas = novasTarefas; }
};

#endif
