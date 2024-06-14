// This code creates an interactive OpenGL program that displays a textured rotating cube.
#include <GL/glut.h>
#include <iostream>
#include <cstdlib>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

const int windowWidth = 800;
const int windowHeight = 600;

GLuint textureID;
GLfloat cubeVertices[] = {
    -1.0f, -1.0f, 1.0f, 0.0f, 0.0f,
    1.0f, -1.0f, 1.0f, 1.0f, 0.0f,
    1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f, 0.0f, 1.0f,

    -1.0f, -1.0f, -1.0f, 0.0f, 0.0f,
    -1.0f, 1.0f, -1.0f, 0.0f, 1.0f,
    1.0f, 1.0f, -1.0f, 1.0f, 1.0f,
    1.0f, -1.0f, -1.0f, 1.0f, 0.0f,

    -1.0f, 1.0f, -1.0f, 0.0f, 0.0f,
    -1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
    1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
    1.0f, 1.0f, -1.0f, 1.0f, 0.0f,

    -1.0f, -1.0f, -1.0f, 0.0f, 0.0f,
    -1.0f, -1.0f, 1.0f, 0.0f, 1.0f,
    1.0f, -1.0f, 1.0f, 1.0f, 1.0f,
    1.0f, -1.0f, -1.0f, 1.0f, 0.0f,

    1.0f, -1.0f, -1.0f, 0.0f, 0.0f,
    1.0f, 1.0f, -1.0f, 0.0f, 1.0f,
    1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
    1.0f, -1.0f, 1.0f, 1.0f, 0.0f,

    -1.0f, -1.0f, -1.0f, 0.0f, 0.0f,
    -1.0f, -1.0f, 1.0f, 0.0f, 1.0f,
    -1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f, -1.0f, 1.0f, 0.0f,
};

void setupWindow(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Textured Cube");
}

void loadTextureData(const char* filename) {
    std::string imagePath = std::string("texture.jpg");

    int width, height, channels;
    unsigned char* image = stbi_load(imagePath.c_str(), &width, &height, &channels, STBI_rgb);

    if (!image) {
        std::cerr << "Failed to load texture: " << stbi_failure_reason() << std::endl;
        exit(EXIT_FAILURE);
    }

    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    stbi_image_free(image);
}

void createTexturedCube() {
    glBegin(GL_QUADS);

    glTexCoord2f(cubeVertices[0], cubeVertices[1]);
    glVertex3f(cubeVertices[0], cubeVertices[1], cubeVertices[2]);

    glTexCoord2f(cubeVertices[5], cubeVertices[6]);
    glVertex3f(cubeVertices[5], cubeVertices[6], cubeVertices[7]);

    glTexCoord2f(cubeVertices[10], cubeVertices[11]);
    glVertex3f(cubeVertices[10], cubeVertices[11], cubeVertices[12]);

    glTexCoord2f(cubeVertices[15], cubeVertices[16]);
    glVertex3f(cubeVertices[15], cubeVertices[16], cubeVertices[17]);

    glTexCoord2f(cubeVertices[20], cubeVertices[21]);
    glVertex3f(cubeVertices[20], cubeVertices[21], cubeVertices[22]);

    glTexCoord2f(cubeVertices[25], cubeVertices[26]);
    glVertex3f(cubeVertices[25], cubeVertices[26], cubeVertices[27]);

    glTexCoord2f(cubeVertices[30], cubeVertices[31]);
    glVertex3f(cubeVertices[30], cubeVertices[31], cubeVertices[32]);

    glTexCoord2f(cubeVertices[35], cubeVertices[36]);
    glVertex3f(cubeVertices[35], cubeVertices[36], cubeVertices[37]);

    glTexCoord2f(cubeVertices[40], cubeVertices[41]);
    glVertex3f(cubeVertices[40], cubeVertices[41], cubeVertices[42]);

    glTexCoord2f(cubeVertices[45], cubeVertices[46]);
    glVertex3f(cubeVertices[45], cubeVertices[46], cubeVertices[47]);

    glTexCoord2f(cubeVertices[50], cubeVertices[51]);
    glVertex3f(cubeVertices[50], cubeVertices[51], cubeVertices[52]);

    glTexCoord2f(cubeVertices[55], cubeVertices[56]);
    glVertex3f(cubeVertices[55], cubeVertices[56], cubeVertices[57]);

    glTexCoord2f(cubeVertices[60], cubeVertices[61]);
    glVertex3f(cubeVertices[60], cubeVertices[61], cubeVertices[62]);

    glTexCoord2f(cubeVertices[65], cubeVertices[66]);
    glVertex3f(cubeVertices[65], cubeVertices[66], cubeVertices[67]);

    glTexCoord2f(cubeVertices[70], cubeVertices[71]);
    glVertex3f(cubeVertices[70], cubeVertices[71], cubeVertices[72]);

    glTexCoord2f(cubeVertices[75], cubeVertices[76]);
    glVertex3f(cubeVertices[75], cubeVertices[76], cubeVertices[77]);

    glTexCoord2f(cubeVertices[80], cubeVertices[81]);
    glVertex3f(cubeVertices[80], cubeVertices[81], cubeVertices[82]);

    glTexCoord2f(cubeVertices[85], cubeVertices[86]);
    glVertex3f(cubeVertices[85], cubeVertices[86], cubeVertices[87]);

    glTexCoord2f(cubeVertices[90], cubeVertices[91]);
    glVertex3f(cubeVertices[90], cubeVertices[91], cubeVertices[92]);

    glTexCoord2f(cubeVertices[95], cubeVertices[96]);
    glVertex3f(cubeVertices[95], cubeVertices[96], cubeVertices[97]);

    glTexCoord2f(cubeVertices[100], cubeVertices[101]);
    glVertex3f(cubeVertices[100], cubeVertices[101], cubeVertices[102]);

    glTexCoord2f(cubeVertices[105], cubeVertices[106]);
    glVertex3f(cubeVertices[105], cubeVertices[106], cubeVertices[107]);

    glTexCoord2f(cubeVertices[110], cubeVertices[111]);
    glVertex3f(cubeVertices[110], cubeVertices[111], cubeVertices[112]);

    glTexCoord2f(cubeVertices[115], cubeVertices[116]);
    glVertex3f(cubeVertices[115], cubeVertices[116], cubeVertices[117]);

    glEnd();
}

void applyTextureToCube() {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, textureID);
}

void renderCube() {
    glLoadIdentity();

    applyTextureToCube();

    createTexturedCube();
}

void animateCube() {
    static float angle = 0.0f;

    angle += 1.0f;

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -5.0f);
    glRotatef(angle, 1.0f, 1.0f, 0.0f);

    glMatrixMode(GL_MODELVIEW);

    glutPostRedisplay();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    applyTextureToCube();
    createTexturedCube();
    renderCube();
    animateCube();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    setupWindow(argc, argv);
    loadTextureData("texture.jpg");

    glutDisplayFunc(display);
    glutIdleFunc([]() {
        glutPostRedisplay();
        });

    glutMainLoop();
    return 0;
}
