---
title: "Paralelismo em nível de dados"
weight: 3
---

DLP (data level paralelism)

→ SIMD (Single Instruction Multiple Data)

- Arquiteturas Vetoriais
- SIMD para multimídia (SPDO – Simultaneous Parallel Data Operation);
- GPU (Graphical Processing Unit).
---
# Arquitetura vetorial

coleta dados da memória, coloca em arquivos em registradores sequenciais e os trata com uma instrução apenas, retornando a memória após o tratamento.

A ideia dos programas vetoriais é manter a memória ocupada todo tempo.

# VMIPS

- trata-se do uso da MIPS (microprocessors without interlocekd pipeline stages) mas vetorial, utilizado em RISC normalmente
- todas as operações são feitas em registradores, ou seja, tem a velocidade de memória mais absurda possível

## ISA VMIPS

- registradores vetoriais
    - único vetor fixo de um registrador
- unidades funcionais vetoriais
    - cada unidade é pipelined
    - uma operação iniciada por ciclo
- unidade de carregamento/armazenamento vetorial
    - carrega e armazena nas pipelines
- conjunto de registradores escalares
    - calculam os endereços para a load/store e promovem a entrada de dados na VMIPS

---

# Tempo de execução

depende

- do tamanho do vetor do registrador? e do geral
- taxa de consumo do operando
- comboio: instruções vetoriais que iniciam sua execução no mesmo período de clock
- tempo do comboio = chime =

$T =$

ciclos de clock(T) = comboios executados - chime(m) / tamanho do vetor (n)

## Otimizações

varias pipelines podem rodar ao mesmo tempo

→ loops

VLR → vector length register // MVL → Max vector length

ou seja, o código é dividido no tamanho do MVL e levado ao VLR

  

### Controle de máscara vetorial

tratar desvios condicionais → coloca-se cada execução condicional em uma instrução vetorial

→ VMR (vector mask register)

  

### Bancos de memória

espalhar o acesso de memória por vários bancos de memória independentes.

  

→ stride: manipulação de arrays multidimensionais

ao se unidimensionar um vetor que pertence a um espaço não unidimensional, o principio de localidade é alterado, portando, deve-se percorrer o vetor com strides (passos) de tamanho específico para cada espaço mantendo logicamente a localidade.

### Gather-Scatter

Gather: pega um vetor de índice e busca o vetores cujos os elementos estão nos endereços da operação;

Scatter: os elementos do vetor disperso são armazenados.

  

### Codando

compilador precisa informar trechos q podem ser vetorizados e tbm data dependency

---

# SIMD para multimidia

- poucos operandos e registradores menores
- n tem registradores de máscara nem gather-scatter

  

PULEI FODASSE VAI SE FODER MULTIMIDIA

---

[[GPU]]