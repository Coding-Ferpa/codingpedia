#include "stdio.h"
#include <GL/freeglut.h>
#include <math.h>

#define MAX_VERTEX 10

typedef struct vertex {
  float x, y;
} vertex;

int n;
float r, g, b;

vertex points[MAX_VERTEX + 1];

void drawLine(int x, int y, int x2, int y2) {
  glBegin(GL_LINES);
  glVertex2f(x, y);
  glVertex2f(x2, y2);
  glEnd();
}

void drawCircle(int x, int y, int scale) {
  float tetha = 0.0f;
  glBegin(GL_LINE_LOOP);
  while (tetha <= 2 * M_PI) {
    glVertex2f(cos(tetha) * scale + x, sin(tetha) * scale + y);
    tetha += 0.000001;
  }
  glEnd();
  glBegin(GL_POINTS);
  glVertex2f(x - 5, y - 1);
  glVertex2f(x + 5, y - 1);
  glEnd();
}

void DISPLAY() {
  glClearColor(0, 0, 0, 0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-200, 200, -200, 200);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glBegin(GL_POLYGON);
  glColor3f(r, g, b);
  for (int i = 0; i < n; i++) {
    glVertex2f(points[i].x, points[i].y);
  }
  glEnd();

  glutSwapBuffers();
}

int main(int argc, char **argv) {
  printf("Insira o numero de vertices (n - no maximo 10)\n");
  scanf("%d", &n);

  if (n > MAX_VERTEX || n < 0) {
    perror("VOCE ERROU IRMAO, SETEI PRA 9 OTARIO!!!\n");
    n = 9;
  }

  printf("Insira os %d vertices nesse formato (0.0 0.0)\n", n);
  for (int i = 0; i < n; i++) {
    scanf("%f %f", &points[i].x, &points[i].y);
  }

  printf("Insira a cor do poligono (1 1 1)\n");
  scanf("%f %f %f", &r, &g, &b);

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(600, 600);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Aula 04 - OpenGL - Hello World");
  glutDisplayFunc(DISPLAY);
  glutMainLoop();
  return 0;
}
