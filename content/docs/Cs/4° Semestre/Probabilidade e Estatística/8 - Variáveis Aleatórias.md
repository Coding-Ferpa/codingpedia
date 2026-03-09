---
title: "Variáveis Aleatórias"
weight: 3
---

# Distribuição de probabilidade
é um modelo probabilístico que relaciona os valores de uma variável à probabilidade daquele valor na população.
Iremos relacionar valores que ela pode assumir aos eventos .
# Definição
uma variável aleatória X é uma variável numérica cujo valor é um resultado de um fenômeno aleatório. Tal variável pode ser discreta ou contínua. 

---
## Distribuições discretas
modelos relacionados às **variáveis aleatórias discretas**. Os valores formam um conjunto discreto. 
### Variável aleatória discreta
É o tipo de variável que assume um n finito de valores possíveis ou enumerável. 
##### props
a) $p(x_{i}) \geq 0, i = 1,...,n$
b) $\sum^{n}_{i=1}p(x_i)=1$

média ponderada = ponto de equilíbrio do gráfico formado pelos eventos

evento $A$ e $\bar A$ $P(A) = P(x>y) = 1 - P(\bar A) = 1 - P(x < y )$
> não basta criar a tabela, tem que detalhar

## Função de distribuição acumulada
$F(x) = P(X \le x)$

valor esperado exercício em aula: $E(x) = 0(0.49) + 100(0.42) + 10000(0.09) = 942$ 

Variância = $(0 - 942)^{2} \times (0.49)$
$+ (100 - 942)^{2} \times (0.42)$
$+ (10000 - 942)^{2} \times (0.09)$
$= 8.116.832$

## Definições
**Esperança em X**: dada uma v.a discreta, assumindo valores $x_i$ chamados valor média ou esperança.
- $\mu_{x}=E(X) =\sum^{n}_{i=1} x_{i}p(x_{i})$

**Variância**: $\sigma_{x}^{2}= V(X) = \sum_{n}^{i=1}(x_{i}-\mu_{x})^{2}p(x)$

**Desvio Padrão** = $\sqrt{Variância}$

---
### Distribuições contínuas 
Modelos relacionados as variáveis continuas. Os valores obedecem uma escala.
