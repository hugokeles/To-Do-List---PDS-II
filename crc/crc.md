#Cartões CRC - To-Do List Universitário

##Classe: Tarefa
**Responsabilidades:**
- Armazenar os dados da tarefa: disciplina, prazo, prioridade e status (concluída ou pendente).
- Permitir atualizar o status da tarefa (ex.: marcar como concluída).

**Colaboradores:**
- GerenciadorTarefas (usa essa classe para acessar e gerenciar as tarefas).

---

## Classe: GerenciadorTarefas
**Responsabilidades:**
- Adicionar novas tarefas.
- Listar todas as tarefas cadastradas.
- Filtrar tarefas por disciplina.
- Ordenar tarefas por prioridade ou data.
- Marcar tarefas como concluídas.
- Gerar lembretes de tarefas com prazos próximos.

**Colaboradores:**
- Tarefa (para acessar e manipular os dados das tarefas).
- Arquivo (para salvar e carregar os dados).

---

## Classe: Arquivo (ou PersistenciaDados)
**Responsabilidades:**
- Salvar as tarefas em um arquivo.
- Carregar tarefas do arquivo quando o programa é iniciado.

**Colaboradores:**
- GerenciadorTarefas (envia e recebe dados da lista de tarefas).
- Tarefa (para ler e escrever os atributos de cada tarefa).

---

## Classe: Lembrete
**Responsabilidades:**
- Verificar tarefas com prazos próximos.
- Enviar notificações ou lembretes.

**Colaboradores:**
- GerenciadorTarefas (acessa a lista de tarefas).
- Tarefa (consulta as datas de entrega).
