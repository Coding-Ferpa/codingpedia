#include <stdlib.h>
#include <stdio.h>
#include <GL/freeglut.h>

void DISPLAY() {
  glClearColor(1, 1, 0, 0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-400, 400, -200, 200);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glutSwapBuffers();
}

int main (int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(800, 600);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Aula 01 - OpenGL - Hello World");
  glutDisplayFunc(DISPLAY);
  glutMainLoop();
  return 0;
}
