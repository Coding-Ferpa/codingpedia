---
title: "Aritmética Computacional"
weight: 3
---

Toda aritmetica é realizada na ALU (arithmetic logic unit) na CPU

- Inteiros
- Floats

A unidade de controle, juntamente aos registradores, buscam e interconectam as informações no sistema computacional (desde a memória cache até a externa e I/O Devices);

  

- A ALU também pode acionar algumas flags como resultado  
    de uma operação;  
    
- A Unidade de Controle provê sinais que controlam a  
    operação e o movimento dos dados na ALU.  
    

## Instruction set

contempla um compilado de instruções que a CPU pode utilizar. Uma ISA (Instruction Set Architecture) garante a unicidade de um tipo se Instruction Set para determinado hardware.

### Elementos básicos de uma instrução

- Código de operação (Op code);
    - Ex: ADD, I/O
- Referência a operando fonte;
    - endereço lógico do operando inicialmente utilizado
    - entradas de memória da instrução
- Referência a operando de destino;
    - referência ao resultado da operação
- Referência à próxima instrução.
    - normalmente representa o incremento da instrução atual por um determinado numero de bits, de acordo com a arquitetura.

  

Normalmente, uma instrução tem o fluxo de

Memória → Barramento de dados → Registrador → ALU → Registrador → Memória

![[/Untitled 6.png|Untitled 6.png]]

  

Criou-se uma representação simbólicas das intruções, especificamente dos OP Codes → os mnemônicos:

- ADD – Adição
- SUB – Subtração
- MPY – Multiplicação
- DIV – Divisão
- LOAD – Carrega dados da memória
- STORE – Guarda dados na memória
- NOP – Ausência de operação

### Exemplo:

ADD R, Y (adicionar o conteúdo de Y para R);

## Categorias:

- Processamento: Instruções lógicas e aritméticas;
- Armazenamento: Instruções de memória;
- Movimento: Instruções de E/S;
- Controle: Instruções de teste.

  

## Tipos de operandos

- Endereços;
- Int e Float
- Char
- Lógicos.