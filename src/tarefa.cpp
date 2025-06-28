#include "tarefa.hpp"

// Construtor: inicializa todos os atributos
// Construtor com validação de data e prioridade
Tarefa::Tarefa(std::string desc, std::string disc, std::string dataEntrega, std::string prioridadeNivel) {
    if (dataEntrega.empty()) {
        throw std::invalid_argument("Data não pode estar vazia.");
    }

    if (prioridadeNivel != "alta" && prioridadeNivel != "media" && prioridadeNivel != "baixa") {
        throw std::invalid_argument("Prioridade inválida. Use alta, media ou baixa.");
    }
    
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
    if (novaData.empty()) {
        throw std::invalid_argument("Data não pode ser vazia.");
    }
    data = novaData;
}

void Tarefa::setPrioridade(std::string novaPrioridade) {
    if (novaPrioridade != "alta" && novaPrioridade != "media" && novaPrioridade != "baixa") {
        throw std::invalid_argument("Prioridade inválida.");
    }
    prioridade = novaPrioridade;
}

void Tarefa::setConcluida(bool status) {
    concluida = status;
}

// Método que retorna um resumo simples da tarefa, como: "Estudar PDS2 (PDS2 - 25/06)"
std::string Tarefa::getResumo() const {
    return descricao + " (" + disciplina + " - " + data + ")";
}
