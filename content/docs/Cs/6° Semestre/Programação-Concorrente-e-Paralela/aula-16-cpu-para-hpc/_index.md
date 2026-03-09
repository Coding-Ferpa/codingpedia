---
title: "aula 16 cpu para hpc"
weight: 4
---

# Risc x Cisc
*Complex Instruction Set Computer (CISC)*: é mais simples para o programador, porém menos eficiente e usa menos memória, no entanto, pode exigir mais ciclos de clock para executar instruções complexas.

*Reduced Instruction Set Computer (RISC)*: é mais eficiente, porém mais complexo para o programador e usa mais memória. 

Atualmente, no entanto, vemos que os novos processadores pessoais tendem a ser RISC, como os processadores ARM (vide Apple Mk, Snapdragon e etc). Isso se deve ao fato de que a eficiência energética é um fator crucial em dispositivos móveis. Alem disso, o pipeling é mais fácil se instruções têm tamanhos fixos.


## Características do Risc
Arquitetura LOAD/STORE: apeans elas acessam memória. Todas as outras acessam registradores.

Ponto flutuante em pipelines: unidades especializadas para operações de ponto flutuante, que podem ser executadas em paralelo com outras instruções.

Tratamentos de desvios: pode-se usar predição, delay slot e execução condicional.
    - delay slot: instrução executada após um desvio, que independe do valor do desvio. Serve para evitar ociosidade no pipeline.


Técnicas básicas sobre como acelerar a execução de programas em CPUs RISC:
- Uso de pipelines: 
    1. aritmeticos: envolvem decompor instruções em etapas menores que podem ser executadas em paralelo.
    2. instruções: envolve load/store, busca, decode, etc. 
- Técnicas de predição de desvios
- Processamento fora de ordem: permite acelerar a execução de um programa com rearranjo dinâmico das instruções. O controle é feito por um buffer de despacho, que espera as seguinte condições:
    1. Ter dados disponíveis
    2. Ter uma unidade funcional livre
    3. Não criar conflitos de escrita
- Processamento multicore/manycore
