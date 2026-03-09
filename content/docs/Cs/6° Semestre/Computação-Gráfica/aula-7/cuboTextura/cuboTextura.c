#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

// Compatibilidade com headers antigos
#ifndef GL_CLAMP_TO_EDGE
#define GL_CLAMP_TO_EDGE GL_CLAMP
#endif

GLuint texID[6]; // IDs das 6 texturas
float angulo = 0.0f; // ângulo de rotação

const char *faces[] = {
    "face1.png",
    "face2.png",
    "face3.png",
    "face4.png",
    "face5.png",
    "face6.png"
};

void loadTexture(const char *filename, GLuint texID) {
    int w, h, channels; //w*h -> resolução da imagem, channels: n. de canais de cor
    unsigned char *data = stbi_load(filename, &w, &h, &channels, 0); //Carrega a imagem do arquivo
    if (!data) { //Verifica se imagem foi carregada corretamente
        printf("Erro ao carregar %s\n", filename);
        exit(1);
    }

  glBindTexture(GL_TEXTURE_2D, texID);//Associa a textura texid às próximas operações do OpenGL envolvendo textura

  //Efeito "esticar" textura para preencher o polígono
  /*GL_TEXTURE_WRAP_S: eixo horizontal da textura (U).
	GL_TEXTURE_WRAP_T: eixo vertical da textura (V).
	GL_CLAMP_TO_EDGE: limita a amostra da textura à borda da imagem (evita “vazamento” de pixels ao redor).*/
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    
  //Efeito "repetir" textura para preencher o polígono GL_REPEAT
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // Repetição no eixo S (horizontal)
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); // Repetição no eixo T (vertical)
    
  /*GL_TEXTURE_MIN_FILTER: quando a textura for reduzida (minificação).
	GL_TEXTURE_MAG_FILTER: quando a textura for ampliada (magnificação).
  GL_LINEAR: faz interpolação linear (suaviza os pixels, evita blocos visíveis)*/
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  GLenum format = (channels == 4) ? GL_RGBA : GL_RGB;
    
	//envia os dados da imagem para a GPU como textura 2D
	glTexImage2D(GL_TEXTURE_2D, 0, format, w, h, 0, format, GL_UNSIGNED_BYTE, data);
  stbi_image_free(data);
}

void initTextures() {
    glGenTextures(6, texID); //gera IDs únicas para texturas no OpenGL.
    for (int i = 0; i < 6; i++) {
        loadTexture(faces[i], texID[i]);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    glLoadIdentity();

    gluLookAt(3, 3, 5, 0, 0, 0, 0, 1, 0);

    glRotatef(angulo, 1.0f, 1.0f, 0.0f); // aplica rotação ao cubo

    // Frente (face1)
    glBindTexture(GL_TEXTURE_2D, texID[0]);
    glBegin(GL_QUADS);
        glTexCoord2f(0,0); glVertex3f(-1,-1, 1);
        glTexCoord2f(1,0); glVertex3f( 1,-1, 1);
        glTexCoord2f(1,1); glVertex3f( 1, 1, 1);
        glTexCoord2f(0,1); glVertex3f(-1, 1, 1);
    glEnd();

    // Trás (face2)
    glBindTexture(GL_TEXTURE_2D, texID[1]);
    glBegin(GL_QUADS);
        glTexCoord2f(0,0); glVertex3f( 1,-1,-1);
        glTexCoord2f(1,0); glVertex3f(-1,-1,-1);
        glTexCoord2f(1,1); glVertex3f(-1, 1,-1);
        glTexCoord2f(0,1); glVertex3f( 1, 1,-1);
    glEnd();

    // Direita (face3)
    glBindTexture(GL_TEXTURE_2D, texID[2]);
    glBegin(GL_QUADS);
        glTexCoord2f(0,0); glVertex3f( 1,-1, 1);
        glTexCoord2f(1,0); glVertex3f( 1,-1,-1);
        glTexCoord2f(1,1); glVertex3f( 1, 1,-1);
        glTexCoord2f(0,1); glVertex3f( 1, 1, 1);
    glEnd();

    // Esquerda (face4)
    glBindTexture(GL_TEXTURE_2D, texID[3]);
    glBegin(GL_QUADS);
        glTexCoord2f(0,0); glVertex3f(-1,-1,-1);
        glTexCoord2f(1,0); glVertex3f(-1,-1, 1);
        glTexCoord2f(1,1); glVertex3f(-1, 1, 1);
        glTexCoord2f(0,1); glVertex3f(-1, 1,-1);
    glEnd();

    // Topo (face5)
    glBindTexture(GL_TEXTURE_2D, texID[4]);
    glBegin(GL_QUADS);
        glTexCoord2f(0,0); glVertex3f(-1, 1, 1);
        glTexCoord2f(1,0); glVertex3f( 1, 1, 1);
        glTexCoord2f(1,1); glVertex3f( 1, 1,-1);
        glTexCoord2f(0,1); glVertex3f(-1, 1,-1);
    glEnd();

    // Base (face6)
    glBindTexture(GL_TEXTURE_2D, texID[5]);
    glBegin(GL_QUADS);
        glTexCoord2f(0,0); glVertex3f(-1,-1,-1);
        glTexCoord2f(1,0); glVertex3f( 1,-1,-1);
        glTexCoord2f(1,1); glVertex3f( 1,-1, 1);
        glTexCoord2f(0,1); glVertex3f(-1,-1, 1);
    glEnd();

    glutSwapBuffers();
}

// Timer para atualizar o ângulo e chamar display
void timer(int value) {
    angulo += 1.0f;       // velocidade de rotação
    if (angulo > 360.0f) angulo -= 360.0f;
    glutPostRedisplay();   // pede redraw
    glutTimerFunc(16, timer, 0); // ~60 FPS
}

void init() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glClearColor(0.3f, 0.3f, 0.3f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45, 1, 1, 100);
    glMatrixMode(GL_MODELVIEW);

    initTextures();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Dado Texturizado Girando");

    init();

    glutDisplayFunc(display);
    glutTimerFunc(16, timer, 0);

    glutMainLoop();
    return 0;
}

