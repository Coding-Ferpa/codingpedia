---
title: "Invariante de laço e Ordem de crescimento"
weight: 3
---

## Ordenação por inserção

insere ordenado ai

subdivide em 2 conjuntos, um ordenado o outro não

o algoritmo acaba quando o Vetor A[1..n] contém valores originais, mas ordenados.

---
# Testes

- provando um algoritmo fácil

## Invariante de laço

qualquer algoritmo de ordenação iterativo pode ser descrito por um invariante de laço (funciona como uma indução matemática)

para o insertion sort, um invariante correto, seria:

- “No inicio de cada iteração para o laço for das linhas 1-8, o sub-vetor A[1:i-1] consiste nos elementos que estavam originalmente em A[i:j-1], porém em sequência ordenada”

  

- inicialização: ele é verdadeiro antes da primeira iteração
- manutenção: se ele for verdadeiro antes, permanecerá verdadeiro antes da próxima iteração
- término: e após, mostra que o algoritmo está correto

> se o invariante for válido, o algoritmo também estará

---

# Convenções

Recuos indicam estrutura de bloco

semelhante a C++, C, Java e Python

// → comentário

não há variáveis globais sem explicitar-nas

1-based vector

---

### Exercícios

No inicio de cada iteração, cada elemento do sub-vetor A[1:i-n] é acrescido a uma variável auxiliar, visto que i é aumentado no for. O valor é atribuído a variável, até o i = n.

- inicialização: a soma é definida como 0, portanto, antes da manutenção, a soma está valida, visto que A[0] é um vetor vazio, com um elemento, então, se somado a 0, a variável soma assumirá o nulo (0).
- manutenção, para todo elemento i:1..n, há soma do elemento atual com a variável ‘soma’. O valor de soma para i = 2 assume a forma de A[1] + A[2], i = 3 ,A[1] + A[2] + A[3], até n.
- o laço quebra quando i = n + 1, onde o elemento out of bound não é adicionado a soma e o valor é retornado. Pode-se constatar que quando i = n, todo elemento do vetor foi somado à variável soma, portanto o sub-vetor inteiro foi trabalhado.

---

# Análise do algoritmo

ver quantas vezes ele executará para cada linha no código * quantidade de tempo de cada linha

são independentes de hardware já.

  
- n° de instruções + acesso a dados

### Custos

comparação → 1

aritmética → 1

for 2n + 1 → 2n → n de custo ou O(n)
  

Calcularemos T(n) para a ordenação de inserção

### Melhor caso

c1n + c2(n-1) + c4(n-1) + $\sum_{i=2}^{n}{(t_i)}$﻿c5 + $\sum_{i=2}^{n}{(t_i-1)}$﻿c6 + $\sum_{i=2}^{n}{(t_i-1)}$﻿ c7+ c8(n-1)

devemos escrever as constantes como uma unica constante, e trocar os somatórios de ti para (n - 1) ou apenas 1 para o melhor caso

$T(n) = an+b$﻿

### Pior caso

- vetor na forma inversa

podemos assumir q os 3 somatórias executarão em sua totalidade

- vale lembrar

$\sum_{j=2}^n j ={\frac{n(n+1)}{2}-1}$﻿

  

$\sum_{j=2}^n{(j-1)} ={\frac{n(n-1)}{2}}$﻿

  

trocando, o resultado será

$T(n) = an² +bn +c$﻿

  

tiramos, portanto, o limite superior do pior caso, sendo uma função do tipo quadrático.

---

# Ordem de crescimento

Para simplificar, usaremos apenas o termo de maior expoente, apenas. Ou seja, nos basearemos na ordem de crescimento de uma fração da função do maior expoente, ou seja, de an² + bn + c, usaremos apenas O(n²).