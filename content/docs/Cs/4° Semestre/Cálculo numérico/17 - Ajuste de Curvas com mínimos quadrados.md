---
title: "Ajuste de Curvas com mínimos quadrados"
weight: 3
---

# Mínimos quadrados
Considere o problema de aproximar uma $f(x)$ ou um conjunto de dados ($X, Y$) por uma função $g(X)$ mais simples na forma que:
- (1) A diferença entre $f(x)$ e $g(x)$ seja mínima.
- (2) a função $g(x)$ seja mais fácil de ser manuseada.

## Caso Discreto
A condição (2) do caso discreto é a seguinte:

| X   | $x_1$      | $\dots$ | $x_n$    |
| --- | ---------- | ------- | -------- |
| Y   | $f(x_{1})$ | $\dots$ | $f(x_n)$ |
$$I = \sum_{j=1}^{n}\limits[f(x_{j})-g(x_{j})]^{2}\times w_{j}$$
onde $w_{j}$ (weight) são os pesos atribuídos a cada diferença. Vamos considerar $w_{j} =1$ a priori.

Escolhemos $n$ funções $g, g_{1}, g_{2} \dots$ contínuas, e tomamos $g(x)$ como a comb. linear $G(x) = \alpha_{1}g_{1}(x) +\dots +\alpha_{n}g_{n}(x)$ com $\alpha_{j} \in R$.

### Exemplo 1: Considere a tabela

| x      | -2  | -1.5 | -1  | -0.5 | 0   | 0.5 | 1   | 1.5 | 2    |
| ------ | --- | ---- | --- | ---- | --- | --- | --- | --- | ---- |
| $f(x)$ | -1  | 0.4  | 2.5 | 3    | 3.4 | 2.9 | 1.9 | 1   | -1.5 |


Representando os dados da tabela no plano cartesiano vemos que a "melhor" função $G(x)$ que se ajusta aos pontos é uma função quadrática., ex:
_$G(x) = \alpha_{1}+\alpha_{2}x^{2}$ (nesse caso, $\alpha x$)_ foi suprimido pois o gráfico aparenta estar simétrico em relação ao eixo Y.

Portanto:
$g_{1}(x) = 1$
$g_{2}(x) = x^{2}$

Vamos minimizar $I = \sum_{j=1}^{n}\limits[f(x_{j})-g(x_{j})]^{2}$

$F(\alpha_{1},..., \alpha_{n}) = \sum_{j=1}^{n}\limits[f(x_{j})-g(x_{j})]^{2}$

___
### Pausa pro Cálculo 3 - Derivada Parcial 
$f(x,y)$ de 2 variáveis independentes.  
_Derivada Parcial_ é a derivada restrita apenas a uma das variáveis da função.
$f(x,y) = x^{2}\times y^{2}$
$g(x,y) = x^{2}+ y^{2}$
ex: $\frac{\partial f}{\partial x} = y^{2}\times 2x = 2xy^{2}$
$\frac{\partial g}{\partial x} = 2x + 0= 2x$

$(*) = \begin{cases} \frac{\partial f}{\partial x} = 0  \\ \frac{\partial f}{\partial y} = 0 \end{cases}$   (pontos críticos)
___
queremos encontrar:

$\begin{cases} \frac{\partial F}{\partial \alpha_{1}} = 0  \\ \vdots  \\ \frac{\partial F}{\partial \alpha_{n}} = 0 \end{cases}$   


$F(\alpha_{1},..., \alpha_{n}) = \sum_{j=1}^{n}\limits[f(x_{j})-\alpha_{1}g_{1}(x_{j})]^{2}-\alpha_{2}g_{2}(x_{j})]^{2}-\dots -\alpha_{n}g_{n}(x_{j})]^{2}$

Calculando $\frac{\partial F}{\partial\alpha_{1}}$:
$\frac{\partial F}{\partial\alpha_{i}} = \sum_{j=1}^{n}\limits 2\times [f(x_{j})-\alpha_{1}g_{1}(x_{j})]^{2}-\alpha_{2}g_{2}(x_{j})]^{2}-\dots -\alpha_{n}g_{n}(x_{j})] - g_{i}(x_{j})$
$\sum_{j=1}^{n}\limits 2\times f(x_{j}) - g_{i}(x_{j}) + 2\times \sum^{N}_{j=1}\limits\sum^{n}_{k=1}\limits\alpha_{k}g_{k}(x_{j})g_{i}(x_{j})$

Como precisamos resolver o sistema:

$\begin{cases} \frac{\partial F}{\partial \alpha_{1}} = 0  \\ \vdots  \\ \frac{\partial F}{\partial \alpha_{n}} = 0 \end{cases}$   

$\begin{cases} \frac{\partial F}{\partial \alpha_{1}} =  -2\sum_{j=1}^{N}\limits \times f(x_{j}) - g_{i}(x_{j}) + 2\times \sum^{N}_{j=1}\limits\sum^{n}_{k=1}\limits\alpha_{k}g_{k}(x_{j})g_{i}(x_{j}) \\ \vdots  \\ \frac{\partial F}{\partial \alpha_{n}} =  -2\sum_{j=1}^{n}\limits \times f(x_{j}) - g_{n}(x_{j}) + 2\times \sum^{N}_{j=1}\limits\sum^{n}_{k=1}\limits\alpha_{k}g_{k}(x_{j})g_{n}(x_{j})\end{cases}$   

Então, temos:

$\begin{cases} \sum^{n}_{k=1}\limits \alpha_{k}a_{1k} = b_{1} \\\sum^{n}_{k=1}\limits \alpha_{k}a_{2k} = b_{2} \\ \vdots \\ \sum^{n}_{k=1}\limits \alpha_{k}a_{nk} = b_{n} \end{cases}$
onde $a_{ik} = \sum_{j=1}^{N}\limits g_{i}g_{k}(x_{j})$ e $b_{i} = \sum_{j=1}^{N}\limits g_{i}(x_{j})f(x_{j})$

---
## Caso Contínuo
$$I = \int^{b}_{a}[f(x) - g(x)]^{2}times $$
onde $w:[a,b]\rightarrow R$ é a função-peso.

Seja $g(x) = \alpha_{1} g_{1}(x) + \alpha_{2} g_{2}(x)$

$\begin{cases} a_{11} = \int^{b}_{a} g_{1}(x)^{2}dx \\a_{12}= \int^{b}_{a}g_{1}(x)g_{2}(x)dx  \\  a_{21}= a_{12} \\ a_{22} = \int^{b}_{a}g_{2}(x)^{2}dx \end{cases}$

$b_{1}= \int^{b}_{a}g_{1}(x)f(x)dx$, $b_{2}= \int^{b}_{a}g_{2}(x)f(x)dx$

em um sistema:
$\begin{cases}a_{11} \alpha_{1}+a_{12}\alpha_{2} = b_{1}\\ a_{21} \alpha_{1}+a_{22}\alpha_{2} = b_{2} \end{cases}$

$a_{ij}= \int^{b}_{a}g_{i}(x)g_{j}(x)dx$, $b_{i}= \int^{b}_{a}g_{i}(x)f(x)dx$
Lembrando: $a_{ij}=a_{ji}$
