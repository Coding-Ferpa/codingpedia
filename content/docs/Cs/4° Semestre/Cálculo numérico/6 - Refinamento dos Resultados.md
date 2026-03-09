---
title: "Refinamento dos Resultados"
weight: 3
---

Fase 1 -> [[5 - Solução de equações não lineares por métodos numéricos]]
> Refinamento de zeros de funções através de métodos iterativos

## Métodos
- um métodos iterativo é a construção de uma sequência de valor $x_0, x_1, x_2,..., x_{x-1}$ tais que:
- $(i)$ para obter $x_{k-1}$ podemos utilizar $x_0, x_1, ..., x_k$. Ou seja, utilizar os elementos anteriores da sequência
- $(ii)$ $\lim_{n->\inf} x_n = \xi$ (zero da função)

### Critério de parada e precisão
Momento em que pararemos a sequência, ou seja, o quão próximo estaremos do zero função. Desta forma, temos 2 definições:
- critério de parada: é um teste utilizado para verificar se o resultado ou aproximação com a **precisão** desejada foi alcançado.
- precisão: $\bar x$ é uma aproximação de $\xi$ com precisão épsilon $\epsilon > 0$ se:
	- $(i) |x-\xi| < \epsilon$ ou
	- $(ii) |f(x)| < \epsilon$
> **$\epsilon$** ( é um termo, em geral, muito pequeno	

para melhorar a precisão, temos que diminuir o intervalo de tamanho $\epsilon$, porém, isto tem um alto custo computacional.
### Observações 
Nos métodos iterativos, como estamos em uma sequência convergente, o critério de Cauchy garante que uma sequencia {$Xn$} converge com valor $\xi$ se:

- |$X_m - X_n|$ -> $0$

Utilizando i critério de Cauchy, podemos substituir a precisão por:
- $(i)' |x_n - x_{n-1}|<0$ ou $\frac{x_n - x_{n-1}}{|X_n} < \epsilon$ (percentual)

---
# Método da Bisseção
Seja $f(x)$ contínua em $[a, b]$ tal que $f(a).f(b)<0$ e supomos que exista um único zero $\xi \in [a,b]$ de $f$.

Começamos o processo de bisseção escolhendo o ponto médio do intervalo $[a,b]$  com:
- $x_0 = \frac{a+b}{2} = \frac{a_0 + b_0}{2}$ 
- $f(a_0).f(b_0) < 0$
- Teorema A -> $\xi \in [a_0, b_0]$.
- Fazemos $a_1=a_0$ e $b_1 = x_0$
- $x_1 = \frac{a_1 + b_1}{2}$ e verificamos se vale $f(a_1).f(x_1) < 0$. Se isso for > 0, o zero de $f$ estará na outra metade do intervalo.
> dessa forma, $\xi \in [a, b]$
- assim, podemos testar novamente:
- $a_2 = x_1, b_2 = b_1$
- $x_2 = \frac{a_2+b_2}{2}$
- repete-se.

> Observe que o intervalo inicial tem comprimento $|b_0 - a_0|$ e como $x_0, \xi \in [a_0, b_0]$ e $x_0 = \frac{a_0 + b_0}2$ -> $|x_0 - \xi| < \frac{|b_0 -a_0|}2$, menor do que a metade do intervalo inicial
   Além disso, $|a_1, b_1| = \frac{b_0 - a_0}2$

Seguindo esse raciocínio, $|x_1 - \xi| < \frac{|b_1 -a_1|}2 = \frac{\frac{|b_1 -a_1|}2}2$
Conforme aumentamos a precisão, o 2 que divide a expressão pode ser descrito melhor como:
$|x_2 - \xi| < \frac{b_0 - a_0)|}{2³}$

Logo, na iteração n, temos:

$|x_n - \xi| < \frac{|b_0 - a_0|}{2^{n+1}}$

Quando $n \implies 0$ 
a sequencia também tende a 0.

## Critério de parada - bisseção
Dada um precisão $\epsilon > 0$, queremos que $|x_n - \xi| < \epsilon$.
Como sabemos que $|x_n - \xi| < \frac{|b_0 - a_0)|}{2^{n+1}}$, basta fazer:
$\frac{|b_0 - a_0)|}{2^{n+1}} < \epsilon$


Para obter o número de iterações $n$ para alcançar a precisão $\epsilon$, escrevemos:
- $2^{-n-1} . |b_0-a_0| < \epsilon$
Aplicando o logaritmo natural $\ln$:
[...]
$n > -1 + \frac{\ln{\frac{|b_0-a_0}{\epsilon}}}{\ln2}$

Logo $n$ é o menor inteiro maior que $\frac{\ln{\frac{|b_0-a_0}{\epsilon}}}{\ln2}$
$n = \lfloor \frac{\ln{\frac{|b_0-a_{0}|}{\epsilon}}}{\ln2}\rfloor$, numero fixo de iterações necessárias para achar a precisão

## Algoritmo (bisseção)
$f.[a,b] \implies R, \xi \in [a,b]$

$a_0 = a, b_0 = b$
$k=0$
$x_k = \frac{a_k+b_k}{2}$
$n = \lceil \frac{\ln{\frac{|b_0-a_0}{\epsilon}}}{\ln2}\rceil$

Para $k=0, 1, 2...$

Se $f(a_k)f(x_k)<0$ então, $a_{k+1} = a_k$  e $b_{k+1} = b_k$
Caso contrário ($f(a_k)f(x_k)\geq0)$
$a_{k+1}=x_k$ e $b_{k+1} =b_k$
$x_{k+1}=\frac{a_{k+1}+b_{k+1}}{2}$

