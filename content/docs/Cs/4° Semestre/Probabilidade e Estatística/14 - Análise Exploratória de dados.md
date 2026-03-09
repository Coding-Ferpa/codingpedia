---
title: "Análise Exploratória de dados"
weight: 3
---

O objetivo é a exploração irrestrita dos dados, na busca por padrões interessantes e conhecimento útil. **As conclusões não possibilitam generalização**.

Utilizaremos métodos numéricos e gráficos para descrever as varáveis de um conjunto de dados e as relações entre elas. 

# Conceitos e definições:
_população (N)_ é a coleção completa de todos os elementos (valores, pessoas, medidas...).
_amostra (n)_ é um sub conjunto organizado por algum intuito.
_censo_ é a coleção de dados relativos a todos os elementos da população.
_variabilidade_ é a dispersão da **variável**
_dados_ são informações sistematicamente registradas, sejam números ou rótulos. São inúteis sem contexto.

amostras aleatórias são uma boa estratégia para selecionar amostragens não enviesadas.

## requisitos
Identificação das variáveis, coerência, representação gráfica, análise das medidas de posição dispersão, gráficos e de possíveis relações entre as variáveis e destaque das anomalias.

## Medidas de dispersão
[[6.1- Matriz de Confusão]] e [[8 - Variáveis Aleatórias]]
Média ponderada é distribuição uniforme com peso 1/n.
média aritmética = $\bar x = \sum^{n}_{i=1}\limits x_{i}\times (\frac{1}{n})$

Coeficiente de variação $cv = \frac{s}{\bar x}\times 100$

| CV         | Dispersão |
| ---------- | --------- |
| <15%       | baixa     |
| 15%<cv<35% | média     |
| >35%       | alta      |

### quantis
Um quantil de ordem p, $Q(p)$ é o valor tal que 100 p% das observações são menores do que $Q(p)$, sendo $0<p<1$

Delimitam a metade central dos dados, ou seja, a amostra de 25% a 75%

#### Resumo de 5 números
QUARTIL 1 = Q=Q(0, 25) -> 25% menores
QUARTIL 3 = Q=Q(0,75) -> 25% maiores
md - mediana
min - minimo 
max - maximo

#### tabela resumo
amostra
média
mediana
moda
variância
desvio padrão
CV
minimo
1° Quartil
3° Quartil
Máximo
Amplitude