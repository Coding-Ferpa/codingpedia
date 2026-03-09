---
title: "Probabilidade Condicional"
weight: 3
---

def: 2 eventos A e B, sendo P(B) > 0, definimos a probabilidade condicional de A dado B, P(A\B), como sendo:
$$ P(A \backslash B) = \frac{P(A\cap B)}{P(B)}$$

Desta relação, obtemos a **regra do produto da probabilidades**:
$$P(A\cap B)= P(A\backslash B)\ P(B)$$

> basicamente, é a probabilidade de algo ocorrer baseado em outro algo que tem sua própria probabilidade

sintaxe: P(A \ M) -> lido como: probabilidade de A acontecer se M -> P de A se M;
# Exemplos

|          | M   | F   | Total |
| -------- | --- | --- | ----- |
| A        | 4   | 6   | 10    |
| $\bar A$ | 8   | 14  | 22    |
| Total    | 12  | 20  | 32    |
### $P(A\backslash M) = \frac{P(A\cap M)}{P(M)} = \frac8{12} = \frac23$

## Exemplo 2
$P(C\backslash M) = 1/2$
$P(C\backslash \bar M) = 1$
média ponderada de $P(C\backslash M)$ e $P(C\backslash \bar M)$

$C = (C\cap M)\cup (C\cap\bar M)$
$P(C) = P(C\cap M)+ P(C\cap \bar M)$
$= P(C\backslash M).P(M) + P(C\backslash\bar M).P(\bar M)$ que neste caso é igual a $0.75$
$\frac{P(A\cap M)}{P(M)} = \frac{0.5}{0.75}$

## Exemplo 3
passos
- Questão impõe alguma condição? 
- quais são os eventos da questão?

$P(B\backslash A) = 0.85$
$P(B\backslash\bar A) = 0.4$
$P(O\backslash C) = 0.8$

$P(B) = P(B\cap A) + P(\cap \bar A)$
[[6.1- Matriz de Confusão]]