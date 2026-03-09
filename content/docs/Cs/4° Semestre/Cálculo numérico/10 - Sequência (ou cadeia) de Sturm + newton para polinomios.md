---
title: "Sequência (ou cadeia) de Sturm + newton para polinomios"
weight: 3
---

Considere um polinômio $P_{n}(x)$ de grau $n$. Defina a seguinte sequência de polinômios:
	$g_{0}(x) = P_{n}(x)$
	$g_{1}(x) = P'_{n}(x)$
e em geral, definimos o termo $g_k(x)$ como sendo resto da divisão $-\frac{g_{k-2}(x)}{g_{k-1}(x)}$ 
**I.e**: $g_0/g_1$ = $q_2$, o resto da divisão $r_2$ = $-g_2$, isso de k = 0 até n, só parando quando $g_k$ for um uma constante.

A sequencia $g_{0}(x), g_{1}(x),.., g_{k}(x), ...$ é chamada de sequência de Sturm.

Seja $\alpha\in R$ e $ṽ({\alpha})$ o numero de variações de sinais da sequência de Sturm obtida **$(g_{k}(\alpha))_{k=1}^{n}$**

# Teorema de Sturm
Sejam $-\infty \leq \alpha \leq \beta \leq +\infty$ . Se $P_{n}(\alpha)\neq 0$ e $P_{n}(\beta) \neq 0$ então o numero de zeros reais distintos de $P_{n}(x)$ no  intervalo $[\alpha, \beta]$ é exatamente 
> $ṽ (\alpha) - ṽ(\beta)$


exemplo no caderno:
```functionplot
---
title: func
xLabel: x
yLabel: y
bounds: [-10,10,-10,10]
disableZoom: false
grid: true
---
f(x) = x^3 + x^2 - x + 1
g(x) = 3x^2 + 2x - 1 
h(x) = (8/9)x - 10/9

```


---
# Método de Newton para polinômios
> lembrando que $x_{k+1}= x_{k}- \frac{f(x)}{f'(x)}$

## algoritmo de Briot-Ruffini-Horner
dado 
$P_{n}(x) = a_{n}x^2+.....a_0$ 
$= \sum^{n}_{i=0} a_{i}x^{i}$

e $y\in R$, queremos um algoritmo para calcular $P_{n}(y)$ e $P'_{n}(x)$ 
Sabemos que:
 $P_{n}(x) = (x-y)Q_{n-1}(x) + b_{0}$ 

Seja:
$Q_{n-1}(x) = \sum^{n}_{i=1}b_{i}x^{i-1}$

Então, 
$\sum^{n}_{i=0}a_{i}x^{i-1} = (x-y). \sum^{n}_{i=1}b_{i}x^{i-1} +b_0$
$= \sum^{n}_{i=1}b_{i}x^{i} - \sum^{n}_{i=1}b_{i}x^{i-1} +b_0$
$\sum^{n}_{i=1}b_{i}x^{i-1} = b_{1}y+b_{2}x +b_{3}yx^{2}+...+b_{n}yx^{n-1}$

$= \sum^{n-1}_{i=0}b_{i+1}yx^{i}$

$\sum^{n}_{i=1} b_{i}x^{i}+b_{0} = b_{n}x^{n}+b_{n-1}x^{n-1} +...+b_{1}x + b_{0}$
$= b_{n}x^{n}+ \sum^{n-1}_{i=0}b_{i}x^{i}$

![[Briot-Houfini-Horner]]

---
Para calcular $P'_n(x)$, observe que $= Q_{n-1}(x) + (x-y) Q'_{n-1}(x)$
Logo, $P'_{n(y)}= Q_{n-1}(y)$.

Usando o mesmo artifício para calcular $P_n(y)$
$Q_{n-1}(x)= (x-y)R_{n-2}(x) +c_{1}$, onde $c_{1} = Q_{n-1}(y)=P'_n(y)$

![[briout-houfini-2]]

Com isso, podemos escrever o métodos de Newton ajustado para polinômios da seguinte maneira:

Fixada uma aproximação inicial $x_{0}$ para o zero $\xi$ de $P_{n}(x) = ...$
para cada $x_{k}$ obtido na sequencia -> $P_{n}(x_{k})$ e $P'_{n}(x_{k})$
- $y = x_k, b_n = n, c_n = b_n$
# $\implies x_{k+1}= x_{k}- \frac{b_{0}}{c_{0}}$
Se temos uma precisão $\epsilon > 0$, então, em cada, passo, devemos verificar se  $|x_{k+1} - x_{k}| = |-\frac{b_{0}}{c_{1}}| < \epsilon$ e repetimos o processo para $y = x_k+1$

