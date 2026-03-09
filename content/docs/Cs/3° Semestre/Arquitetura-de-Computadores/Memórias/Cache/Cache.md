---
title: "Cache"
weight: 5
---

Memoria mais rapida existente, usa o tipo fisico SRAM e metodo de acesso associativo.

  

### Localizacao

Entre a CPU e a memoria principal, separado em L1, L2 e L3

![[/Untitled 13.png|Untitled 13.png]]

  

# Operacao

CPU → solicita conteudo → verifica na cache (se tiver retorna) → (se nao) avanca para principal (por blocos) e o tras por completo a cache → de novo para a CPU

![[/Untitled 1 6.png|Untitled 1 6.png]]

  

# Funcoes de mapeamento

É forma como as informações são mapeadas na transferencia da memória  
principal para a cache, ou seja, como cada bloco e/ou palavra sera movido para a cache  

  

### Mapeamento Direto

- Uma palavra na cache naturalmente envolve:

![[/Untitled 2 3.png|Untitled 2 3.png]]

- Toda palavra da memoria principal e diretamente enviada para a cache
- Lento, mas barato e simples

  

### Mapeamento Associativo

Um bloco da memoria principal pode ser carregado em qualquer linha de cache, com uma tag para cada bloco e uma para cada palavra

  

### Mapeamento Associativo em Conjunto

Cache sera dividida em uma serie de conjuntos, os quais contem series de linhas, portanto, qualquer bloco eh mapeado a qualquer linha de qualquer conjunto.

  

# Algoritmos de Substituicao

- LFU (Least Frequently Used): Menos Frenquentemente Usado.
- LRU (Least Recently Used): Menos Recentemente Usado;
- FIFO (First-In-First-Out): Fila;
- MRU (Most Recently Used): Mais Recentemente Usado;

  

# Politicas de Escrita

- Write-through
    - Todas as escritas vão para a memória principal e também para a cache simultaneamente;
    - Muito trafego
- Write-back
    - Atualizações feitas inicialmente apenas na cache, bit de atualizacao eh definido quando ocorre atualizacao, ou seja, se o bloco nao for alterado, nao ocorre escrita alguma (nao havera bit de alteracao)

# Tamanho da palavra

Um tamanho de 8 a 64 bytes parece ser razoavelmente próximo do ideal, visto que não há um valor exato para a medida