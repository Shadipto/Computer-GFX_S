#ifdef __APPLE__
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif

const int WIDTH  = 1162;
const int HEIGHT = 644;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Water
    glColor3f(0.0f, 0.4f, 0.8f);
    glBegin(GL_QUADS);
        glVertex2f(0, 0);
        glVertex2f(WIDTH, 0);
        glVertex2f(WIDTH, 310);
        glVertex2f(0, 310);
    glEnd();

    // Horizon
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(0, 310);
        glVertex2f(WIDTH, 310);
        glVertex2f(WIDTH, 350);
        glVertex2f(0, 350);
    glEnd();

    // Sky
    glColor3f(0.0f, 0.7f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(0, 350);
        glVertex2f(WIDTH, 350);
        glVertex2f(WIDTH, HEIGHT);
        glVertex2f(0, HEIGHT);
    glEnd();

    // Mountain — intentionally modest
    glColor3f(0.8f, 0.0f, 0.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f(WIDTH / 2, 560);
        glVertex2f(WIDTH / 2 - 70, 350);
        glVertex2f(WIDTH / 2 + 70, 350);
    glEnd();

    // Boat body — SIGNIFICANTLY enlarged
    glColor3f(0.55f, 0.27f, 0.07f);
    glBegin(GL_QUADS);
        glVertex2f(470, 190);
        glVertex2f(690, 190);
        glVertex2f(640, 120);
        glVertex2f(520, 120);
    glEnd();

    // Mast — taller
    glColor3f(0.8f, 0.0f, 0.0f);
    glBegin(GL_LINES);
        glVertex2f(580, 190);
        glVertex2f(580, 330);
    glEnd();

    // Sail — dominant shape
    glColor3f(0.0f, 0.7f, 0.0f);
    glBegin(GL_TRIANGLES);
        glVertex2f(580, 330);
        glVertex2f(580, 190);
        glVertex2f(740, 260);
    glEnd();

    glFlush();
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WIDTH, 0, HEIGHT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Boat Scene");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
