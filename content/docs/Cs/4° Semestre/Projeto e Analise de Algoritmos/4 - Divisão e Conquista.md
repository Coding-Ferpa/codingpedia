---
title: "Divisão e Conquista"
weight: 3
---

Divisão de problemas maiores para gerar subproblemas com recursão, capazes de serem resolvidos.

Neste método, temos:
- caso base -> problema simples o bastante para ser resolvido.
- caso recursivo:
	- divisão: dividir o problema em subproblemas
	- conquista: resolver recursivamente os subproblemas
	- combinação: das soluções dadas aos subproblemas, associá-las ao problema "acima"

## Merge Sort 

- **Divisão**: Em cada etapa, ele ordena um subvetor $A[p:q]$, dividindo-o a cada chamada por 2, sempre pegando cada metade até achar o caso base (vetor unitário ou nulo)
- **Conquista**: ordenando os 2 subvetores $A[p:q]$ e $A[q+1: r]$ recursivamente.
- **Combinação**: juntar os os 2 de cima com a mesma ordenação.

	O procedimento de **merge** é executado no tempo $\Theta(n)$, visto que temos diversos laços que operam essencialmente na metade de vetores originais. O while que percorre a metade do vetor original para passar o elemento ordenado pra um novo vetor, passa por, no máximo, pelo tamanho do vetor original.  

Usamos o **MERGE** como subrotina do procedimento **MERGE-SORT**, caso min < max funcione, se n, um beijo do gordo.

A primeira parte da divisão recebe o teto da divisão dos índices **i.e** (0, $\lceil n/2 \rceil$).

---
# Equação de recorrência

Expressar uma função recursiva usando uma equação, que descreve o tempo de execução global para um problema de tamanho n em termos do tempo de execução para entradas menores.

## Exemplo merge sort

Temos que descrever os 3 casos do método de divisão e conquista. 
Descrevemos o **pior caso** inicialmente como $T(n)$, dessa forma, se tratarmos $n$ como pequeno o bastante, a solução demonstrará um tempo $\Theta(1)$.

aT(n/b) -> representa as recorrências, então, D(n) representa as divisões e C(n) para a conquista.

Chegamos em:
##### $T(n) = \empheqlbrace{\dbinom{\Theta(1)}{D(n) + aT(\frac{n}{b})+C(n)}} \implies T(n) = 2T\left(\frac{n}{2}\right)+ \Theta(n)$ 

através da árvore de recorrência:

## $= \Theta(n\log n)$

