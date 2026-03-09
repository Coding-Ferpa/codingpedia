---
title: "Introdução"
weight: 3
---

**organização estruturada de computadores**: projetar sistemas computacionais de forma sistemática e organizada.
[[Organização de Computadores]]

---
# Linguagens, níveis e máquinas virtuais

_tradução:_ reescrever um programa escrito em uma máquina, traduzindo suas instruções para instruções aceitas em outra máquina.

_interpretação:_ um programa em uma máquina passa a ser tratado como uma entrada em outra, sendo lido linha a linha e executando diretamente a sequência de instruções equivalente.

_máquina virtual:_ simula um ambiente onde um outro sistema é utilizado. Digamos que um programa rode em Windows de forma padrão, mas você precisa do mesmo em Linux. Pode-se dizer que uma máquina virtual simula o sistema escolhido, interpretando suas instruções para o ambiente ***macro***.

_máquina multinível:_
nível/máquina virtual indicam o mesmo conceito. A ideia é que um computador possa simular e utilizar diversas linguagens durante sua vida útil, tornando a abstração cada vez maior sem perder o desempenho. Como pode ser visto abaixo:

	nivel 5 -> linguanges alto nível
	nivel 4 -> assembly
	nivel 3 -> SO
	nivel 2 -> ISA
	nivel 1 -> microarquitetura 
	nivel 0 -> parte mecânica, flip flops e etc

---
# Evolução das máquinas multinível
1. Instruções para multiplicação e divisão de inteiros.
2. Instruções aritméticas para ponto flutuante.
3. Instruções para chamar e sair de procedimentos.
4. Instruções para acelerar laços (looping).
5. Instruções para manipular cadeias de caracteres.
6. cálculos para vetores (indexação e endereçamento indireto).
7. Características para permitir que os programas fossem movidos na memória
8. Sistemas de interrupção que avisavam o computador tão logo uma operação de entrada ou saída estivesse concluída.(watch dog)

_Microcontroladores_: gerenciam dispositivos simples, normalmente só podendo ter o nível ISA e máquina 
_PC_: desktop e notebook.
_Server_: centenas de GB's e alta capacidade de trabalho em rede.
_Cluster_: vários servidores conectados com alta velocidade. 
_Mainframe_: simplesmente absurdo.