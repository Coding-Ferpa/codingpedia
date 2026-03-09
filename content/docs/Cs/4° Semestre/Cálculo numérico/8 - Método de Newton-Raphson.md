---
title: "Método de Newton-Raphson"
weight: 3
---

Seja $g(x) = x + A(x)f(x)$, temos, então, o objetivo de determinar $A(x)$ que garanta a derivada 0 no ponto fixo.

Vamos impor sobre $g(x)$ a condição de que $g'(\xi) = 0$, onde $\xi$ é solução de $f(x) = 0$. Derivando $g(x)$ temos:
$$g'(x) = 1 + A'(x)f(x)+A(x)f'(x)\newline 
g'(\xi) = 1 + A'(\xi)f(\xi)+A(\xi)f'(\xi)\newline 
$$
Sabemos que $A'(\xi).f(\xi) = 0$, porntato:
$$0 = 1 + A(\xi)f'(\xi)$$
Logo:
$$ A(\xi) = - \frac1{f'(\xi)}$$
Podemos, então, escolher 
$$A(x) = -\frac1{f'(x)}$$
Temos que: $f'(x) \neq 0$ perto de $\xi$
Logo:
$$ g(x) = x - \frac{f(x)}{f'(x)}$$

a sequência numérica do método de Newton será:

> $$X_{k+1} = x_{k}- \frac{f(x_k)}{f'(x_k)}$$

Se escolhermos um $x_{0}$ próximo a $\xi$, ele convergirá.

## Critério de parada
$x_{k+1}- x_{k} < \xi$

---
# Interpretação Geométrica

Dado um gráfico genérico, a reta tangente ao gráfico de f(x) em $x_0$ é dada por:

$y = f(x_0)+f'(x_{0})(x-x_0)$ 

e defino $x_1$ como sendo o 0 da reta tangente

Fazendo y = 0 e dividimos os 2 lados por f', teremos:
$$x_{1}= x_{0} - \frac{f(x_0)}{f'(x_0)}$$

Em geral, $x_{k+1}$ será o zero da reta tangente ao gráfico de f(x) no ponto $x_k$.

---

