---
title: "aula 22 otim avaliacao"
weight: 4
---

# Tecnicas de Otimização de código
Precisa-se das medidas de desempenho em mão.

Pontos críticas de otimização:
- Linguagem (ou estruturas utilizadas): estruturas estaticas, simples e homogeneas sao usualmente mais rapidas e quanto menores melhores em comparacao a estruturas hetereogenas, dinamicas e de ponteiros (nem sempre eh possivel)
- Funções: deve-se evitar o uso de funções curtas, preferindo-se usar definições de macros (function inlining).
- Blocos de repetição: maior fonte para otimizações: 
1) Desdobramento de código
2) Remoção de testes desnecessários
3) Inversão de aninhamentos
4) Fissão ou fusão de laços


## Desdobramento de código
```c
// inicialmente
for (i=0; i<N; i++)
    A[i] = A[i] + B[i] * C;

// se torna
for (i=0; i<N; i=i+4)
{ A[i] = A[i] + B[i] * C;
    A[i+1] = A[i+1] + B[i+1] * C;
    A[i+2] = A[i+2] + B[i+2] * C;
    A[i+3] = A[i+3] + B[i+3] * C;
}

// Desdobramento de ciclos
ii = N % 4;

for (i=0; i<ii; i++)
    A[i] = A[i] + B[i] * C;

for (i=ii; i<N; i=i+4)
{ A[i] = A[i] + B[i] * C;
    A[i+1] = A[i+1] + B[i+1] * C;
    A[i+2] = A[i+2] + B[i+2] * C;
    A[i+3] = A[i+3] + B[i+3] * C;
}
```
## Remoção de testes desnecessários
Muitas vezes fazemos testes que, a menos por precisão, poderiam ser evitados

Podemos tirar testes com invariantes (constantes) completamente do código.

Testes que nao podem ser removidos com desdobramento podem ainda ser paralelizados se o hardware permitir loop unrolling ou processamento vetorial.

### Inversão de aninhamentos
Ciclos aninhados usualmente representam acesso a matrizes. A ordem de acesso a elementos de matrizes pode ser otimizada para melhorar o uso do cache.

```c
// inicialmente
for (i=0; i<N; i++)
    for (j=0; j<N; j++)
        A[i][j] = A[i][j] + B[i][j] * C;

// se torna
for (j=0; j<N; j++)
    for (i=0; i<N; i++)
        A[i][j] = A[i][j] + B[i][j] * C;
```

### Fissão ou fusão de laços

Fusão de laços é possível quando dois laços consecutivos operam sobre os mesmos indexadores de controle.

Fissão de laços é possível quando um laço realiza operações independentes que podem ser separadas em dois ou mais laços.

```c 
// inicialmente
for (i=0; i<N; i++) {
    D[i] = D[i] + E[i] * F;
}

for (i=0; i<N; i++) {
    A[i] = A[i] + B[i] * C;
}

// fusão de laços
for (i=0; i<N; i++) {
    A[i] = A[i] + B[i] * C;
    D[i] = D[i] + E[i] * F;
}
// fissão de laços
for (i=0; i<N; i++) {
    A[i] = A[i] + B[i] * C;
}
for (i=0; i<N; i++) {
    D[i] = D[i] + E[i] * F;
}
```

## Trabalho do compilador 

1) Propagação de código: quando uma expressão ou atribuição é repetida, o compilador pode substituir a expressão pelo seu valor já calculado anteriormente.
2) Renomeação de variáveis: quando duas variáveis não interferem entre si, o compilador pode renomear uma delas para evitar conflitos e melhorar a eficiência.
3) Desdobramento de constantes: quando uma variavel é calculada e tem valor constante, o compilador pode substituir a variavel pelo valor constante diretamente no código.
4) Redução de força: alterar operações custosas por mais simples. Exemplo: substituir multiplicações por somas repetidas.

# Técnicas de Avaliação de Desempenho

A própria definição de desempenho pode variar conforme o contexto, em geral envolve tempo.  No caso do HPC, algumas situações podem atrapalhar a avaliação de desempenho:
1) Overhead gerado pela paralelização, em atividades como
 - sincronismo,
 - comunicação,
 - processamento (do SO ou do próprio
 - programa)
2) Restrições como:
    - Trechos não paralelizáveis (Amdahl's Law)
    - Contenção de recursos (memória, barramentos, etc)
    - Ociosidade de processadores (load balancing)

## Medidas de Desempenho
Ganho de Velocidade (Speedup - S):
- Razão entre o tempo de execução sequencial (Ts) e o tempo de execução paralelo (Tp):
  $S = Ts / Tp$
> Lei de Amdahl: razão entre os tempos de execução de um programa considerando tanto seus trechos paralelizáveis quanto os estritamente sequenciais
> $S_n = \frac{1}{R_s + \frac{R_p}{n}} = \frac{n}{1 + (n - 1) \times \alpha}$ com $\alpha = R_s$
> Problema: essa lei esquece que se temos mais poder computacional iremos resolver problemas maiores.

> Lei de Gustafson: O ganho de velocidade pode aumentar com o aumento do tamanho do problema, mesmo que a fração sequencial permaneça constante.
> Mantem a carga em cada no fixa, aumentando a carga total do problema:
> $S_n = n - \alpha \times (n - 1)$

- Speedup medido: Tempo de execução sequencial medido / Tempo de execução paralelo medido

- Capacidade de crescimento (Scalability): Mede o quanto um problema ou sistema pode crescer sem prejuizo de desempenho. Depende de hardware, granularidade, custo de comunicação, etc. Nao indica ganho maximo de velocidade, mas quando esse ganho passa a ser prejudicado.

> Parallel Slowdown: Situação em que o tempo de execução paralelo é maior que o tempo de execução sequencial (S < 1).

Programa paralelo monoprocessado: abordagem otimista, speed up relativo. É o tempo de execução do programa quando executado em um unico processador.

## Medição e Predição (Benchmarking)

O que medir?
- Tempo de execução
- Tempo de CPU
- Tempo gasto em certas atividades
- Ganhos de velocidade em sistemas paralelos
- Eficiência na utilização de recursos

Como medir?
- Monitoramento 
1) por hardware: analisadores lógicos e outros equipamentos
2) por software: interrupções do SO
- Modificação do código
1) Inserção de pontos de medição (timers), seja na fonte, num objeto ou no executável

Monitoração vs Modificação

Existem duas abordagens principais para medição:

    Monitoração: 

    Mais precisa.

    Exige conhecimentos sobre hardware e sistema operacional.

    Pouco utilizada devido à complexidade e custo.

Modificação de código:

    Mais utilizada, feita com ferramentas prontas ou manualmente.

    Usa técnicas de profiling e extração de eventos.

Ferramentas comuns: prof, gprof, pixie, tcov.

Problemas: Precisão da amostragem e dificuldade em tratar paralelismo.

Técnicas de Modificação

1. Modificação de Objeto/Executável (Profiling) Exemplo de uso com gprof:

    Compilar com flag de profiling: gcc -pg loops.c -o loops 

Executar o programa: ./loops

Gerar arquivo de análise: gprof > loops.prof

Analisar o Flat profile (tempo gasto por função) e o Call graph (árvore de chamadas).

2. Modificação de Código Fonte (Instrumentação Manual) O programador insere chamadas de funções para contagem de tempo.

    Depende de acesso ao código fonte.

Gera overhead na medição (o próprio ato de medir consome tempo).

Funções como clock_gettime (precisão de nanossegundos) são usadas, mas sujeitas a aproximações do relógio do sistema.

```c

#include <time.h>
#include <stdio.h>

// Exemplo de medição manual [cite: 702, 703]
int main() {
    double Start, End, Duration;
    struct timespec tp;

    // Marca tempo inicial
    clock_gettime(CLOCK_REALTIME, &tp);
    Start = tp.tv_sec + tp.tv_nsec/1000000000.0;

    do_whatever_has_to_be_measured();

    // Marca tempo final
    clock_gettime(CLOCK_REALTIME, &tp);
    End = tp.tv_sec + tp.tv_nsec/1000000000.0;

    Duration = End - Start;
    printf("Function took %f seconds\n", Duration);
}
```

3. Instrumentação Dinâmica

    Ferramentas como Paradyn (usando Dyninst) permitem instrumentação em tempo de execução, diferente da instrumentação offline do prof.

## Benchmarking

Para medir desempenho de forma padronizada, utilizam-se benchmarks. É necessário definir a carga de trabalho (workload) e os padrões de medida (hardware, compiladores, etc).

Categorias de Benchmarks
- Por Organizações (Padrões de Referência): 
- Programas complexos que testam diferentes características (E/S, ponto flutuante, etc).
- Exemplos: 
1) SPEC: Diferenciado por segmentos (CPU, Web, Graphics).
2) NAS: Desenvolvido pela NASA (CFD applications).
3) Linpack/Lapack: Origem do ranking TOP500.
4) Rodinia: Focado em aceleradores (GPU, OpenMP, CUDA).

Locais:
- Desenvolvidos especificamente para uma aplicação da organização.
- Resultados válidos apenas localmente, não generalizáveis.

## Normalização de Resultados

Ao comparar sistemas com múltiplos programas de teste, não se deve apenas somar os tempos totais. É fundamental normalizar pelo volume de uso de cada programa.

    Análise Simplória (Errada): Somar tempos de execução de todos os programas. O sistema que roda mais rápido o programa menos usado pode parecer falsamente superior.

Análise Correta: Aplicar média ponderada baseada na frequência de uso de cada programa (Exemplo de Dowd & Severance).

Previsão de Desempenho

Além de medir (benchmarking), é possível prever o desempenho sem ter o sistema físico:

    Modelos Analíticos: 

    Formulação algébrica/matemática.

    Exemplos: Cadeias de Markov, Teoria de Filas, Redes de Petri.

Modelos de Simulação:

        Baseados em características funcionais e interações entre partes.

        Exemplos: Simuladores baseados em Monte Carlo, simuladores de nuvem (CloudSim).

Critérios de Escolha (Medir vs Prever)

A escolha depende de:

    Fase do projeto: Analíticos/Simulação são úteis antes do protótipo; Benchmarking/Instrumentação exigem o sistema (pós-protótipo).

    Tempo para resultados: Analíticos são rápidos; Simulação e Benchmarking demoram mais.

    Exatidão: Benchmarking tem exatidão variada (mas é real); Analíticos têm baixa exatidão; Simulação é moderada.

    Custo: Benchmarking tem alto custo; Analíticos baixo custo.

Ferramentas de Análise na Prática

Benchmarking e Profiling:

    Intel Advisor / vTune: Parte da suite oneAPI. Permitem análise global (CPU, GPU, Energia). O Advisor é focado em vetorização e Roofline Analysis. O vTune foca em traces e utilização de CPU.

TAU (Tuning and Analysis Utilities): Gera traces e profiles, configurável para diversos ambientes. Usa ferramentas de visualização como Paraprof (gera traces 3D).

Paradyn/Dyninst: Instrumentação dinâmica.

Scalasca: Focado em análise de desempenho paralelo.

Simulação:

    CloudSim Plus / Simgrid: Simulação de sistemas distribuídos e nuvem.

iSPD: Iconic Simulator of Parallel and Distributed Systems (focado em grades e IaaS).
