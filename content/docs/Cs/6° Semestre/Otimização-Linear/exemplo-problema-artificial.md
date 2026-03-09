---
title: "exemplo-problema-artificial"
weight: 3
---

Exemplo (problema artificial):

Maximizar $g(x) = 3x_1 + 2x_2$
sujeito a $2x_1 + x_2 \leq 2$
          $3x_1 + 4x_2 \geq 12$
          $x_1, x_2 \geq 0$

# Metodo do grande-M

Colocando na Forma padrão: 
Minimizar $f(x) = -3x_1 - 2x_2 + 0x_3 + 0x_4$ 
sujeito a $2x_1 + x_2 + x_3 = 2$
          $3x_1 + 4x_2 - x_4 = 12$
          $x_1, x_2, x_3, x_4 \geq 0$

$$
A = \begin{bmatrix}
2 & 1 & 1 & 0 \\
3 & 4 & 0 & -1
\end{bmatrix}, \quad
b = \begin{bmatrix} 2 \\ 12 \end{bmatrix}, \quad
c = \begin{bmatrix} -3 \\ -2 \\ 0 \\ 0 \end{bmatrix}
$$

Adicionando variáveis artificiais $x^a_5$ na segunda restrição:
Minimizar $f(x) = -3x_1 - 2x_2 + 0x_3 + 0x_4 + x^a_5$
sujeito a $2x_1 + x_2 + x_3 = 2$
          $3x_1 + 4x_2 - x_4 + x^a_5 = 12$
          $x_1, x_2, x_3, x_4, x^a_5 \geq 0$

Agora, temos: 

$$
A = \begin{bmatrix}
2 & 1 & 1 & 0 & 0 \\
3 & 4 & 0 & -1 & 1
\end{bmatrix}, \quad
b = \begin{bmatrix} 2 \\ 12 \end{bmatrix}, \quad
c = \begin{bmatrix} -3 \\ -2 \\ 0 \\ 0 \\ 1 \end{bmatrix}
$$


Fase I: 

$(B_1, B_2) = (3, 5)$
$(N_1, N_2, N_3) = (1, 2, 4)$

$$
B = \begin{bmatrix}
3 & 1 \\
4 & -1
\end{bmatrix}, \quad
$$

Fase II:
Usar o metodo simplex para resolver o problema.

.
.
.

Se, ao resolver a Fase II, o resultado de x contiver $x^a_5 > 0$, então o problema original não tem solução viável. Caso contrário, se $x^a_5 = 0$, então a solução encontrada é a solução ótima do problema original.
