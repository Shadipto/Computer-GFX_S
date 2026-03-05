#include "include/header.h"
#include "include/colors.h"
#include "include/shapes.h"
#include "include/reshape.h"

#define float double
#define PI 3.1416

// ── window: 1200x600 → after reshape: x[-2, 2], y[-1, 1] ────────────────────
// ── grid: 6 columns × 4 rows, each cell ~0.65w × 0.50h ─────────────────────
// ── col centers: -1.65, -0.99, -0.33, 0.33, 0.99, 1.65 ─────────────────────
// ── row centers:  0.75,  0.25, -0.25, -0.75 ─────────────────────────────────

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    // body
    glColor3ub(BLUE);
    rectangle(-.2, 0, .2, 0, .2, .6, -.2, .6);

    // neck
    glColor3ub(SKIN_LIGHT);
    rectangle(-.05,.6, .05,.6, .05,.7, -.05,.7);

    // head
    glColor3ub(SKIN_LIGHT);
    rectangle(-.15,.7, .15,.7, .15,0.9, -.15,0.9);

    // torso
    glColor3ub(BROWN_500);
    rectangle(-.1, -.2, .1, -.2, .1, 0, -.1, 0);

    // left hand
    glColor3ub(SKIN_LIGHT);
    triangle(-.2, 0.4, -.4, 0.1, -.2, 0.0);

    // left hand trigangle
    glColor3ub(BLACK);
    triangle(-.4, 0.1, -.5, 0, -.3, 0);

    // right hand
    glColor3ub(SKIN_LIGHT);
    triangle(.2, 0.4, .4, 0.1, .2, 0.0);    

    // right hand trigangle
    glColor3ub(BLACK);
    triangle(.4, 0.1, .5, 0, .3, 0);

    // left eye 
    glColor3ub(WHITE);
    circleFan(-.05, 0.85, .03);

    // right eye
    glColor3ub(WHITE);
    circleFan(.05, 0.85, .03);

    // left leg
    glColor3ub(BROWN_500);
    triangle(-.05, -.2, -.1, -.6, 0, -.6);

    // right leg
    glColor3ub(BROWN_500);
    triangle(.05, -.2, .1, -.6, 0, -.6);

    // left foot
    glColor3ub(BLACK);
    triangle(-.1, -.6, -.1, -.8, 0, -.8);

    // right foot
    glColor3ub(BLACK);
    triangle(0, -.6, .1, -.8, 0, -.8);

    // mouth
    glColor3ub(RED);
    rectangle(-.05, 0.77, .05, 0.77, .05, 0.75, -.05, 0.75);

        glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1200, 600);
    glutCreateWindow("My Template");
    glClearColor(1.0, 1.0, 1.0, 1.0); // white background
    glutReshapeFunc(reshape);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}