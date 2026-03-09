---
title: "Variáveis Aleatórias Contínuas"
weight: 3
---

# Modelo uniforme
Def: Uma variável aleatória X tem distribuição Uniforme no intervalo $[a,b]$ se sua **função densidade** de probabilidade for dada por:
$$ f(x) \begin{cases}
 \frac{1}{b-a}  & se & a \leq x\leq b \\
 \ \ 0,  & se  & x<a \ ou \ x>b
\end{cases} $$
Notação: $X \eqcirc u(a,b)$
média: $E(X) = \frac{b+a}{2}$ 
variância: $V(X) = \frac{(b-a)²}{12}$

1. $f(x) \geq0$
2. $\int^{\infty}_{-\infty}\limits{f(x)dx} = 1$
3. $f(x) = P(X\leq x)$
	- disclaimer, toda variável contínua $P(X = x) = 0$
4. função de distribuição acumulada = 	$\int^{x}_{-x}\limits{f(x)dx}$
## Exercício
1.  Um ônibus chega dez minutos em um ponto de parada. Assume-me que o tempo de espera para 1 indivíduo é uma v.a com dist. contínua.
a) Qual a P de que o indivíduo espere mais que 10m?
$\int^{10}_{7}\limits{\frac{1}{10}}dx$  = $\frac{3}{10}$

b) qual a $P(|x-5|\leq2)$? = 0.4
## Coeficiente de Variação
$CV = \frac{desvio}{média}$
# Modelo Exponencial
Definição: A variável aleatória X tem dist. Exponencial de parâmetro $\alpha (\alpha \geq 0)$, se tiver densidade dada por:
$$\begin{cases}
\alpha e^{-\alpha x}, & se \ x\geq0 \\
0, & caso \ contrário
\end{cases}$$
Média: $E(X) = \frac{1}{\alpha}$
Variância: $V(X) = \frac{1}{\alpha^{2}}$

1. Tempo -> v.a exponencialmente distribuida.
média de tempo numa rede = 30s, de modo que -> $f(x) = \frac{1}{30}e^{-\frac{x}{30}}$ 
$F(x) = \int^{x}_{-\infty}\limits{\alpha e^{-\alpha x} dx} = 1 - e^{-\alpha x} \rightarrow P(x>35) = 1 - P(X \leq 35) \approx 3.11$ 





