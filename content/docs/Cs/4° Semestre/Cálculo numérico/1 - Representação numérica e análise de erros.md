---
title: "Representação numérica e análise de erros"
weight: 3
---

## 1.1 Conversão do sistema binário para decimal
- Dado um número natural $\beta$, um numero $x$ é escrito na base $\beta$ se $x = a_{n}\beta^n + a_{n-1} \beta^{n-1}+ ... + a_{0} \beta^{0}$ 
	- Usamos então a notação $x = (a_{n}a_{n-1}...a_{1}a_{0})_\beta$(polinômio avaliado em $\beta$).
- Na base 2, se $x = (d_{k}d_{k-1}...d_{1}d_{0})_{2}$, então $x =d_{k}2^{k}+d_{k-1}2^{k-1} +...+ d_{1}2^{1} + d_{0}2^{0}$ .
- Podemos simplificar a conversão de binário para decimal, colocando a "base" em evidência (no caso, 2).
- **Exemplo:** $x = 1\cdot2^{4} + 0\cdot2^{3} + 1\cdot2^{2}+1\cdot2^{1}+1\cdot2^{0}$ -> $x = 2\cdot(2\cdot(2\cdot(1\cdot2^{1}+0)+1)+1)+1$
	- De 15 para 8 operações necessárias
	- $a_{4}$: primeiro dígito (1 no exemplo)
	- $a_{3} = a_{4} \times 2 + 0 = 2$
	- $a_{2} = a_{3} \times 2 + 1 = 5$
	- $a_{1} = a_{2} \times 2 + 1 = 11$
	- $a_{0} = a_{1} \times 2 + 1 = 23$

### Algoritmo:
$x = (d_{k}d_{k-1}...d_{1}d_{0})_{2}$, $d_{k} \in [0,1]$
$A_{k} = d_{k}$
$A_{i} = 2 \times A_{i+1} + d_{i}$ para $i = k-1, ..., 0$
$A_{0}$: número $x$ na base 10

## 1.2 Conversão do sistema decimal para binário
- Os dígitos $a_{i}$ são o resto da divisão de $N_{i}$ por 2 e $N_{i+1}$ é o quociente da divisão
### Algoritmo: 
$k = 0$
Enquanto $N_{k} \neq 0$
	$N_{K+1}$ = $\lfloor\frac{N_{k}}{2}\rfloor$
$a_{k} = N_{k} - 2 \times N_{k+1}$

## 1.3 Representação de números fracionários
- Um número $x = (0 , d_{1}d_{2}...d_{k})\beta$, em uma base $\beta$ é escrito como $x = d_{1}\times \beta^{-1} + d_{2}\times \beta^{-2} + ... + d_{k}\times \beta^{-k}$.
- A parte fracionária de $x$ é chamada de **mantissa**.
- O primeiro número da mantissa é chamado de **algarismo mais significativo**
Podemos simplificar a conversão isolando a "base" novamente:
	$x = (0.1011)_{2}$
	$x = 1 \times 2^{-1} + 0 \times 2^{-2} + 1 \times 2^{-3} + 1 \times 2^{-4}$
	$x = 2^{-1}(1+2^{-1}(0+2^{-1}(1+1\times2^{-1})))$
	$A_{5} = 0$
	$A_{4} = \frac{b_{4} + A_{5}}{2}$ = 0.5
	$A_{3} = \frac{b_{3} + A_{4}}{2}$ = 0.75
	$A_{2} = \frac{b_{2} + A_{3}}{2} = 0.375$
	$A_{1} = \frac{b_{1} + A_{2}}{2} = 0.6875$
### Algoritmo
$A_{n+1}= 0$
Para $k = n, n-1, ..., 2, 1$:
$A_{k} = \frac{(b_{k}+A_{k+1})}{2}$
