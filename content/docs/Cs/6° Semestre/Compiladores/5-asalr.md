---
title: "aula 6 asalr"
weight: 3
---

# Algoritmo de Análise Sintática Descendente Não Recursivo (ADNR)
Essa análise sintática usa a tabela preditiva, vista anteriormente.

*Entrada*: $w$ e $M$ (tabela sintática preditiva)

*inicio*
│   $ip$ aponta para o primerio simbolo de $w$
│   empilha $\$$
│   empilha o simbolo inicial da gramática
│   *repetir*
│   │   seja $X$ o simbolo no topo da pilha
│   │   seja $a$ o simbolo apontado por $ip$
│   │   se $X$ é um terminal então
│   │   │   *se* $X$ = $a$ *então*
│   │   │   │   desempilha $X$
│   │   │   │   avança $ip$
│   │   │   *senao*
│   │   │   │   erro de análise sintática
│   │   *senao se* $X$ é *não-terminal* e $M[X,a]$ = $X \rightarrow Y_1 Y_2 \dots Y_k$ *então*
│   │   │   desempilha $X$
│   │   │   empilha $Y_k, Y_{k-1}, \dots, Y_1$ (se $k$ = 0, nada é empilhado)
│   │   *senao*
│   │       erro de análise sintática
│   *até que* $X = \$ $
*fim*

Exercicio (sala): feito no caderno

Exercicio (casa):  repita o exercicio feito no caderno, utilizando a cadeia de entrada:

a) id + id * idid
b) id * id**id + id

# Analise Sintatica Ascendente (*Bottom-up*)
> [!note] LISP BEBÊÊÊÊÊÊEÊÊÊÊÊ

Usaremos a redução agora, ao invés da derivação. Ainda é necessário o uso do PDA, visto que a linguagem mantém-se LC.

Analise Sintática LR(k) 
- k = lookahead
- varredura da esquerda pra direita
- derivacao mais a direita ao contrario

Tipos: 
- LR simples (SLR): mais facil de implementar, menos poderoso.
- LR canonico (LRC): mais poderoso, mais custoso.
- LR lookahead (LALR): intermediário.

![[Pasted image 20250926101755.png]]

## SLR (Simple LR)
Vamos marcar a regra de produção com pontos ($\cdot$)  
i.e. 

Def: Um item LR(0) para uma gramática G é uma Produção de G com um ($\cdot$) em alguma das posições do lado direito da regra. Exemplo:
- a regra $A \rightarrow XYZ$ possui os items:
	- $A \rightarrow \cdot \ XYZ$
	- $A \rightarrow X\cdot YZ$
	- $A \rightarrow XY\cdot Z$
	- $A \rightarrow XYZ\cdot$

Considere a GLC:

P:
- E -> E + T | T
- T -> T * F | F
- F -> (E) | id

*Passo 1*: construir a GLC "aumentada":
- acrescentar um novo simbolo de partida
- e.g: E' -> E

*Passo 2*: construir os conjuntos de items. Comece com a regra de 'nova' produção.

$I_0$ = {$E'\rightarrow \cdot E$, 

apos inserir essa entrada, devemos fazer o *fechamento* em DFS, descendo pelas produções das variáveis que vem a aparecer:

$I_0$ = {
	$E'\rightarrow \cdot E$, 
	$E \rightarrow \cdot E + T$
	$E \rightarrow \cdot T$
	$T \rightarrow \cdot T * F$
	$T \rightarrow \cdot F$
	$F \rightarrow \cdot (E)$
	$F \rightarrow \cdot id$
}

agora fazendo a movimentação do ponto:

$I_1$ = {
	$E'\rightarrow E\cdot$, 
	$E \rightarrow  E\cdot + T$
}

$I_2$ = {
	$E\rightarrow T\cdot$
	$T\rightarrow\cdot *F$
}

$I_3$ = {
	$T\rightarrow F\cdot$
}
$I_4$ = {
	$F\rightarrow(\cdot E)$
	$E \rightarrow \cdot E + T$
	$E \rightarrow \cdot T$
	$T \rightarrow \cdot T * F$
	$T \rightarrow \cdot F$
	$F \rightarrow \cdot (E)$
	$F \rightarrow \cdot id$
}

$I_5$ = {
	$F\rightarrow id\cdot$
}
$I_6$ = {
	$E\rightarrow E + \cdot T$
	$T\rightarrow \cdot T * F$
	$T\rightarrow \cdot F$ 
	$F\rightarrow\cdot (E)$
	$F\rightarrow\cdot id$
}
$I_7$ = {
	$E\rightarrow T * \cdot F$
	$F \rightarrow \cdot (E)$
	$F\rightarrow \cdot id$
}
$I_8$ = {
	$F\rightarrow(E\cdot)$
	$E\rightarrow E\cdot+T$
}
$I_9$ = {
	$E\rightarrow E + T\cdot$
	$T\rightarrow T \cdot * F$
}
$I_{10}$ = {
	$T \rightarrow * F \cdot$
}
$I_{11}$ = {
	$F\rightarrow(E)\cdot$
}
