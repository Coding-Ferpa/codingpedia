---
title: "Exercicios-3"
weight: 3
---

# Programação dinâmica
1. Considere uma modificação do problema do corte da haste no qual, além de um preço
pi para cada haste, cada corte incorre em um custo fixo c. A receita associada à solução,
agora, é a soma dos preços das peças menos os custos da execução dos cortes. Dê um
algoritmo de programação dinâmica para resolver esse problema modificado.
2. Modifique CORTA-HASTE e CORTA-HASTE-MEMOIZADO de modo que seus laços for
subam para apenas ⌊n/2⌋, em vez de subir para n. Que outras mudanças de
procedimentos precisariam ser feitas? Como os tempos de execução seriam afetados?
3. Modifique CORTA-HASTE-MEMOIZADO para retornar não somente o valor, mas
também a solução propriamente dita.
4. Os números de Fibonacci são definidos pela recorrência:

Fi = {
0 se i = 0,
1 se i = 1,
Fi−1 + Fi−2

se i ≥ 2

Forneça um algoritmo de programação dinâmica de tempo O(n) para calcular o n-
ésimo número de Fibonacci.

5. Determine uma parentização ótima de um produto de cadeias de matrizes cuja
sequência de dimensões é 〈5, 10, 3, 12, 5, 50, 6〉.
6. Forneça um algoritmo recursivo MULTIPLICA-CADEIA-MATRIZES(A, s, i, j) que
realmente execute a multiplicação ótima de cadeias de matrizes, dadas a sequência
de matrizes 〈A1, A2, ..., An〉, a tabela s calculada por ORDENA-CADEIA-DE-MATRIZES e
os índices i e j. (A chamada inicial seria MULTIPLICA-CADEIA-MATRIZES(A, s, 1, n).)
Suponha que a chamada MULTIPLICA-MATRIZ-RETANGULAR(A, B) retorne o produto
das matrizes A e B.
7. Qual modo é mais eficiente para determinar o número ótimo de multiplicações em
um problema de multiplicação de cadeias de matrizes: enumerar todos os modos de
parentizar o produto e calcular o número de multiplicações para cada um ou
executar CADEIA-DE-MATRIZES-RECURSIVO? Justifique sua resposta.
8. Desenhe a árvore de recursão para o procedimento MERGE-SORT em um vetor de 16
elementos. Explique por que a memoização não aumenta a velocidade de um bom
algoritmo de divisão e conquista como MERGE-SORT.
9. Considere uma variante contrária do problema da multiplicação de cadeias de
matrizes na qual a meta é parentizar a sequência de matrizes de modo a maximizar,
em vez de minimizar, o número de multiplicações escalares. Esse problema exibe
subestrutura ótima?
10. Determine uma LCS de 〈1, 0, 0, 1, 0, 1, 0, 1〉 e 〈0, 1, 0, 1, 1, 0, 1, 1, 0〉.
11. Dê o pseudocódigo para reconstruir uma LCS partindo da tabela c concluída e das
sequências originais X = 〈x1, x2, ..., xm〉 e Y = 〈y1, y2, ..., yn〉 em tempo O(m + n), sem
usar a tabela b.

12. Dê uma versão memoizada de COMPRIMENTO-LCS que seja executada no tempo
O(mn).

# Algoritmos gulosos
1. (Problema das atividades) Suponha que, em vez de sempre selecionarmos a primeira
atividade a terminar, selecionemos a última atividade a começar que seja compatível
com todas as atividades selecionadas anteriormente. Descreva como essa
abordagem é um algoritmo guloso e prove que ela produz uma solução ótima.
2. Forneça uma solução de programação dinâmica para o problema binário da mochila
que seja executado no tempo O(nW), em que n é o número de itens e W é o peso
máximo de itens que o ladrão pode colocar em sua mochila.
3. (Huffman) Prove que uma árvore binária que não é estritamente binária não pode
corresponder a um código de prefixo ótimo.
4. Qual é o código de Huffman ótimo para o conjunto de frequências a seguir, baseado
nos oito primeiros números de Fibonacci?
a:1 b:1 c:2 d:3 e:5 f:8 g:13 h:21
Generalize sua resposta para determinar o código ótimo quando as frequências são os
primeiros n números de Fibonacci?
