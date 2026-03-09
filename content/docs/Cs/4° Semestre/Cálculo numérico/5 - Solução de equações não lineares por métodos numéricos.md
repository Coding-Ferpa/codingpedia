---
title: "Solução de equações não lineares por métodos numéricos"
weight: 3
---

- vamos ver métodos numéricos p/ resolver equações do tipo
$f(x) = 0$ 
- onde $f:[a,b]$ reais é uma continua derivável em (a,b)
- $f$ tem derivadas de todas as ordem de $(a,b)$

 Um numero real (ou complexo) $\xi$ é um zero da função $f(x)$ ou uma raiz da equação $f(x) = 0$, ou ainda, uma *solução* de $f(x) = 0$, se $f(\xi) = 0$ 
- estamos interessados somente em raízes reais. Deixaremos o caso complexo de fora.

# Interpretação Gráfica
> ex. no caderno...

Graficamente, um zero de $f(x)$ é um ponto que corresponde à intersecção do gráfico de $f(x)$ com o eixo $x$ .

$\xi_1 = -3$, $ξ_2 = -2$, $ξ_3 = -\frac{1}2$, $ξ_4 = 2$    

O Método de obtenção de raízes aproximadas consiste em 2 fases:
- 1) localização dos zeros
- 2) refinamento dos zeros

# Fase 1 - Localização de zeros
Precisaremos do Teorema A:
- seja $f(x)$ uma função contínua no intervalo $[ a, b]$. Se $f(a) . f(b) \lt 0$, então existe $\xi \in (a,b)$  , tal que $f(\xi) =0$ . Basicamente, se f(a) tem sinal inverso a f(b), então, $f(\xi) = 0$.
	- esse teorema garante que existam raízes, mas não determina quantas.
		- exemplo no caderno
	- a escolha ideal de um intervalo é aquele que contempla menos raízes (preferencialmente uma) contido em si. Lembre-se que $f(a) . f(b) \lt 0$  
	- derivada não muda de sinal, idealmente

> def: Sejam $f(x)$ e $f'(x)$ contínuos em $[a,b]$ ; Se $f(a) . f(b) \lt 0$  e $f'(x)$ não altera seu sinal em $(a,b)$, então existe um único zero de $f(x)$ em $[a,b]$

## Outros métodos ferozes de verificação dos 0 da função
a partir de $f(x) = 0$,1 podemos obter uma equação do tipo 
- $h(x) = g(x)$
onde h(x) e g(x) são mais simples que f(x).

ex: $f(x) = \sin(x) -e^{-\frac{-x}{4}}$   
- podemos reescrever a equação $f(x) = 0$ como $\sin(x) -e^{-\frac{-x}{4}} = 0$, portanto: 
	- $\sin(x) -e^{-\frac{-x}{4}} =0$    
	- $\sin(x) = e^{-\frac{-x}{4}}$    
	$g(x)	 = \sin(x)$ e $h(x) = e^{-\frac{-x}{4}}$
- ou seja, os 0 de $f(x)$ são os pontos de intersecção entre os novos gráficos  $h(x)$ e $g(x)$

### Tabelamento para achar os 0
Usando o Teorema A1, podemos encontrar zeros de $f(x)$ de forma sistemática tabelando alguns valores e analisando  os sinais de $f(x)$ nesses valores.

ex:  considere a função:
- $f(x) = \arctan{g(x)} - (8x⁴ - 8x² +1)+\frac12$  

| x      | -0.4 | -0.2  | 0   | 0.2  | 0.4  | 0.6   |
| ------ | ---- | ----- | --- | ---- | ---- | ----- |
| $f(x)$ | 0.67 | -0.32 | 0.5 | 1.32 | 0.32 | -2.23 |
| sinal  | +    | -     | +   | +    | +    | -     |
sabemos que durante as mudanças de sinais, tem raízes em determinados intervalos.

