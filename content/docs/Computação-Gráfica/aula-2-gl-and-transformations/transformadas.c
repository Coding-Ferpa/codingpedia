#include <GL/freeglut.h>
#include <math.h>

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

void drawHuman(int x, int y, int human_size) {
  drawCircle(x, y, human_size);
  drawLine(x, -human_size, 0, y + human_size - 90);
  drawLine(x, y - 20, x - 20, y - 30);
  drawLine(x, y - 20, x + 20, y - 30);
  drawLine(x, y - 90, x - 20, y - 120);
  drawLine(x, y - 90, x + 20, y - 120);
  drawLine(x, -human_size, x, y - 90);
}

void DISPLAY() {
  glClearColor(0, 0, 0, 0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(-200, 200, -200, 200);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glPushMatrix();
  glColor3f(1, 1, 1);
  drawHuman(0, 0, 15);
  glPopMatrix();

  // red
  glPushMatrix();
  glColor3f(1, 0, 0);
  glRotatef(20, 0, 0, 1);
  glScalef(0.5, 0.5, 0);
  glTranslatef(70, 0, 0);
  drawHuman(0, 0, 15);
  glPopMatrix();


  // green
  glPushMatrix();
  glColor3f(0, 1, 0);
  glRotatef(40, 0, 0, 1);
  glScalef(0.4, 0.4, 0);
  glTranslatef(140, -70, 0);
  drawHuman(0, 0, 15);
  glPopMatrix();

  // blue 
  glPushMatrix();
  glColor3f(0, 0, 1);
  glRotatef(50, 0, 0, 1);
  glScalef(0.3, 0.3, 0);
  glTranslatef(260, -130, 0);
  drawHuman(0, 0, 15);
  glPopMatrix();
  
  // yellow
  glPushMatrix();
  glColor3f(1, 1, 0);
  glRotatef(80, 0, 0, 1);
  glScalef(0.2, 0.2, 0);
  glTranslatef(400, -400, 0);
  drawHuman(0, 0, 15);
  glPopMatrix();


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
