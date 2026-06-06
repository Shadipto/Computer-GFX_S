#ifdef _WIN32
#include <windows.h>
#endif
#include <GLUT/glut.h>
#include <cmath>


// putpixel equivalent using OpenGL points
void plotPixel(int x, int y, float r, float g, float b) {
glColor3f(r, g, b);
glBegin(GL_POINTS);
glVertex2i(x, y);
glEnd();
}
// DDA Line Algorithm
void DDA(int x1, int y1, int x2, int y2, float r, float g, float b) {
int dx = x2 - x1;
int dy = y2 - y1;
int steps = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);
if (steps == 0) { plotPixel(x1, y1, r, g, b); return; }
float xInc = (float)dx / steps;
float yInc = (float)dy / steps;
float x = x1, y = y1;
for (int i = 0; i <= steps; i++) {
plotPixel((int)(x + 0.5f), (int)(y + 0.5f), r, g, b);
x += xInc;
y += yInc;
}
}
// Bresenham Line Algorithm
void Bresenham(int x1, int y1, int x2, int y2, float r, float g, float b) {
int dx = abs(x2 - x1), dy = abs(y2 - y1);
int sx = (x1 < x2) ? 1 : -1, sy = (y1 < y2) ? 1 : -1;
int err = dx - dy;
while (true) {
plotPixel(x1, y1, r, g, b);
if (x1 == x2 && y1 == y2) break;
int e2 = 2 * err;
if (e2 > -dy) { err -= dy; x1 += sx; }
if (e2 < dx) { err += dx; y1 += sy; }
}
}

// Midpoint Circle Algorithm
void MidpointCircle(int cx, int cy, int r, float red, float grn, float blu) 
{
    int x = 0, y = r, p = 1 - r;
    while (x <= y) 
    {
        plotPixel(cx + x, cy + y, red, grn, blu);
        plotPixel(cx - x, cy + y, red, grn, blu);
        plotPixel(cx + x, cy - y, red, grn, blu);
        plotPixel(cx - x, cy - y, red, grn, blu);
        plotPixel(cx + y, cy + x, red, grn, blu);
        plotPixel(cx - y, cy + x, red, grn, blu);
        plotPixel(cx + y, cy - x, red, grn, blu);
        plotPixel(cx - y, cy - x, red, grn, blu);
        if (p < 0) 
        {
            p += 2 * x + 3;
        }
        else 
        { 
            p += 2 * (x - y) + 5; y--; 
        }
        x++;
    }
}


// Fill rectangle using Bresenham scan lines
void fillRect(int x1, int y1, int x2, int y2, float r, float g, float b) {
for (int row = y1; row <= y2; row++)
Bresenham(x1, row, x2, row, r, g, b);
}
// Draw rectangle border using Bresenham
void borderRect(int x1, int y1, int x2, int y2, float r, float g, float b) {
Bresenham(x1, y1, x2, y1, r, g, b);
Bresenham(x2, y1, x2, y2, r, g, b);
Bresenham(x2, y2, x1, y2, r, g, b);
Bresenham(x1, y2, x1, y1, r, g, b);
}
// Fill circle using concentric Midpoint circles
void fillCircle(int cx, int cy, int r, float red, float grn, float blu) 
{
    for (int i = 1; i <= r; i++)
    {
        MidpointCircle(cx, cy, i, red, grn, blu);
    }
}
// Upper half arc using Midpoint Circle (used for pillar arch tops)
void upperHalfCircle(int cx, int cy, int r, float red, float grn, float blu) {
int x = 0, y = r, p = 1 - r;
while (x <= y) {
plotPixel(cx + x, cy + y, red, grn, blu);
plotPixel(cx - x, cy + y, red, grn, blu);
plotPixel(cx + y, cy + x, red, grn, blu);
plotPixel(cx - y, cy + x, red, grn, blu);
if (p < 0) p += 2 * x + 3;
else { p += 2 * (x - y) + 5; y--; }
x++;
}
}
void fillUpperHalf(int cx, int cy, int r, float red, float grn, float blu) {
for (int i = 1; i <= r; i++)
upperHalfCircle(cx, cy, i, red, grn, blu);
}
void drawBackground() 
{
    fillRect(0, 270, 1000, 700, 0.53f, 0.81f, 0.98f);
    fillRect(0, 0, 1000, 270, 0.25f, 0.55f, 0.15f);
}
// Part A: Bangladesh Flag
void drawBangladeshFlag() {
// Flagpole using DDA
for (int t = 0; t < 3; t++)
DDA(58 + t, 50, 58 + t, 660, 0.40f, 0.22f, 0.07f);
fillRect(46, 50, 72, 62, 0.30f, 0.30f, 0.30f);
int fx1 = 60, fy1 = 545, fx2 = 315, fy2 = 655;
// Flag body using Bresenham
fillRect(fx1, fy1, fx2, fy2, 0.00f, 0.50f, 0.15f);
borderRect(fx1, fy1, fx2, fy2, 1.0f, 1.0f, 1.0f);
// Red circle slightly left of centre using Midpoint Circle
int sunX = 168;
int sunY = (fy1 + fy2) / 2;
fillCircle(sunX, sunY, 42, 1.0f, 0.0f, 0.0f);
}
// Part B: Shaheed Minar
void drawShaheedMinar() {
float wr = 0.96f, wg = 0.96f, wb = 0.96f;
float gr = 0.42f, gg = 0.42f, gb = 0.42f;
float pr = 0.78f, pg = 0.78f, pb = 0.78f;
// Stepped base platform using Bresenham
fillRect(400, 118, 710, 132, pr, pg, pb);
borderRect(400, 118, 710, 132, gr, gg, gb);
fillRect(365, 132, 745, 152, pr, pg, pb);
borderRect(365, 132, 745, 152, gr, gg, gb);
fillRect(330, 152, 780, 175, pr, pg, pb);
borderRect(330, 152, 780, 175, gr, gg, gb);
// Large red circle backdrop using Midpoint Circle (drawn before pillars)
fillCircle(550, 320, 130, 1.0f, 0.0f, 0.0f);
for (int i = 130; i <= 132; i++)
MidpointCircle(550, 320, i, 0.75f, 0.0f, 0.0f);
// Five pillars using Bresenham — tallest centre, shorter outward
fillRect(528, 175, 572, 430, wr, wg, wb);
borderRect(528, 175, 572, 430, gr, gg, gb);
fillRect(462, 175, 506, 370, wr, wg, wb);
borderRect(462, 175, 506, 370, gr, gg, gb);
fillRect(594, 175, 638, 370, wr, wg, wb);
borderRect(594, 175, 638, 370, gr, gg, gb);
fillRect(390, 175, 432, 318, wr, wg, wb);
borderRect(390, 175, 432, 318, gr, gg, gb);
fillRect(668, 175, 710, 318, wr, wg, wb);
borderRect(668, 175, 710, 318, gr, gg, gb);
// Arch tops using Midpoint Circle upper arc
fillUpperHalf(550, 430, 22, wr, wg, wb);
upperHalfCircle(550, 430, 22, gr, gg, gb);
upperHalfCircle(550, 430, 22, gr, gg, gb);
fillUpperHalf(484, 370, 22, wr, wg, wb);
upperHalfCircle(484, 370, 22, gr, gg, gb);
fillUpperHalf(616, 370, 22, wr, wg, wb);
upperHalfCircle(616, 370, 22, gr, gg, gb);
fillUpperHalf(411, 318, 21, wr, wg, wb);
upperHalfCircle(411, 318, 21, gr, gg, gb);
fillUpperHalf(689, 318, 21, wr, wg, wb);
upperHalfCircle(689, 318, 21, gr, gg, gb);
// Decorative vertical lines on pillars using DDA
DDA(538, 180, 538, 428, gr, gg, gb);
DDA(550, 180, 550, 428, gr, gg, gb);
DDA(562, 180, 562, 428, gr, gg, gb);
DDA(472, 180, 472, 368, gr, gg, gb);
DDA(496, 180, 496, 368, gr, gg, gb);
DDA(604, 180, 604, 368, gr, gg, gb);
DDA(628, 180, 628, 368, gr, gg, gb);
DDA(411, 180, 411, 316, gr, gg, gb);
DDA(689, 180, 689, 316, gr, gg, gb);
DDA(432, 162, 462, 162, gr, gg, gb);
DDA(506, 162, 528, 162, gr, gg, gb);
DDA(572, 162, 594, 162, gr, gg, gb);
DDA(638, 162, 668, 162, gr, gg, gb);
}
// Part C Extra 1: Sky sun — disc via Midpoint Circle, rays via DDA
void drawSkySun() {
int sx = 860, sy = 590, sr = 28;
const float PI = 3.14159265f;
fillCircle(sx, sy, sr, 1.0f, 0.90f, 0.10f);
for (int i = 0; i < 12; i++) {
float ang = i * (360.0f / 12.0f) * PI / 180.0f;
int x1 = sx + (int)((sr + 5) * cosf(ang));
int y1 = sy + (int)((sr + 5) * sinf(ang));
int x2 = sx + (int)((sr + 18) * cosf(ang));
int y2 = sy + (int)((sr + 18) * sinf(ang));
DDA(x1, y1, x2, y2, 1.0f, 0.85f, 0.0f);
}
}
// Part C Extra 2: Clouds — overlapping circles via Midpoint Circle
void drawOneCloud(int x, int y) 
{
    fillCircle(x, y, 18, 1.0f, 1.0f, 1.0f);
    fillCircle(x + 23, y + 10, 24, 1.0f, 1.0f, 1.0f);
    fillCircle(x + 52, y + 6, 20, 1.0f, 1.0f, 1.0f);
    fillCircle(x + 76, y + 8, 16, 1.0f, 1.0f, 1.0f);
}
void drawClouds() 
{
    drawOneCloud(390, 622);
    drawOneCloud(620, 640);
    drawOneCloud(430, 638);
}
void display() 
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawBackground();
    drawBangladeshFlag();
    drawSkySun();
    drawShaheedMinar();
    drawClouds();
    glutSwapBuffers();
}
void reshape(int w, int h) {
glViewport(0, 0, w, h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, 1000.0, 0.0, 700.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}
void keyboard(unsigned char key, int x, int y) 
{
    if (key == 27 || key == 'q' || key == 'Q') exit(0);
}

int main(int argc, char** argv) 
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000, 700);
    glutInitWindowPosition(50, 30);
    glutCreateWindow("Bangladesh Tribute Scene");
    glClearColor(0.53f, 0.81f, 0.98f, 1.0f);
    glPointSize(1.0f);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}