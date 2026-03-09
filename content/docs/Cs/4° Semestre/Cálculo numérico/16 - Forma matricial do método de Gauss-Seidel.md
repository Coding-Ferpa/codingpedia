---
title: "Forma matricial do método de Gauss-Seidel"
weight: 3
---

Sejam :
$A = \begin{bmatrix} a_{11}  & a_{12} & \dots & a_{1n} \\ a_{21} & a_{22} & \dots  & a_{2n} \\ \vdots & \vdots  &  & \vdots  \\ a_{n1} & a_{n2} & \dots  & a_{nn} \end{bmatrix}$


$L = \begin{bmatrix} 0  & 0 & \dots  &  0 \\ a_{21} & 0 & \dots  & 0 \\ \vdots & \vdots  &  & \vdots  \\ a_{n1} & a_{n2} & \dots  & 0 \end{bmatrix} + D= \begin{bmatrix} a_{11}  & 0 & \dots  &  0 \\ 0 & a_{22} & \dots  & 0 \\ \vdots & \vdots  &  & \vdots  \\ 0  & 0 & \dots  & a_{nn} \end{bmatrix} + R=\begin{bmatrix} 0  & a_{12} & \dots  &  a_{1n} \\ 0 & 0 & \dots  & a_{2n} \\ \vdots & \vdots  &  & \vdots  \\ 0  & 0 & \dots  & 0 \end{bmatrix}$ 

 Logo, $A = L_{1}+D+R_{1}$.
 Assim, temos:
 $Ax = b \implies (L_{1}+D+R_{1})x=b$
 $\implies L_{1}x+Dx+R_{1}x = b$
 $\implies Dx = -L_{1}x - R_{1}x + b$
 $\implies x = D^{-1}(-L_{1}x - R_{1}x + b)$
 $\implies x = -D^{-1}L_{1}x - D^{-1}R_{1}x + D^{-1}b$
 
 Daqui obtemos:
 $X^{(k+1)}= -D^{-1}L_{1}x^{(k+1)} - D^{-1}R_{1}x^{(k)} + D^{-1}b$
-> .... após o Gauss-Seidel
$\implies x^{(k+1)}= (I_{n}+D^{-1}L_{1})^{-1}D^{-1}R_{1}x^{k}+(I_{n}+D^{-1}L_{1})^{-1}D^{-1}b$

> Logo, obtemos o método de Gauss-Seidel  no formato $x^{k+1}= Bx^{k}+c$

# Critérios de Convergência de Sassenfeld
O **critério das linhas modificado** ainda vale para o método de Gauss Seidel
$A = (a_{ij})_{n\times m}$
$A = |a_{ij}|>\sum^{n}_{j+1}\limits |a_{ij}|, \forall i$
então o método de Gauss-Seidel converge.

O critério de Sassenfeld é outro método prático para determinar se Gauss-Seidel converge.
Sejam:
$\beta_{1}= \sum_{j=2}^{n}\limits \frac{|a_{1j}|}{|a_{11|}}$ 

$\beta_{2}= \frac{|a_{21}|}{|a_{22}|}\times \beta_{1} + \sum_{j=3}^{n}\limits \frac{|a_{2j}|}{|a_{22|}}$ 

$\beta_{3}= \frac{|a_{31}|}{|a_{33}|} \times \beta_{1} + \frac{|a_{32}|}{|a_{32}|}\times \beta_{2} + \sum_{j=4}^{n}\limits \frac{|a_{3j}|}{|a_{33|}}$ 
$\vdots$
$\beta_{n}=\sum^{n-1}_{j=1}\limits  \frac{|a_{ij}|}{|a_{nn}|}\times \beta_{j}$

# Ordem de Convergência dos métodos iterativos
Seja $(X_{n})_{n\geq0}$ uma sequência numérica convergente, com $\lim_{n\rightarrow\infty}\limits x_{n} = \xi$
Sejam $e_{k}=|\xi - x_{k}|, k=0,1..,n$
Dizemos que $(x_{n})$ tem ordem de convergência $p>0$, se 
$$\lim_{k \rightarrow a}\limits{\frac{e_{k+1}}{e_{k}^{p}}} = c>0$$
Podemos então dizer que quando $k$ é suficientemente grande, temos:
$$e_{k+1} \approx c - e_{k}^{p}$$
> se, por exemplo, $e_{k}= 10^{-2}$ e $p=2$, então: $e_{k+1}\approx c\times (10^{-2})^{2}=c\times 10^{-4}$

# Ordem de Convergência do MPF
Sejam $f(x) =0$ cuja solução é $\xi$ e $g(x)$ a função de iteraçãoo de $f(x)$   de onde a sequência $x_{k+1}=g(x_{k})$.
Do MPF, sabemos que se $|g'(\xi)| < 1$ então o $x_{k}$ converge para $\xi$

Suponha que $g'(\xi) \neq 0$.


---
## Teorema do valor médio
Dada $g:[a,b] \rightarrow R$ continua e derivável em $(a,b)$, existe $c\in(a,b)$ tal que 
$$g(b)-g(a)= g'(c).(b-a)$$


----
Aplicando o TVM
$e_{k+1}=|g'(c_k)(\xi-x_{k})|$, onde $c_{k}(\xi-x_{k})$, onde $c_{k}\in(\xi, x_{k})$.
Logo, 
$e_{k+1} = |g'(c_{k})-e_{k}|$
$\implies \lim_{k\rightarrow\infty}\frac{e_{k+1}}{e_{k}} = \lim_{k\rightarrow\infty}|g'(k)| = |g'(\xi)|>0$
Logo, ordem de convergencia do MPF é $p=1$

Quando $p=1$, também dezenas que a ordem de convergência é linear.

# Ordem de convergência do método de Newton

Como $g'(\xi) = 0$  no método de Newton, a ordem de convergência não pode ser linear, pois $$\lim_{k\rightarrow \infty}\frac{e_{k+1}}{e_{k}}=|g'(\xi)| = 0$$
Veremos que a ordem de convergência é p=2.

# Fórmula de Taylor
Dada $f(x)$ uma função real dada derivável até a ordem $n+1$, a fórmula de Taylor de ordem $n$ com resto de Lagrange em torno de x=q é dada por: $$f(x)=f(a)+\frac{f'(a)}{1!}(x-a)^{1}+ \frac{f''(a)}{2!}(x-a)^{2}+ \dots + \frac{f^{(n)}(a)}{n!}(x-a)^{n}+ \frac{f^{(n+1)}(c)}{(n+1)!}(x-a)^{n+1}$$
com $c\in(x,a)$.

Temos o polinômio de Taylor:
$$P_{n}= f(x)=f(a)+\frac{f'(a)}{1!}(x-a)^{1}+  \dots + \frac{f^{(n+1)}(a)}{n!}(x-a)^{n}$$
e o resto:

$$R_{n}= \frac{f^{(n+1)}(c)}{(n+1)!}(x-a)^{n+1}$$