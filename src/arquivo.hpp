#ifndef ARQUIVO_HPP
#define ARQUIVO_HPP

#include <vector>
#include <string>
#include "tarefa.hpp"

class ArquivoManager {
public:
    // Salva as tarefas em um arquivo de texto/csv no formato: disciplina;descricao;data;prioridade;concluida
    static bool salvarTarefas(const std::string& nomeArquivo, const std::vector<Tarefa>& tarefas);

    // Carrega as tarefas de um arquivo (no mesmo formato acima)
    static std::vector<Tarefa> carregarTarefas(const std::string& nomeArquivo);
};

#endif
