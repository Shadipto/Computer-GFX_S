#pragma once
#include "header.h"

#define PI 3.1416

// Circle Fan method
void circleFan(float centerX, float centerY, float radius) {
    glBegin(GL_TRIANGLE_FAN);
        glVertex2d(centerX, centerY);
        for (int i = 0; i <= 100; i++) {
            float angle = 2.0 * PI * i / 100;
            float x = centerX + radius * cos(angle);
            float y = centerY + radius * sin(angle);
            glVertex2d(x, y);
        }
    glEnd();
}

// Circle Outline using GL_LINE_LOOP
void circleOutline(float centerX, float centerY, float radius) {
    glBegin(GL_LINE_LOOP);
        for (int i = 0; i <= 100; i++) {
            float angle = 2.0 * PI * i / 100;
            float x = centerX + radius * cos(angle);
            float y = centerY + radius * sin(angle);
            glVertex2d(x, y);
        }
    glEnd();
}

// Partial Circle (arc) using GL_LINE_STRIP
void circleArc(float centerX, float centerY, float radius, float startAngle, float endAngle) {
    glBegin(GL_LINE_STRIP);
        for (int i = 0; i <= 100; i++) {
            float angle = (startAngle + (endAngle - startAngle) * i / 100) * PI / 180.0;
            float x = centerX + radius * cos(angle);
            float y = centerY + radius * sin(angle);
            glVertex2d(x, y);
        }
    glEnd();
}

// Triangle using GL_POLYGON
void triangle(float x1, float y1, float x2, float y2, float x3, float y3) {
    glBegin(GL_POLYGON);
        glVertex2d(x1, y1);
        glVertex2d(x2, y2);
        glVertex2d(x3, y3);
    glEnd();
}

// Triangle outline using GL_LINE_LOOP
void triangleOutline(float x1, float y1, float x2, float y2, float x3, float y3) {
    glBegin(GL_LINE_LOOP);
        glVertex2d(x1, y1);
        glVertex2d(x2, y2);
        glVertex2d(x3, y3);
    glEnd();
}

// Equilateral triangle given center and size using GL_POLYGON
void equilateralTriangle(float centerX, float centerY, float size) {
    float h = size * sqrt(3.0) / 2.0;
    glBegin(GL_POLYGON);
        glVertex2d(centerX, centerY + h * 2.0 / 3.0);
        glVertex2d(centerX - size / 2, centerY - h / 3.0);
        glVertex2d(centerX + size / 2, centerY - h / 3.0);
    glEnd();
}

// Rectangle using GL_POLYGON
void rectangle(float x1, float y1, float x2, float y2,
               float x3, float y3, float x4, float y4) {
    glBegin(GL_POLYGON);
        glVertex2d(x1, y1);
        glVertex2d(x2, y2);
        glVertex2d(x3, y3);
        glVertex2d(x4, y4);
    glEnd();
}

// Rectangle using width-height using GL_POLYGON
void rectangleWH(float x, float y, float width, float height) {
    glBegin(GL_POLYGON);
        glVertex2d(x,         y);
        glVertex2d(x + width, y);
        glVertex2d(x + width, y - height);
        glVertex2d(x,         y - height);
    glEnd();
}

// Rectangle Outline using width-height using GL_LINE_LOOP
void rectangleOutline(float x, float y, float width, float height) {
    glBegin(GL_LINE_LOOP);
        glVertex2d(x,         y);
        glVertex2d(x + width, y);
        glVertex2d(x + width, y - height);
        glVertex2d(x,         y - height);
    glEnd();
}

// Square using GL_POLYGON
void square(float x1, float y1, float x2, float y2,
            float x3, float y3, float x4, float y4) {
    glBegin(GL_POLYGON);
        glVertex2d(x1, y1);
        glVertex2d(x2, y2);
        glVertex2d(x3, y3);
        glVertex2d(x4, y4);
    glEnd();
}

// Square using center and size using GL_POLYGON
void squareSize(float centerX, float centerY, float size) {
    float half = size / 2.0;
    glBegin(GL_POLYGON);
        glVertex2d(centerX - half, centerY + half);
        glVertex2d(centerX + half, centerY + half);
        glVertex2d(centerX + half, centerY - half);
        glVertex2d(centerX - half, centerY - half);
    glEnd();
}

// Square Outline using center and size using GL_LINE_LOOP
void squareOutline(float centerX, float centerY, float size) {
    float half = size / 2.0;
    glBegin(GL_LINE_LOOP);
        glVertex2d(centerX - half, centerY + half);
        glVertex2d(centerX + half, centerY + half);
        glVertex2d(centerX + half, centerY - half);
        glVertex2d(centerX - half, centerY - half);
    glEnd();
}

// Polygon with n sides using center and radius using GL_POLYGON
void polygon(float centerX, float centerY, float radius, int sides) {
    glBegin(GL_POLYGON);
        for (int i = 0; i < sides; i++) {
            float angle = 2.0 * PI * i / sides;
            glVertex2d(centerX + radius * cos(angle),
                       centerY + radius * sin(angle));
        }
    glEnd();
}

// Polygon outline with n sides using center and radius and n sides using GL_LINE_LOOP
void polygonOutline(float centerX, float centerY, float radius, int sides) {
    glBegin(GL_LINE_LOOP);
        for (int i = 0; i < sides; i++) {
            float angle = 2.0 * PI * i / sides;
            glVertex2d(centerX + radius * cos(angle),
                       centerY + radius * sin(angle));
        }
    glEnd();
}

// Star with n points using center and inner/outer radius using Fan
void star(float centerX, float centerY, float outerRadius, float innerRadius, int points = 5) {
    glBegin(GL_TRIANGLE_FAN);
        glVertex2d(centerX, centerY);
        for (int i = 0; i <= points * 2; i++) {
            float angle = PI / 2.0 + i * PI / points;
            float r = (i % 2 == 0) ? outerRadius : innerRadius;
            glVertex2d(centerX + r * cos(angle),
                       centerY + r * sin(angle));
        }
    glEnd();
}

// Line using GL_LINES
void line(float x1, float y1, float x2, float y2) {
    glBegin(GL_LINES);
        glVertex2d(x1, y1);
        glVertex2d(x2, y2);
    glEnd();
}

// Line with thickness using GL_LINES and glLineWidth
void thickLine(float x1, float y1, float x2, float y2, float width) {
    glLineWidth(width);
    glBegin(GL_LINES);
        glVertex2d(x1, y1);
        glVertex2d(x2, y2);
    glEnd();
    glLineWidth(1.0); // reset to default
}

// Point using GL_POINTS
void point(float x, float y) {
    glBegin(GL_POINTS);
        glVertex2d(x, y);
    glEnd();
}

// Points with size using GL_POINTS and glPointSize
void bigPoint(float x, float y, float size) {
    glPointSize(size);
    glBegin(GL_POINTS);
        glVertex2d(x, y);
    glEnd();
    glPointSize(1.0); // reset to default
}

// Ellipse using Fan
void ellipse(float centerX, float centerY, float radiusX, float radiusY) {
    glBegin(GL_TRIANGLE_FAN);
        glVertex2d(centerX, centerY);
        for (int i = 0; i <= 100; i++) {
            float angle = 2.0 * PI * i / 100;
            glVertex2d(centerX + radiusX * cos(angle),
                       centerY + radiusY * sin(angle));
        }
    glEnd();
}

// Elipse outline using GL_LINE_LOOP
void ellipseOutline(float centerX, float centerY, float radiusX, float radiusY) {
    glBegin(GL_LINE_LOOP);
        for (int i = 0; i <= 100; i++) {
            float angle = 2.0 * PI * i / 100;
            glVertex2d(centerX + radiusX * cos(angle),
                       centerY + radiusY * sin(angle));
        }
    glEnd();
}

// Ring (donut shape) using GL_TRIANGLE_STRIP
void ring(float centerX, float centerY, float innerRadius, float outerRadius) {
    glBegin(GL_TRIANGLE_STRIP);
        for (int i = 0; i <= 100; i++) {
            float angle = 2.0 * PI * i / 100;
            glVertex2d(centerX + outerRadius * cos(angle),
                       centerY + outerRadius * sin(angle));
            glVertex2d(centerX + innerRadius * cos(angle),
                       centerY + innerRadius * sin(angle));
        }
    glEnd();
}

// Arrow using GL_POLYGON for body and GL_TRIANGLES for head
void arrow(float centerX, float centerY, float size) {
    float h = size / 2.0;
    // arrow body
    glBegin(GL_POLYGON);
        glVertex2d(centerX - size,  centerY + h * 0.3);
        glVertex2d(centerX,         centerY + h * 0.3);
        glVertex2d(centerX,         centerY - h * 0.3);
        glVertex2d(centerX - size,  centerY - h * 0.3);
    glEnd();
    // arrow head
    glBegin(GL_TRIANGLES);
        glVertex2d(centerX,        centerY + h);
        glVertex2d(centerX + size, centerY);
        glVertex2d(centerX,        centerY - h);
    glEnd();
}