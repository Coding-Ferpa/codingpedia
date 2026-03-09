---
title: "Arquitetura e Funcionamento de Microcontroladores"
weight: 3
---

- sistemas embarcados → utilizados em ampla gama de dispositivos e setores. Em essência, eles são soluções criadas para desempenhar tarefas especificas em tempo real.

## Microcontroladores

- circuito integrado que forma um pequeno computador, tem memória, uma CPU, periféricos programáveis e comunicação, porém, de baixíssima capacidade (memso).
    - utilizaremos a arquitetura de Harvard, que possui memórias separadas para instruções e dados.

desenvolveremos tanto firmware (colocado em uma mem não volátil) e software (carregada para a ram da memória secundária).

> registradores de deslocamento são capazes de load/store dados sequencial ou paralelamente.

---

# Configuração de hardware

```Assembly
    \#include <xc.inc>

    CONFIG FOSC=XT      ; configura um oscilador de cristal externo de baixa frequencia
    CONFIG WDTE=OFF/ON  ; watchdog timer é um contador que reinicia o microcontrolador se ele não for regularmente resetado pelo programa. (kicking)
                        ; dispara um reset no programa se o progama não enviar um reset ao watchdog continuo
    CONFIG PWRTE=ON/OFF ; garante que o microcontrolador tenha tempo suficiente para establizar após ser ligado, evitando problemas de inicialização
                        ; ou seja, espera um tempo para garantir funcionamento normal dos componentes
    CONFIG BOR=ON       ; brown-out-reset reinicia o microcontrolador se a tensão cair abaixo do nivel seguro
    CONFIG LVP=OFF/ON   ; permite programação de baixa voltagem, uma tensão menor, precisa em alguns ambientes
    CONFIG CPD=ON/OFF   ; desativa/ativa a proteção de código de data EEPROM. A proteção impede a leitura desse código
    CONFIG WRT=ON/OFF   ; ativa ou desativa a escrita após a programação ser definida
    CONFIG CP=OFF       ; impede que o codigo do programa seja lido ou copiado do microcontrolador


    \#define carlos b1231435153151

    Inicio
      movlw carlos
      goto Inicio
```

# Linguagem Assembly

- labels
    - designação textual de fácil leitura, que define para onde o programa deve saltar e/ou inicio/fim do programa
        - ex: Inicio, _fim, P123, valor_maior?
- instruções
    - são especificas para cada ISA  
        -ex: goto < ROTULO > , movlw < ADDRESS> mov literal to page register  
        
- operandos
    - elementos utilizados pela instrução, são registros, variáveis e constantes.
- comentários
    - sim.
        - ex: ;carlos
- diretivas
    - parece uma instrução, mas independe do microcontrolador
        - ex: ORG, EQU (def constante), CBLOCK (bloco de memória para reg), ENDC (finaliza um bloco de memória)
