---
title: "aula 8 alg asdr"
weight: 3
---

HOT TAKE: Analise Sintatica Ascendente LR precisa extender a gramatica.
HOT TAKE: Se A -> $\epsilon$ é uma produção, então A -> . é um item válido.

Exercicio: construir a coleção cacônica de itens LR(0): 
S -> L = R
S -> R
L -> * R
L -> id
R -> L

feito no caderno

Exercicio (casa): construir a tabela SLR para o exemplo anterior.

---

# Algoritmo de Analise Sintatica Ascendente
O algoritmo permance inalterado para as 3 formas de Analise (SLR, LRC, SALR).

Inicialmente, o analisador sintatico possui $s_0$ na pilha, onde $s_0$ é o estado inicial e $w\$ $ no buffer de entrada. O analisador executa, então, o seguinte programa:

*Entrada*: $w\$$ e $M$ (tabela SLR)

*inicio*
│  fazer $ip$ apontar para o primeiro token $w\$$
│  repetir para sempre
│  │  seja $s$ o estado ao topo da pilha $e$
│  │  $a$ é o token apontado por $ip$
│  │  se *ação*$[s, a]$ = empilha A -> $\beta$ então inicio:
│  │  │  empilhar $a$ e em seguida $s'$ na pilha
│  │  │  avançar $ip$ para o próximo token
│  │  senão se *ação*$[s, a]$ = reduzir A -> $\beta$
│  │  │  desempilhar 2* quantidade de simbolos em $\beta$, seja $s'$ agora o novo topo da pilha;
│  │  │  empilhar $A$ e em seguida *desvio*$[s', A]$
│  │  senão se *ação*$[s, a]$ = aceitar entao
│  │  │  retornar
│  │  senão erro()
│  *fim*
*fim*
