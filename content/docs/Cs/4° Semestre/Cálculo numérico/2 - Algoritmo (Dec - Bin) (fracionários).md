---
title: "Algoritmo (Dec - Bin) (fracionários)"
weight: 3
---

# DEC - Bin
**Exemplo:** $r = (0.625)_{10}$
1. $0.625 = d_{1}\times 2^{-1} + d_{2}\times 2^{-2} + ... + d_{k}\times 2^{-k}$
2. $1.250 = d_{1} + d_{2}\times 2^{-1} + ... + d_{k}\times 2^{-k+1}$
3. $d_{2}\times 2^{-1} + ... + d_{k}\times 2^{-k+1} \leq 1\times 2^{-1} + ... + 1\times 2^{-k+1} \leq 2^{-1} + ... + 2^{-k+1} + ... = 1$
Portanto $d_{1}$ é a parte inteira de 1.250, ou seja $d_{1} = 1$. Logo,
$1.250 = 1 + d_{2} \times 2^{-1} + ... + d_{2} \times 2^{-k+1}$
Subtraindo 1, obtemos:
$0.250 = d_{2} \times 2^{-1} + ... + d_{k} \times 2^{-k+1}$
Multiplicando por 2 a equação:
$0.500 = d_{2} + ... + d_{k} \times 2^{-k+2}$ -> $d_{2} = 0$
... (Repetição desse processo )

Seja $R_{0}$ um número fracionário positivo na base decimal, e seja $(0.d_{1}d_{2}...)_{2}$ sua representação na base 2. Então:
1. Para j = 1, 2 ,3, ... :
	1. $r_{j} = 2 \times R_{J-1}$
	2. $d_{j} = \lfloor r_{j} \rfloor$ 
	3. $R_{j} = r_{j}-d_{j}$
Esse processo termina quando:
1. $j$ atingir o número de dígitos binários desejados
2. $R_{j} = 0$

## 1.5. Aritmética de ponto flutuante
Dados número inteiros $M_{min}$, $M_{max}$ , $\beta > 0$, $d_{1}, d_{2},..., d_{n}$, um número $x$ escrito em aritmética de ponto flutuante de base $\beta$ é um número da forma $x = \pm  (0.d_{1}d_{2}...d_{n}) \times \beta^{M}$, onde 
1. $.d_{1}d_{2}...d_{n}$ é a **mantissa** de $x$
2. $M \in \mathbb{Z}$ e $M \in [M_{min}, M_{max}]$
3. $0 \leq d_{j} \leq \beta -1, j=1, ..., n$ e $d_{1} \neq 0$

**Exemplo:** O número $x = -0.00072018$ no sistema $S[\beta,t,M_{min}, M_{max}]$ com $\beta = 10 ,t = 4, M_{min} = -3, M_{max} = 4$. Então $S[10, 4, -3, 4]$ é:
$x = -0.72018 \times 10^{-3} = -(0.7201 \times 10^{-3} + 0.00008\times 10^{-3}) = -(0,7201 \times 10^{-3} + 0.8\times10^{-3-4})$
Para escrever o número $x$ em $S[10, 4, -3, 4]$ podemos aproximá-lo por **truncamento** ou **arredondamento**. Dado um sistema $S[\beta,t,M_{min}, M_{max}]$ e um número   $x = f_{x} \times 10^{h} + g_{x}\times 10^{h-t}$ com $0.1 \leq f_{x} < 1$ e $0.1 \leq g_{x} < 1$.
1. Aproximar $x$ por truncamento é simplesmente eliminar o termo $g_{x}\times 10^{h-t}$ : $x \approx f_{x} \times 10^{h}$.
2. Aproximar $x$ por arredondamento é fazer a seguinte aproximação:: $x \approx f_{x} = \times 10^{h}$, se $\vert g_{x} \vert < \frac{1}{2}$ ou $x  \approx f_{x} \times 10^{h}+10^{h-t}$, se $\vert g \vert \geq \frac{1}{2}$.

**Truncamento:** $x \approx - 0.7201 \times 10^{-3}$
**Arredondamento:** $x \approx  -(0.7201 \times 10^{-3} + 10^{-3-4}) = 0.7202 \times 10^{-3}$

- Qualquer número menor do que o menor número positivo do sistema deve ser considerado zero e é chamado de underflow do sistema.
- Qualquer número maior do que o maior número positivo possível do sistema deve ser considerado como o maior número positivo possível do sistema e é chamado de overflow do sistema.

## 1.6 Erro absoluto e relativo
Seja $x$ um número e $x'$ uma aproximação de x. Definimos o **erro absoluto**  na aproximação de $x$ por $x'$ como sonde o número:
$$
EA_{x} = x - x'
$$
ou:
$$
\vert EA_{x} \vert = \vert x - x' \vert 
$$
- O erro absoluto não leva em consideração o "tamanho" dos números

Definimos o **erro relativo** na aproximação de x por $x'$ como sendo o número
$$
ER_{x} = \frac{EA_{x}}{x'}
$$