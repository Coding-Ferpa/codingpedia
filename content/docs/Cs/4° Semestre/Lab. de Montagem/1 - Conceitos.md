---
title: "Conceitos"
weight: 3
---

## high level lang

- compiladores/interpretadores
- abstração da maquina
- recursos
- frameworks e bilbliotecas

## low level

- assembler (montador)
- ISA
- hardware
- registers and mem
---
# conceitos básicos

assembly → forma de representar textualmente um o conjunto de instruções de uma máquina

- microcontrolador → serve como um micro computador, o qual possui processamento, mem e etc
- microprocessador → processamento.

assembler → montador, traduz o assembly para lang de maquina

assembly n é portável

  
# compilador x interpretador x montador

compilador → traduz código-fonte para código de máquina

interpretador → executa diretamente linha por linha o código fonte, tradução e execução simultâneas, desempenho `MERDA`

montador → traduz direto, só q rápidão

  

usos: bios, kernel, embarcados, iot e etc.

# registradores

ESP e EBP → referencia pilhas

EAX → acumulator

EBX → ponteiro de acesso a memória, indice

ECX → contador de laços

EDX → dados, resto de divisão…

ESI e EDI → mov de dados