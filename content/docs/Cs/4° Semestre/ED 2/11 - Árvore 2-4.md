---
title: "Árvore 2-4"
weight: 3
---

É um caso especial da árvore B, de ordem 4. (árvore 2-3-4, arvore 2-4 ou arvore B simétrica)

Tem até quatro filhos e até 3 chaves. Mas esta não é usada em memória secundária.

__props__
- são balanceadas
- são boas pra memória principal

lidamos com overflow na inserção com um split simples, mas sem escrita na memória

A altura da árvore é O(log n).
![[arvore-2-4.excalidraw]]

A utilização de cada página tende a ser próxima dos 69%.

Essa árvore será, então, transformada em uma árvore binária na qual cada nó contém apenas uma chave.
Conexões que representam chaves pertencentes ao mesmo nó de uma árvore e conexões que representam uma relação regular pai-filhos entre nós -> chamadas de **ponteiros horizontais e verticais** (ponteiros r e ponteiros d). 

pode ser representado por uma **árvore rubro-negra**.


# Operações 
## Inserção
flag flipping

## Remoção
