// This code creates an interactive OpenGL program that displays and controls a colored square.
// Use arrow keys to move the square up, down, left, or right. Use '+' to increase its size and '-' to decrease its size.
#include <GL/glut.h>
#include <cstdlib>
#include <iostream>

GLfloat squareDimension = 50.0f;
GLfloat squarePosX = 0.0f;
GLfloat squarePosY = 0.0f;
GLfloat colorRed = 1.0f, colorGreen = 1.0f, colorBlue = 1.0f;

void displaySquare() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the square
    glColor3f(colorRed, colorGreen, colorBlue);
    glRectf(squarePosX - squareDimension / 2, squarePosY - squareDimension / 2, squarePosX + squareDimension / 2, squarePosY + squareDimension / 2);

    glutSwapBuffers();
}

void reshapeWindow(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);
    glMatrixMode(GL_MODELVIEW);
}

void setMenu(int value) {
    switch (value) {
    case 1: colorRed = 1.0f; colorGreen = 0.0f; colorBlue = 0.0f; break; // Red
    case 2: colorRed = 0.0f; colorGreen = 1.0f; colorBlue = 0.0f; break; // Green
    case 3: colorRed = 0.0f; colorGreen = 0.0f; colorBlue = 1.0f; break; // Blue
    case 4: exit(0); break; // Exit
    }
    glutPostRedisplay();
}

void handleSpecialKeys(int key, int x, int y) {
    int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
    int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);

    switch (key) {
    case GLUT_KEY_LEFT:
        if (squarePosX - squareDimension / 2 > 0)
            squarePosX -= std::min(10.0f, squareDimension / 2);
        break;
    case GLUT_KEY_RIGHT:
        if (squarePosX + squareDimension / 2 < windowWidth)
            squarePosX += std::min(10.0f, windowWidth - squarePosX - squareDimension / 2);
        break;
    case GLUT_KEY_UP:
        if (squarePosY + squareDimension / 2 < windowHeight)
            squarePosY += std::min(10.0f, windowHeight - squarePosY - squareDimension / 2);
        break;
    case GLUT_KEY_DOWN:
        if (squarePosY - squareDimension / 2 > 0)
            squarePosY -= std::min(10.0f, squarePosY - squareDimension / 2);
        break;
    }
    glutPostRedisplay();
}

void handleKeyboard(unsigned char key, int x, int y) {
    switch (key) {
    case '1': squareDimension *= 0.9f; break; // Scale down
    case '2': squareDimension *= 1.1f; break; // Scale up
    }
    glutPostRedisplay();
}

void handleMouse(int button, int state, int x, int y) {
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        glutCreateMenu(setMenu);
        glutAddMenuEntry("Red", 1);
        glutAddMenuEntry("Green", 2);
        glutAddMenuEntry("Blue", 3);
        glutAddMenuEntry("Exit", 4);
        glutAttachMenu(GLUT_RIGHT_BUTTON);
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("OpenGL Square Program");

    glClearColor(0.5f, 0.5f, 0.5f, 1.0f); // Grey background

    // Set initial position of the square to the center of the window
    squarePosX = glutGet(GLUT_WINDOW_WIDTH) / 2.0f;
    squarePosY = glutGet(GLUT_WINDOW_HEIGHT) / 2.0f;

    glutDisplayFunc(displaySquare);
    glutReshapeFunc(reshapeWindow);
    glutSpecialFunc(handleSpecialKeys);
    glutKeyboardFunc(handleKeyboard);
    glutMouseFunc(handleMouse);

    glutMainLoop();

    return 0;
}
