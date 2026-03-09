---
title: "microarquitetura"
weight: 3
---

## Exemplo de Microarquitetura

- O projeto de microarquitetura pode ser visto como um problema de programação, onde cada instrução no nível ISA é uma função chamada por um programa mestre.
- O programa mestre é um laço simples e sem fim que invoca funções com base em variáveis acessíveis, conhecidas como o **estado do computador**.
- IFU -> instruction fetch unit
- EU -> executa
### Caminho de Dados
- O caminho de dados é a parte da CPU que contém a ULA (Unidade Lógica e Aritmética), suas entradas e saídas.
- Para controlar o caminho de dados, são necessários 29 sinais, divididos em cinco grupos funcionais:
  - sinais para controle de escrita nos registradores.
  - sinais para controle dos registradores para a entrada da ULA.
## Projeto de Nível de Microarquitetura

### Melhoria de Velocidade
- Existem três abordagens básicas para aumentar a velocidade de execução:
  1. Reduzir o número de ciclos de clock para cada instrução.
  2. Simplificar a organização, tornando o ciclo de clock mais curto.
  3. Sobrepor a execução de instruções.
### Operações por Instrução
- Para cada instrução, as seguintes operações podem ocorrer:
  1. O PC (Program Counter) é incrementado.
  2. O próximo byte da sequência de instruções é buscado.
  3. Operandos são lidos e escritos na memória.
  4. A ULA realiza cálculos e armazena os resultados.
### Pipeline
- Pipeline é uma técnica fundamental que permite sobreposição de execução de instruções, reduzindo o tempo total de processamento.
## Memória Cache

- Uma cache armazena palavras de memória usadas recentemente, acelerando o acesso.
- Muitas arquiteturas modernas utilizam **cache dividida** para instruções e dados.
- Sistemas podem ter até três níveis de cache para otimizar ainda mais o desempenho.

### Tipos de Cache
- **Cache de Mapeamento Direto**: o tipo mais simples de cache.
- **Cache Associativa**: permite que múltiplos blocos de memória sejam mapeados para uma mesma linha de cache.

## Previsão de Desvio

- Programas não seguem uma sequência linear, mas incluem muitas instruções de desvio.
- O pipelining precisa lidar com desvios, que criam **slots de atraso**.
- Técnicas como o **histórico de desvio de 1 bit** e **histórico de desvio de 2 bits** são utilizadas para prever desvios com mais precisão.

## Execução Fora de Ordem e Renomeação de Registrador

- A **renomeação de registrador** evita hazards entre instruções (WAR e WAW), alocando registradores temporários que não são visíveis para o programador.
- Esta técnica permite a emissão de instruções em paralelo, aumentando o desempenho.

## Execução Especulativa

- A execução especulativa divide o programa em **blocos básicos** e tenta prever a execução de instruções futuras.
- Um problema com a execução especulativa é que as instruções executadas podem causar exceções ou serem inválidas, pois dependem de uma condição futura.