---
title: "Método do Ponto Fixo (MPF)"
weight: 3
---

# Ponto Fixo

Seja $g:[a,b] \rightarrow R$ e $\xi \in [a,b]$
Dizemos que $\xi$ é ponto fixo de $g$ se 
	$g(\xi) = \xi$

Ex: x² -> não altera os valores de 0 e 1, ou seja, f(x) = x, se x = [0, 1]

Ou seja, onde os o gráfico de função $f(x)$ intersecta a reta $y = x$

---
# Método do ponto fixo
O método do ponto fixo consiste em transformar uma equação $f(x) = 0$  em uma função da forma
$$x = g(x)$$
Definimos uma sequência numérica, então, como:
$x_{k+1} = g(x_{k}),k=0,1, [..]$ para alguma aproximação inicial $x_0$. Ou seja, 
$$x_{0}, x_{1} = g(x_{0})...$$
se a sequencia $(x_k)_{k\geq0}$ converge, então ela converge para o ponto fixo de $g(x)$ ($\xi$)

Supomos que g é continua. Como $x_{k+1} = g(x)$ e como $x_k$ converge, isto é, $\lim_{k \rightarrow\infty} x_k = \xi$

Então, aplicando lim em $x_{k+1} = g(x)$:
- $\xi = \lim_{k \rightarrow\infty} x_{k} = \lim_{k \rightarrow\infty} g(x_k)$
- $g(\lim_{x \rightarrow \infty}x_k) = g(\xi)$
- $g(\xi) = \xi$ 

# Critério de convergência para o MPF

Seja $g:[a,b] \rightarrow R$ contínua, dizemos que g é uma **contração** se  existe $0 < \lambda < 1$ tal que $\forall x,y\in(a,b)$ vale -> $|{g(y)-g(x)}| < \lambda |y-x|$.

- Uma contração é uma função que contrai distâncias.
- precisa valer:
	- $g'(x) < 1$ para $x\in[a,b]$

então, se a função g(x) é uma contração, dentro do intervalo em que g(x) é contração, há apenas **1** ponto fixo. 
## Teorema do ponto fixo de Contrações (se derivável)
Seja $g:[a,b] \rightarrow R$ e $\xi \in [a,b]$, uma contração, **um ponto fixo** de g e $x_0\in(a,b)$ qualquer.
Então, a sequência  $(x_k)_{k\geq0}$ converge para um único ponto fixo $\xi$ de $g$ em $(a,b)$

usaremos $|x_{n+1}- x_{n}|$ ou $|\frac{|x_{n+1} - x_{n}|}{|x_{n+1}|}$
