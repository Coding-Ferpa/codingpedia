---
title: "lalr"
weight: 3
---

# Tabela LALR 

Conjunto de itens igual LR(1), mas unindo os conjuntos de itens que possuem o mesmo núcleo (core), ou seja, que o lookahead é diferente.

Tarefa: estudar a construção da tabela LALR a partir da tabela LR(1), no capitulo 4 do livro.

# Erros sintáticos 
exemplo: var i integer; // falta :

Estratégias de tratamento de erros:
- Panic mode: pula0se parte do texto de entrada ate encontrar um token de sync (a partir dai continua a analise). Pode ser uma palavra-chave, um simbolo especial ou o fim de linha.
- Reparo (recuperação total): opção mais comum é inserir ou remover tokens para continuar a analise. Pode ser custoso.

# Analise Semântica
Feita durante a analise sintática, verificando se o sentido do programa está correto.

Exemplo:
a = b + c 

- a, b e c devem ser declaradas, devem ser do mesmo tipo, etc.
- operador + deve ser definido para os tipos de b e c.
- a deve ser atribuível (lvalue).
- caso a tenha um tipo diferente do resultado de b + c, deve ser feita um casting (ou gerar um erro).

## ASDR
Inserir ações semânticas no código. 

Exemplo: A -> id = id + id

```
Procedimento a():
    prox = analex()
    if prox == 'id'
        ação-semantica(1) // i.e verificar se id tem tipo x
```

Exercicio (casa): Inserção de ações semânticas nos ASDR já projetadas.

Exercicio (casa): construir o ASDR de:

F-> id (id, id): TIPO 
Atribuição: 
    - ATRIB -> id = CF 

essa regra é para decl de função e tem um valor de retorno. Quais rotinas semânticas devem ser construidas?
