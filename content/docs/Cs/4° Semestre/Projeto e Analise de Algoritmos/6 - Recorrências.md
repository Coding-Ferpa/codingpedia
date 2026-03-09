---
title: "Recorrências"
weight: 3
excalidraw-plugin:
---

É uma equação ou inequação que descreve uma função em termos de seu valor em outros argumentos, normalmente menores. (explicitamente, recursão)

Uma recorrência é algorítmica se, para cada constante de limiar suficientemente grande $n_{0}> 0$, as seguintes props forem verdadeiras:
- $\forall n < n_{0}, T(n) = \Theta(1)$
-$\forall n \geq n_{0}$ cada caminho de recursão termina em um caso base dentro de um numero finito de chamadas recursivas 

---
Adotamos a seguinte convenção:
> sempre que uma recorrência e enunciada sem um caso base explicito consideramos a recorrência e algorítmica.

Inequações são representadas na notação O ou $\Omega$, visto que são limites tanto superior quanto inferior

## Métodos de solução

- Metodo iterativo: expandir os termos e analisar
- Metodo da substituicao: arriscamos um palpite para a forma de um limite e usamos a indução para provar o palpite.
 - Arvore da recursao: converte a recorrência em uma árvore cujos nós representam os custos em nivel. 
 - Teorema ou metodo mestre: 
	 - $T(n) = aT(\frac{n}{b}) + f(n)$
	 - essa é a forma dele, onde a e b > 1


## Exemplo
$T(n) = T(\frac{n}{2}) + 3$
podemos reescrever como:
$T(2^k) = T({2}^{k-1}) + 3$

pois $2^{k}= n$ 
	$log_{2}n \ ou \ lgn = k$
então,
	$T(n) = lg(n) + 3$
# Exercícios subs
- estrutura da questão
	- escolhemos 2 valores convenientes e válidos para a desigualdade para $c$ e para $n$
	- depois, escolhemos os casos bases trocando $c$ pelo generico e $n$ por um T(n) 
1) T(n) = T(n-1) + n = T(n) < c(n-1)² + n
		(cn - c)²	+ n = cn² - 2cn + c + n <= cn² 
			desde que c e 0 sejam naturais, a desigualdade é valida.
- escolha do caso base T(1) = 1
2) $T(n) = T\left(\frac{n}{2}\right)+\Theta(1)$ 
		T(n) <= $clg\frac{n}{2} + \Theta(1)$ = clgn <= clgn 
	- desde que c > 0 e n > 1
	
		