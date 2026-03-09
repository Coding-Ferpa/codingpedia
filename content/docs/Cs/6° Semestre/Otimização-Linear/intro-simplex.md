---
title: "intro-simplex"
weight: 3
---

# Soluções Básicas
Precisamos transformar, inicialmente, os problemas de otmização linear em sua forma padrão, ou seja, com restrições antes dadas por inequações em equações. Para isso, utilizamo-nos das variáveis de folga, que representam a diferença entre o lado esquerdo e o lado direito de uma inequação.

Uma solução básica é, portanto, uma solução que satisfaz todas as restrições e que possui exatamente $m$ variáveis básicas (não nulas), node $m$ é o número de restrições do problema. As demais variáveis são chamadas de variáveis não básicas e são iguais a zero.

Resto no caderno porque sim.

## Posto de uma matriz
Seja A uma matriz $m \times n$. O posto-linha da matriz é igual ao número máximo de linhas linearmente independentes de A. 

O posto-ocluna de A é o mesmo mas para colunas.

Pode ser mostrado que o ponto-linhas é igual ao posto-coluna e, portanto, o posto da matriz é igual ao máximo número de linhas ou colunas linearmente independentes de A. ($posto(A) < \min{m, n}$)

Se $posta(A) = \min{m, n}$, então A é dita de posto completo.

Agora, considere o sistema linear $Ax = b$, onde A é uma matriz $m \times n$ e $b \in R^m$. Se $posto(A) = posto(A|b) = m$, então o sistema é consistente e possui solução única. Se $posto(A) = posto(A|b) < m$, então o sistema é consistente e possui infinitas soluções. Se $posto(A) < posto(A|b)$, então o sistema é inconsistente e não possui solução.
