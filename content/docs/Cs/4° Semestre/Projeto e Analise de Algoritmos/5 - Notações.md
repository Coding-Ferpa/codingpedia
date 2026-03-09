---
title: "Notações"
weight: 3
---

A ideia é chegar o mais rápido possível na ordem de crescimento de um algoritmo. 

## Notação $O$
A notação O caracteriza o limite superior sobre o comportamento assintótico de uma função. Em outras palavras, descreve o limite de crescimento de alguma função. Representamos sempre pelo termo de mais alta ordem de uma função de custo. A constante apenas modifica o quanto de entrada será necessário para chegar no limite definido, então ela n importa.


## Notação $\Omega$
Caracteriza o limite inferior da função. Ou seja, tenta descrever o melhor dos casos possíveis, sempre demorará mais ou o mesmo tempo que $\Omega$.

$$
Ω(g(n))=0≤cg(n)≤f(n)
$$

Por exemplo:

$$
4n^2+100n+500 = O(n^2)
$$

$$
4n^2+100n+500≥cn^2
$$

$$
4+100/n+500/n^2≥n
$$

Isso vale para $n_0$ sendo qualquer inteiro e $c=4$. Porém o valor de $c$ muda conforme o $n_0$ escolhido, diminuindo o valor de $c$.
## Notação $\Theta$
Limite restrito sobre o comportamento assintótico da função. Ela diz que uma função cresce precisamente em determinada taxa, ou seja, as constantes e termo de maior grau importam igualmente. O delimitador *inferior* e *superior* não precisam ser iguais.

$$
O(g(n))=0<=c_1g(n)<=f(n)<=c_2g(n)
$$

### Teorema:

Para quaisquer funções $f(n)$ e $g(n)$, temos $f(n) = θ(g(n))$ se, e somente se $f(n)=O(g(n))$ e $f(n) = Ω(g(n))$. Embora as 3 formas de caracterizar os tempos de execuções, o limite θ é preferível por ser mais precisa, porém nem sempre é aplicável por O e Ω não serem iguais e conforme o teorema, e errado afirmar θ.

## Definição

O uso do O pode ser assintóticamente justo ou não, ou seja $n^2=O(n^2)$ é justo já que tem um resultado de um limite compatível e justo à complexidade porém quando é dito que $2n=O(n^2)$ percebemos que é um limite não justo uma vez que, mesmo sendo um limite verdadeiro ele não pode ser aplicado na prática por não ser justo. Esse tipo de limite injusto é chamado de little $O$  e pode ser representado por $o$ mesmo pode ocorrer com Ω e ω(little omega).