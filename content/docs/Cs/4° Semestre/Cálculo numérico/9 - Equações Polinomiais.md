---
title: "Equações Polinomiais"
weight: 3
---

Um polinômio de grau n é uma expressão da forma
- $P_{n(x)}= a_{a}+ a_{i}x^{1}+..+a_{n}x^n$ 
- $P_{n(x)}= a_{n}x^{n}+ a_{i}x^{1}+..+ a_{a}$  ou
- $P_{n}(x) = \sum^{n}_{i=0a} a_{i}x^{i}$
com $a_{n}\neq 0$ e os $a_{i}$ são números reais.

# Teorema Fundamental da Álgebra.

Seja $n\geq P_{n}(x)$ um polinômio de grau n. Então $P_{n}(x)$ tenha exatamente $n$ raízes (zeros da função), podendo ser reais ou complexos, desde que cada zero seja contado com a multiplicidade.
Dizemos que um zero $\xi$ de $P_{n}(x)$ tem multiplicidade $k \ (1 \leq k \leq n)$  se $P_{n(\xi)}=0,\ P_{n}'(\xi), \ P_{n}^{n}(\xi) = 0, \ .., \ P_{n}^{k-1}(\xi) = 0$ e $P_{n}^{k}(\xi) \neq 0$

## Propriedades para polinômios
Sejam $P_{n}(x) = a_{0}+ a_{1}x^{1}+ a_{n}x^{n}$

1. se $\xi_{1}, \xi_{2}, \xi_3$  são zeros, então: $P_{n}=a_{n}(x-\xi_{1})(x-\xi_{2})(x-\xi_{3})$
	>$P_{n}(x) = \prod^{i=1}_{n} (x-\xi_{i})$ 
2. se $\xi$	é um zero de $P_{n}(x)$ então $P_{n}(x)$ é divisível por $x - \xi$.
	1.  isto é, existe um $Q_{n-1}(x)$ polinômio de grau n - 1 tal que 
	 $$P_{n}(x) = (x-\xi)Q_{n-1}(x)$$
3. se $y$ é um numero real que não é zero de $P_{n}(x)$ , então existe um polinômio  $Q_{n-1}(x)$  e numero $b_{0}\neq 0$ tal que:
 $$ P_{n}(x) = (x-y)Q_{n-1}(x) + b_{0}$$
sendo $b_0$ o resto da divisão por $x-y$ e $b_{0}= P_{n}(y)$.

---
# Localização de zeros de polinômios
## 1. Regra do Sinal do Descartes
Dado um $P_{n}(x)$ com coeficientes reais, o **número de zeros positivos** $p$ desse polinômio não excede o numero de **variações** **de** **sinal** $v$  dos coeficientes. Mais ainda, $v-p$ é positivo e par.
(Variação de sinal -> coeficientes (1, 4, 1, -6) -> $v$++ se há troca de sinal) -> neste caso, $v = 1$

$P_{4}(x) = (x)^{4}-5(x)^{3}+5(x)^{2}+5(x)-6$
troca de sinal -> +, -, +, +, -
$v = 3$
$v - p = 0 \ ou \ 2$
$p = 1 \ ou \ 3$
### 1.1 Para zeros negativos
usaremos x = -x no polinômio e aplicaremos a regra de Descartes:
$P_{4}(-x) = (-x)^{4}-5(-x)^{3}+5(-x)^{2}+5(-x)-6$
$= x^{4}+ 5x^{3} + 5x^{2}- 5x -6$
troca de sinal -> +, +, +, -, -
$v = 1$
$v - p > 0 \ e \ par$
$v - p = 0$
portanto, $p=1$

### Observação
A regra de Descartes leva em consideração a multiplicidade do zero na avaliação do número de zeros positivos, ou seja, se um zero tem multiplicidade 2, ele conta como 2 zeros "distintos".

## 2. Regra de Descartes modificada
Seja $P_{n}(x) = a_{0}+a_{1}x^{1}+..+a_{n}x^n$ um polinômio de grau $n$ e considere a expansão de $P$ pela fórmula de Taylor em torno de $\alpha \neq 0$:
$$P_{n}(x) = P_{n}(\alpha) + \frac{P'_{n}(\alpha)}{1!}(x-\alpha)^{1}+ \frac{P''_{n}(\alpha)}{2!}(x-\alpha)^{2} +..+\frac{P^{(n)}_{n}(\alpha)}{n!}(x-\alpha)^{n}$$
Os números ${ã}_{i}= \frac{P_{n}^{(i)}(\alpha)}{i!}$ são os coeficientes do polinômio de Taylor de $P_{n}(x)$, ou seja, $v$ = troca de sinal de $\bar{a}_{i}$