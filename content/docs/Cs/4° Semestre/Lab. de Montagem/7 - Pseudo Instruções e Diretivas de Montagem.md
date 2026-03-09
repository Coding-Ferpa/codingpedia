---
title: "Pseudo Instruções e Diretivas de Montagem"
weight: 3
---

# pseudo instrução
Pseudo instruções são comandos usados em asm que não correspondem diretamente a uma instrução de máquina mas que ajudam a simplificar o código e são transformadas em instruções de máquina.

Elas são reconhecidas pelo montador que as converte em uma ou mais instruções.
**EX:**
- alocação de memória;
- atribuição de valores; e
- manipulação de dados.

# diretivas
servem apenas para o montador, elas não geram código executável.

_end_: marca o final do código fonte.
_segment_: 
_DB_: declara um ou mais bytes de dados. Pode ser usado para definir variáveis de byte e inicializá-las com valores especificos.
_EQU_: define uma constante com valor fixo.
_NOP_:  não faz nada, consome um ciclo de clock.