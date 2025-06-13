#ifndef TAREFA_HPP
#define TAREFA_HPP

#include <string>

class Tarefa {
private:
    std::string descricao;
    std::string disciplina;
    std::string data; // formato esperado: "DD/MM/AAAA"
    std::string prioridade; // "alta", "media" ou "baixa"
    bool concluida;

public:
    // Construtor
    Tarefa(std::string desc, std::string disc, std::string dataEntrega, std::string prioridadeNivel);

    // Getters
    std::string getDescricao() const;
    std::string getDisciplina() const;
    std::string getData() const;
    std::string getPrioridade() const;
    bool estaConcluida() const;

    // Setters
    void setDescricao(std::string novaDesc);
    void setDisciplina(std::string novaDisciplina);
    void setData(std::string novaData);
    void setPrioridade(std::string novaPrioridade);
    void setConcluida(bool status);

    // Retorna um resumo formatado da tarefa
    std::string getResumo() const;
};

#endif
