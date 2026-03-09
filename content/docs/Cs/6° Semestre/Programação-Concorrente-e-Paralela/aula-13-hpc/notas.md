---
title: "notas"
weight: 4
---

# HPC em Sistemas Paralelos e Distribuídos

Como se pode introduzir computação de alto desempenho (HPC): 
    - Uso de supercomputadores
    - Clusters de computadores
    - Uso de grids 
    - Uso de processadores paralelos massivos (multicores e GPUs) híbridos

Cada um dos sistemas anteriores se diferenciam por terem arquiteturas diferentes. Cada qual apresenta recursos de hardware e desempenho distintos.

Possiveis mitigações para o gargalo de Von Neumann:
    - Uso de cache
    - Uso de pipelines
    - Uso de arquiteturas paralelas

Cache: armazenamento intermediário de dados e instruções em memória rápida. 
Pipeline: substitui a CPU por unidades especializadas em etapas do processamento de instruções.

## Arquiteturas Paralelas e Classificação de Flynn

Arquiteturas paralelas (baseado na Classificação de Flynn):
    - SISD: sistemas convencionais
    - SIMD: computadores vetoriais
    - MISD: arrays sistólicos
    - MIMD: paralelismo massivo

S=single, M=multiple, I=instruction stream, D=data stream

Isso altera fortemente a estrutura de memória vigente, tendo os multiprocessadores 3 modelos distintos:
    - UMA: uniform memory access
        Todos os dados, independente de onde se localizam, possuem tempo de acesso uniforme.
    - NUMA: not uniform memory access
        Cada processador possui memória local, o acesso a memórias remotas possuem tempos diferentes. Utiliza-se de um cluster hierárquico de memórias.
    - COMA: cache only memory access
        O acesso aos dados é feito considerando a memória local como memória chace.


## Sistemas distribuidos
O padrao de acesso a memória é feito por IPC (inter process communication)
    - troca de mensagens (RPC, Renzdevouz, Sockets, MPI...)
        Visto anteriormente
    - memória compartilhada distribuída (modelos PRAM - Parallel Random Access Machine)
        Temos as seguintes formas de acesso:
        - EREW: Escrita e Leitura esclusivas
        - CREW: Escrita exclusiva, Leitura concorrente
        - ERCW: Escrita concorrente, Leitura exclusiva
        - CRCW: Escrita e Leitura concorrentes
    Neste caso, conflitos de escritas são resolvidos por protocolos de coerência ou políticas de resolução de conflitos (todos iguais, ultimo a escrever, soma, etc)


## Padrao atual de HPC
Incremento de ambientes multicomputadores:
    - Clusters (Beowulf)
    - Grids computacionais
    - Soluções multicore (incluindo GPUs e FPGAs - Field Programmable Gate Arrays)
