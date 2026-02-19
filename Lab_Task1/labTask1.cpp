#include <iostream>
#include <cstdio>
#include <cmath>

#ifdef __APPLE__
    #include <OpenGL/gl.h>
    #include <GLUT/glut.h>
#elif defined(_WIN32) || defined(_WIN64)
    #include <windows.h>
    #include <GL/gl.h>
    #include <GL/glut.h>
#else
    #include <GL/gl.h>
    #include <GL/glut.h>
#endif

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Sky
    glBegin(GL_QUADS);
        glColor3f(0.13f, 0.65f, 0.13f); // Green
        glVertex2f(-1.0f,  0.24f);
        glVertex2f( 1.0f,  0.24f);
        glVertex2f( 1.0f,  1.00f);
        glVertex2f(-1.0f,  1.00f);
    glEnd();

    // Road
    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 0.0f); // Black
        glVertex2f(-1.0f,  0.08f);
        glVertex2f( 1.0f,  0.08f);
        glVertex2f( 1.0f,  0.24f);
        glVertex2f(-1.0f,  0.24f);
    glEnd();

    // Water
    glBegin(GL_QUADS);
        glColor3f(0.27f, 0.63f, 0.87f); // Blue
        glVertex2f(-1.0f, -1.00f);
        glVertex2f( 1.0f, -1.00f);
        glVertex2f( 1.0f,  0.08f);
        glVertex2f(-1.0f,  0.08f);
    glEnd();

    // Triangle
    glBegin(GL_TRIANGLES);
        glColor3f(0.80f, 0.0f, 0.0f); // Red
        glVertex2f( 0.52f,  0.90f);   
        glVertex2f( 0.18f,  0.24f);   
        glVertex2f( 0.88f,  0.24f);   
    glEnd();

    // Boat
    glBegin(GL_QUADS);
        glColor3f(1.0f, 0.55f, 0.0f); // Orange
        glVertex2f(-0.55f, -0.55f);   
        glVertex2f( 0.52f, -0.55f);   
        glVertex2f( 0.35f, -0.78f);   
        glVertex2f(-0.38f, -0.78f);   
    glEnd();

    // Outline
    glLineWidth(2.5f);
    glBegin(GL_LINE_LOOP);
        glColor3f(0.45f, 0.22f, 0.05f); // Brown
        glVertex2f(-0.55f, -0.55f);
        glVertex2f( 0.52f, -0.55f);
        glVertex2f( 0.35f, -0.78f);
        glVertex2f(-0.38f, -0.78f);
    glEnd();

    // Pole
    glBegin(GL_QUADS);
        glColor3f(0.55f, 0.27f, 0.07f); // Dark Brown
        glVertex2f(-0.24f, -0.55f);   
        glVertex2f(-0.17f, -0.55f);  
        glVertex2f(-0.17f,  0.06f);   
        glVertex2f(-0.24f,  0.06f);   
    glEnd();

    // Sail
    glBegin(GL_TRIANGLES);
        glColor3f(0.0f, 0.75f, 0.0f); // Green
        glVertex2f(-0.17f,  0.04f);   
        glVertex2f(-0.17f, -0.55f);   
        glVertex2f( 0.50f, -0.55f);   
    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Lab Task 1");
    glClearColor(0.27f, 0.63f, 0.87f, 1.0f);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}