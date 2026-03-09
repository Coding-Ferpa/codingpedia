---
title: "opengl"
weight: 4
---

Começaremos com OpenGL (Open Graphics Library). A interface entre o software e o hardware gráfico é feita através de procedimentos disponíveis pela API.

Opengl é um pacote de um sistema gráfico e usa rotinas de baixo nivel, como:
- <GL/freeglut.h>
- glutMainLoop()

Carrega comandos no buffer de comandos OpenGL, ao inves da ordem imperativa.

Definicoes:
- glVertex3f(10.0, 8.0, 5.0);
    - gl: biblioteca
    - vertex: nome da funcao
    - 3: quantidade de variaveis (ou 2 -> 2d)
    - f: tipo (float)

- glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
- glutSwapBuffers();
    - troca os view buffers entre o visivel e o nao visivel
- glClearColor() - com float - RGBA
- glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

- glutDisplayFunc(DISPLAY);
- glutMainLoop(); - loop que inicializa
