---
title: "aula 9 bison asdrc"
weight: 4
---

# Bison (parser generator)

- Preambulo: declaração dos tokens, artefatos, ordem de precedência e etc.
```c
%{
    #include <stdio.h>


%}
```
- Gramática (LLR):
 - funções: seção de funções auxiliares

## Compilação

O código Bison deve ser transformado em código C, via comando:

```sh
bison -d -v parser.y
```

Logo em seguida deve ser compilado via g++ 

```sh
gcc parser.tab.c -lfl 
```

# Integração com flex

- parser.tab.c:
- parser.tab.h: podemos incluir no flex
- parser.output: descrição da gramática gerada

```c 
%{
#include "parser.tab.h"
%}

```

o arquivo flex não terá mais uma função auxiliar main, ou seja, o bison terá que tê-la.

A maneira mais direta de trasnferir dados entre as 2 ferramentas é utilizando yylval que funciona como uma variável global. Os valores devem ser escritos no flex e apenas lidos no Bison para armazenar o estado do parser é necessário programar as próprias estruturas.