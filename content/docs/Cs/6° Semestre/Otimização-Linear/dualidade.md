---
title: "dualidade"
weight: 3
---

# Dualidade

A dualidade é um conceito fundamental na otimização linear que estabelece uma relação entre dois problemas de otimização: o problema primal e o problema dual. Cada problema de otimização linear tem um problema dual associado, e as soluções desses problemas estão interligadas.

## Relaxação Lagrangeana
Considere um problema primal: 

Minimizar $f(x) = c^T x$
sujeito a $Ax = b$
          $x \geq 0$

que agora será chamado de problema primal.

Exemplo (Problema de Corte)Ç

Deseja-se cortar bobinas de aço sendo que cada bobina tem largura L = 1m e pesa 1t, para a produção de 108t de subbobinas de 0.4m, 120t de subbobinas de 0.3m. O peso total das bobinas cortadas deve ser minimizado. 

$x_{ij}$: quantidade (em t) de bobinas cortadas segundo o padrao de corte j. 
Um padrao de corte $p_j$, no problema atual, é um vetor $p_j = (p_{1j}, p_{2j})$
onde,
- $p_{1j}$ é a quantidade de subbobinas de 0.4m.
- $p_{2j}$ é a quantidade de subbobinas de 0.3m.

$p_{1j}$ e $p_{2j}$ são inteiros positivos e $0.4p_{1j} + 0.3p_{2j} \leq 1$.

As possibilidades:

$p_1 = (2, 0)$
$p_2 = (1, 2)$
$p_3 = (0, 3)$

A função a ser minimizada é o peso total das bobinas cortadas, ou seja, $f(x) = x_1 + x_2 + x_3$.

Para as restrições, temos:

- Bobinas de 0,4m:
    - 1° Padrão: $2 \times 0,4m = \frac{4}{5}$
    - 2° Padrão: $1 \times 0,4m = \frac{2}{5}$
    - 3° Padrão: $0 \times 0,4m = 0$
- Bobinas de 0,3m:
    - 1° Padrão: $0 \times 0,3m = 0$
    - 2° Padrão: $2 \times 0,3m = \frac{6}{5}$
    - 3° Padrão: $3 \times 0,3m = \frac{9}{5}$

Restrições:
$$
\begin{align*}
\frac{4}{5}x_1 + \frac{2}{5}x_2 = 108 \\
\frac{6}{5}x_2 + \frac{9}{5}x_3 = 120 \\
x_1, x_2, x_3 \geq 0
\end{align*}
$$

O problema de otimização linear é:
Minimizar $f(x) = x_1 + x_2 + x_3$
sujeito a $\frac{4}{5}x_1 + \frac{2}{5}x_2 = 108$
          $\frac{6}{5}x_2 + \frac{9}{5}x_3 = 120$
          $x_1, x_2, x_3 \geq 0$


Dado a base otima $B = \{1, 2\}$, temos:

$x^* = \begin{bmatrix} 35 \\ 200 \\ 0 \end{bmatrix}$

f(x*) = 235

Suponha que houve alteração na demanda de um ou mais tipos de corte. Então, a restrição $Ax = b$ não é mais válida.


---

A relaxação lagrangeana consiste em relaxar a restrição $Ax = b$ e incorporá-la na função objetivo por meio de um vetor de multiplicadores $\lambda \in \mathbb{R}^m$. 

$L(x, \lambda) = f(x) + \lambda_1 y_1 + \lambda_2 y_2 + ... + \lambda_m y_m$
onde $y = b - Ax$. Ou seja,

$L(x, \lambda) = f(x) + \lambda^T (b - Ax)$

no final,

$L(x, \lambda) = (c^T - \lambda^T A)x + \lambda^T b$

--- 

Chamamos de função dual a função 

$g(\lambda) = min_{x \geq 0} L(x, \lambda)$ = $min_{x \geq 0} (c^T - \lambda^T A)x + \lambda^T b$



