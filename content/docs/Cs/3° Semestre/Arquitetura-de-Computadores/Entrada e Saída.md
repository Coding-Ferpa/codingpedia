---
title: "Entrada e Saída"
weight: 3
---

Dispositivos são provavelmente mais lentos do que a CPU

Estão, existem módulos de conexão tanto com periféricos quanto com CPU e memória

Barramento do Sistema envia os dados para o módulo de E/S que redireciona para os dispositivos

# Funções do módulo de E/S

- Controle e temporização
- Comunicação com a CPU
- Comunicação com dispositivo
- Buffering de dados
- Detecção de erro

# Etapas

CPU → módulo de E/S → transferencia de dados (dispositivo → E/S) → CPU

## Programada

CPU controla o módulo

Há a espera da execução do módulo, ou seja, pausa da CPU


## Interrupção

Módulo de E/S envia uma interrupção para a CPU através do barramento de controle quando está pronto para receber dados e ao finalizar a execução de uma tarefa

  

## DMA (Direct Memory Access)

Módulo adicional (hardware) no barramento.

DMA toma o comando da CPU → módulo E/S

- Comunicação é direta entre a CPU e o DMA, assim, a CPU solicita uma leitura/escrita em algum dispositivo(endereçado) em alguma parte da memória a qual quer achar.
- CPU volta ao seu trabalho normal e o DMA lida com o dispositivo e a própria transferencia de dados. Ao terminar, ele então, assume o barramento por um ciclo e transfere a palavra vinda do dispositivo