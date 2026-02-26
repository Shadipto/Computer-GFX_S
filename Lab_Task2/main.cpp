#include <iostream>
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

const float PI = 3.14159265f;

// Draw a filled circle using the formula:
// x = p1 + r1 * cos(i * tp2 / tringle2)
// y = q1 + r1 * sin(i * tp2 / tringle2)
void drawCircle(float p1, float q1, float r1, int tringle2 = 40) {
    float tp2 = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(p1, q1); // center
    for (int i = 0; i <= tringle2; i++) {
        glVertex2f(p1 + (r1 * cos(i * tp2 / tringle2)),
                   q1 + (r1 * sin(i * tp2 / tringle2)));
    }
    glEnd();
}

// Draw a puffy cloud made of exactly 3 overlapping circles
void drawCloud(float cx, float cy, float scale) {
    glColor3f(1.0f, 1.0f, 1.0f);
    // Left circle
    drawCircle(cx - 0.10f * scale, cy - 0.01f * scale, 0.09f * scale);
    // Centre circle (tallest)
    drawCircle(cx,                  cy + 0.03f * scale, 0.12f * scale);
    // Right circle
    drawCircle(cx + 0.11f * scale, cy - 0.01f * scale, 0.09f * scale);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Sky
    glBegin(GL_QUADS);
        glColor3f(0.68f, 0.87f, 0.93f);
        glVertex2f(-1.0f, -1.0f);
        glVertex2f( 1.0f, -1.0f);
        glVertex2f( 1.0f,  1.0f);
        glVertex2f(-1.0f,  1.0f);
    glEnd();

    // Water
    glBegin(GL_QUADS);
        glColor3f(0.0f, 0.62f, 0.82f);
        glVertex2f(-1.0f, -1.0f);
        glVertex2f( 1.0f, -1.0f);
        glVertex2f( 1.0f,  0.25f);
        glVertex2f(-1.0f,  0.25f);
    glEnd();

    // Left Triangle
    glBegin(GL_TRIANGLES);
        glColor3f(0.13f, 0.65f, 0.13f);
        glVertex2f(-1.0f,  0.25f);   
        glVertex2f(-1.0f, -1.0f);   
        glVertex2f( 0.28f, -1.0f);  
    glEnd();

    // Right Triangle
    glBegin(GL_TRIANGLES);
        glColor3f(0.13f, 0.65f, 0.13f);
        glVertex2f( 0.65f,  0.25f);  
        glVertex2f( 1.0f,   0.25f);  
        glVertex2f( 1.0f,  -1.0f);  
    glEnd();

    // Mountain Triangles
    glColor3f(0.40f, 0.82f, 0.0f);

    // Left mountain
    glBegin(GL_TRIANGLES);
        glVertex2f(0.60f, 0.25f);
        glVertex2f(0.78f, 0.25f);
        glVertex2f(0.68f, 0.72f);
    glEnd();

    // Middle mountain
    glBegin(GL_TRIANGLES);
        glVertex2f(0.68f, 0.25f);
        glVertex2f(0.88f, 0.25f);
        glVertex2f(0.78f, 0.58f);
    glEnd();

    // Right mountain
    glBegin(GL_TRIANGLES);
        glVertex2f(0.82f, 0.25f);
        glVertex2f(1.00f, 0.25f);
        glVertex2f(0.95f, 0.58f);
    glEnd();

    // Sun
    glColor3f(1.0f, 0.97f, 0.0f);
    drawCircle(0.82f, 0.73f, 0.10f);

    // Clouds
    drawCloud(-0.40f, 0.72f, 1.0f);   // left cloud
    drawCloud( 0.20f, 0.73f, 1.1f);   // centre cloud

    // Boat 
    glColor3f(0.48f, 0.0f, 0.0f);

    // Cabin 
    glBegin(GL_QUADS);
        glVertex2f(-0.32f,  0.12f);
        glVertex2f( 0.08f,  0.12f);
        glVertex2f( 0.08f,  0.07f);
        glVertex2f(-0.32f,  0.07f);
    glEnd();

    // Hull (trapezoid — wider, with angled bow and stern)
    glBegin(GL_POLYGON);
        glVertex2f(-0.45f,  0.07f);  
        glVertex2f( 0.18f,  0.07f);  
        glVertex2f( 0.22f,  0.03f);  
        glVertex2f( 0.18f, -0.01f); 
        glVertex2f(-0.48f, -0.01f); 
        glVertex2f(-0.52f,  0.03f); 
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1271, 714);
    glutCreateWindow("River Scene");
    glClearColor(0.68f, 0.87f, 0.93f, 1.0f);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}