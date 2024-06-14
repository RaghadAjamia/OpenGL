#include <GL/glut.h>
#include <process.h>
#include <iostream>

GLfloat squareSize = 25.0f;
GLfloat squareX = 0.0f;
GLfloat squareY = 0.0f;
GLfloat red = 1.0f, green = 1.0f, blue = 1.0f;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(red, green, blue);
    glRectf(squareX - squareSize / 2, squareY - squareSize / 2, squareX + squareSize / 2, squareY + squareSize / 2);

    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);
    glMatrixMode(GL_MODELVIEW);
}

void menu(int value) {
    switch (value) {
    case 1:
        red = 1.0f;
        green = 0.0f;
        blue = 0.0f;
        break;
    case 2:
        red = 0.0f;
        green = 1.0f;
        blue = 0.0f;
        break;
    case 3:
        red = 0.0f;
        green = 0.0f;
        blue = 1.0f;
        break;
    case 4:
        exit(0);
        break;
    }
    glutPostRedisplay();
}

void specialKeys(int key, int x, int y) {
    int windowWidth = glutGet(GLUT_WINDOW_WIDTH);
    int windowHeight = glutGet(GLUT_WINDOW_HEIGHT);

    switch (key) {
    case GLUT_KEY_LEFT:
        if (squareX - squareSize / 2 > 0)
            squareX -= std::min(10.0f, squareSize / 2);
        break;
    case GLUT_KEY_RIGHT:
        if (squareX + squareSize / 2 < windowWidth)
            squareX += std::min(10.0f, windowWidth - squareX - squareSize / 2);
        break;
    case GLUT_KEY_UP:
        if (squareY + squareSize / 2 < windowHeight)
            squareY += std::min(10.0f, windowHeight - squareY - squareSize / 2);
        break;
    case GLUT_KEY_DOWN:
        if (squareY - squareSize / 2 > 0)
            squareY -= std::min(10.0f, squareY - squareSize / 2);
        break;
    }
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case '1':
        squareSize *= 0.9f;
        break;
    case '2':
        squareSize *= 1.1f;
        break;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        glutCreateMenu(menu);
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

    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

    squareX = glutGet(GLUT_WINDOW_WIDTH) / 2.0f;
    squareY = glutGet(GLUT_WINDOW_HEIGHT) / 2.0f;

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(specialKeys);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);

    glutMainLoop();

    return 0;
}