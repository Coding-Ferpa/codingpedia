---
title: "Organização de sistemas de computadores"
weight: 3
---

- somente operações LOAD/STORE devem referenciar a memória.
- necessários muitos registradores, trabalhando em uma pipeline unica ou dividida em threads físicas e/ou logicas, onde cada registrador manipulado pode ser parte do processo.

#Memoria #cache #ram #paralelismo
# Instruções
[[Conjunto de Instruções]]
[[Ciclo de instrução – O retorno]]
A CPU executa cada instrução em uma série de pequenas etapas. Em termos simples, as etapas são as seguintes:
1. Trazer a próxima instrução da memória até o registrador ele instrução.
2. Alterar o contador de programa para que aponte para a próxima instrução.
3. Determinar o tipo de instrução trazida.
4. Se a instrução usar uma palavra na memória, determinar onde essa palavra está.
5. Trazer a palavra para dentro de um registrador da CPU, se necessário.
6. Executar a instrução.
7. Voltar à etapa 1 para iniciar a execução da instrução seguinte.
# Paralelismo
[[Paralelismo em nível de instrução]]
[[Paralelismo em nível de dados]]
[[Paralelismo em nível de thread (n vou terminar esse)]]
# Memória
[[Memórias]]

Dividida em células (ou locais) os quais são referenciados por um endereço único e indicado para cada célula.
- os bytes em uma palavra podem ser organizados 
	- big endian -> bytes numerados da esquerda pra direita 
	- little endian-> bytes numerados da direita pra esquerda

![[Pasted image 20240814174741.png]]
> devido a possibilidade de falhas, faz-se necessária a detecção de erros. Veja: [[#Error Handling]] e tipos de memória

# Error Handling

### Código de Hamming
Dadas duas palavras de código quaisquer, por exemplo, 10001001 e 10110001, é possível determinar quantos bits correspondentes são diferentes. Nesse caso, 3.

> O número de posições de bit nas quais as duas palavras de código diferem é denominado distância de Hamming (Hamming, 1950). 

Se duas palavras de código estiverem separadas por uma distância de Hamming d, será preciso d erros de único bit para converter uma na outra. 

_ex:_ Por exemplo, as palavras de código 11110001 e 00110000 estão a uma distância de Hamming 3 porque é preciso 3 erros de único bit para converter uma na outra.

palavra = m + r $\implies$ (qtd de bits de dados) + (qtd de bits de paridade)
- ex: uma palavra com 16 bits de dados tem q ter 5 de paridade (1, 2, 4, 8 e 16 ($2^{i} >= m$ -> i = 0, 1, 2, 3, 4))
![[Pasted image 20240904103651.png]]

> se os bits de paridade 1 e 4 estiverem incorretos, mas 2, 8 e 16 estiverem corretos, o bit 5 (1 + 4) foi invertido.

# Memória Secundária 
[[1-2 - Armazenamento secundário]]
![[Pasted image 20240904104532.png]]


## RAID
[[Memoria Interna#RAID (Redundant Array of Independent Disks)]]
a ideia é conseguir utilizar diversos drives logicamente conectados sendo tratados com um SLED (disco único e grandão) e acessar seus dados de forma paralela.

alguns RAID's promovem versões diferentes de paridade, no geral, sem seguir a de Hamming.
### exemplos:

_Solid State Drive (SSD -> memória flash não volátil)_: bom 
_CD-ROM_: codifica cada byte em 14 bits, amontoados em quadros de 42 * 14 bytes
_CD-R e CD-RW_: um só lê, já o outro...
# Entrada e Saída
[[Entrada e Saída]]

_Barramento PCI_: 
![[Pasted image 20240904111043.png]]

VRAM -> memória RAM feita pra armazenar pixels e buffers de vídeo.