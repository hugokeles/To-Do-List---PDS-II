#ifndef TAREFA_HPP
#define TAREFA_HPP

#include <string>
#include <stdexcept>  // Necessário para lançar exceções (ex: std::invalid_argument)

class Tarefa {
private:
    std::string descricao; //o que precisa ser feito
    std::string disciplina; //matéria da tarefa
    std::string data; //prazo: formato esperado: "DD/MM/AAAA"
    std::string prioridade; //nível de importância: "alta", "media" ou "baixa"
    bool concluida; //se a tarefa já foi feita (true ou false)

public:
    /*
     * Construtor da classe.
     * Pode lançar std::invalid_argument se prioridade ou data forem inválidas.
     */
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

    /*
     * Define a data de entrega da tarefa.
     * Lança exceção se a nova data for vazia.
     */
    void setData(std::string novaData);

    /*
     * Define a prioridade da tarefa.
     * Lança exceção se não for "alta", "media" ou "baixa".
     */
    void setPrioridade(std::string novaPrioridade);

    void setConcluida(bool status);

    // Retorna um resumo da tarefa, como: "Estudar PDS2 (PDS2 - 25/06/2025)"
    std::string getResumo() const;
};

#endif
