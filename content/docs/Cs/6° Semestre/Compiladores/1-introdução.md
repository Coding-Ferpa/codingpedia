---
title: "introdução"
weight: 3
---

# Introdução
Compilador: programa que recebe entradas de texto em uma determinada linguagem fonte e a "traduz" sem percas para uma outra determinada linguagem, através do seguinte fluxo de dados: (1) analise; e (2) síntese.

1. Analise: subdividida em:
    - analisador léxico: responsável por tokenizar (ler, agrupar e classificar) o input de texto recebido pelo compilador (arquivo(s)).
    - analisador sintático: responsável por fazer uma analise hierárquica dos tokens, agrupando-os em coleções com significados coletivos.
    - analisador semântico: assegura que os componentes agrupados tem algum sentido (e.g int = 5 e nao int = 2.0 ou "2")

2. Síntese:
    - gerador de código intermediário (opcional): tem como objetivo quebrar o código fonte em instruções mais simples e, consequentemente, mais próximas do código alvo.
    - otimizador de códigos: tenta melhorar o código (se houver, intermediário) de forma a obter um código alvo menos custoso em execução.
    - gerador de códigos: fase final de geração de código o qual culmina na criação de um "executável".

3. sub-etapas (acontecem em paralelo às demais):
    - tratador de erros
    - gerenciador da tabela de símbolos

--- 
## Extra
O livro [compiladores](https://github.com/Felipe-gsilva/cs-common-private-files/blob/main/Books/Compiladores_%20Princ%C3%ADpios%2C%20T%C3%A9cnicas%20e%20Ferramentas%20--%20ALFRED%20V_%20AHO%2C%20Ravi%20Sethi%2C%20monica%20S_%20Lam.pdf) mostra outra estrutura um pouco mais robusta (com uma tabela de símbolos externa):

string -> **analisador léxico** -> fluxo de tokens -> **analisador sintático** -> arvore de sintaxe -> **analisador semântico** ->  arvore de sintaxe -> **gerador de código intermediário** -> representação intermediaria -> **gerador de código dependente da maquina** -> representação intermediaria -> **gerador de código** -> código da maquina alvo -> **otimizador independente de maquina** -> código final 

## Analisador Léxico

todo lexema (válido) escaneado pelo analisador léxico tem uma entrada na tabela de símbolos dada por <id, 1> onde id é um símbolo abstrato e 1 é a posição na tabela. Se for um operador a entrada se dá por <\*>, descartando os separadores.

e. g:

$a = b + c * 60$
$\vdots$
$<id, 1> \ <=> \ <id, 2> \ <+> \ <id, 3> \ <*> \ <60>$

## Analisador sintático
Utiliza uma forma intermediaria de representação tipo árvore, através dos tokens recebidos pela analise léxica, demonstrando a estrutura gramatical da sequencia de tokens. Uma representação típica é uma árvore sintática em que cada nó é um operador e os filhos representam seus operandos (ou outros operadores e símbolos).

## Analisador semântico
Também utiliza a mesma representação de árvore mas ajusta alguns "problemas" (ou ao menos os detecta). Por exemplo, uma multiplicação de int's não pode ter um operando do tipo float, então será chamado a função floattoint() para corrigir o problema. Em outras palavras, o analisador semântico utiliza da árvore sintática e das entradas da tabela de símbolos para verificar a consistência semântica do programa com a definição da linguagem.

Certas técnicas são empregadas, como a supracitada verificação de tipos. Esses ajustes de tipo são chamados de **coerções** de acordo com o tipo preferido.

## Geração de código intermediário, otimização e geração de código
Não vou me estender, é bem direto o que eu já escrevi antes. Será visto melhor no capitulo 6.