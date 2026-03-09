---
title: "solucao-grafica"
weight: 3
---

# Solução Gráfica com 2 variáveis
Maximizar $f(x_1, x_2) = x_1 + 2x_2$
sujeito a: 
$x_1 + x_2 \leq 4$
$x_1 \leq 2$
$x_2 \leq 3$
$x_1, x_2 \geq 0$

Para resolver o problema graficamente, primerio precisamos representar a região factível no plano. A região deste problema é: 
$S = \{(x_1, x_2) | x_1 + x_2 \leq 4, x_1 \leq 2, x_2 \leq 3, x_1, x_2 \geq 0\}$

A partir da representação, representamos a equação da função objetivo (já que é uma reta) como f(x_1, x_2) = k, onde k é uma constante. Assim, temos:
$x_1 + 2x_2 = k$

Ao extrairmos o vetor de gradientes ($\nabla f = (1, 2)$), vemos que a função objetivo é crescente na direção do vetor de gradiente. Assim, para maximizar a função objetivo, precisamos mover a reta o máximo possível na direção do vetor de gradiente, sem sair da região factível, de modo que existirão pontos (x_1, x_2) que satisfazem a equação.

Observe que se a região factível for limitada, existe um valor máximo $k\*$  para qual a reta $x_1 + 2x_2 = k\*$ ainda intersecta a região factível.  Neste caso, ocorre no ponto $A=(1,3)$, assim, sabemos que $(x^*, y^*) = (1,3)$ é a solução ótima do problema.

Podemos determinar o valor do ponto com um sistema linear formado pelas retas que se intersectam no ponto A:
$\begin{cases}
x_1 + x_2 = 4 \\
x_2 = 3
\end{cases}$
Resolvendo o sistema, temos:
$x_1 = 4 - x_2 = 4 - 3 = 1$
Assim, o ponto A é (1, 3).

# Tipos de Soluções 

1. Solução única não-degenerada em conjunto factível limitado: O ponto ótimo é um vértice da região factível, e a função objetivo tem um valor máximo único nesse ponto.
2. Conjunto limitado de soluções ótimas em conjunto factível limitado: A função objetivo atinge o mesmo valor máximo em vários pontos ao longo de uma aresta da região factível.
3. Solução única não-degenerada em conjunto factível ilimitado: O ponto ótimo é um vértice da região factível, e a função objetivo tem um valor máximo único nesse ponto, mesmo que a região factível se estenda indefinidamente.
4. Conjunto ilimitado de soluções: A função objetivo pode ser aumentada indefinidamente ao longo de uma direção dentro da região factível, resultando em um conjunto ilimitado de soluções ótimas.
5. Solução Ótima Degenerada: O ponto ótimo é um vértice da região factível, mas a função objetivo atinge o mesmo valor máximo em vários pontos ao longo de uma aresta que passa por esse vértice.
6. Não existe solução ótima: A região factível é vazia, ou seja, não há pontos que satisfaçam todas as restrições do problema.
