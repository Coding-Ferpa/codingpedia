#include <GL/freeglut.h>
#include <math.h>

void draw() {
  int x = 0, y = 0;
  glColor3f(1, 1, 1);
  while (x <= 200) {
    glBegin(GL_POINTS);
    glVertex2f(x, y);
    glVertex2f(-x, y);
    glVertex2f(-x, -y);
    glVertex2f(x, -y);
    glEnd();
    x += 12;
    y += 12;
  }

  x = 0;
  y = 0;
  glColor3f(0, 1, 0);
  while (x <= 100) {
    glBegin(GL_TRIANGLES);
    glVertex2f(sin(x) * 40, cos(y) * 40);
    glVertex2f(sin(x) * 80, cos(y) * 80);
    glVertex2f(sin(x) * 40 + 50, cos(y) * 40 + 50);
    glEnd();
    x += 1;
    y += 1;
  }
}

void DISPLAY() {
  glClearColor(0, 0, 0, 0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-200, 200, -200, 200);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  draw();
  glutSwapBuffers();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(600, 600);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Aula 01 - OpenGL - Hello World");
  glutDisplayFunc(DISPLAY);
  glutMainLoop();
  return 0;
}
