#include <GL/gl.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <math.h>
#include <stdlib.h>

// Global variables for transformations and animation
int rot_x = 0, rot_y = 0, rot_z = 0;
float pos_x = 30.0, pos_y = 0.0, pos_z = 0.0;
int shouldAnimate = 0;
int animation_step = 0;

// Function Prototypes
void reshapeScene(int width, int height);
void drawScene();
void animate(int value);
void Mouse(int botao, int estado, int x, int y);
void keyboard(unsigned char key, int x, int y);
void TeclasEspeciais(int key, int x, int y);

// Drawing function
void drawScene() {
  // 1. CLEAR THE SCREEN - This should be at the start of the drawing function.
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // sky blue
  // should darken on both ends and move to lighter in the middle
  float sky_r = fmax(0.2, 0.2 + fabs(pos_x) / 50.0);
  float sky_g = fmax(0.2, 0.2 + fabs(pos_y) / 50.0);
  float sky_b = fmax(1.0, 0.2 + fabs(pos_z) / 50.0);


  glClearColor(sky_r, sky_g, sky_b, 1.0);

  // Reset ModelView Matrix
  glLoadIdentity();

  // Set up the camera
  gluLookAt(0, 0, 40,    // Camera position (eye)
            0, 0, 0,    // Where to look at (center)
            0, 1, 0);   // Up vector

  // Apply object transformations
  glPushMatrix();
  glTranslatef(pos_x, pos_y, pos_z);
  glRotatef(rot_x, 0, 1, 0);
  glRotatef(rot_y, 1, 0, 0);
  glRotatef(rot_z, 0, 0, 1);

  // house common color 
  glColor3ub(98, 58, 0);
  glutSolidCube(10.0);

  // puxadinho

  // --- Draw the Black Wireframe Outline ---
  // This is a more efficient way to draw the outline.
  glColor3ub(0, 0, 0);
  glLineWidth(2.0); // Make the lines a bit thicker
  glutWireCube(10.05); // Draw a slightly larger wire cube

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
  glColor3ub(255, 255, 255);
  glVertex3f(-3.5, -5, 5.01);
  glVertex3f(-3.5, 2, 5.01);
  glVertex3f(-0.5, 2, 5.01);
  glVertex3f(-0.5, -5, 5.01);
  glEnd();
  glPopMatrix();


  glPushMatrix();
  glBegin(GL_QUADS);
  glColor3ub(255, 255, 255);
  glVertex3f(2, 1, 5.01);
  glVertex3f(2, 2, 5.01);
  glVertex3f(3, 2, 5.01);
  glVertex3f(3, 1, 5.01);
  glEnd();
  glPopMatrix();

  glPushMatrix();
  glBegin(GL_QUADS);
  glColor3ub(255, 255, 255);
  glVertex3f(3.2, 1, 5.01);
  glVertex3f(3.2, 2, 5.01);
  glVertex3f(4.2, 2, 5.01);
  glVertex3f(4.2, 1, 5.01);
  glEnd();
  glPopMatrix();

  glPushMatrix();
  glBegin(GL_QUADS);
  glColor3ub(255, 255, 255);
  glVertex3f(3.2, -0.2, 5.01);
  glVertex3f(3.2, 0.8, 5.01);
  glVertex3f(4.2, 0.8, 5.01);
  glVertex3f(4.2, -0.2, 5.01);
  glEnd();
  glPopMatrix();


  glPushMatrix();
  glBegin(GL_QUADS);
  glColor3ub(255, 255, 255);
  glVertex3f(2, -0.2, 5.01);
  glVertex3f(2, 0.8, 5.01);
  glVertex3f(3, 0.8, 5.01);
  glVertex3f(3, -0.2, 5.01);
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
  glTranslatef(pos_x * -2, 20, -20);
  glColor3ub(255, 215, 0);
  glutSolidSphere(1, 20, 20);
  glPopMatrix();
  glPopMatrix();

  glutSwapBuffers();
}


// Reshape function - sets up the projection and viewport
void reshapeScene(int width, int height) {
  if (height == 0) height = 1; // Prevent a divide by zero
  float ratio = 1.0 * width / height;

  // Use the Projection Matrix
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  // Set the viewport to be the entire window
  glViewport(0, 0, width, height);

  // Set the perspective
  gluPerspective(45, ratio, 1, 150);

  // Get back to the ModelView Matrix
  glMatrixMode(GL_MODELVIEW);
}

// Animation timer function
void animate(int value) {
  if (!shouldAnimate) return;

  pos_x -= 0.5; // Slowed down for better visibility
  animation_step++;

  if (animation_step > 100) { // Adjusted the limit
    shouldAnimate = 0;
    return;
  }

  // 3. LOGIC FIX - Removed the second animation_step++
  glutPostRedisplay();
  glutTimerFunc(33, animate, 0); // ~30 frames per second
}

// Mouse callback
void Mouse(int botao, int estado, int x, int y) {
  if (botao == GLUT_LEFT_BUTTON && estado == GLUT_DOWN) {
    // Reset position and rotation
    pos_y = 0;
    pos_x = 0;
    pos_z = 0;
    rot_x = 0;
    rot_y = 0;
    rot_z = 0;
    shouldAnimate = 0; // Stop animation on reset
    glutPostRedisplay();
  } else if (botao == GLUT_RIGHT_BUTTON && estado == GLUT_DOWN) {
    // Start animation
    if (!shouldAnimate) { // Prevent multiple timers
      animation_step = 0;
      shouldAnimate = 1;
      animate(0);
    }
  }
}

// Keyboard callback for regular keys
void keyboard(unsigned char key, int x, int y) {
  switch(key) {
    case 'd': pos_x += 1; break;
    case 'a': pos_x -= 1; break;
    case 'w': pos_y += 1; break;
    case 's': pos_y -= 1; break;
    case 'q': pos_z += 1; break;
    case 'e': pos_z -= 1; break;
    case 27: exit(0); break; // ESC key
  }
  glutPostRedisplay();
}

// Keyboard callback for special keys
void TeclasEspeciais(int key, int x, int y) {
  switch(key) {
    case GLUT_KEY_RIGHT: rot_x += 5; break;
    case GLUT_KEY_LEFT:  rot_x -= 5; break;
    case GLUT_KEY_UP:    rot_y -= 5; break;
    case GLUT_KEY_DOWN:  rot_y += 5; break;
  }
  glutPostRedisplay();
}

// Main function
int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(800, 600);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Fixed OpenGL Code");

  // Enable features
  glEnable(GL_DEPTH_TEST);

  // Register callbacks
  glutDisplayFunc(drawScene);       // The function to call for drawing
  glutReshapeFunc(reshapeScene);    // The function to call on window resize
  glutMouseFunc(Mouse);
  glutKeyboardFunc(keyboard);
  glutSpecialFunc(TeclasEspeciais);

  glutMainLoop();
  return 0;
}
