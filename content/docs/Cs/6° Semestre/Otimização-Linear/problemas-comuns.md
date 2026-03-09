---
title: "problemas-comuns"
weight: 3
---

Trataremos de 4 problemas padrão da prog. linear neste documento:
- Problema da Mistura
- Problema do Transporte 
- Problema do Transbordo 
- Problema da Designação

# Problema da mistura
Entende-se como um problema de se misturar ingredientes ou materiais com um suposto custo associado e uma determinada quantidade (os quais se deseja otimizar). Cada um dos ingredientes possui uma quantia de componentes a qual se é necessário assegurar uma quantidade correta na mistura.

>Deseja-se determinar as quantidades de cada ingrediente que devemos utilizar para fabricar a mistura, atendendo as especificações mínimas e com o menor custo. 

## Definição 
- $n$: número de ingredientes
- $m$: número de componentes relevantes para a mistura
- $x_j$: a quantidade de um dado ingrediente $j$ em uma unidade da mistura, $j=1\dots n$. 
- $x_j \geq 0, j=1\dots n$
- $a_{ij}$ eh a fração do componente i no ingrediente $j$.
- $b_i$ a quantidade ou fração mínima do componente $i$
- $c_j$ é o custo associado ao componente $x_j$

Temos então, a formulação do problema da mistura:

Minimizar $c_1x_1 + c_2x_2 + \dots c_nx_n$
sujeito a:
$a_{11}x_1 + \dots + a_{1n}x_n \geq b_1$
$a_{21}x_1 + \dots + a_{2n}x_n \geq b_2$
$\vdots$
$a_{mn}x_nn+ \dots + a_{mn}x_n \geq b_m$
$x_1, x_2, \dots, x_n \geq 0$

___

# Problema do Transporte

Normalmente se referem ao transporte ou distribuição de produtos de centros de produção e consumidores, no qual há limitações de produção e demanda e também custo relacionado ao transporte (ou armazenamento).

## Definição 
- $m$: origens
- $n$: destinos
- $a_i$: capacidade de oferta de um determinado produto na origem $i$
- $b_j$: demanda do produto no destino $j$
- $x_{ij}$ a quantia de produto transportado de $i$ para $j$ e $c_{ij}$ seu custo associado.

O custo total é dado por:

$f(x_{11}, \dots , x_{mn})= \sum_{i=1}^{m} \sum_{j=1}^{n} c_{ij}x_{ij}$

Conseguimos descrever a quantidade produtos que sai de i e devemos limita-la pela oferta $a_i$:
$\sum_{j=1}^{n} x_{ij} \leq a_{i}, i=1\dots\, m$

Conseguimos, também, descrever a limitação de demanda de um destino j:

$\sum_{i=1}^{m} x_{ij} = b_{j}, j=1\dots\, n$

# Problema do Transbordo
A ideia é a mesma do problema do transporte, mas adiciona-se nós intermediários às, já existentes, origens e destinos. Neste caso, devemos garantir que o que passa pelo transbordo saia de lá ($\sum^{}_{i}=x_{ij} = \sum_k x_{jk}$)

# Problema da Designação

O problema da designação é um problema de alocação de recursos em idênticas quantidades de tarefas. Em geral, cada recurso disponível pode ter afinidades (medidas numericamente) com as tarefas. 

A função de eficiência total se dá por:  $\sum\limits^{m}_{i=1}\sum\limits^{n}_{j=1}c_{ij}x_{ij}$

- c: afinidade que recurso i tem com a tarefa j 
- x =1, i realizou j, x =0 caso não

As restrições do problema impõem condições do tipo "cada recurso só pode realizar uma única tarefa(\*)" e “cada tarefa s ́o poder ́a ser realizada por um  ́único recurso (\*\*)”,

- (\*) $\sum\limits^{n}_{j=1}x_{ij}, \ \text{para} \ i=1,\dots,n$
- (\*\*)  $\sum\limits^{m}_{i=1}x_{ij}, \ \text{para} \ j=1,\dots , n$

Nesse tipo de problema, em geral, busca-se maximizar a eficiência e portanto, trata-se de um problema de maximização.