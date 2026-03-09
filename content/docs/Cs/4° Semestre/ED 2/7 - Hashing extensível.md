---
title: "Hashing extensível"
weight: 3
---

- O espalhamento extensível usa tries de ordem 2 como índices.
- Tabela de espalhamento indexa um conjunto de cestos 
- Função Hash gera um endereço binário
- Busca por chave: análise bit-a-bit do valor de h(key) permite localizar o seu cesto.
- Níveis internos: rotulados com bits
- Nível dos nós folha: buckets contendo várias chaves ou registros

## Diretório
Se faz necessário transformar a trie em um vetor de registros consecutivos, formando um diretório de endereços de espalhamento e ponteiros para os cestos associados.
- a arvore precisa ser uma árvore completa (todas as folhas no mesmo nivel)
![[Pasted image 20241001074046.png]]

precisamos guardar o rrn referente ao bucket e os bits que escolhemos pra representá-los

## rearranjando o diretório

rearranjar os buckets caso tenham mais chaves do que o permitido em N. Ou seja, podemos alterar a quantidade de bits necessários para indexação. A profundidade do diretório define a quantidade de bits para indexação

Usando os bits mais significativos, quando estouramos o numero de chaves num bucket, passamos a usar k + 1 bits significativos, sendo assim, temos que o 1001 e 1000 ficariam em um bucket e o 1010 em um outro.
![[hashing expansivel]]
