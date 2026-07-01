#include "stdio.h"
#include <GL/freeglut.h>
#include <math.h>

#define WIDTH 1000
#define HEIGHT 700

void drawStar(int x, int y, float scale) {
  glPushMatrix();
  glColor3f(1, 1, 1);
  glScalef(scale, scale, 1);

  glBegin(GL_LINE_LOOP);
  glVertex2f(x , y + 10);
  glVertex2f(x + 2.5, y + 3);
  glVertex2f(x + 9.5, y + 3);
  glVertex2f(x + 3.5, y - 1);
  glVertex2f(x + 5.5, y - 8);
  glVertex2f(x + 0.,  y - 3);
  glVertex2f(x - 5.5, y - 8);
  glVertex2f(x - 3.5, y - 1);
  glVertex2f(x - 9.5, y + 3);
  glVertex2f(x - 2.5, y + 3);

  glEnd();
  glPopMatrix();
}

void drawCircle(int x, int y, int scale) {
  float tetha = 0.0f;
  glBegin(GL_POLYGON);
  glColor3ub(48,38,129);
  while (tetha <= 2 * M_PI) {
    glVertex2f(cos(tetha) * scale + x, sin(tetha) * scale + y);
    tetha += 0.000001;
  }
  glEnd();

}

void drawStrip(float offset_y) {
  float tetha = 2;
  glPushMatrix();
  glColor3ub(255, 255, 255);

  glBegin(GL_LINE_STRIP);
    while (tetha >= 0.8) {
      glVertex2f(cos(tetha) * 105 - 15, sin(tetha) * 50 - (30 + offset_y));
      tetha -= 0.01;
    }
  glEnd();
  glPopMatrix();
}

void DISPLAY() {
  glClearColor(0, 0.58, 0.25, 0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-200, 200, -200, 200);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glBegin(GL_POLYGON);
  glColor3ub(255, 203, 0);
  glVertex2f(-(WIDTH / 5) + 30, 0);
  glVertex2f(0, (HEIGHT / 4) - 30);
  glVertex2f((WIDTH / 5) - 30, 0);
  glVertex2f(0, - (HEIGHT / 4) + 30);
  glEnd();

  drawCircle(0, 0, 60);

  for (float i = 0; i < 10; i+=0.1)
    drawStrip(i);

  drawStar(80, 60, 0.15);
  drawStar(0, 0, 0.1);
  drawStar(0, 0, 0.1);
  drawStar(0, 0, 0.1);
  drawStar(0, 0, 0.1);
  drawStar(0, 0, 0.1);
  drawStar(0, 0, 0.1);
  drawStar(0, 0, 0.1);
  drawStar(0, 0, 0.1);
  drawStar(0, 0, 0.1);
  drawStar(0, 0, 0.1);
  drawStar(0, 0, 0.1);
  drawStar(0, 0, 0.1);
  drawStar(0, 0, 0.1);
  drawStar(0, 0, 0.1);
  drawStar(0, 0, 0.1);
  drawStar(0, 0, 0.1);
  drawStar(0, 0, 0.1);
  drawStar(0, 0, 0.1);
  drawStar(0, 0, 0.1);
  drawStar(0, 0, 0.1);
  drawStar(0, 0, 0.1);
  drawStar(0, 0, 0.1);
  drawStar(0, 0, 0.1);
  drawStar(0, 0, 0.1);
  drawStar(0, 0, 0.1);
  drawStar(0, 0, 0.1);

  glutSwapBuffers();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(WIDTH, HEIGHT);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Aula 04 - OpenGL - Hello World");
  glutDisplayFunc(DISPLAY);
  glutMainLoop();
  return 0;
}
