---
title: "Exercicios-2"
weight: 3
---

# Heaps
1. Quais são os números mínimo e máximo de elementos em um heap de altura h?
R:
- mínimo: 2^h (apenas a última camada preenchida parcialmente).
- máximo: 2h+1−12h+1−1 (todas as camadas preenchidas completamente).

2. Mostre que um heap de n elementos tem altura ⌊lg n⌋.
R: Um heap nada mais eh do que uma arvore indexada, o que significa que as propriedades de altura permanecem. Ou seja, log n.

3. Mostre que, em qualquer subárvore de um heap de máximo, a raiz da subárvore
contém o maior valor que ocorre em qualquer lugar nessa subárvore.
R: 
A propriedade de heap de máximo garante que o valor na raiz de qualquer subárvore é maior ou igual aos valores em seus filhos, o que se propaga recursivamente para todos os descendentes.

4. Em que lugar de heap de máximo o menor elemento poderia residir, considerando que todos os elementos sejam distintos?
R:
O menor elemento estará em um dos nós folha, que correspondem às últimas ⌈n/2⌉ posições no array que representa o heap.


5. Um vetor que está em sequência ordenada é um heap de mínimo?
R: Sim, um vetor ordenado em ordem crescente satisfaz a propriedade de heap de mínimo, pois cada elemento é menor que ou igual aos seus filhos.


6. A sequência 〈33, 19, 20, 15, 13, 10, 2, 13, 16, 12〉 é um heap de máximo?
R: Nao, pois o elemento 16 eh filho de 15, porem, eh maior do que este.

7. Ilustre a operação de MAXIMIZA-HEAP (A, 3) sobre o vetor A = 〈7, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9, 0〉.
R: 
![[exercicio-7-lista-2-paa.png]]

8. Começando com o procedimento MAXIMIZA-HEAP, escreva o pseudocódigo para o
procedimento MINIMIZA-HEAP (A, i), que executa a manipulação correspondente
sobre um heap de mínimo.
R: 
```
MINIMIZA-HEAP(A, i)
    left = 2 * i
    right = 2 * i + 1
    smallest = i
    if left ≤ tamanho(A) and A[left] < A[smallest]
        smallest = left
    if right ≤ tamanho(A) and A[right] < A[smallest]
        smallest = right
    if smallest ≠ i
        troca A[i] e A[smallest]
        MINIMIZA-HEAP(A, smallest)

```
9. Qual é o efeito de chamar MAXIMIZA-HEAP(A, i) quando o elemento A\[i] é maior que seus filhos?
R: Nenhum, ele apenas nao fara nenhuma troca.


10. Ilustre a operação de HEAPSORT sobre o vetor A = 〈5, 13, 2, 25, 7, 17, 20, 8, 4〉.
R: 


11. Suponha que os objetos em uma fila de prioridade máxima sejam apenas chaves. Ilustre a operação de EXTRAI-MAX-MAX-HEAP sobre o heap A = 〈15, 13, 9, 5, 12, 8, 7, 4, 0, 6, 2, 1〉.
R:


12. Suponha que os objetos em uma fila de prioridade máxima sejam apenas chaves. Ilustre a operação de INSERE-MAX-HEAP(A, 10, 15) sobre o heap A = 〈15, 13, 9, 5, 12, 8, 7, 4, 0, 6, 2, 1〉.
R:


13. Mostre como implementar uma fila “primeiro a entrar, primeiro a sair” com uma fila de prioridade. Mostre como implementar uma pilha com uma fila de prioridades.
R: 

---
# Ordenação em tempo linear
1. Ilustre a operação de ORDENA-POR-CONTAGEM sobre o vetor A = 〈6, 0, 2, 0, 1, 3, 4, 6, 1, 3, 2〉.
R: ![[exercicio-1-counting-lista-2-paa.png]]


2. Prove o seguinte invariante de laço para ORDENA-POR-CONTAGEM: No início de cada iteração do laço for das linhas 11–13, o último elemento em A com valor i que ainda não foi copiado para B pertence a B\[C\[i]].
R:


3. Suponha que o vetor sendo ordenado contenha apenas inteiros no intervalo de 0 a k e que não haja dados satélites a serem movidos com essas chaves. Modifique a ordenação por contagem para que use apenas os vetores A e C, colocando o resultado ordenado de volta para o vetor A, em vez de um novo vetor B.
R:


4. Ilustre a operação de ORDENA-POR-DÍGITO sobre a seguinte lista de palavras em
inglês: COW, DOG, SEA, RUG, ROW, MOB, BOX, TAB, BAR, EAR, TAR, DIG, BIG, TEA,
NOW, FOX.
R:



5. Quais dos seguintes algoritmos de ordenação são estáveis: ordenação por inserção, ordenação por intercalação, ordenação por heap e quicksort? Forneça um esquema simples que torne estável qualquer algoritmo de ordenação. Quanto tempo e espaço adicionais seu esquema requer?
R:


6. Ilustre a operação de ORDENA-POR-BALDE no vetor A = 〈0,79, 0,13, 0,16, 0,64, 0,39, 0,20, 0,89, 0,53, 0,71, 0,42〉.
R:



7. Explique por que o tempo de execução do pior caso para a ordenação por balde é Θ(n 2). Qual é a alteração simples no algoritmo que preserva seu tempo de execução linear do caso médio e torna seu tempo de execução do pior caso igual a O(n lg n)?
R:


