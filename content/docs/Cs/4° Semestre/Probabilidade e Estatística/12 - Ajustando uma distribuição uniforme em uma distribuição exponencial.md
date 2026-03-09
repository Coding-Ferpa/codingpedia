---
title: "Ajustando uma distribuição uniforme em uma distribuição exponencial"
weight: 3
---

Se $F(t)= u,$ então t = $F^{-1}(u)$
$1 - e^{-\alpha t}=u \implies$ 
$1-u = e^{-\alpha t}\implies$
$\ln(1-u) = -\alpha t \implies$ 
$$t = - \frac{1}{a}\ln(1-u)$$
---
Para gerar uma seq de n valores com dist exp de parametro

1. faça j=1
2. gere o NA u, no intervalo $[0,1]$
3. calcule o valor de t, usando a fórmula (1)
4. verifique se t>0 e $n\geq 1$
5. se $j<n$, faça j=j+1 
6. volte ao passo 2

---
Exemplo: Ajuste de modelo exponencial.
média = $\frac{1}{\alpha} = 3 ,\alpha = \frac{1}{3}$
T: tempo residual
$T ~ Exp(\frac{1}{3})$ 

$\begin{cases}\alpha e^{-\alpha t}  \\ 0\end{cases}$ -> $1 - e^{-\alpha t}$



