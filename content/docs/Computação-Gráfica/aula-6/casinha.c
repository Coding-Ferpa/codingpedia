#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void DesenharCena();

void desenhaJanela(float z) {

  // janelas
  glPushMatrix();
  glBegin(GL_QUADS);
  glColor3ub(255, 255, 255);
  glVertex3f(2, 1, z);
  glVertex3f(2, 2, z);
  glVertex3f(3, 2, z);
  glVertex3f(3, 1, z);
  glEnd();
  glPopMatrix();

  glPushMatrix();
  glBegin(GL_QUADS);
  glColor3ub(255, 255, 255);
  glVertex3f(3.2, 1, z);
  glVertex3f(3.2, 2, z);
  glVertex3f(4.2, 2, z);
  glVertex3f(4.2, 1, z);
  glEnd();
  glPopMatrix();

  glPushMatrix();
  glBegin(GL_QUADS);
  glColor3ub(255, 255, 255);
  glVertex3f(3.2, -0.2, z);
  glVertex3f(3.2, 0.8, z);
  glVertex3f(4.2, 0.8, z);
  glVertex3f(4.2, -0.2, z);
  glEnd();
  glPopMatrix();

  glPushMatrix();
  glBegin(GL_QUADS);
  glColor3ub(255, 255, 255);
  glVertex3f(2, -0.2, z);
  glVertex3f(2, 0.8, z);
  glVertex3f(3, 0.8, z);
  glVertex3f(3, -0.2, z);
  glEnd();
  glPopMatrix();
}

float time_of_day = 0;
// Declaração de Variáveis Globis
int projecao = 0; // Variável Lógica para Definir o Tipo de Projeção
                  // (Perspectiva ou Ortogonal)
float posx = 0, posy = 20,
      posz = 50;               // Variáveis que definem a posição da câmera
float oy = 30, ox = 0, oz = 0; // Variáveis que definem para onde a câmera olha
int lx = 0, ly = 1, lz = 0;    // Variáveis que definem o eixo da câmera

GLfloat angulox = 0.0;
GLfloat anguloy = 0.0;

int x_temp = -1; // Armazena posição X do ponteiro do mouse
int y_temp = -1; // Armazena posição Y do ponteiro do mouse
int rotacao = 0; // Controla eixo de rotação do mouse
int i;           // controle do for

float rotacao_porta;
bool is_open;

void stroke_output(GLfloat x, GLfloat y, char *format,
                   ...) // função para escrever em 3d
{
  va_list args;
  char buffer[200], *p;
  va_start(args, format);
  vsprintf(buffer, format, args);
  va_end(args);
  glPushMatrix();
  glScalef(0.05, 0.05, 0.05);
  for (p = buffer; *p; p++)
    glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
  glPopMatrix();
}

// Inicializa parâmetros de rendering
void Inicializa(void) {
  // Define a cor de fundo da janela de visualização como preta
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_SMOOTH);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glutWarpPointer(400, 300);
  glutSetCursor(GLUT_CURSOR_NONE);
}

void drawHouse(int x, int y, int z, int size) {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // sky blue
  // should darken on both ends and move to lighter in the middle
  float sky_r = fmin(0.8 + 0.6 * cos(time_of_day - M_2_PI / 2), 0.4);
  float sky_g = fmin(0.8 + 0.4 * cos(time_of_day - M_2_PI / 2), 0.7);
  float sky_b = fmin(1.0 + 0.1 * cos(time_of_day - M_2_PI / 2), 0.9);

  glClearColor(sky_r, sky_g, sky_b, 1.0);

  // house
  glPushMatrix();
  glColor3ub(0, 0, 0);
  glLineWidth(4.0);    // Make the lines a bit thicker
  glutWireCube(10.05); // Draw a slightly larger wire cube

  // porta
  glPushMatrix();
  glTranslatef(-3.5, -5.0, 5.0);
  glRotatef(rotacao_porta, 0, 1, 0);
  glTranslatef(3.5, 5.0, -5.0);

  glBegin(GL_QUADS);
  glColor3ub(255, 255, 255);
  glVertex3f(-3.5, -5, 5);
  glVertex3f(-3.5, 2, 5);
  glVertex3f(-0.5, 2, 5);
  glVertex3f(-0.5, -5, 5);
  glEnd();

  // macaneta
  glPushMatrix();
  glColor3ub(33, 33, 33);
  glTranslatef(-1, -0.5, 5);
  glScalef(1, 1, .5);
  glutSolidSphere(0.1, 20, 20);
  glPopMatrix();
  glPopMatrix();

  glColor3ub(88, 54, 0);
  glBegin(GL_QUADS);
  glVertex3f(-5, -5, 5);
  glVertex3f(-3.5, -5, 5);
  glVertex3f(-3.5, 5, 5);
  glVertex3f(-5, 5, 5);
  glEnd();

  glColor3ub(88, 54, 0);
  glBegin(GL_QUADS);
  glVertex3f(-3.5, 2, 5);
  glVertex3f(-3.5, 5, 5);
  glVertex3f(-0.5, 5, 5);
  glVertex3f(-0.5, 2, 5);
  glEnd();

  glColor3ub(88, 54, 0);
  glBegin(GL_QUADS);
  glVertex3f(-0.5, 5, 5);
  glVertex3f(-0.5, -5, 5);
  glVertex3f(5, -5, 5);
  glVertex3f(5, 5, 5);
  glEnd();

  glColor3ub(98, 58, 0);
  glBegin(GL_QUADS);
  glVertex3f(-5, -5, -5);
  glVertex3f(5, -5, -5);
  glVertex3f(5, 5, -5);
  glVertex3f(-5, 5, -5);
  glEnd();

  glColor3ub(98, 58, 0);
  glBegin(GL_QUADS);
  glVertex3f(5, 5, 5);
  glVertex3f(5, -5, 5);
  glVertex3f(5, -5, -5);
  glVertex3f(5, 5, -5);
  glEnd();

  glBegin(GL_QUADS);
  glVertex3f(-5, 5, 5);
  glVertex3f(-5, -5, 5);
  glVertex3f(-5, -5, -5);
  glVertex3f(-5, 5, -5);
  glEnd();
  glPopMatrix();

  if (time_of_day < 180) {
    // shadow
    glPushMatrix();
    glColor4ub(0, 0, 0, 200);

    glBegin(GL_TRIANGLES);
    glVertex3f(5, -5.001, 0);
    glVertex3f(-5, -5.001, 0);
    glVertex3f(time_of_day * 10, -5.001, 50);
    glEnd();
    glPopMatrix();
  }

  // teto
  glPushMatrix();
  glBegin(GL_TRIANGLES);
  glColor3ub(0, 255, 0);
  glVertex3f(-5, 5, 5);
  glVertex3f(5, 5, 5);
  glVertex3f(0, 10, 0);
  glEnd();
  glPopMatrix();

  glPushMatrix();
  glBegin(GL_TRIANGLES);
  glColor3ub(0, 255, 0);
  glVertex3f(5, 5, -5);
  glVertex3f(5, 5, 5);
  glVertex3f(0, 10, 0);
  glEnd();
  glPopMatrix();

  glPushMatrix();
  glBegin(GL_TRIANGLES);
  glColor3ub(0, 255, 0);
  glVertex3f(-5, 5, -5);
  glVertex3f(-5, 5, 5);
  glVertex3f(0, 10, 0);
  glEnd();
  glPopMatrix();

  glPushMatrix();
  glBegin(GL_TRIANGLES);
  glColor3ub(0, 255, 0);
  glVertex3f(-5, 5, -5);
  glVertex3f(5, 5, -5);
  glVertex3f(0, 10, 0);
  glEnd();
  glPopMatrix();

  glPushMatrix();
  glBegin(GL_QUADS);
  // ground
  glColor3ub(34, 139, 34);
  glVertex3f(-50, -5.01, 50);
  glVertex3f(50, -5.01, 50);
  glVertex3f(50, -5.01, -50);
  glVertex3f(-50, -5.01, -50);
  glEnd();
  glPopMatrix();

  glPushMatrix();
  // sun
  glTranslatef(200 * sin(time_of_day), 200 * cos(time_of_day), -200);
  glColor3ub(255, 215, 0);
  glutSolidSphere(10, 20, 20);
  glPopMatrix();
  // janela
  desenhaJanela(5.01);
  desenhaJanela(4.99);
  glPopMatrix();
}

void DISPLAY(void) {
  glMatrixMode(GL_PROJECTION); /*glMatrixMode()- define qual matriz será
                             alterada. SEMPRE defina o tipo de apresentação
                             (Ortogonal ou Perspectiva) na matriz PROJECTION.*/
  glLoadIdentity(); //"Limpa" ou "transforma" a matriz em identidade, reduzindo
                    //possíveis erros.
  if (projecao == 1) {
    glOrtho(-200, 200, -200, 200, -200, 200); // Define a projeção como
                                              // ortogonal
    if (rotacao = 1)
      glRotatef(angulox, 1.0, 0.0, 0.0);
    if (rotacao = 2)
      glRotatef(anguloy, 0.0, 1.0, 0.0);
  }
  if (projecao == 0) {
    gluPerspective(90, 1, 1, 500); // Define a projeção como perspectiva
    if (rotacao = 1)
      glRotatef(angulox, 1.0, 0.0, 0.0);
    if (rotacao = 2)
      glRotatef(anguloy, 0.0, 1.0, 0.0);
  }

  glMatrixMode(
      GL_MODELVIEW); /*glMatrixMode()- define qual matriz será alterada. SEMPRE
                    defina a câmera (Ortogonal ou Perspectiva) na matriz
                    MODELVIEW (onde o desenho ocorrerá).*/
  glLoadIdentity();  ////"Limpa" ou "transforma" a matriz em identidade,
                     ///reduzindo possíveis erros.

  glClear(
      GL_COLOR_BUFFER_BIT |
      GL_DEPTH_BUFFER_BIT); /* "limpa" um buffer particular ou combinações de
                            buffers, onde buffer é uma área de armazenamento
                            para informações da imagem. Nesse caso, está
                            "limpando os buffers para suportarem animações */
  time_of_day = (time_of_day + 0.01);
  if (time_of_day == 360 ) time_of_day = 0;
  DesenharCena();
  glutSwapBuffers();
  glutPostRedisplay();
}

void DesenharCena() {
  /*Crosta Terrestre*/
  glColor3ub(100, 200, 0);
  glPushMatrix();
  glTranslatef(0, -0.02, 0);
  glScalef(60, 0.01, 60);
  glutSolidCube(20);
  glPopMatrix();
  /******/

  gluLookAt(posx, posy, posz, ox, oy, oz, lx, ly, lz);
  /*TEXTO Exemplo*/
  glColor3ub(0, 0, 0);
  glPushMatrix();
  glTranslatef(-35, 41, 40.2);
  stroke_output(0, 0, "CASA");
  glPopMatrix();

  glPushMatrix();

  drawHouse(0, 0, 0, 10);
  glPopMatrix();
}

void MOUSE_Button(int botao, int estado, int x, int y) {
  // botão - recebe o código do botão pressionado
  // estado - recebe se está pressionado ou não
  // x, y - recebem respectivamente as posições do cursor do mouse
  switch (botao) {
  case GLUT_LEFT_BUTTON:
    if (estado == GLUT_DOWN) {
      projecao = 1;
      posx = 0;
      posy = 0;
      posz = 20;
      ox = 0, oy = 0, oz = 0;
      lx = 0, ly = 1, lz = 0;
      glutPostRedisplay();
    }
    break;

  case GLUT_RIGHT_BUTTON:
    if (estado == GLUT_DOWN) {
      projecao = 0;
      posx = 0;
      posy = 30;
      posz = 200;
      oy = 30;
      ox = 0;
      oz = 0;
      lx = 0, ly = 1, lz = 0;
      glutPostRedisplay();
    }
    break;
  }
}

void MOUSE(int x, int y) {
  if (x > x_temp) {
    anguloy = anguloy + (x / 100.0);
    if (anguloy > 360.0)
      anguloy = anguloy - 360;
    rotacao = 2;
    glutPostRedisplay();
  }
  if (x < x_temp) {
    anguloy = anguloy - (x / 100.0);
    if (anguloy > 360.0)
      anguloy = anguloy - 360;
    rotacao = 2;
    glutPostRedisplay();
  }
  x_temp = x;
  if (y > y_temp) {
    angulox = angulox + (y / 100.0);
    if (angulox > 360.0)
      angulox = angulox - 360;
    rotacao = 1;
    glutPostRedisplay();
  }
  if (y < y_temp) {
    angulox = angulox - (y / 100.0);
    if (angulox > 360.0)
      angulox = angulox - 360;
    rotacao = 1;
    glutPostRedisplay();
  }
  y_temp = y;
  if (x >= 500 || x <= 300 || y >= 400 ||
      y <= 200) // delimitar uma area de acesso ao mouse de 600x450
  {
    glutWarpPointer(400, 300);
    glutPostRedisplay();
  }
}

void keyboard(unsigned char tecla, int x, int y) {
  switch (tecla) {
  case 's':
    posx = posx + (5 * cos((anguloy + 90) / 57.32));
    posz = posz + (5 * sin((anguloy + 90) / 57.32));
    ox = ox + (5 * cos((anguloy + 90) / 57.32));
    oz = oz + (5 * sin((anguloy + 90) / 57.32));
    glutPostRedisplay();
    break;

  case 'w':
    posx = posx - (5 * cos((anguloy + 90) / 57.32));
    posz = posz - (5 * sin((anguloy + 90) / 57.32));
    ox = ox - (5 * cos((anguloy + 90) / 57.32));
    oz = oz - (5 * sin((anguloy + 90) / 57.32));
    glutPostRedisplay();
    break;

  case 'd':
    posx = posx + (5 * sin((anguloy + 90) / 57.32));
    posz = posz - (5 * cos((anguloy + 90) / 57.32));
    ox = ox + (5 * sin((anguloy + 90) / 57.32));
    oz = oz - (5 * cos((anguloy + 90) / 57.32));
    glutPostRedisplay();
    break;

  case 'a':
    posx = posx - (5 * sin((anguloy + 90) / 57.32));
    posz = posz + (5 * cos((anguloy + 90) / 57.32));
    ox = ox - (5 * sin((anguloy + 90) / 57.32));
    oz = oz + (5 * cos((anguloy + 90) / 57.32));
    glutPostRedisplay();
    break;
  case 'e':
    if (posx < 10 && posx > -10 && posy < 10 && posy > -10 && posz < 10 &&
        posz > -10) {
      if (!is_open) {
        rotacao_porta -= 1;
        if (rotacao_porta == -90)
          is_open = true;
      } else {
        rotacao_porta += 1;
        if (rotacao_porta == 0)
          is_open = false;
      }
    }
    break;
  case 27:
    exit(0);
    break;
  default:
    break;
  }
}

void TeclasEspeciais(int key, int x, int y) {
  // Key - recebe o código ASCII da tecla
  // x, y - recebem respectivamente as posições do cursor do mouse (permite
  // tratar os dois dispositivos)
  if (key == GLUT_KEY_PAGE_UP) {
    posy += 5;
    oy += 5;
  } else if (key == GLUT_KEY_PAGE_DOWN) {
    posy -= 5;
    oy -= 5;
  }
  glutPostRedisplay();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_STENCIL);
  glutInitWindowSize(800, 600);
  glutInitWindowPosition(10, 10);
  glutCreateWindow("Aula 07");
  Inicializa();
  glutDisplayFunc(DISPLAY);
  glutKeyboardFunc(keyboard);
  glutMouseFunc(MOUSE_Button);
  glutPassiveMotionFunc(MOUSE);
  glutSpecialFunc(TeclasEspeciais);
  glutMainLoop();
  return 0;
}
