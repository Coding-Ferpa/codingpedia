---
title: "Complexidade"
weight: 3
---

Quantidade de trabalho depende da entrada/”estados” da aplicação e da estrutura de dados.

Se a complexidade é tomada como máxima para qualquer caso a complexidade é chamada de `complexidade no pior caso`

Se, acaso, a ocorrência for média, chama-se de `complexidade média`

- tipos de complexidade

- melhor caso
- pior caso
- caso médio

### função assintótica

buscamos uma $f(n)$﻿ que representa o custo tanto de eficiência de acesso, eficiência energética e/ou tempo de execução.

---
## Complexidade de tempo

A medida empírica, sendo dependente de hardware, tende a ser completamente diferente da função que descreve a complexidade de tempo. Não depende de linguagem ou hardware.

## Complexidade de espaço

Cálculo para requisitos de memória, representação do espaço requerido.

## Modelo RAM

Devemos considerar a arquitetura disponível, mas nesse caso, idealizaremos uma máquina modelo baseada em acesso aleatório de memória.

Teremos que cada instrução leva a mesma quantidade de tempo que qualquer outra instrução e que cada acesso a dados leva a mesma quantidade de tempo que qualquer outro acesso.


instruções definidas →

- instruções aritméticas
- mov de dados
- controle
- desvios

tipos de dados →

- inteiros, float, strings…

# Somatórios

$\sum_{k=1}^{n} ak$﻿, se n = 0, o somatório vale 0 e seus termos podem ser somados em qualquer ordem.

se o $\lim_{n=0} \sum_{k=1}^{\infty}ak$﻿
  

pode-se remover uma constante de um somatório

$\sum_{k=1}^{\infty}ak = a\sum_{k=1}^{\infty}k$﻿

[…]

### Reindexação de somatórios

serve só pra simplificar a análise, alterando os valores do índice anterior por um simplificado

$\sum_{k=0}^{\infty}a_{n-k} = a\sum_{j = 0}^{\infty}a_j$﻿

### indução

- provar a base pra um valor especificado, talvez 0
- assumir que k é válido
- testar para k + 1