---
title: "Ordenacao em Tempo Linear"
weight: 3
---

O modelo de árvore de decisão:
- uma árvore binária cheia que representa comparações entre elementos para obter informações de ordem para uma sequência de entrada. Isto é, dados 2 elementos $a_{i}$ e $a_{j}$ executamos um dos testes $a_i< a_j, a_i \leq a_j, a_i = a_j, a_i > a_{j} \ ou \  a_{i} \geq a$

## props
- cada nó interno é tido como um intervalo do vetor $i:j$.
- cada folha é uma permutação entre os elementos do vetor.

# Ordenação por contagem (Counting Sort)
Uma ordenação por contagem supõe que cada um dos n elementos de entrada é um inteiro na faixa 1 a k, para algum inteiro k. Quando k = $O(n)$ a ordenação é executada no tempo n.

A ordenação por contagem determina, para cada elemento de entrada x, o número de elementos menores que x e usa essa info para inserir o elemento x diretamente eu sua posição no arranjo de saída.

- não aceita números negativos
- o vetor C conta a quantidade de valores em A iguais a $i$

![[Pasted image 20241007105202.png]]

Pseudo codigo:
```
countingSort(A, n, k):
	sejam B[1 : n] e C[0 : k] novos vetores
	for i = 0 até k
		C[i] = 0
	for j = 1 até n
		C[A[j]] = C[A[j]] + 1
		// C[i] contém agora o número de elementos iguais a i.
	for i = 1 até k
		C[i] = C[i] + C[i – 1]
		// C[i] contém agora o número de elementos menores ou iguais a i.
		// Copia A para B, começando do final de A.
	for j = n até 1
		B[C[A[j]]] = A[j]
		C[A[j]] = C[A[j]] – 1 //para lidar com valores duplicados
	return B

```
O laço for das linhas 2–3 demora o tempo Θ(k), o laço for das linhas 4–5 demora o tempo Θ(n), o laço for das linhas 7–8 demora o tempo Θ(k) e o laço for das linhas 11–13 demora o tempo Θ(n). Assim, o tempo total é Θ(k + n). Na prática, normalmente usamos a ordenação por contagem quando temos k = O(n), caso em que o tempo de execução é Θ(n). 

O counting sort supera o limite de $\Omega (n lg(n))$ porque não é uma ordenação por comparação, funcionando por indexação em um vetor. Uma propriedade importante da ordenação por contagem é ser estável: elementos com o mesmo valor aparecem no vetor de saída na mesma ordem em que aparecem no vetor de entrada. Isto é, ela desempata dois números segundo a regra de que qualquer número que aparecer primeiro no vetor de entrada aparecerá primeiro no vetor de saída. Essa propriedade tem importância devido ao uso frequente do counting sort como uma sub-rotina na ordenação digital.

# Radix Sort
A ordenação digital, ou radix sort, é um algortimo usado pelas máquinas de ordenação de cartões. Os cartões empregados na época tinha 80 colunas e em cada coluna uma máquina podia fazer a perfuração em uma das 12 posições. O ordenador pode ser programado para examinar determinada coluna do cartão em uma das 12 caixas dependendo do local perfurado. No caso de dígitos decimais, cada coluna utiliza apenas 10 posições (as outras duas posições são reservadas para codificar caracteres não numéricos). Então, um número de d dígitos ocuparia um campo de d colunas. Visto que o ordenador de cartões pode examinar apenas uma coluna por vez, o problema de ordenar n cartões em um número de d dígitos requer um algoritmo de ordenação.

Intuitivamente, poderíamos ordenar números sobre seu dígito mais significativo (mais à esquerda), ordenar cada uma das caixas resultantes recursivamente e depois combinar as pilhas em ordem. O radix sort resolve o problema da ordenação de cartões — contra a intuição normal — ordenando primeiro pelo dígito menos significativo.

O código para ordenação digital é direto. O procedimento radixSort a seguir considera que cada elemento no vetor A[1 : n] tem d dígitos, em que o dígito 1 é o dígito de ordem mais baixa e o dígito d é o dígito de ordem mais alta.

```
radixSort(A, n, d)
	for i = 1 até d
		usar ordenação estável para ordenar o vetor
		A[1 : n] no dígito i
```

Dados n números de d dígitos nos quais cada dígito pode adotar até k valores possíveis, ORDENA-POR-DÍGITO ordenará corretamente esses números no tempo Θ(d(n + k)) se a ordenação estável levar o tempo Θ(n + k). 

A análise do tempo de execução depende da ordenação estável usada como algoritmo de ordenação intermediária. Quando cada dígito está no intervalo de 0 a k – 1 (de modo que pode adotar até k valores possíveis) e k não é muito grande, a ordenação por contagem é a escolha óbvia. Então, cada passagem sobre n números de d dígitos leva o tempo Θ(n + k). Há d passagens e, assim, o tempo total para ordenação digital é Θ(d(n + k)).

Quando d é constante e k = O(n), podemos executar a ordenação digital em tempo linear. De modo mais geral, temos alguma flexibilidade quanto aos modos de desmembrar cada chave em dígitos.

# Bucket Sort
O procedimento bucketSort considera que a entrada é um vetor A[1 : n] e que cada elemento A[i] no vetor satisfaz 0 ≤ A[i] < 1. O código exige um vetor auxiliar B[0 : n – 1] de listas encadeadas (baldes) e considera que existe um mecanismo para manter tais listas.

```
ORDENA-POR-BALDE(A, n)
	seja B[0 : n – 1] um novo vetor
	for i = 0 até n – 1
		faça B[i] uma lista vazia
	for i = 1 até n
		insira A[i] na lista B[⎿n · A[i]⏌]
	for i = 0 até n – 1
		ordene a lista B[i] com ordenação por inserção
	concatene as listas B[0], B[1], ..., B[n – 1] em ordem
	return as listas encadeadas
```


