#include <GL/freeglut.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void Mouse(int botao, int estado, int x, int y);
void keyboard(unsigned char key, int x, int y);
void TeclasEspeciais(int key, int x, int y);

void drawDice() {
  glPushMatrix();
  glColor3ub(255, 255, 255);
  glutSolidCube(9.95);
  glPopMatrix();

  glPushMatrix();
  glColor3ub(0, 0, 0);
  glutWireCube(10.08);
  glutWireCube(10.09);
  glutWireCube(10.1);
  glutWireCube(10.11);
  glutWireCube(10.12);
  glutWireCube(10.13);
  glPopMatrix();

  // face 1
  glPushMatrix();
  glTranslatef(0, 0, 5);
  glScalef(1, 1, 0.1);
  glColor3ub(0, 0, 0);
  glutSolidSphere(0.5, 20, 20);
  glPopMatrix();

  // face 6
  glPushMatrix();
  glTranslatef(2.5, 2.5, -5);
  glScalef(1, 1, 0.1);
  glColor3ub(0, 0, 0);
  glutSolidSphere(0.5, 20, 20);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(2.5, 0, -5);
  glScalef(1, 1, 0.1);
  glColor3ub(0, 0, 0);
  glutSolidSphere(0.5, 20, 20);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(2.5, -2.5, -5);
  glScalef(1, 1, 0.1);
  glColor3ub(0, 0, 0);
  glutSolidSphere(0.5, 20, 20);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-2.5, 2.5, -5);
  glScalef(1, 1, 0.1);
  glColor3ub(0, 0, 0);
  glutSolidSphere(0.5, 20, 20);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-2.5, 0, -5);
  glScalef(1, 1, 0.1);
  glColor3ub(0, 0, 0);
  glutSolidSphere(0.5, 20, 20);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-2.5, -2.5, -5);
  glScalef(1, 1, 0.1);
  glColor3ub(0, 0, 0);
  glutSolidSphere(0.5, 20, 20);
  glPopMatrix();

  // face 2

  glPushMatrix();
  glTranslatef(2.5, -5, 2.5);
  glScalef(1, 0.1, 1);
  glColor3ub(0, 0, 0);
  glutSolidSphere(0.5, 20, 20);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-2.5, -5, -2.5);
  glScalef(1, 0.1, 1);
  glColor3ub(0, 0, 0);
  glutSolidSphere(0.5, 20, 20);
  glPopMatrix();

  // face 5
  glPushMatrix();
  glTranslatef(-2.5, 5, 2.5);
  glScalef(1, 0.1, 1);
  glColor3ub(0, 0, 0);
  glutSolidSphere(0.5, 20, 20);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(2.5, 5, 2.5);
  glScalef(1, 0.1, 1);
  glColor3ub(0, 0, 0);
  glutSolidSphere(0.5, 20, 20);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0, 5, 0);
  glScalef(1, 0.1, 1);
  glColor3ub(0, 0, 0);
  glutSolidSphere(0.5, 20, 20);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-2.5, 5, -2.5);
  glScalef(1, 0.1, 1);
  glColor3ub(0, 0, 0);
  glutSolidSphere(0.5, 20, 20);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(2.5, 5, -2.5);
  glScalef(1, 0.1, 1);
  glColor3ub(0, 0, 0);
  glutSolidSphere(0.5, 20, 20);
  glPopMatrix();

  // face 3

  glPushMatrix();
  glTranslatef(-5, 0, 0);
  glScalef(0.1, 1, 1);
  glColor3ub(0, 0, 0);
  glutSolidSphere(0.5, 20, 20);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-5, -2.5, 2.5);
  glScalef(0.1, 1, 1);
  glColor3ub(0, 0, 0);
  glutSolidSphere(0.5, 20, 20);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(-5, 2.5, -2.5);
  glScalef(0.1, 1, 1);
  glColor3ub(0, 0, 0);
  glutSolidSphere(0.5, 20, 20);
  glPopMatrix();

  // face 4

  glPushMatrix();
  glTranslatef(5, 2.5, 2.5);
  glScalef(0.1, 1, 1);
  glColor3ub(0, 0, 0);
  glutSolidSphere(0.5, 20, 20);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(5, 2.5, -2.5);
  glScalef(0.1, 1, 1);
  glColor3ub(0, 0, 0);
  glutSolidSphere(0.5, 20, 20);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(5, -2.5, 2.5);
  glScalef(0.1, 1, 1);
  glColor3ub(0, 0, 0);
  glutSolidSphere(0.5, 20, 20);
  glPopMatrix();

  glPushMatrix();
  glTranslatef(5, -2.5, -2.5);
  glScalef(0.1, 1, 1);
  glColor3ub(0, 0, 0);
  glutSolidSphere(0.5, 20, 20);
  glPopMatrix();
}

int projecao = 0;
int rot_x = 0, rot_y = 0, rot_z = 0, pos_x = -30, pos_y = 0, pos_z = 0;

void DISPLAY() {
  glEnable(GL_DEPTH_TEST); /*Realize teste de profundidade por amostra (frame)
 em relação ao volume e seus limites. Se o teste falhar, o fragmento é
 descartado. Se o teste for aprovado, o buffer de profundidade será atualizado*/
  glEnable(GL_LINE_SMOOTH);
  glEnable(GL_POLYGON_SMOOTH);
  glEnable(GL_SMOOTH);
  glEnable(GL_BLEND); /*Pixels podem ser desenhados combinando o espaço de cor
 RGBA de entrada (origem) com os valores RGBA que já estão no buffer (frame).*/

  glClearColor(255, 255, 255, 255);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  if (projecao == 1)
    glOrtho(-150, 150, -150, 150, -150, 150); // Define a projeção como
                                              // ortogonal
  else
    gluPerspective(45, 1, 1, 150);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(0, 0, 40, 0, 0, 0, 0, 1, 0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glPushMatrix();
  glRotatef(2 * rot_x, 0, 1, 0);
  glRotatef(2 * rot_y, 1, 0, 0);
  glRotatef(2 * rot_z, 0, 0, 1);
  glTranslatef(pos_x, pos_y, pos_z);

  drawDice();
  glPopMatrix();

  glutSwapBuffers();
}

int shouldAnimate = 0;
int animation_step = 0;

void animate(int value) {
  if (!shouldAnimate)
    return;

  pos_x += 3;
  animation_step++;

  if (animation_step > 190) {
    shouldAnimate = 0;
    return;
  }

  animation_step++;

  glutPostRedisplay();

  glutTimerFunc(10, animate, 0);
}

void Mouse(int botao, int estado, int x,
           int y) { // botão - recebe o código do botão pressionado
  // estado - recebe se está pressionado ou não
  // x, y - recebem respectivamente as posições do mouse na tela
  switch (botao) {
  case GLUT_LEFT_BUTTON:
    if (estado == GLUT_DOWN) {
      pos_y = 0;
      pos_x = 0;
      pos_z = 0;
      glutPostRedisplay();
    }
    break;

  case GLUT_RIGHT_BUTTON:
    if (estado == GLUT_DOWN) {
      animation_step = 0;
      shouldAnimate = 1;
      animate(0);
    }
    break;
  }
}
void keyboard(unsigned char key, int x,
              int y) { // Key - recebe o código ASCII da tecla
                       // x, y - recebem as posições do mouse na tela (permite
                       // tratar os dois dispositivos)
  if (key == 'd') {
    pos_x += 1;
  } else if (key == 'a') {
    pos_x -= 1;
  } else if (key == 'w') {
    pos_y += 1;
  } else if (key == 's') {
    pos_y -= 1;
  } else if (key == 27) {
    exit(0);
  }
  glutPostRedisplay();
}

void TeclasEspeciais(
    int key, int x, int y) { // Key - recebe o código ASCII da tecla
                             // x, y - recebem respectivamente as posições mouse
                             // na tela (permite tratar os dois dispositivos)
  if (key == GLUT_KEY_RIGHT) {
    rot_x += 5;
  } else if (key == GLUT_KEY_PAGE_UP) {
    rot_y += 5;
  } else if (key == GLUT_KEY_UP) {
    rot_y -= 5;
  } else if (key == GLUT_KEY_LEFT) {
    rot_x -= 5;
  } else if (key == GLUT_KEY_PAGE_DOWN) {
    rot_y -= 5;
  } else if (key == GLUT_KEY_DOWN) {
    rot_y += 5;
  }
  glutPostRedisplay();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(600, 600);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Aula 01 - OpenGL - Hello World");
  glutDisplayFunc(DISPLAY);
  glutMouseFunc(Mouse);
  glutKeyboardFunc(keyboard);
  glutSpecialFunc(TeclasEspeciais);
  glutMainLoop();
  return 0;
}
