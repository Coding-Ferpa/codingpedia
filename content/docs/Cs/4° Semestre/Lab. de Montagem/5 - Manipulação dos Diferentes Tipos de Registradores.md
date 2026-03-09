---
title: "Manipulação dos Diferentes Tipos de Registradores"
weight: 3
---

CS -> code segment 
DS -> data segment, contém o endereço base do segmento de dados
ES -> extra (data) segment
FS -> segmento com mais dados
GS -> ainda mais dados
SS -> Segmento de pilha (stack)

---
é possśivel dividir registrador entre a parte alta e baixa, os quais representam metade.
## exemplos
MOV AX 25
MOV BX 4
IMUL BX; multiplica AX por BX; 

DX pode ser uma memória temporária

## Divisão
O AX armazena o dividendo e o divisor é armazenado em outro registrador, como BX
## SI
é usado como um índice para operações de leitura em uma fonte de dados
(SOURCE INDEX) -> um indice que pode ser usado para percorrer vetores/cadeias de caracteres
## SP 
mantém o endereço do topo da pilha
# ASCII
PrintNumber:
	mov ah, 02h
	mov dl, al
	add dl, '0'
	ret
# Algoritmo de ordenação
```asm
.MODEL SMALL
.STACK 100h
.DATA 
	vetor DB 5, 3, 8, 1, 2, 9, 4, 7, 6 ; define byte (0 a max)
	n EQU 9 ; define uma constante 
	msg DB 0Dh, 0Ah, 'Vetor Ordenado: $' ;Mensagem a ser exibida antes do vetor

.CODE 
	MAIN:
		MOV AX, @DATA 
		MOV DS, AX
		MOV ES, AX
		LEA SI, vetor ;;carrega o endereço inicial do vetor
		MOV CX, n ;; carrega o tamanho do vetor
		CALL OrdenaVetor
		LEA DX, msg
		MOV AH, 09h
		INT 21h
		CALL ImprimeVetor
		MOV AH, 4Ch
		INT 21h
	OrdenaVetor:
		MOV BX, CX
		DEC BX
	OurterLoop:
		MOV SI, 0
		MOV CX, BX
	InnerLoop:
		MOV AL, [vetor + SI]
		MOV DL, [vetor + SI +1]
		CMP AL, DL
		JBE NoSwap
		XCHG AL, DL ; troca quando o primeiro valor é maior que o segundo
		MOV [vetor + SI], AL
		MOV [vetor + SI + 1], DL
	NoSwap:
		INC SI
		LOOP InnerLoop
		DEC BX
		JNZ OuterLoop
		RET
	ImprimeVetor:
		MOV CX, n
```
