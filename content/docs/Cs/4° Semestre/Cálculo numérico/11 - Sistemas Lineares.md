---
title: "Sistemas Lineares"
weight: 3
---

# Operações elementares como operações matriciais

1. Matriz elementar de permutação de linhas
	 - A matriz $P_{i,j}$ que troca as linhas i e j de lugar na matriz identidade $I_{n}= (\delta_{ij})$ é chamada e matriz de permutação nas linhas i e j e, quando multiplicada por uma matriz A à esquerda, ela permuta as linhas i e j de A.
	 - Obs: $P_{i,j}$ é inversível e $P^{-1} = P_{ij}$ 

2. Matriz elementar que multiplica linhas por um numero $\alpha \neq 0$
	- A matriz $D_{i}(\alpha)$ , obtida substituindo $\delta_{ii} = 1$  por $\alpha$ na $I_n$, quando multiplicada à esquerda multiplica a linha inteira.
	- Obs: $D_{i}(a)^{-1} = D_{i}(a^{-1})$
	
3. Matriz elementar que multiplica linha i por $\alpha \neq 0$ e adiciona à linha j
	- A matriz $E_{ij}(\alpha)$, obtido substituindo o termo $\delta_{ji}$ de matriz identidade $I_{n}$ quando multiplicada à esquerda em uma matriz A tem o efeito de  multiplicar linha i por $\alpha \neq 0$ e adicionar à linha j
	- Obs: 
		- $E_{ij}(\alpha)$ é inversível e $E_{ij}(\alpha)^{-1} = E_{ij}(-\alpha)$ 
		- Podemos realizar muitas operações $E_{ij}$ ao mesmo tempo

# Processo sistemático de soluções de sistemas
1°) Suponha que $a_{11}^{(0)} \neq 0$. O termo  $a_{11}$ é chamado de pivô da 1° etapa.
Sejam:
$$m_{21}=\frac{a_{21}^{(a)}}{a_{11}^{(a)}} \ e \  m_{31}=\frac{a_{31}^{(a)}}{a_{11}^{(a)}}$$

[...]
