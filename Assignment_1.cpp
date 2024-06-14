// In this code  i draw the Palestinian flag with the text "Free Palestine"
#include <GL/glut.h>

void drawTriangle() {
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0); 
    glVertex2f(0.0, 0.0);
    glVertex2f(0.5, -0.5);
    glVertex2f(0.0, -0.5);
    glEnd();
}

void drawPolygon(GLfloat xmin, GLfloat xmax, GLfloat ymin, GLfloat ymax, GLfloat r, GLfloat g, GLfloat b) {
    glBegin(GL_QUADS);
    glColor3f(r, g, b);
    glVertex2f(xmin, ymin);
    glVertex2f(xmax, ymin);
    glVertex2f(xmax, ymax);
    glVertex2f(xmin, ymax);
    glEnd();
}

void display() {
    glClearColor(0.2f, 0.2f, 0.2f, 0.0f);  
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glOrtho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);

    GLfloat middleX = 0.0;
    GLfloat middleY = -0.25;

    drawPolygon(-0.5 + middleX, 0.5 + middleX, 0.25 + middleY, 0.75 + middleY, 0.0, 0.6, 0.0);

    drawPolygon(-0.5 + middleX, 0.5 + middleX, 0.42 + middleY, 0.25 + middleY, 1.0, 1.0, 1.0);

    drawPolygon(-0.5 + middleX, 0.5 + middleX, 0.25 + middleY, 0.08 + middleY, 0.0, 0.0, 0.0);

    drawTriangle();

    char str[] = "Free Palestine!";
    print_text(-0.2, -0.8, str);

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Palestinian Flag");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
