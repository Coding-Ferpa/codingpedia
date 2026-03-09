---
title: "Modelos Probabilísticos para v.a discretas"
weight: 3
---

# Modelo Binomial
$p(x) = P(X = x) = \binom{n}{x}p^{x}(1-p)^n-x$;
$x = 0,1,2,...,n$

p -> proporção
x -> valores possíveis

_notação:_ $X-b(n,p)$
p < 1

$E(X) = np$
$V(X) = np(1-p)$
## exemplo
noticias falsas enviadas a 100 pessoas com 0.7 chance delas acreditarem
$n=100$
$p=0.7$
$X:$ n° de pessoas que acreditam em noticias falsas
E(X) -> quantas pessoas eu espero que acreditem
- $100 \times 0.7 = 70$

*enunciado*: qual a probabilidade de no máximo 2 pessoas acreditem que a notícia é verdadeira?

$P(x\le 2) = p(x=0) + p(x=1) + p(x=2)$

$X_{i} \times \frac{F}{n}$

# Características de uma variável aleatória de Poisson
1. o experimento consiste em contar o n vezes que certo evento ocorre dentro de um conjunto, seja tempo, área, volume etc.
2. a probabilidade de que um evento ocorra em uma dada unidade é a mesma para todas as unidades
3. O numero de eventos que ocorre em uma unidade de medição é independente do numero que ocorre outra unidade mutualmente excludente.
4. a media (ou numero separado) de eventos em cada unidade é denotada pela letra grega $\lambda$ (lambda)
$$P(X = k)=\frac{\lambda^{k}e^{-\lambda}}{k!} = 0,1,2{...}$$
$E(X) = \lambda$ e $V(X) = \lambda$
## Exercícios
*n° de pedidos por hora < 2*
$X:$ n° de pedidos por horas
x = 0, 1, 2...
$P(x>2) = 1 - P(x\le2)$
$= 1 -[P(x=0)+P(x=1)+P(X=2)]$

*n° de pedidos por dia*:
usaremos a média "igual"
$\lambda_{1} = 8 \times x = 32$
y = 50
# $\frac{32^{50} \times e^{-32}}{50!}$
