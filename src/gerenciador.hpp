#ifndef GERENCIADOR_HPP
#define GERENCIADOR_HPP

#include <vector>
#include <string>
#include "tarefa.hpp"

class GerenciadorTarefas {
private:
    std::vector<Tarefa> tarefas;
    
    // Métodos auxiliares para manipulação de arquivos
    bool salvarParaArquivo(const std::string& nomeArquivo) const;
    bool carregarDoArquivo(const std::string& nomeArquivo);

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
    
    // Persistência (interface simplificada)
    bool salvarTarefas(const std::string& nomeArquivo) const;
    bool carregarTarefas(const std::string& nomeArquivo);
};

#endif
