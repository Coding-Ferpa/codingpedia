---
title: "Matrizes"
weight: 3
---

# Multiplicação de cadeias de matrizes

Temos uma sequência (cadeia)$〈A_1 , A_2 , ..., A_n 〉$ de n matrizes para multiplicar e desejamos calcular o produto $A_1A_2...A_n$ usando o algoritmo-padrão para multiplicação de matrizes retangulares, enquanto minimizamos o número de multiplicações escalares.

A multiplicação de matrizes é associativa, ou seja o resultado depende da ordem em que é realizada, assim, $A_1(A_2(A_3A_4)))\neq (A_1((A_2A_3)A_4))$. No problema de multiplicação de cadeias de matrizes, não estamos realmente multiplicando matrizes. Nossa meta é apenas determinar uma ordem para multiplicar matrizes que tenha o custo mais baixo.

Para ilustrar os diferentes custos incorridos pelas diferentes posições dos parênteses em um produto de matrizes, considere o problema de uma cadeia $〈A_1 , A_2 , A_3〉$ de três matrizes. Suponha que as dimensões das matrizes sejam 10 × 100, 100 × 5 e 5 × 50, respectivamente.

Se multiplicarmos as matrizes de acordo com a posição dos parênteses
$((A_1A_2
)A_3
)$, executaremos 10 · 100 · 5 = 5.000 multiplicações escalares para calcular o produto 10 × 5 de matrizes A1A2, mais outras 10 · 5 · 50 = 2.500 multiplicações escalares para multiplicar essa matriz por A3, produzindo um total de 7.500 multiplicações escalares.
A multiplicação de acordo com a posição alternativa dos parênteses $(A1(A2 A3))$ executa 100 · 5 · 50 = 25.000 multiplicações escalares para calcular o produto 100 × 50 de matrizes $A_2A_3$, mais outras 10 · 100 · 50 = 50.000 multiplicações escalares para multiplicar A1 por essa matriz, resultando em um total de 75.000 multiplicações escalares. Assim, o cálculo do produto de acordo com a primeira posição dos parênteses é 10 vezes mais rápido. 

A verificação exaustiva de todas as possíveis parentizações não resulta
em um algoritmo eficiente.

Vamos representar por P(n) o número de parentizações alternativas de uma sequência de n matrizes. Quando n = 1, a sequência consiste em apenas uma matriz e, portanto, somente um modo de parentizar totalmente o produto de matrizes. Quando n ≥ 2, um produto de matrizes totalmente parentizado é o produto de dois subprodutos de matrizes totalmente parentizados, e a separação entre os dois subprodutos pode ocorrer entre a k-ésima e a (k + 1)-ésima matrizes para qualquer k = 1, 2, ..., n – 1.

Assim, obtemos:

$$
P(n) = \begin{cases} 1 \text{ se n = 1} \newline \sum^{n-1}_{k=1} P(k)P(n-k)\text { se n} \geq \text{ 2}\end{cases}
$$



