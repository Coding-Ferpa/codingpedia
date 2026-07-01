---
title: "aula 3"
weight: 4
---

Gráficos 3D
- Projeções geométricas
    - representação de um objeto em uma dimensão em outra
    - transformacao $R^3$ para o $R^2$ 

Uso de matriz homogeneas, calculando um ponto a ser projetado da simulacao do espaco 3D em 2D.

Elementos Basicos:
    - Centro de projecao: origem dos `raios de projecao` / Projetantes
    - pode ser paralelo ou em perspectiva


# Projecao Paralela 
Centro de projecao (infinito) 

## Ortografica (multiplas vistas)
As linhas de projecao sao paralelas entre si e perpendiculares ao plano de projecao

Matrix de projecao:
$$ 
\begin{bmatrix}
1 & 0 & 0 & 0 \\
0 & 1 & 0 & 0 \\
0 & 0 & 0 & 0 \\
0 & 0 & 0 & 1 \\
\end {bmatrix}
$$


## Axonometrica
Representa mais de uma face ao mesmo tempo, todas as visiveis.

Mais comum eh a `isometrica`, ou seja, todos os 3 angulos referentes. (2 rotacoes de 45 em x e y, projetando em z).

tem a dimetrica e trimetrica.

## Obliqua
Projeto o plano com um certo angulo de inclinacao, mas paralelo.
- cavaleira
- cabinet

---

# Projecao Perspectiva

- 1 pontos de fuga
- 2 pontos de fuga
- 3 pontos de fuga

Tentam produzir uma iimagem realista, nao reproduzindo o objeto com sua verdadeira proporcao, ou seja, nao preserva angulas nem escala.

Objetos distantes sao menores, retas paralelas parecem se encontrar no ponto de fuga.

Temos, entao, um centro de projecao (ponto P). 

> matematica evidenciada no caderno.

---
# OPENGL

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45, 1, 0, 15);
  // camera
  gluLookAt(0, 0, 10, 0, 0, 0, 0, 1, 0);
      3 primeiros digitos -> posicao da camera 
      3 digitos seuintes  ->
      3 digitos finais -> topo da camera

  glutKeyboardFunc(nome da funcao com as instrucoes de interacao)
  glutPostRedisplay()
  glutMouseFunc(nome da funcao com as instrucoes de interacao)
