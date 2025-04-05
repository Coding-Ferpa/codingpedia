# Processos
__Virtualizacao da CPU__: fazer cada processo achar que tem a totalidade da CPU atraves do Compartilhamento de Tempo da CPU.

__Mecanismos__ sao metodos e protocolos __low level__ que implementam funcionalidades do sistema.
__Estados de Maquina__: todos os componentes o qual o programa consegue alterar.

Estados dos processos:
- Running: executando as instrucoes.
- Ready: esta pronto, mas nao executando as instrucoes, por algum motivo.
- blocked: quando o processo precisa de alguma resposta de outro evento, e.g, I/O calls.

# Execucao Limitada e Direta

Esta tecnica eh bem simples, e direta, como o nome sugere. Apenas rodamos o programa requirido diretamente na CPU e limita esse processo de algumas forma.

Escopos: modo kernel e modo user. User pode acessar o kernel apenas atraves de mecanismos chamados __System Calls__, os quais geram __Traps de instrucoes__ que limitam o que o modo x pode acessar em y. 

# Context Switch

Podemos salvar o contexto atual de regs e memoria no kernel stack, para fazer o context switch entre o processo que esta rodando e o proximo.

# Escalonamento

Turnaround Time: Diferenca entre o tempo de completude e de chegada
Efeito de Comboio:
Tempo de resposta: Diferenca entre o 

SJF -> Shortest Job First (menor trabalho primeiro)
STCF -> Shortest Time-To-Completion First (se eh que possivel ser calculado)
RR -> Round Robin (procura menor tempo de resposta, da tempo igual pra todo mundo)

# Espacos de Memoria

# Virtualizacao de Memoria

# Segmentacao 

# Gerenciamento de Espacos Livres

# TLBs

# Tabelas Menores

# Swapping
