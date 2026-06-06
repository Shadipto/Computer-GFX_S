#ifdef __APPLE__
    #include <GLUT/glut.h>
#else
    #include <GL/glut.h>
#endif

const int WIDTH  = 1162;
const int HEIGHT = 644;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 0.0);   // black outline

    glBegin(GL_LINE_LOOP);
        glVertex2i(100, 100);   // bottom‑left
        glVertex2i(300, 100);   // bottom‑right
        glVertex2i(300, 300);   // top‑right
        glVertex2i(100, 300);   // top‑left
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
    glutCreateWindow("LabTask1s");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
