---
title: "Fatoração LU com pivoteamento parcial"
weight: 3
---

# Teorema (Fatoração LU)
Seja A uma matriz $n\times m$ e $A_k$ a martiz constituida das primeiras k linhas e k colunas de A.
Se $det(A_k) \neq 0, \forall k=1, 2, 3, ..., n-1$ então A admite uma composição A=LU , onde $L = (l_{ij})_{n\times m}$ é uma matriz triangular inferior $U = (u_{ij})_{n\times m}$ é uma matriz triangular superior e $det(A) = u_{11} \times u_{22} \times ... \times u_{nn}$

# Decomposição com pivoteamento
Se em cada etapa $k$ foi aplicada uma permutação $P_{k}$, então:
$$L.U = P.A$$
onde $P = \prod_{k=0}^{n-1}P_{k}$ 

## exemplo 1
$$A^{(0)}={\begin{bmatrix} 1 & 4 & 1 \\ 2 & 1 & 1 \\ 3 & 1 & 2 \end{bmatrix}}$$
**procedimento**: Verificar se essa matriz admite decomposição LU e, em caso afirmativo, obter L e U com pivoteamento parcial.
_Solução_: $A_{1}=[1]$
$A_{2}= {\begin{bmatrix} 1 & 4 \\ 2 & 1\end{bmatrix}}$
$det(A_{1}) = 1 \neq 0$
$det(A_{2})= 1 - 8 = -7 \neq 0$
*pelo teorema*, $A^{(0)}$ admite decomposição LU.

_pivoteamento parcial_:
**eliminação de Gauss**
_etapa 1:_

$$A^{(0)}={\begin{bmatrix} 1 & 4 & 1 \\ 2 & 1 & 1 \\ 3 & 1 & 2 \end{bmatrix}}$$
trocar linha 1 <-> 3

$$ \bar A^{(0)} = \begin{bmatrix} 3 & 1 & 2 \\  2 & 1 & 1 \\  1 & 4 & 1 \end{bmatrix} = P_{13}A^{(0)}$$

$a_{n}=3$ (pivô)
$$m_{21} = \frac{a_{21}}{a_{11}} = \frac{2}{3} \ , m_{31}= \frac{a_{31}}{a_{11}} = \frac{1}{3} $$

$$A^{(1)}={\begin{bmatrix} 3 & 1 & 2 \\ m_{21}= \frac{2}{3} & \frac{1}{3} & \frac{-1}{3} \\ m_{31}=\frac{1}{3} & \frac{11}{3} & \frac{1}{3} \end{bmatrix}} ops: L_{2}^{(1)} -  m_{21}.L_{1}^{(0)} \ e \ L_{3}^{(0)}-m_{31}.L_{1}^{(0)}$$
_Etapa 2:_ 

$$ \bar A^{(1)} = \begin{bmatrix} 3 & 1 & 2 \\  \frac{1}{3} & \frac{11}{3} & \frac{1}{3} \\  \frac{2}{3} & \frac{1}{3} & \frac{-1}{3} \end{bmatrix} = P_{23}A^{(1)}$$

$$m_{32}= \frac{a_{32}}{a_{22}} = \frac{\frac{1}{3}}{\frac{11}{3}} = \frac{1}{11}$$


$$A^{(2)}={\begin{bmatrix} 3 & 1 & 2 \\ \frac{1}{3} & \frac{11}{3} & \frac{1}{3} \\ \frac{2}{3} & m_{32}=\frac{1}{11} & \frac{-12}{33} \end{bmatrix}} ops: L_{3}^{(1)} - m_{32}.L_{2}^{(1)}$$
A matriz L é 
$$L = \begin{bmatrix}
L & 0 & 0 \\ \frac{1}{3} & 1  &  0 \\ \frac{2}{3} & \frac{1}{11} &  1
\end{bmatrix}$$
A matriz U é
$$U = \begin{bmatrix}
3  & 1  &  2 \\ 0  & \frac{11}{3} & \frac{1}{3}  \\ 0 & 0 & \frac{-12}{33} 
\end{bmatrix}$$
Logo, $L.U = P.A \ onde \ P_{23}.P_{13}.A$ 
$$P=P_{23}= \begin{bmatrix}
0 & 0 & 1  \\ 0 & 1 & 0 \\ 1 & 0 & 0
\end{bmatrix}= P_{23}.P_{13}\begin{bmatrix}
0 & 0 & 1 \\ 1 & 0 & 0 \\ 0 & 1 & 0
\end{bmatrix}$$
$$L.U = P.A^{(0)} =
\begin{bmatrix}
1  & 0 & 0 \\ \frac{1}{3} & 1 & 0 \\ \frac{2}{3} & \frac{1}{11} & 1
\end{bmatrix}\times \begin{bmatrix}
3 & 1 & 2  \\ 0 & \frac{11}{3} & \frac{1}{3} \\ 0 & 0 & \frac{-12}{31}
\end{bmatrix}=\begin{bmatrix}
0 & 0 & 1 \\ 1 & 0 & 0 \\ 0 & 1 & 0
\end{bmatrix} \times \begin{bmatrix}
1 & 4 & 1 \\ 2 & 1 & 1 \\ 3 & 1 & 2
\end{bmatrix}$$ 
