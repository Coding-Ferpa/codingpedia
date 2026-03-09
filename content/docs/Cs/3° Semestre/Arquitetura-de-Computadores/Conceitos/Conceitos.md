---
title: "Conceitos"
weight: 4
---

## Lei de moore

Até 2014, todo ano se dobrava a quantidade de transistores num processador, o numero baixou para cerca de 18 meses e continua diminuindo

## Ciclo de instrução

Calcula endereço de uma nova instrução → busca a instrução → decodifica uma instrução → calcula endereço dos operandos → busca dos operandos → operação → calculo do operando ao final → armazenamento

## Interrupções

o barramento de controle recebe uma interrupção, que para a execução da instrução atual no próximo clock, salvando seu contexto para uso posterior ao fim da interrupção ou apenas buscando a próxima instrução

Podem haver várias interrupções simultaneas, inclusas numa fila de prioridade

## Controle de arbitração

controla qual módulo tem acesso ao barramento

## Temporalização

eventos e sincronia do sistema

Pode ser sync → sequencias de clock com intervalos iguais e “digitais”

ou assync → cada evento ocorre de forma contínua (”analógica”) e sem conexão ao anterior ou algum paralelo

## Principais Registradores

PC - program counter

AC - acumulator

IR - Instruction register

MAR - memory access register

MBR - memory buffer register

I/O AR e BR

## Gargalo do fera

As memórias são nativamente mais lentas do que a unidade central de processamento, fazendo com que haja um atraso de velocidade e/ou sincronia dos 2.

## Pipeline

Uma lista de processos que ocorrem ou não simultaneamente, gerando um resultado em específico

Tende-se a deixar as instruções mais simples neste caso, para utilização do multicore

## Processamento

pode ser medido por FLOPS (float ops per second) ou IPS(instruction per secod)

  

[[Barramentos]]