---
title: "Persistência"
weight: 3
---

DMI - Direct Media Interface, o qual conecta diretamente a um I/O Chip
PCIe (Peripheral Component Interconnect Express)


## Responsabilidades do SO:
checar disponibilidade do IO device. Chamamos o estado de espera (enquanto STATUS == BUSY) como polling. Esse polling representa verificações constantes ao dispositivo de IO se ele está ou não disponível.

Quando a CPU está envolvida no processo de IO, chamamos isso de `IO Programado ou PIO.`

> [!error]  Error
>
> Esse método, no entanto, cria um overhead na CPU desnecessário, visto que polling faz a CPU para o que está fazendo para esperar o resultado do IO.

Portanto, a melhor solução para isso é atribuir um *interrupt handler* que é capaz de gerenciar melhor a espera de um IO.

Ainda melhor do que isso, podemos usa o DMA - direct memory access. Esse dispositivo permite à CPU enviar o request de dados e não mais se importar em acessar a memória, ou seja, ainda mais diminuindo o seu overhead de uso.

Memory Mapped IO e IO Instructions existem.
