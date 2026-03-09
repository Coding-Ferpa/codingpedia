---
title: "analise-sintatica"
weight: 3
---

> aula referente ao cap 4.1 e 4.4 do livro

# Análise Sintática
![[Pasted image 20250916171035.png]]

Entrada: Cadeia de tokens representando o programa fonte e verifica se a cadeia em si pertence a linguagem gerada pela gramatica.

Ele deve ser projetado para emitir mensagens de erros de uma forma inteligível e se recuperar deles, em certas ocasiões.

Aqui, devemos estruturar a gramatica de fato, partindo, naturalmente, de uma _keyword_ definida, i.e, *while* ou *int*, assim, os próximos lexemas a serem aceitos devem se basear nessa indicação.

Utilizaremos um PDA (*push-down automata*) para aceitarmos a gramatica, devido a sua "memoria" (pilha). Assim, podemos aceitar uma sequencia de tokens como `int a = 5;` ou não, ja que ele olha todos os lexemas.

O analisador sintático interage com a tabela de símbolos, adicionando, por exemplo, `tipo`, `argumentos`, etc.

Saída: Gera uma arvore de derivação (arvore sintática) como saída.

## Tratamento de erro

Precisa-se tratar erros corretamente e existem diversas maneira de o fazer. Devemos atrasar a _parada_ do programa, apenas marcando erros e os informando ao final da analise (se não for critico); O compilador pode, por exemplo, parar essa emissão de mensagens em caso de um *threshold* de erros seja alcançado (e.g 50). 

Estratégias podem ser:

### Recuperação no modo panico
// livro
### Recuperação em nível de frase
// livro
### Produções de Erro 
// livro
### Correção Global
// livro

# Tipos de Analise Sintática
- Descendente
- Ascendente
## Descendente (top down)
> "Na analise sintatica Descendente, inicia-se o processo pelo simbolo S e chega-se à cadeia."

constroi a arvore de derivação para a cadeia de cima para baixo, da raiz para as folhas, criando os nos da arvore em pré-ordem (DFS). Pode ser recursiva ou nao recursiva.


## Ascendente (bottom up)
> "Na análise ascendente, tenta-se construir a árvore de derivação para uma sentença $w$ a partir dos símbolos de $w$ (folhas), fazendo reduções (substituir o lado direto de uma regra pelo seu lado esquerdo) até obter-se o símbolo inicial S".

constroi a arvore de redução ao invés de derivação para a cadeia de baixo para cima, das folhas para a raiz.

## Diagramas de Transicao para Analisadores Sintaticos Preditivos

> [!note] Caderneta
> Visto no caderno

## Construcao do ASDR (analisador sintatico descendente recursivo)
- construir as rotinas que implementam cada um dos diagramas de transição da gramatica referente.

## Extra 

como implementar a tabela de simbolos?
- pode ser uma AVL, com busca consideravelmente rapida (em $O(log(n))$);
- qualquer arvore balanceada;
- tabela hash (prioridade - se bem espalhada) $(O(log(1)))$.


# Continuação análise sintática descendente

- sem retrocesso
- chamado analisador sintático preditivo.
- adequado para gramaticas LL(1) -> left-to right -> left (derivações) -> (k-lookahead = 1)

2 tipos de AS (analisadores sintáticos) preditivos: 
- recursivo: associa uma função para cada simbolo não terminal da gramatica.
- não recursivo: usa uma tabela que indica quais regras de produção devem ser usadas.

## Construir um analisador sintático descendente recursivo para G

```python
# nao funciona
token: str = None

def ASDR():
    try:
        token = solicita_token(analex)
        e(token)
    except Excepetion as e:
        print(e)

def e(token):
    t(token)
    e_linha(token)

def t(token):
    f(token)
    t_linha(token)

def e_linha(token):
    if token.value == "+" or token.value == "-":
        token = solicita_token(analex)
        t(token)
        e_linha(token)

def f(token):
    if token.value == "(":
        token.value = solicita_token(analex)
        e()
        if token.value == ")":
            return
        throw new Error("Nao fechou parenteses")

    if token.type == num:
        return

    throw new Error("Nem parenteses nem numero")

def t_linha(token):
    if token.value == "*" or token.value == "/":
        f()
        t_linha()
```


## Quando usar um ASDR
-> poucas regras gramaticais 
-> linguagens de programação possui recursividade
-> ATENÇÃO: a GLC não pode ser recursiva à esquerda

Exercício: construir os diagramas (caderno)

# Eliminação de recursividade à esquerda
$A -> A\alpha |\beta$ pode ser substituído por:
$A -> \beta A'$
$A' -> \alpha A' |\epsilon$

outro exemplo:
E -> E + T | T

vira: E -> TE'
      E' -> +TE' | $\epsilon$


# Analise Sintatica Produtiva
![[Pasted image 20250829102631.png]]

# First and Follow
Necessários para construir um analisador sintático preditivo, podendo prever a regra de produção correta a ser escolhida.

## First
1. Se X for terminal, First (X) = {X}
2. Se X -> $\epsilon$ for uma produção, adicione $\epsilon$ a First(X)
3. Se X for não-terminal e $X \rightarrow Y_1, Y_2,\ \dots,\ Y_n$ uma produção, colocar a em primeiro (X) se para algum $i$, a estiver em First($Y_i$), e $\epsilon$ estiver em todos: First($Y_1$) $\dots$ First($Y_{i-1}$), isto é, se $$Y_1\dots Y_{i-1}\xRightarrow{y} \ \epsilon$$
Se $\epsilon$ estiver em First($Y_j$), $j = 1,\ 2 \ \dots \ n$, então adicione $\epsilon$ a First(X).

## Follow(seguinte)
1. colocar \$ em Seguinte(S), S símbolo de partida.
2. Se existir uma produção A->$\alpha B \beta$, então tudo em First($\beta$) está em Seguinte($\beta$) exceto $\epsilon$
3. Se existir uma produção A->$\alpha B\beta$ onde First($\beta$) contém $\epsilon$, então tudo em Seguinte de A está em Seguinte($B$).

	