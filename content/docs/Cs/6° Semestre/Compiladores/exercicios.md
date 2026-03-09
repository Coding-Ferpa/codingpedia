---
title: "exercicios"
weight: 3
---

AULA 1

---
AULA 2
Identifique os tokens:
	int a,b,c;
	char cadeia;
	leia(a);
	b = 3;
	c = 2;
	c = c + a + b;
	escreva(c);
	Cadeia = 'S';
	escreva(S);	

---
AULA 3

---
AULA 4
Exercício(casa): usando derivação, obtenha 10 cadeias da linguagem abaixo
$G = ({E, E', T, T'}, {+,-,*,/,num}, P, E)$
$P:  E -> TE'$
	$E' \rightarrow +TE' | - TE' | \epsilon$
    $T \rightarrow FT'$
    $T' \rightarrow *FT' | /FT' | \epsilon$
    $F \rightarrow (E) | num$

Exercícios: Calcule o conjunto First e Seguinte
a) 
  $E \rightarrow TE'$
  $E' \rightarrow +TE' \ | \ - TE' \ | \ \epsilon$
  $T \rightarrow FT'$
  $T' \rightarrow \ *FT' \ | \ FT' \ | \ \epsilon$
  $F \rightarrow (E) \ | \ num$

b)  $S\rightarrow aAeS \ | \ Bd \ | \ d$
	$A\rightarrow aA \ | \ \epsilon$
	$B\rightarrow bB \ | \ c$

---
AULA 5

Exercício (Sala):
Encontrar os conjuntos Primeiro e Seguinte

a) S -> AB
   A -> c|$\epsilon$
   B -> cbB|ca 

b) S -> XYZ
    X -> aXb|$\epsilon$
    Y -> cYZcX|d
    Z -> eZYe|f

Exercícios (Casa):
Construir os diagramas sintaticos e o ASDR:
- entrada->expressao _eof_
- expressao->termo expressao_restante
- termo -> _id_ | expressao_entre_parenteses
- expressao_entre_parenteses -> ( expressao )
- expressao_restante -> expressao | $\epsilon$


Exercicio: Construir a tabela de analise sintática preditiva para a seguinte gramática

E-> TE'
E'-> +TE' | $\epsilon$
T-> FT'
T'-> *FT' | $\epsilon$
F-> (E) | id


| não terminal | id      | +         | *         | (       | )      | $      |
| ------------ | ------- | --------- | --------- | ------- | ------ | ------ |
| E            | E-> TE' |           |           | E-> TE' |        |        |
| E'           |         | E'-> +TE' |           |         | E'-> ε | E'-> ε |
| T            | T-> FT' |           |           | T-> FT' |        |        |
| T'           |         | T'-> ε    | T'-> *FT' |         | T'-> ε | T'-> ε |
| F            | F-> id  |           |           | F-> (E) |        |        |

posições em branco na tabela representam erros de análise sintática.

---

Prova 2

# Exercicios

1. Construir o conjunto de itens LR(0) para as gramáticas:

a) 
E' -> E
E -> (L)
E -> a
L -> L, E 
L -> E

resultado: 

$I_0$ = {
    E' -> .E
    E -> .(L)
    E -> .a
}

$I_1$ = {
    E' -> E.
}
$I_2$ = {
    E -> (.L),
    L-> .L,
    L-> .E,
    E-> .a,
    E -> .(L)
}
$I_3$ = {
    E -> a.,
}
$I_4$ = {
    E -> (L.),
    L-> L.
}
$I_5$ = {
    L-> E.,
}
$I_6$ = {
    E -> (L).,
}


b) 
S' -> S
S -> S(S) 
S -> $\epsilon$

c) 
E' -> E
E -> (L) 
E -> a 
L -> EL 
L -> E


2. Construir o conjunto de itens LR(1)  de S -> S(S) | $\epsilon$


3. Construir itens LR(0) 
S -> AS | b 
A -> SA | a

----

S -> id | V = E
V -> id 
E -> V | n

Gramatica aumentada

1. S' -> S 
2. S -> id
3. S -> V = E
4. V -> id
5. E -> V
6. E -> n

a) Construa a tabela de análise preditiva LR(1) para a gramática acima.

first sets:
first (S) = {id}
first (V) = {id}
first (E) = {id, n}

$I_0$ = {
    S' -> .S, \$
    S -> .V = E, \$ 
    S -> .id, \$
    V -> .id, =
}
$I_1$ = {
    S' -> S., \$
}

$I_2$ = {
    S -> id., \$
    V -> id., =
}

$I_3$ = {
    S -> V. = E, \$
}
$I_4$ = {
    S -> V = .E, \$
    E -> .V, \$
    E -> .n, \$
    V -> .id, \$
}
$I_5$ = {
    E -> n., \$
}
$I_6$ = {
    E -> V., \$
}
$I_7$ = {
    V -> id., \$
}
$I_8$ = {
    S -> V = E., \$
}


--- 
Construção da tabela de análise preditiva LR(1):

| Estado | id      | =       | n       | $       | S       | V       | E       |
|--------|---------|---------|---------|---------|---------|---------|---------|
| 0      | s2 | | | | 1 | 3| |
| 1      | | | | acc | | | |
| 2      |  | r4 | | r2 | | | |
| 3      | | s4| | | | | |
| 4      | s7 |  | s5 | | | 6 | 8 |
| 5      | | |  | r6 | | | |
| 6      | | |  | r5 | | | |
| 7      |  | | | r4| | | |
| 8      | | | | r3 | | | |


---