---
title: "aula 17 memoria hpc"
weight: 4
---

# Memória para CAD (HPC)

Em geral, no passado (40 anos atras), a memoria tinha velocidade de clock muito similar ao clock da CPU. Hoje essa diferenca esta na escala de magnitude de $10^3$. Ao disco, então, a diferença é ainda mais significativa.

Hoje, temos memorias DRAM (dinamicas - precisa de refresh) e SRAM (estaticas).

Usou-se, por muito tempo, a métrica de Tempo de Ciclo (Cycle Time) para aferir a velocidade da memória, visto que o clock era sincrono, em tempos, com a CPU. No entanto, usaremos a banda-larga de memória (Memory Bandwidth) como métrica principal, ou seja, quantos bytes pode-se transferir para cada unidade de tempo.

---
# Obtendo desempenho

- Usar apenas componentes mais rapidos, porem caros.
- Antecipar o acesso em componentes lentos. Assim, teriamos os dados ja na cpu quando necessarios (prefetching).
- Transferir um volume de dados maior por acesso (largura de banda maior).
- Usar hierarquia de memoria (cache).
- Arquiteturas tridimensionais de memoria. Por exemplo: Hybrid Memory Cube (HMC) - largura alta e canal lento - e High Bandwidth Memory (HBM) - largura muito alta e canal rapido.
- GDDR6 (Graphics Double Data Rate 6) - memoria para placas de video.

# Hierarquia de Memoria
- registradores  - 2ns
- cache L1, L2, L3 - 2 a 30ns
- memoria principal (DRAM) - 50 a 200ns
- memoria secundaria (SSD, HD) - 5 a 10ms
- bibliotecas (fitas, CD-ROMs, DVDs, etc.)
- armazenamento remoto - 100ms a segundos

# Gerenciamento do subsistema de memória

Para a memoria principal, temos:
- tradução de endereços lógicos e físicos
1. relocação estática: endereços são converttidos durante o carregamento de um programa
2. relocação dinâmica: endereços são convertidos durante a execução do programa
3. em sistemas de uso geral, podemos utilizar a segmentação estrututal dos programas, separando código, dados e pilha. Ou então, a paginação, onde o espaço de endereçamento é dividido em blocos de tamanho fixo (páginas) e alocados conforme a necessidade do programa.
- alocação de espaço de memória
1. alocação contígua: blocos de memória (usualmente associados a estruturas de dados homogêneas) são alocados em blocos contíguos de memória física.)
2. alocação não contígua: blocos de memória são alocados em blocos não contíguos.
3. alocação em blocos: os bytes dos segmentos são armazenados em páginas de tamanho fixo, não (necessariamente) sequenciais. Demanda o uso de hardware especial (MMU - memory management unit e TLB - translation lookaside buffer).

## Fragmentação
A fragmentação representa inutilizar-se certas regiões da memória, mesmo que vazias, e é causada conforme a alocação dinâmica é feita. Existem dois tipos principais de fragmentação:
- Fragmentação externa: ocorre quando há espaço suficiente na memória para alocar um bloco, mas esse espaço está dividido em pequenos blocos não contíguos.
- Fragmentação interna: ocorre quando o bloco alocado é maior do que o que é exigido pelo conjunto de bytes residente na página, resultando em espaço não utilizado dentro do bloco alocado.

Podemos tratar esse sintoma da segmentação com:
    - best fit, worst fit e first fit (algoritmos de alocação)
    - compactação de memória (realocação dos blocos alocados para formar um bloco


## Memória Virtual
O tamanho da memória física torna-se menos relevante, visto que este método virtualiza os endereços e permite que as páginas sejam carregadas ou removidas da memória principal (para a secundária) conforme o programa precise.

### Algoritmos de paginação 
Eles necessitam de algumas parametros, como sequencia de referencia, conjunto residente (número de quadros alocados para o processo), tamanho do conjunto residente, taxa de faltas de página.

Destacam-se:
- Fifo (first in, first out): pode causar a anomalia de Belady (aumentar o número de quadros pode aumentar o número de faltas de página)
- LRU  (last recently used)
- opt (ideal)
- Segunda chance (tenta trocar a pagina 2 vezes, se for referenciada na 1a vez, ganha uma "segunda chance")

Problemas decorrentes:
    - Taxa de faltas de página
    - Nivel de multiprogramacao: diminui o tamanho do conjunto residente de cada processo, o que pode aumentar a taxa de faltas de página.
    - Trashing: muito hit miss de paginas causa muita troca de paginas entre memoria principal e secundaria, deixando a CPU sem tempo para executar os processos.
    - Coerencia de cache: quando uma pagina é trocada, o cache deve ser invalidado. Tecnicas de manutencao: write-through e write-back.


### Maquinas virtuais
Duas estruturas podem ser usadas:
- MV globalmente compartilhada
- MV privativas em cada processador

### Mapeamento de cache
- Direto: o que esta na cache mapeia diretamente para um bloco na memoria principal.
- Associativo por conjunto: uma linha da cache pode armazenar blocos de um conjunto especifico da memoria principal, ou seja, a traducao e feita em dois passos: primeiro, identifica-se o conjunto na cache, depois, procura-se o bloco dentro do conjunto.
- Totalmente associativo: qualquer bloco da memoria principal pode ser armazenado em qualquer bloco da cache, com uma tabela de mapeamento.
