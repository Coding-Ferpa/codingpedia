---
title: "aula 2 gl and transformations"
weight: 4
---

# Resumo álgebra linear

Vetor: unidade matemática com direção, sentido, módulo e mais, como limite conhecido por um ponto inicial $p_i$ e um final $p_f$.

$$v = p_ip_f =p_f-p_i=<x_{pf}-x_{pi},\ x_{pf}-x_{pi}>$$
A norma de um vetor v é medida pelo seu comprimento e é dado por:
$$
|v|= <x, y, z> =\sqrt{x^2+y^2+z^2}
$$
![[Pasted image 20250831083217.png]]

`produto interno`(escalar): simbolizado pelo operador $.$ produz um valor relacionado ao comprimeto dos 2 vetores e ao ângulo formado entre eles:
$$
v.w=x_v *x_w + y_v * y_w + z_w * z_v = |v||w|cos(\tetha)
$$
![[Pasted image 20250831083551.png]]
algumas props: quando $\tetha = 90°$, $v.w = 0$.

`produto vetorial`: resulta em um terceiro ortogonal aos 2 primeiros

$$
u = v\times w= <y_v * z_w - z_v * y_w, \ x_v * z_w - x_w * z_v,\ x_v * y_w - x_w - y_w>
$$
o comprimento do vetor resultante é equivalente a área do paralelogramo formado pelos vetores $v$ e $w$. $|v\times w| = |v||w|\sin(\tetha)$ 

Podemos utilizar o produto vetorial, por exemplo, para verificar se dois
vetores são paralelos.

Dado um [espaço vetorial](https://pt.wikipedia.org/wiki/Espa%C3%A7o_vetorial) V e outro W (com seus devidos axiomas) sobre um [corpo](https://pt.wikipedia.org/wiki/Corpo_(matem%C3%A1tica)) K, podemos definir transformações lineares como $T: V \rightarrow W$ se para $\forall u, v \in V, \alpha \in K$  se valem:
- $T(v+u)=T(v)+T(u)$
- $T( \alpha v) = \alpha T ( v )$

O mundo da computação gráfica é dividido em alguns sistemas de coordenadas simultâneos (espaços vetoriais sobre o mesmo corpo):
- Sistema de Coordenadas do Objeto (Modelo);
- Sistema de Coordenadas do Mundo;
- Sistema de Coordenadas da Câmera; 
- Sistema de Coordenadas de Normalizado (-1 a 1 para se trabalhar com a tela do dispositivo);
- Sistema de Coordenadas do Dispositivo;

# Transformações geométricas

Assim, podemos definir as seguintes transformações geométricas a seguir como:

## Translação (Translate)
Soma do vetor de Translação T a P (ponto). 




## Escala (Scale)
Multiplicamos o vetor P (x, y, z) pela matriz de escala:
$$
\begin{bmatrix}
s_x & 0 & 0\\
0 & s_y & 0 \\
0 & 0 & s_z \\
\end{bmatrix}
$$

## Cisalhamento (Shearing)
Fator de deslocamento: multiplicar todos os vertices por:


$$
\begin{bmatrix}
1 & 0 \\
c_y & 1 \\
\end{bmatrix}
$$


$$
\begin{bmatrix}
1 & c_x \\
0 & 1 \\
\end{bmatrix}
$$

## Espelhamento
Inverter (pelo eixo de )

Multiplicar pelo oposto do eixo que se quer refletir (troque -1 por 1 e mantenha aquele eixo da mesma maneira que antes)

$$
\begin{bmatrix}
-1 & 0 \\
0 & -1 \\
\end{bmatrix}
$$

## Rotação

Matriz de rotação: 

$$
R(\tetha) \times P = 
\begin{bmatrix}
cos(\tetha) & -sin(\tetha) \\
sin(\tetha) & cos(\tetha) \\
\end{bmatrix}
$$

### Rotação no 3D
trave o eixo em si e use a formula acima, chegando em:
![[Pasted image 20250831084702.png]]

# Transformações Homogêneas
## Coordenadas homogêneas

Pontos equivalentes ao tridimensional, porem com uma dimensao a mais.
![[Pasted image 20250831084959.png]]

Assim, traduzimos a translação para:
$$\begin{bmatrix} 1 & 0 & 0 & t_1 \\ 0 & 1 & 0 & t_2 \\ 0 & 0 & 1 & t_3 \\ 0 & 0 & 0 & t_4 \end{bmatrix}$$

Podemos fazer em Coordenadas Homogêneas todas as transformações como multiplicações em sequência, ao invés de nos preocuparmos com ordem de execução.

---
# opengl
Representações em opengl das transformações mencionadas
glTranslatef
glScalef
glRotatef


