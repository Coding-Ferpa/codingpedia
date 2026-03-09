---
title: "Conjunto de Instruções"
weight: 3
---

# Modos de endereçamento

- um bit identifica o modo de endereçamento

## TIPOS

---

- Imediato
    - instrução guarda também o operando
    - economiza um ciclo mas útil apenas para instruções simples
- Direto
    - instrução guarda uma referência a instrução que está na memória principal
    - limitada pelo espaço do endereçamento
- Indireto
    - instrução guarda uma referência a uma referencia a instrução que está na memória principal
    - refere-se a um endereço de uma palavra na memória, a qual contem o endereço completo do operando.
- Registrador Direto
    - instrução chama o registrador com sua respectiva referencia, assim o registrador busca na memória o operando
    - espaço limitado
- Registrador Indireto
    - idêntico ao indireto, mas refere-se inicialmente ao registrador
- Deslocamento
    - Necessita de dois campos para endereçamento
    - O valor contido em um dos campos de endereçamento é  
        usado diretamente, outro valor é implicitamente referenciado no OPCODE e  
        se refere ao registrador.  
        
- Pilha
    - O ponteiro para a pilha é mantido em um registrador, sendo alterado conforme é referenciado

---

## Tamanho da instrução

- A instrução deve ser deve ser do mesmo tamanho da faixa de transferência da memória, ou deve ser múltipla dela
- Um tamanho maior não implica necessariamente em mais desempenho, vide 64bits como padrão e não 128 (para computadores comerciais)