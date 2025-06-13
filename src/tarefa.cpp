#include "tarefa.hpp"

// Construtor: inicializa todos os atributos
Tarefa::Tarefa(std::string desc, std::string disc, std::string dataEntrega, std::string prioridadeNivel) {
    descricao = desc;
    disciplina = disc;
    data = dataEntrega;
    prioridade = prioridadeNivel;
    concluida = false; // por padrão, tarefa começa como "não concluída"
}

// Getters
std::string Tarefa::getDescricao() const {
    return descricao;
}

std::string Tarefa::getDisciplina() const {
    return disciplina;
}

std::string Tarefa::getData() const {
    return data;
}

std::string Tarefa::getPrioridade() const {
    return prioridade;
}

bool Tarefa::estaConcluida() const {
    return concluida;
}

// Setters
void Tarefa::setDescricao(std::string novaDesc) {
    descricao = novaDesc;
}

void Tarefa::setDisciplina(std::string novaDisciplina) {
    disciplina = novaDisciplina;
}

void Tarefa::setData(std::string novaData) {
    data = novaData;
}

void Tarefa::setPrioridade(std::string novaPrioridade) {
    prioridade = novaPrioridade;
}

void Tarefa::setConcluida(bool status) {
    concluida = status;
}

// Método que retorna um resumo simples da tarefa, como: "Estudar PDS2 (PDS2 - 25/06)"
std::string Tarefa::getResumo() const {
    return descricao + " (" + disciplina + " - " + data + ")";
}
