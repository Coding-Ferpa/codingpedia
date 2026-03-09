---
title: "Memoria Interna"
weight: 5
---

|        |             |                                   |
| ------ | ----------- | --------------------------------- |
| RAM    | Volatil     | Acesso aleatorio                  |
| ROM    | Nao Volatil | Read-only                         |
| PROM   | Nao Volatil | Read-only (programavel uma vez    |
| EPROM  | Nao Volatil | Read-only (programavel e apagavel |
| EEPROM | Nao Volatil | Read-only (apagavel eletricamente |
| Flash  | Nao Volatil |                                   |

## Dynamic Random Access Memory (DRAM)

- Precisa de renovacao energetica
- so funciona ligada / volatil
- Memoria Principal

## Static Random Access Memory (SRAM)

- Nao perde a carga e eh mais rapida
- Mais caro
- cache

## Read-Only Memory (ROM)

Armazenamento permanente;

Aplicações:

- Sub-rotinas de biblioteca;
- Programas do sistema (BIOS);
- Tabelas de função.

## Magnetic Disk

há uma lacuna entre cada trilha concêntrica

Tamanho de bloco mínimo é de um setor completo, porém, o máximo é o tamanho do disco, angariando todos os setores

![[/Untitled 14.png|Untitled 14.png]]

  

### Velocidade de Disco

- tempo de busca: movendo cabeça para a trilha correta
- latencia rotacional: esperando dados passarem sob a cabeça
- Tempo de acesso = busca + latencia

# RAID (Redundant Array of Independent Disks)

Um disco é bem lento, mais que um é menos lento (mas ainda lento) e barato

  

- Tem 7 niveis (0 a 6), sendo estes todos virtualizados num unico “disco” pelo SO.
- Os dados são distribuidos pelos discos através de Striping
- Guarda-se informação de paridade

## RAID 0

- Não redundante
- Mapeamento Round Robin (escalona as tarefas em uma Fila (buffer) com um determinado tempo pré estabelecido igualitáriamente)
- Discos buscam em paralelo, portanto, um conjunto de dados será splitado por mais de um disco (possivelmente)

## RAID 1

- Discos espelhados, ou seja, todos os dados são duplicados totalmente
- Caro

## RAID 2

- Discos sincronizados, correção de erro calculada pelos bits correspondentes em ambos os discos

  

## RAID 3

- Um disco apenas é separado com bits de correção
- No caso de erro, o drive de paridade é acessado e os dados são reconstituidos
- Rapido para paralelismo, lento para transações

![[/Untitled 1 7.png|Untitled 1 7.png]]

## RAID 4

- cada disco opera sozinho
- Bom para taxa de solicitação de E/S alta;
- Paridade armazenada no disco de paridade.

## RAID 5

- Paridade espalhada por todos os discos;
- Alocação round-robin para stripe de paridade;
- Evita gargalo do RAID 4 no disco de paridade.

## RAID 6

- Dois cálculos de paridade;
- Armazenado em blocos separados em discos diferentes;
- Alta disponibilidade de dados: Três discos precisam falhar para haver perda de dados;