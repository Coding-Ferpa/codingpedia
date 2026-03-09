---
title: "1 e 2 - Armazenamento secundário"
weight: 3
---

# Armazenamento secundário (parte 1)

# Formatação Física

HDD é organizado em

- discos
- superfícies: organizados em trilhas
- trilhas: organizados em setores
- cilindro: conjunto de trilhas em diferentes discos


Seeking → movimento de posicionar a cabeça de R/W sobre a trilha/setor

Cluster → conjunto de setores logicamente contíguos no disco, descritos pelo sistema de arquivos

Extent → sequencia de clusters consecutivos em um disco

Fragmentação → perda parcial de setores de tamanho fixo

# Formatação lógica

## Sistemas de Arquivos

estruturas lógicas e sub-rotinas usadas para controlar dados em disco (ex: ext4, ntfs, fat..)

- FAT → organiza grupo de setores
    - um arquivo ocupa, no minimo, um cluster (cause fragmentação interna)

## Overhead

Tamanho dos cluster?

---

# Custo de acesso a disco

calculado por 3 fatores:

- tempo de busca (seeking)
- delay de rotação (tempo pro disco rodar)
- tempo de transferência (de dados)

# Técnicas pra diminuir isso dai

- Multiprogramação
- RAID
- Disk Cache
- RAM disk

  

## Buffering

grande parte da RAM transfere parcialmente o disco

→ precisa-se, portanto, de, no mínimo 2 buffers I/O → quanto mais mlr, até um limite fisico ai