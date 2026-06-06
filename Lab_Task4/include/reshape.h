#pragma once
#include "header.h"

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float aspect = (float)w / (float)h;

    if (w >= h)
        // wider than tall: expand x range
        gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
    else
        // taller than wide: expand y range
        gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}