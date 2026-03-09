---
title: "Prog Dinamica"
weight: 3
---

Programação dinâmica: subdividir um problema de otimização nos quais temos estratégias mais simples de chegar em solução ótima.

A estratégia fundamental é armazenar a solução para cada um desses subproblemas em vez de recalculá-la. Veremos como essa ideia pode transformar algs de tempo péssimo em um tempo ótimo.

Os algoritmos gulosos se aplicam a problemas de otimização. A ideia é fazer cada escolha de maneira ótima local, resultando em um algoritmo mais rápido do que aquele obtido na prog dinâmica.

Veremos a análise amortizada também. Impõe um limite para o custo real da sequência inteira.

# programação dinâmica
armazenar os dados em tabelas para otimização

_ETAPAS_
1. caracterizar a estrutura de uma solução ótima
2. definir recursivamente o valor de uma solução ótima
3. calcular o valor de uma solução ótima, normalmente de baixo para cima
4. construir uma solução ótima


## Cortes de Hastes
O problema do corte de hastes consiste em decidir onde cortar hastes de aço. Uma empresa compra hastes de aço longas e as corta em hastes mais curtas, para vendê-las. Cada corte é livre. A direção da empresa precisa saber qual é o melhor modo de cortar as hastes. A empresa possui uma tabela indicando, para i = 1, 2, ..., n, o preço pi em dólares que a empresa cobra por uma haste de i polegadas de comprimento. O comprimento de cada haste é sempre um número inteiro de polegadas. Dada uma haste de n polegadas de comprimento e uma tabela de preços $\text{p}_i$ para i = 1, 2, ..., n, determine a receita máxima $\text{r}_n$ que se pode obter cortando a haste e vendendo os pedaços. Observe que, se o preço pn para uma haste de comprimento n for suficientemente grande, uma solução ótima pode exigir que ela não seja
cortada.

Se uma solução ótima cortar a haste em k pedaços, para algum $1 ≤ k ≤ n$, então o desdobramento ótimo:

$n = i_1 + i_2 + ⋯ + i_k$

da haste em peças de comprimentos $i_1, i_2, ..., i_k$ gera a receita máxima correspondente 

$r_n
= p_{i1} + p_{i2} + ⋯ + p_{ik}$

Como não sabemos de antemão qual é o valor de i que otimiza a receita, temos de considerar todos os valores possíveis para i e escolher aquele que maximize a receita.  Temos também a opção de não escolher nenhum i se pudermos obter mais receita vendendo a haste sem cortes.  Observe que, para resolvermos o problema original de tamanho n, resolvemos problemas menores do mesmo tipo, porém de tamanhos menores. Uma vez executado o primeiro corte, podemos considerar os dois pedaços como instâncias independentes do problema do corte da haste.  A solução ótima global incorpora soluções ótimas para os dois
subproblemas relacionados, maximizando a receita gerada por esses
dois pedaços. Dizemos que o problema do corte de hastes exibe subestrutura ótima: soluções ótimas para um problema incorporam soluções ótimas para subproblemas relacionados, que podemos resolver independentemente.

O procedimento CORTA-HASTE implementa o cálculo implícito na equação anterior de modo direto, recursivo, de cima para baixo. O procedimento CORTA-HASTE toma como entrada um vetor p[1:n] de preços e um inteiro n, e retorna a máxima receita possível para uma haste de comprimento n.

```
CORTA-HASTE(p, n)
	if n == 0
		return 0
	q = –∞
	for i = 1 to n
		q = máx{q, p[i] + CORTA-HASTE(p, n – i)}
	return q
```

O problema é que CORTA-HASTE chama a si mesmo recursivamente repetidas vezes com os mesmos valores de parâmetros, o que significa que ele resolve os mesmos problemas repetidamente.  Quando esse processo se desenrola recursivamente, a quantidade de trabalho realizada, em função de n, cresce explosivamente.

Para analisarmos o tempo de execução de CORTA-HASTE, indicamos por T(n) o número total de chamadas feitas a CORTA-HASTE(p, n) para um valor particular de n.  Essa expressão é igual ao número de nós em uma subárvore cuja raiz é identificada por n na árvore de recursão. A contagem inclui a chamada inicial à raiz.

Assim, T(0) = 1 e $T(n) = 1+ \sum_{j=0}^{n-1}T(j)$

Essa recorrência tem como solução T(n) = 2n. Ou seja, o tempo de execução de CORTA-HASTE é exponencial em n. Esse tempo de execução exponencial não é surpresa. CORTA-HASTE considera explicitamente todos os modos possíveis de cortar uma haste de comprimento n. 

Agora, vamos aplicar programação dinâmica para melhorar essa solução e ao invés de resolver os mesmos subproblemas repetidamente nós a adaptamos para resolver cada problema somente uma vez, armazenando esta solução e não a recalculando. Apesar de isso custar mais memória a melhora em tempo é imensa, passando de um algoritmo exponencial para um algoritmo polinomial.

Normalmente, há dois modos equivalentes de implementar uma abordagem de programação dinâmica e essas duas abordagens produzem algoritmos com o mesmo tempo de execução assintótico, exceto em circunstâncias incomuns, quando a abordagem de cima para baixo não executa recursão propriamente dita para examinar todos os subproblemas possíveis. Muitas vezes, a abordagem de baixo para cima tem fatores constantes muito melhores, visto que tem menos sobrecarga para chamadas de procedimento. Os procedimentos CORTA-HASTE-MEMOIZADO e CORTA-HASTE-BAIXO- PARA-CIMA retornam o valor de uma solução ótima para o problema do corte de hastes, mas não retornam a solução propriamente dita: uma lista de tamanhos de peças. 

Podemos estender a abordagem da programação dinâmica para registrar não apenas o valor ótimo calculado para cada subproblema, mas também uma escolha que levou ao valor ótimo. Com essa informação, podemos imprimir imediatamente uma solução ótima.


## Abordagem de cima para baixo com memoizacao
Na abordagem de cima para baixo, escrevemos o procedimento recursivamente de maneira natural, porém modificado para salvar o resultado de cada subproblema. Agora, o procedimento primeiro verifica se já resolveu antes esse subproblema. Se já resolveu, retorna o valor salvo, poupando computação adicional nesse nível; se ainda não resolveu, o procedimento calcula o valor da maneira usual, mas também o salva.

```
CORTA-HASTE-MEMOIZADO-AUX(p, n, r)
	if r[n] ≥ 0
		return r[n]
	if n == 0
		q = 0
	else q = –∞
		for i = 1 to n
			q = máx{q, p[i] + CORTA-HASTE-MEMOIZADO-AUX(p, n – i, r)}
	r[n] = q
	return q

CORTA-HASTE-MEMOIZADO(p, n)
	seja r[0:n] um novo vetor //guarda “subsoluções”
	for i = 0 to n
		r[i] = –∞
	return CORTA-HASTE-MEMOIZADO-AUX(p, n, r)
```
## Abordagem de baixo para cima

Essa abordagem depende normalmente de alguma noção natural do “tamanho” de um subproblema, tal que resolver qualquer subproblema particular depende somente de resolver subproblemas “menores”.

Resolvemos os subproblemas por ordem de tamanho, o menor primeiro, armazenando a solução de cada subproblema quando ele é resolvido inicialmente.

Desse modo, ao resolvemos determinado subproblema, já existem soluções salvas para todos os menores subproblemas dos quais sua solução depende. Assim é resolvido os subproblemas apenas uma vez.

```
CORTA-HASTE-BAIXO-PARA-CIMA(p, n)
	seja r[0:n] um novo vetor
	r[0] = 0
	for j = 1 to n
		q = –∞
		for i = 1 to j
			q = máx{q, p[i] + r[j – i]}
		r[j] = q
	return r[n]
```
### Calculo de Tamanho
O procedimento CORTA-HASTE-BAIXO-PARA-CIMA-EXT calcula, para cada tamanho de haste j, não somente a receita máxima rj, mas também sj, o tamanho ótimo da primeira peça a ser cortada.

Esse procedimento é semelhante a CORTA-HASTE-BAIXO-PARA-CIMA, exceto pela criação do vetor s na linha 1 e pela atualização de s[j] na linha 8 para guardar o tamanho ótimo i da primeira peça a cortar ao resolver um subproblema de tamanho j.

```
CORTA-HASTE-BAIXO-PARA-CIMA-EXT(p, n)
	sejam r[0:n] e s[1:n] novos vetores
	r[0] = 0
	for j = 1 to n
		q = –∞
		for i = 1 to j
			if q < p[i] + r[j – i]
				q = p[i] + r[j – i]
				s[j] = i
		r[j] = q
	return r e s
```
