#ifndef ARQUIVO_HPP 
#define ARQUIVO_HPP

#include <vector>
#include <string>
#include <stdexcept>  // <--- Adicionado para exceções
#include "tarefa.hpp"

/*
 * Classe utilitária para salvar e carregar tarefas de/para um arquivo.
 * Utiliza arquivos de texto no formato: disciplina;descricao;data;prioridade;concluida
 */
class ArquivoManager {
public:
    /*
     * Salva as tarefas em um arquivo. 
     * Retorna true se sucesso, false se falhar.
     */
    static bool salvarTarefas(const std::string& nomeArquivo, const std::vector<Tarefa>& tarefas);

    /*
     * Carrega tarefas do arquivo.
     * Lança std::runtime_error se não conseguir abrir o arquivo.
     */
    static std::vector<Tarefa> carregarTarefas(const std::string& nomeArquivo);
};

#endif
