---
title: "Simulação de Linguagem Assembly x86 para 8086"
weight: 3
---

# 1- Familia x86
Familia de processadores da intel. É importante ver o **asm** especificamente nessses modelos. Baseada na arquitetura de Von Neumann, com uma [[CPU]] e uma [[Memoria Interna]]/Principal. Baseado, essencialmente em CISC. Vide [[RISC X CISC]];

## Registradores 

- AX - Acumulador (Usado em **operações aritméticas**)
- CX - Contador (Usado em loops)
- DX - Registrador de Dados (Usado em I/O, multiplicações e divisões)
- BX - Base (usado para apontar referências no segmento de dados).
- SP - Stack Pointer (pilha)
- BP - Apontador da base do frame
- SI - Indice da fonte de dados a copiar (SOURCE INDEX)
- DI - Indice do destino de dados.

> são dividos em 6 segmentos

# 2 - tipos
Prefixos
- 64 bits - R (RAX)
- 32 bits - E (EAX)
- 16 bits - sem prefixo (AX)

# 3 - Controle de Fluxo
## 3.1 - Saltos Condicionais
Em linguagens de montagem, saltos condicionais são instruções que alteram o fluxo de execução:
- JE/JZ - jump if equal

```assembly
CMP AX, BX ; Comparação entre AX e BX
JE EQUAL   ; Salta para o rótulo EQUAL se forem iguais no registrador AX
```

- JNE/JNZ - jump if not equal

```assembly
CMP AX, BX    ; Comparação entre AX e BX
JNE NOT_EQUAL ; Salta para o rótulo NOT_EQUAL se AX e BX não forem iguais 
```

- JZ - Jump if zero

```assembly
TEST AX, BX ; Testa se o valor AX é = 0
JZ IsZERO   ; Salta se for 0
```
- JG - jump if greater
- JL - jump if less
- JMP - Jump sem condições
```assembly
JMP LABEL ; só pula
```
- and so on...

# 4 - Laços e sub-rotinas
## Sub-rotinas
A instrução CALL é usada para chama uma sub-rotina em um programa. Ou seja, o ponto atual de execução é salvo em uma pilha e outra sub-rotina se inicia.
```assembly
CALL SUBROUTINE
```
pode-se utilizar uma pilha auxiliar para salvar o estado atual, pré sub-rotina, evitando perder os dados anteriores.

RET -> usada para retornar o valor das operações feitas na sub-rotina.
```assembly
RET RENAN
```

## Laços 
### for
for -> iniciar um contador, verificar uma condição de parada, executar um bloco de código, incrementar ou decrementar, verificar a condição dnv, repetir o bloco de código e só sair de a condição não for verdadeira.

```assembly
section .text
global _start

_start: 
	mov ecx, 1 ; inicializa o contador com 1
	
loop_start:
	; bloco a ser repetido
	; insira o que ele faz aqui..
	inc ecx 
	cmp ecx, 6
	jnz loop_start

```

### while

```assembly
section .text
global _start

_start: 
	mov ecx, 1 ; inicializa o contador com 1
	
loop_start:
	cmp ecx, 6
	jae loop_end
	
	; bloco a ser repetido
	; insira o que ele faz aqui..
	
	inc ecx 
	jmp loop_start

```

