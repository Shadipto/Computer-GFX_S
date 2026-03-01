#include "include/header.h"
#include "include/colors.h"
#include "include/shapes.h"
#include "include/reshape.h"

#define float double
#define PI 3.1416


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // sky
    glColor3ub(SKY_BLUE);
    rectangle(-1,0,1,0,1,1,-1,1);

    // Left triangle land
    glColor3ub(GREEN);
    triangle(-1, 0, -1, -1, -0.3, -1); // mark

    // river
    glColor3ub(BLUE);
    glBegin(GL_POLYGON);
        glVertex2d(-1,0);
        glVertex2d(-.3,-1);
        glVertex2d(1,-1);
        glVertex2d(1,-.7); // mark
        glVertex2d(.4,0);
    glEnd();

    // right triangle land
    glColor3ub(GREEN);
    triangle(.4,0,1,-.7,1,0); // mark

    // boat
    glColor3ub(BROWN);
    rectangle(-.7,-.25,-.5,-.5,-.2,-.5,-.1,-.25);

    // boat house
    glColor3ub(BROWN);
    rectangle(-.4,-.15,-.4,-.25,-.25,-.25,-.25,-.15);

    // left mountain
    glColor3ub(LIGHT_GREEN);
    triangle(.55,0,.6,.2,.65,0);

    // mid mountain
    glColor3ub(LIGHT_GREEN);
    triangle(.6,0,.7,.4,.75,0);

    // right mountain
    glColor3ub(LIGHT_GREEN);
    triangle(.71,0,.8,.2,1.1,0);

    // sun
    glColor3ub(YELLOW);
    circleFan(.7,.8,.1);

    // right cloud
    glColor3ub(WHITE);
    circleFan(-.1,.7,.1); // mark

    glColor3ub(WHITE);
    circleFan(.1,.7,.18);

    glColor3ub(WHITE);
    circleFan(.3,.7,.15);

    // left cloud
    glColor3ub(WHITE);
    circleFan(-.75,.75,.15);

    glColor3ub(WHITE);
    circleFan(-.5,.75,.20);

    glColor3ub(WHITE);
    circleFan(-.3,.75,.10);

        glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("My Template");
    glClearColor(1.0, 1.0, 1.0, 1.0); // white background
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}