---
title: "Montar um caso real - probabilidade e estatística"
weight: 3
---

exercício: montar uma matriz de confusão, achar a sensibilidade, a precisão, a acurácia e especifidade baseado em um set real.

# Teste Genérico
## Exemplo de Dataset Pequeno para Classificação Binária (gerado pelo gpt)

Dados:

| Amostra | Predição do Modelo | Classe Verdadeira |
|---------|--------------------|-------------------|
| 1       | Positivo           | Positivo          |
| 2       | Positivo           | Negativo          |
| 3       | Negativo           | Negativo          |
| 4       | Positivo           | Positivo          |
| 5       | Negativo           | Negativo          |
| 6       | Negativo           | Positivo          |
| 7       | Positivo           | Positivo          |
| 8       | Negativo           | Negativo          |
| 9       | Positivo           | Negativo          |
| 10      | Positivo           | Positivo          |

Compilado:

    Verdadeiros Positivos (VP): Amostras 1, 4, 7, 10 (4 casos)
    Falsos Positivos (FP): Amostras 2, 9 (2 casos)
    Verdadeiros Negativos (VN): Amostras 3, 5, 8 (3 casos)
    Falsos Negativos (FN): Amostra 6 (1 caso)

|          | Positivo | Negativo | Total |
| -------- | -------- | -------- | ----- |
| Positivo | VP = 4   | FN = 1   | 5     |
| Negativo | FP = 2   | VN = 3   | 5     |
| Total    | 6        | 4        | 10    |
## Métricas de Avaliação

- **Sensibilidade/Revocação** -> taxa de verdadeiro positivo. ($S = \frac{VP}{VP + FN}$)
- **Especificidade do teste** -> taxa de verdadeiro negativo. ($\xi = \frac{VN}{VN+PF}$)
- **Acurácia** ->  dentre todas, quais classificações estavam corretas. ($A = \frac{VP + VN}{VN + VP + FN + FP}$)
- **Precisão** -> dentre as que foram ditas como corretas, quais são, de fato. ($P = \frac{VP}{VP+FP}$)

Sensibilidade -> $S = \frac{4}{4+1} = \frac45 = 0.8$
Especificidade -> $\xi = \frac{3}{3+1} = \frac34 = 0.75$
Acurácia -> $A = \frac{4+3}{4+3+1+2} = \frac7{10} = 0.7$
Precisão -> $P = \frac{4}{4+2} = \frac46 \approx 0.667$

---
# Teste Real
Baseado no dataset [Wine](https://archive.ics.uci.edu/dataset/109/wine), um dataset que visa avaliar a qualidade de determinados vinhos, baseado em composição química. Evidentemente, são dados muito avançados para este teste, então pedi pra uma IA deixar apenas uma tabela com dados binários para que eu pudesse fazer uma avaliação mais simples. Temos um dataset binário com 107 amostras, onde:

    A coluna 1 representa a porcentagem de álcool.
    A coluna 13 representa a prolina (um aminoácido).

As classes foram mapeadas de forma binária:

    0: Representa a classe original 1 (um tipo de vinho).
    1: Representa a classe original 2 (outro tipo de vinho).

# Amostragem parcial
Neste caso, vamos utilizar somente 9 amostras, para fazer o cálculo manual.

| Amostra | Classe preditada | Classe Verdadeira | Álcool | Prolina |
| ------- | ---------------- | ----------------- | ------ | ------- |
| 0       | 0                | 0                 | 14.23  | 1065    |
| 1       | 0                | 0                 | 13.20  | 1050    |
| 2       | 0                | 0                 | 13.16  | 1185    |
| 3       | 1                | 0                 | 14.37  | 1480    |
| 4       | 0                | 0                 | 13.24  | 735     |
| 5       | 0                | 1                 | 13.71  | 1285    |
| 6       | 1                | 1                 | 13.40  | 915     |
| 7       | 0                | 1                 | 13.27  | 1280    |
| 8       | 1                | 1                 | 13.17  | 520     |
# Tabela

Foi utilizada uma escolha de predição sem critério, portanto, os números foram apenas gerados e colocados ali para serem comparados com o caso real do dataset.

|       | 0   | 1   | TOTAL |
| ----- | --- | --- | ----- |
| 0     | 4   | 1   | 5     |
| 1     | 2   | 2   | 4     |
| TOTAL | 6   | 3   | 9     |

Fazendo os cálculos:

-  **Sensibilidade/Revocação**: $S = \frac{4}{4 + 1} = 0.8$
- **Especificidade do teste**: $\xi = \frac{2}{2 + 2} = 0.5$
- **Acurácia**: $A = \frac{4 + 2}{4 + 1 + 2 + 2} \approx 0.667$
- **Precisão**: $P = \frac{4}{4 + 2} \approx 0.667$

Podemos perceber que usando a análise binária, esse dataset e a predição não criteriosa não produziu resultados magníficos, mas ao mesmo tempo, por ser binário, teve números de probabilidade consideravelmente altos. 

--- 
# Testando em Python, com predição real

```Python
import pandas as pd
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score, classification_report, confusion_matrix

# Carregar o dataset
column_names = [
    'Class',
    'Alcohol',
    'Malic Acid',
    'Ash',
    'Alcalinity of Ash',
    'Magnesium',
    'Total Phenols',
    'Flavanoids',
    'Nonflavanoid Phenols',
    'Proanthocyanins',
    'Color Intensity',
    'Hue',
    'OD280/OD315 of Diluted Wines',
    'Proline'
]

# Carregar o arquivo de dados
data = pd.read_csv('wine.data', header=None, names=column_names)

# Selecionar apenas as colunas 'Alcohol' e 'Proline' para características
X = data[['Alcohol', 'Proline']]
y = data['Class']

# Dividir os dados em conjuntos de treinamento e teste
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=42)

# Criar e treinar o modelo de Regressão Logística
model = LogisticRegression(max_iter=1000, multi_class='auto', solver='lbfgs')
model.fit(X_train, y_train)

# Fazer previsões
predictions = model.predict(X_test)

# Calcular a acurácia
accuracy = accuracy_score(y_test, predictions)
print(f'Acurácia: {accuracy:.2f}')

# Matriz de confusão
print("\nMatriz de Confusão:")
print(confusion_matrix(y_test, predictions))

# Relatório de classificação
print("\nRelatório de Classificação:")
print(classification_report(y_test, predictions))
```

Foi utilizado algumas funções prontas de python para a realização deste teste. Pode-se notar que foi utilizado uma regressão logistica para prever os resultados do modelo. Na regressão logística, uma transformação logit é aplicada à chance, isto é, a probabilidade de sucesso dividida pela probabilidade de fracasso. .

Change de acontecer / chance de não acontecer
quanto mais perto de 1 é que vai acontecer, mais perto de 0 é que não vai.

# Avaliação

Neste caso aqui, foram utilizados as 3 colunas possíveis do dataset, dispostas nas linhas, ao lado do que foi predito, nas colunas.

## Matriz de Confusão

|            | Predito 1 | Predito 2 | Predito 3 | Total |
| ---------- | --------- | --------- | --------- | ----- |
| **Real 1** | 19        | 0         | 0         | 19    |
| **Real 2** | 0         | 19        | 2         | 21    |
| **Real 3** | 1         | 3         | 10        | 14    |
| Total      | 20        | 22        | 12        | 54    |

## Métodos de avaliação
Os métodos de avaliação utilizados foram gerados automaticamente pelo código 
`classification_report(y_test, predictions)`, baseado na coluna de "Classes" (Resultados Reais) e no que foi predito. Dos tipos de classificação gerados, vimos apenas o da precisão.

Acurácia: 0.89

| Classe        | Precisão | Especificadade | F1-Score |
| ------------- | -------- | -------------- | -------- |
| 1             | 0.95     | 1.00           | 0.97     |
| 2             | 0.86     | 0.90           | 0.88     |
| 3             | 0.83     | 0.71           | 0.77     |
| **Média**     | 0.88     | 0.87           | 0.88     |
| **Ponderada** | 0.89     | 0.89           | 0.89     |
