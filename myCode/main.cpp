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

    // ── ROW 1 ────────────────────────────────────────────────────────────────

    // filled circle — center fan method
    glColor3ub(RED);
    circleFan(-1.65, 0.75, 0.20);

    // circle outline only — no fill
    glColor3ub(RED);
    circleOutline(-0.99, 0.75, 0.20);

    // arc — partial circle from 0° to 270°
    glColor3ub(RED);
    circleArc(-0.33, 0.75, 0.20, 0, 270);

    // filled ellipse — different x and y radius
    glColor3ub(RED);
    ellipse(0.33, 0.75, 0.28, 0.17);

    // ellipse outline only — no fill
    glColor3ub(RED);
    ellipseOutline(0.99, 0.75, 0.28, 0.17);

    // ring / donut — inner and outer radius
    glColor3ub(RED);
    ring(1.65, 0.75, 0.10, 0.22);

    // ── ROW 2 ────────────────────────────────────────────────────────────────

    // filled triangle — 3 corner points
    glColor3ub(RED);
    triangle(-1.65, 0.45, -1.45, 0.08, -1.85, 0.08);

    // triangle outline only — no fill
    glColor3ub(RED);
    triangleOutline(-0.99, 0.45, -0.79, 0.08, -1.19, 0.08);

    // equilateral triangle — center and size
    glColor3ub(RED);
    equilateralTriangle(-0.33, 0.27, 0.38);

    // filled square — 4 corner points
    glColor3ub(RED);
    square(0.15, 0.45, 0.51, 0.45, 0.51, 0.08, 0.15, 0.08);

    // square — center and size
    glColor3ub(RED);
    squareSize(0.99, 0.27, 0.38);

    // square outline only — no fill
    glColor3ub(RED);
    squareOutline(1.65, 0.27, 0.38);

    // ── ROW 3 ────────────────────────────────────────────────────────────────

    // filled rectangle — 4 corner points
    glColor3ub(RED);
    rectangle(-1.90, -0.08, -1.40, -0.08, -1.40, -0.42, -1.90, -0.42);

    // rectangle — top-left corner, width, height
    glColor3ub(RED);
    rectangleWH(-1.24, -0.08, 0.50, 0.34);

    // rectangle outline only — no fill
    glColor3ub(RED);
    rectangleOutline(-0.58, -0.08, 0.50, 0.34);

    // regular polygon — 6 sides (hexagon)
    glColor3ub(RED);
    polygon(0.33, -0.25, 0.22, 6);

    // polygon outline — 8 sides (octagon)
    glColor3ub(RED);
    polygonOutline(0.99, -0.25, 0.22, 8);

    // star — 5 points, outer and inner radius
    glColor3ub(RED);
    star(1.65, -0.25, 0.22, 0.10, 5);

    // ── ROW 4 ────────────────────────────────────────────────────────────────

    // simple line — two endpoints
    glColor3ub(RED);
    line(-1.90, -0.60, -1.40, -0.90);

    // thick line — two endpoints and width
    glColor3ub(RED);
    thickLine(-1.24, -0.60, -0.74, -0.90, 4.0);

    // single point — just a dot
    glColor3ub(RED);
    point(-0.33, -0.75);

    // big point — dot with custom size
    glColor3ub(RED);
    bigPoint(0.33, -0.75, 10.0);

    // arrow — center and size, points right
    glColor3ub(RED);
    arrow(0.99, -0.75, 0.30);

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