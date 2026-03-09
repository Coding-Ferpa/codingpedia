---
title: "CPU"
weight: 3
---

# Registradores

## Dados e endereços

- Acumulador e segmento de endereço, respectivamente
- Balanço:
    
    → Menos registradores há mais referências à memória;
    
    → mais registradores ocupam mais espaço no processador (mais caro tbm)
    
- Tamanho do registrador
    
    → Grande o suficiente para manter palavra, endereço e op code completos
    

## Códigos condicionais

- Servem para:
    
    — Conjuntos de bits individuais.  
    - Ex: resultado da última operação foi zero.  
    
    — Podem ser lidos (implicitamente) por programas.  
    - Ex: Jump (dependendo da condição) ou stall (delay slot).  
    

## Controle e Estados

- Contador de programa (PC)
- Registrador de decodificação de instrução (IDR)
- Registrador de endereço de memória (MAR)
- Registrador de buffer de memória (MBR)

---

# Palavras de estados

Um conjunto de bits que inclui:

- flags (códigos condicionais)
- Sinal do último resultado
- Zero

EX:

- Carry.
- Igual.
- Overflow.
- Habilitar/desabilitar interrupção.
- Supervisor.

  

---

# Modo de supervisão

- Modo kernel
- Permite execução de instruções privilegiadas
- Usado pelo sistema operacional
- Não disponível aos programas do usuário