---
title: "RISC X CISC"
weight: 3
---

# Cisc

- Grandes conjuntos de instruções.
- Mais modos de endereçamento.
- Implementações de hardware de instruções de high level language

![[/Untitled 8.png|Untitled 8.png]]

---

# Chamadas de procedimento

- Muito demorada.
- Depende do número de parâmetros passados.
- Depende do nível de aninhamento.
- Maioria dos programas não faz muitas chamadas seguidas por muitos retornos.
- Maioria das variáveis é local.
- (Compare com localidade de referência)

  

## Arquivo de registradores grande

- Solução de software:
    - Requer que compilador reserve registradores.
    - Aloca com base nas variáveis mais usadas em determinado momento.

  

## Janela de Registradores

- Intervalo limitado de profundidade de chamada.
- Usam múltiplos conjuntos pequenos de registradores.

## Operação de buffer circular

Quando uma chamada é feita, um ponteiro de janela atual é movido para mostrar a janela de registrador atualmente ativa. Se todas as janelas estiverem em uso, uma interrupção é gerada.

Um ponteiro de janela salva indica para onde as próximas janelas salvas deverão ser restauradas.

## Variáveis globais

Alocadas pelo compilador para a memória.

  

![[/Untitled 1 3.png|Untitled 1 3.png]]

  

# RISC - objetivamente melhor, só q mais caro

Principais características:

- Conjunto de instruções limitado e simples.
- Ênfase na otimização do pipeline de instrução.
- Uma instrução por ciclo.
- Operações de registrador a registrador.
- Projeto fisicamente conectado (sem microcódigo).
- Formato de instrução fixo.
- Mais tempo/esforço de compilação.

## Optimização de pipeline

- Desvio atrasado:  
    —Não tem efeito antes da execução da instrução seguinte, o delay slot (n faz porra nenhuma no caso)  
    
- Leitura atrasada:  
    — Registrador a ser alvo é bloqueado pelo processador.  
    — Continue a execução da instrução até o registrador ser exigido.  
    — Ocioso até carga completa.  
    — Rearranjar instruções permite que um trabalho útil seja feito enquanto ocorre leitura.  
    
- Laço desenrolado:  
    —Replica corpo do laço em um número de vezes.  
    —Faz iteração do loop menos vezes.  
    —Aumenta paralelismo de instrução.