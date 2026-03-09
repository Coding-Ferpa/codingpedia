#include <GL/glut.h>
#include <GL/glu.h>
//#include <circle/circle.h>
#define Inteiro(x)  ((x) >=0.0 ? (int)floor((x)+0.5) : (int)ceil((x)-0.5))
// Função callback chamada para fazer o desenho
void Desenha()
{
   float ang;
   
//   glScalef(3, 3, 0); //aumenta o tamanho da casa
	//Define uma casinha composta por um quadrado e um triângulo.
   glColor3f(0,0,1); //Define cor como azul
   glBegin(GL_QUADS); //quadrado
      glVertex2f(-15,-15);
      glVertex2f(-15, 5);
      glVertex2f( 15, 5);
      glVertex2f( 15,-15);
   glEnd();

   glColor3f(1,1,1); //Altera cor para branca
   glBegin(GL_QUADS); //desenha a porta da casa
      glVertex2f(-4,-14.5);
      glVertex2f(-4, 0);
      glVertex2f( 4,0);
      glVertex2f( 4,-14.5);
      glVertex2f( 7,-5);
      glVertex2f( 7,-1);
      glVertex2f( 13,-1);
      glVertex2f( 13,-5);
   glEnd();
	//Define a cor como azul
   glColor3f(0,0,1); 
   glBegin(GL_LINES); //define as linhas da janela
      glVertex2f(7,  -3);
      glVertex2f(13, -3);
      glVertex2f(10, -1);
      glVertex2f(10, -5);
   glEnd();

	//Define a cor como vermelha
   glColor3f(0,1,0); 
   glBegin(GL_TRIANGLES); //define as linhas da janela
      glVertex2f(-15, 5);
      glVertex2f(0, 17);
      glVertex2f(15, 5);
   glEnd();
 glutSwapBuffers(); 
}

// Inicializa parâmetros de rendering
void DISPLAY (int x, int y)
{   //x é largura e y é altura (Janela)   
    // Define a cor de fundo da janela de visualização
    glClearColor(0.9, 0.9, 0.4, 0);
    if (y==0) y=1; //Evita divisão por zero
    if (x==0) x=1; //Evita divisão por zero
    glViewport(0,0,x,y); 

    glMatrixMode(GL_PROJECTION); //Ativa matriz de projeção
    glLoadIdentity(); //Define a matriz de Projeção como identidade.
    if (x>=y) //largura maior que altura
      glOrtho(-100*(x/y), 100*(x/y), -100*(x/y), 100*(x/y), -100*(x/y), 100*(x/y)); //Define o volume com base no tamanho da janela
    else //altura aumentada
      glOrtho(-100*(y/x), 100*(y/x), -100*(y/x), 100*(y/x), -100*(y/x), 100*(y/x)); //Define o volume com base no tamanho da janela*/
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity(); //Define a matriz de Visualização como identidade.
    glClear(GL_COLOR_BUFFER_BIT); 
}

// Programa Principal 
int main(int argc,char **argv)
{
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(200,200);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Aula 07 - ViewPort");
	glutReshapeFunc(DISPLAY);
	glutDisplayFunc(Desenha);
	glutMainLoop();
    return(0);
}
