#include <GL/glut.h>
#include <process.h>
#include <iostream>

GLfloat rectSize = 50.0f; 
GLfloat rectPosX = 0.0f;    
GLfloat rectPosY = 0.0f;    
GLfloat rectRed = 1.0f, rectGreen = 1.0f, rectBlue = 1.0f; 

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    
    glColor3f(rectRed, rectGreen, rectBlue);
    glRectf(rectPosX - rectSize / 2, rectPosY - rectSize / 2, rectPosX + rectSize / 2, rectPosY + rectSize / 2);

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
    case 1: // Red
        rectRed = 1.0f;
        rectGreen = 0.0f;
        rectBlue = 0.0f;
        break;
    case 2: // Green
        rectRed = 0.0f;
        rectGreen = 1.0f;
        rectBlue = 0.0f;
        break;
    case 3: // Blue
        rectRed = 0.0f;
        rectGreen = 0.0f;
        rectBlue = 1.0f;
        break;
    case 4: // Exit
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
        if (rectPosX - rectSize / 2 > 0)
            rectPosX -= std::min(10.0f, rectSize / 2);
        break;
    case GLUT_KEY_RIGHT:
        if (rectPosX + rectSize / 2 < windowWidth)
            rectPosX += std::min(10.0f, windowWidth - rectPosX - rectSize / 2);
        break;
    case GLUT_KEY_UP:
        if (rectPosY + rectSize / 2 < windowHeight)
            rectPosY += std::min(10.0f, windowHeight - rectPosY - rectSize / 2);
        break;
    case GLUT_KEY_DOWN:
        if (rectPosY - rectSize / 2 > 0)
            rectPosY -= std::min(10.0f, rectPosY - rectSize / 2);
        break;
    }
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case '1': 
        rectSize *= 0.9f;
        break;
    case '2': 
        rectSize *= 1.1f;
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
    glutCreateWindow("OpenGL Rectangle Program");

    glClearColor(0.5f, 0.5f, 0.5f, 1.0f); // Grey background

    
    rectPosX = glutGet(GLUT_WINDOW_WIDTH) / 2.0f;
    rectPosY = glutGet(GLUT_WINDOW_HEIGHT) / 2.0f;

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(specialKeys);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);

    glutMainLoop();

    return 0;
}
