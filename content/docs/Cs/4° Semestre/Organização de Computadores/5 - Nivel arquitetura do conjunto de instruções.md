---
title: "Nivel arquitetura do conjunto de instruções"
weight: 3
---

O nivel ISA precisa de informações prévias declaras sobre o sistema computacional, como por exemplo:
- tamanho da stack
- tipo de registradores
- tipo de dados
- instruções na memória fisica 


No geral, é separada uma palavra de $n$ bytes que representa a memória do sistema (os endereços), ou seja, que quando referenciada, indica a posição de alguma outra palavra em uma memória maior.

## Endereçamento
Pode-se colocar o endereço completado do operando na instrução, permitindo o acesso direto a ele, também pode-se colocar o operando em si na instrução (horrivel).
Outra maneira, é usar o endereçamento indexado, o qual salva um valor que representa uma posição em um conjunto pré definido de memória, como um vetor ou outra estrutura de dados.

## Tipos de instruções
Operações de movimento de dados: MOV ou LOAD e STORE  
Operações diáticas:  2 operandos, uma saida ADD OR NOT NOR 
Operações monádicas: 1 operando e resultado unico
Chamada de procedimento: colocar o endereço de retorno em uma pilha
Controle de laço:  o laço do tipo teste final sempre é executado, mesmo que n <= 0
E/S:
1. E/S programada com espera ocupada.
2. E/S por interrupção.
3. E/S por DMA.

