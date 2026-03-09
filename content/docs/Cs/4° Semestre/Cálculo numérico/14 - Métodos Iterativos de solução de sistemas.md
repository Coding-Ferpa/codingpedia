---
title: "Métodos Iterativos de solução de sistemas"
weight: 3
---

Considere o espaço vetorial $R^{n}$ das n-uplas $(x_{1}, x_{2},..., x_{n})$  de números reais.
A norma euclidiana em $R^{n}$ é dada por $||(x_{1}, x_{2},..,x_{n})|| = \sqrt{x_{1}^{2} + .. + x_{n}^{2}}$  
$d = ||x-y||$ 
outras normas:
- norma da soma -> $||x||_{1}$ = $|x_{1}| + |x_{2}| +...+|x_{n}|$
- norma do máximo -> $||x||_{\infty} = max_{1\leq x \leq n} |x_{i}|$  -- usaremos essa

Todas essas normas são equivalentes e também induzem à ideia de distância em $R^{n}$.

## Normas de matriz
Seja:
$$A = \begin{bmatrix}
a_{11} & a_{12}... & a_{1n} \\ a_{21} & a_{22}... & a_{2n}  \\ a_{n1} & a_{n2}... & a_{nn}
\end{bmatrix}$$
_Norma linha de A_: $||A||_{\infty } = max\lbrace \sum_{j=1}^{n}\limits{|a_{ij}}\rbrace$ 
_Norma coluna de A_: $||A||_{1} = max \lbrace \sum_{i=1}^{n}\limits{|a_{ij}|} \rbrace$

# Método Iterativo de Jacobi 

Considere um sistema na forma matricial:
	$Ax = B$ onde $A$ é uma matriz $n\times m$

Vamos reescrever o sistema como $$x= Bx+c$$ e então definimos uma sequência iterativa por $$x^{(k+1)}= Bx^{(k)}+c$$
para k = 0, 1, 2,3 ..., com uma aproximação inicial de $x^{(0)}$, onde k+1 são os índices da sequência.

## Teste de parada:
dada uma precisão $\epsilon > 0$, tomaremos como aproximação $\bar x$ da solução real $\xi$ de $Ax = B$ o valor $x^{(k+1)}$ que satisfaz:
$$||x^{(k+1)}-x^{(k)}||_{\infty}< \epsilon$$

# Teorema do Método de Jacobi
Seja $\xi$ a solução do sistema $Ax = B$, ou equivalentemente, $x=Bx+c$. Para alguma norma matricial $||.||$, se $||B||=\lambda<1$, então a sequencia $(X^{(k)})$ converge para $\xi$ com qualquer escolha do vetor inicial $x^{(0)}$, isto é $$\lim_{k\rightarrow\infty} ||x^{(k)}-\xi||_\infty=0$$
