---
title: "nível lógico digital"
weight: 3
---

# Portas e álgebra booleana
![[Pasted image 20240906081026.png]]

Usaremos tabelas verdade baseadas na álgebra booleana.

O objetivo é criar um circuito que faz um cálculo da maneira mais efetiva possível, ou seja, tem a menor quantidade de portas e a mesma precisão.

![[Pasted image 20240906081353.png]]

## Circuitos integrados
Os componentes lógicos são agora distribuídos dentro de chips, que são um pedaço de silício que compreende portas lógicas.
Tipos comuns de pacotes de circuito integrado, incluindo um pacote dual-in-line, ou DIP, PGA e LGA.

![[Pasted image 20240906081703.png]]

## Circuitos combinatórios
Aplicações digitais exigem muitas entradas e muitas saídas. 
_decodificador_: circuito que toma um número de n bits como entrada e o usa para selecionar (isto é, definir em 1) exatamente uma das 2n linhas de saída.

_comparador_:  que compara duas palavras de entrada. 

_meio somador_: calcula o bit de soma e o de transporte 

![[Pasted image 20240906082604.png]]

## clock
clock é um circuito que emite pulsos em um determinado intervalo de tempo preciso. Serve para sincronizar o sistema computacional.

## Memória de 1 bit
conhecido como latch, são "memórias" que "lembram" dos valores de entradas anteriores.
![[Pasted image 20240906084733.png]]

_latch SR_: permite a alteração ou não da memória com uma entrada de clock e 2 portas and (uma negada)

![[Pasted image 20240906084908.png]]


_flip-flop_: transição de estado ocorre na borda ascendente ou descendente.

_flip-flop D_: transição de estado ocorre na borda ascendente ou descendente, mas com um clock para determinar quando ou não mudar.

# Registrador
um registrador tem flip-flops ligados com a intenção de garantir entrada, saida e armazenamento. Neste exemplo são 8 bits:

![[Pasted image 20240906085302.png]]

# RAMs e ROMs

_RAMs_ podem ser:
- static: construidas com circuitos similares ao flip-flop D 
- dynamic: um arranjo com células que contém um transistor e um capacitor.

_ROMs_: memórias que não podem ser apagadas.
# Chip de CPU
toda cpu é dividida em pinos de comunicação que são agrupados da seguinte maneira:
1. Controle de barramento.
2. Interrupções.
3. Arbitragem de barramento.
4. Sinalização de coprocessador.
5. Estado.
6. Diversos.
# Barramento
barramentos podem ser síncronos e assíncronos.
- os síncronos tem sua linha baseada na oscilação de um oscilador de cristal, que sincroniza o clock geral da máquina.

## arbitragem do barramento
são métodos para manter o controle de quem é mestre do barramento com determinada prioridade.
podem ser **centralizados** ou **descentralizados**

![[Pasted image 20240906090940.png]]

## exemplos de barramento
_PCI (e PCIe)_ -> utiliza um árbitro de barramento centralizado. 
![[Pasted image 20240906091136.png]]

![[Pasted image 20240906091221.png]]

_USB_:  é um root hub que é ligado ao barramento principal, ligando os dispositivos E/S ao central.

_PIO_: paralel input/output, geralmente usadas em sistemas embutidos para entrada/saida de dados paralela.