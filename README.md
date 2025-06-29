# To-Do List Universitário 📚✅

---

## Visão Geral do Projeto

O *To-Do List Universitário* é uma aplicação de terminal desenvolvida em C++ com o objetivo de ajudar estudantes universitários a gerenciar tarefas acadêmicas de forma simples e eficiente. O sistema permite organizar prazos de trabalhos, estudos para provas e tarefas de grupos, facilitando o cotidiano acadêmico.

---

## Funcionalidades Principais

- *Adicionar tarefas:* Inclua tarefas com informações como disciplina, descrição, data de entrega e prioridade.
- *Listar tarefas:* Visualize todas as tarefas ou filtre por disciplina ou status de conclusão.
- *Marcar como concluída:* Sinalize tarefas já realizadas.
- *Filtrar tarefas:* Exiba apenas tarefas de uma disciplina específica ou apenas pendentes.
- *Salvar e carregar dados:* As tarefas são persistidas em arquivo, evitando perda de dados.
- *Lembretes automáticos:* O sistema notifica sobre prazos próximos.
- *Ordenar tarefas:* Organize por prioridade ou data de entrega.

---

## Estrutura do Projeto


/src
  tarefa.hpp / tarefa.cpp         # Classe que representa uma tarefa
  gerenciador.hpp / gerenciador.cpp # Lógica de gerenciamento das tarefas
  arquivo.hpp / arquivo.cpp       # Persistência das tarefas em arquivo
  main.cpp                        # Interface de usuário (menu no terminal)
/docs
  README.md                       # Este arquivo


---

## Como Compilar e Executar

1. *Clone o repositório:*

bash
git clone https://github.com/hugokeles/To-Do-List---PDS-II.git
cd To-Do-List---PDS-II


2. *Compile o projeto:*

Se houver um Makefile:
bash
make

Ou, manualmente:
bash
g++ src/*.cpp -o todolist


3. *Execute o programa:*

No Linux/macOS:
bash
./todolist

No Windows:
bash
todolist.exe


---

## Exemplos de Uso

- *Adicionar tarefa:*  
  Preencha os campos solicitados pelo menu para incluir uma nova tarefa.
- *Listar tarefas:*  
  Escolha listar todas ou filtrar por disciplina/status.
- *Salvar/Carregar:*  
  O sistema salva automaticamente ao sair e carrega as tarefas ao iniciar.

---

## Tecnologias Utilizadas

- C++ (Standard Template Library: vector, string, etc)
- Paradigma: Programação Orientada a Objetos
- Persistência simples: arquivos .txt (formato CSV "simples")

---

## Sobre as Classes Principais

- *Tarefa:* Armazena os dados de cada tarefa.
- *GerenciadorTarefas:* Controla a lista de tarefas e oferece métodos de manipulação.
- *ArquivoManager:* Salva e carrega as tarefas do arquivo.
- *main.cpp:* Gerencia o menu e a interface com o usuário.

---

## Colaboradores

- Alexandre Rodrigues
- Hugo Keles
- Bruna Maria
- Pedro Lara

---

## Contribuição e Dúvidas

Fique à vontade para abrir uma issue com dúvidas, sugestões ou melhorias!

---

## Licença

Projeto acadêmico – uso livre para fins educacionais.
