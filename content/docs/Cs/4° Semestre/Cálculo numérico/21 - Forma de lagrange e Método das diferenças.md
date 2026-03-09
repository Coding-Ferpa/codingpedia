---
title: "Forma de lagrange e Método das diferenças"
weight: 3
---

# Forma de Lagrange
Sejam $x_{0}, x_{1}, \dots, x_{n} \ (n+1)$  nós de interpolação, $f(x)$ uma função $y_{j}=f(x_{j})$, $j=0, \dots, n$.
A forma de Lagrange do polinômio interpolador $g_{n}(x)$ consiste em escrever $g_{n}(x)$ como $g_{n}(x) = y_{0}L_{0}(x)+y_{1}L_{1}(x)+\dots+y_{n}L_{n}(x)$, onde $L_{j}(x)$ são polinômios de grau $n$ satisfazendo a condição $$L_{j}(x_{i}) = \begin{cases}
0, se \ i \neq j \\ 1, se \ i = j 
\end{cases}$$
Logo, 
 $g_{n}(x_{i}) = y_{i}L_{i}(x_{i})=y_{i}=f(x_{i})$

Os polinômios $L_{j}(x)$ que satisfazem a condição anterior são $$L_{j}(x) = \frac{(x-x_{0})(x-x_{1})\times\dots\times(x-x_{n})}{(x_{j}-x_{0})(x_{j}-x_{1}\times\dots\times (x_{j}- x_{j}))}$$
$$= \frac{\prod^{}_{i\neq j}(x-x_{i})}{\prod_{i\neq j}(x_{j}-x_{i})}$$

Observe que, se $i \neq j$ o fator $(x-x_{j})$ está no produto de $L_{j}(x)$ . Logo, $L_{j}(x_{i}) =0$, pois no produto, aparecerá o fator $x_{i}-x_{i}=0$

Se $i=j$, temos:$$L_{j}(x_{j}) = \frac{\prod^{}_{i\neq j}(x-x_{i})}{\prod_{i\neq j}(x_{j}-x_{i})}  = 1$$
Os polinômios $L_{j}(x)$ são chamados de polinômios de Lagrange.

# Métodos das diferenças divididas de Newton
Seja $f(x)$ uma função tabelada em $n+1$ pontos $x_{0}, x_{1}, \dots, x_{n}$.
Vamos definir por indução a seguinte sequência de valores:
_ORDEM 0_:
$f[x_{j}] = f(x_{j}), j=0,\dots,n$

_ORDEM 1_:
$f[x_{j}, x_{j+1}] = \frac{f[x_{j+1}]-f[x_{j}]}{x_{j+1}=x_{j}}$, $j=0, \dots, n-1$

_ORDEM 2_:
$f[x_{j},x_{j+1}, x_{j+2}] =\frac{f[x_{j+1}, x_{j+2}]-f[x_{j}, x_{j+1}]}{x_{j+2}-x_{j}}$

_ORDEM n+1_:
$f[x_{0}, x_{1},\dots, x_{n}] = \frac{f[x_{1}, x_{n}]-f[x_{0}, x_{n-1}]}{x_{n}-x_{0}}$

