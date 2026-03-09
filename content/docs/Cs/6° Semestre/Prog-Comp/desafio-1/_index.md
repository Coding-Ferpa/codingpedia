---
title: "desafio 1"
slug: desafio-1-obi-2025-fase-3-prog-comp
date: 2025-10-20
tags: [Cs, 6º Semestre, Prog-Comp, OBI, Desafio]
weight: 4
---

https://olimpiada.ic.unicamp.br/static/extras/obi2025/provas/ProvaOBI2025_f3ps.pdf


problema 1 (fotos) - conceios chaves:

esse problema espera a contagem de subvetores continuos que contem exatamente um numero 1. Um par (l, r) representa um subvetor que vai do indice l ate o indice r (inclusive).

para resolver, precisamos olhar para os 2 lados de um vetor e entender quantos sub vetores ele pode formar. Contamos, começando sempre pelas posições com valor = 1, qual o tamanho do subvetor a direita e a esquerda q ele pode formar ate encontrar outro 1 ou o fim do vetor.

Assim, nossa soma total sera:

```c
soma += (left_count + 1) * (right_count + 1)
```
