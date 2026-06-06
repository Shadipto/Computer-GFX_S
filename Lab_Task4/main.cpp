#include "include/header.h"
#include "include/colors.h"
#include "include/shapes.h"
#include "include/reshape.h"

#define float double
#define PI 3.1416


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // background
    glColor3ub(SKY_BLUE);
    rectangle(-1,1, 1,1, 1,-1, -1,-1);

    // lower cloud
    glColor3ub(WHITE); // right
    circleFan(-0.75, 0.1, 0.1);
    glColor3ub(WHITE); // middle
    circleFan(-0.6, 0.1, 0.15);
    glColor3ub(WHITE); // left
    circleFan(-0.45, 0.1, 0.12);

    // upper cloud
    glColor3ub(WHITE); // right
    circleFan(-0.45, 0.5, 0.1);
    glColor3ub(WHITE); // middle
    circleFan(-0.30, 0.5, 0.15);
    glColor3ub(WHITE); // left
    circleFan(-0.10, 0.5, 0.12);

    // triangle
    glColor3ub(RED);
    triangle(-.1,-.2, -.5,-.22, -.30,-.6);

    // box
    glColor3ub(BROWN);
    rectangle(-.5, -.22, -.3,-.6, -.62,-.8, -.85,-.40);

    // upper triangle flame
    glColor3ub(YELLOW);
    triangle(-.8,-.45, -0.98,-.43, -0.9,-.6);

    // lower triangle flame
    glColor3ub(YELLOW);
    triangle(-0.71,-.67, -0.88,-.63, -0.80,-.84);


    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("My Template");
    glClearColor(1.0, 1.0, 1.0, 1.0); // white background
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}