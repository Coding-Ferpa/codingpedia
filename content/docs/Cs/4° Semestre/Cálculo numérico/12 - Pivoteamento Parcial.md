---
title: "Pivoteamento Parcial"
weight: 3
---

Pivoteamento parcial é uma estratégia para evitar erros de solução de sistemas cuja origem são pivôs muito pequenos ($x\times10^{-i>2}$) em módulo. Dado um sistema:
$$Ax=b$$
a estratégia de pivoteamento parcial consiste em:
Para $j=1,2,3 ...,n-1$, na Etapa $j$ da eliminação de *Gauss* consideramos o pivô $a_{jj}$ e escolhemos a linha $i \gt j$ que satisfaz $|a_{ij}| = max_{k>j}|a_{ij}|$ e trocamos a linha $i$ com a linha $j$.

nota de otário (eu):

> simplesmente escolha o pivô como sendo o maior da coluna em questão, se na coluna temos 0.00002 e 2, escolha o pivô como 2 e coloque a linha onde 2 está como a linha da operação atual (ex: j = 2 = linha 2)
