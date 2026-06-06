#define GL_SILENCE_DEPRECATION
#ifdef __APPLE__
    #include <OpenGL/gl.h>
    #include <GLUT/glut.h>
    #include <OpenGL/glu.h>
    #include <OpenGL/glext.h>
#elif defined(_WIN32) || defined(_WIN64)
    #include <windows.h>
    #include <GL/gl.h>
    #include <GL/glut.h>
    #include <GL/glu.h>
    #include <GL/glext.h>
#else
    #include <GL/gl.h>
    #include <GL/glut.h>
    #include <GL/glu.h>
    #include <GL/glext.h>
#endif
#define PI 3.1416
#include<math.h>
 
GLfloat tx = 0.0f;
GLfloat ty = 0.0f;
GLfloat angle = 0.0f;
GLfloat speed = 0.0f;
GLfloat scale = 1.0f;
int translateFlag = 0;
int rotationFlag = 0;
int scaleFlag = 0;
int zoom = 1;
 
 
void CC(float x, float y, float ra, int r, int g, int b) {
	int i;
    GLfloat p1 = x; GLfloat q1 = y; GLfloat r1 = ra;
    int tringle2=40;
    GLfloat tp2 =2.0f * PI  ;
    glBegin (GL_TRIANGLE_FAN);
    glColor3ub (r,g,b);
    glVertex2f (p1,q1);
    for(i= 0;i<=tringle2; i++)
    {
        glColor3ub(255,255,255);
        glVertex2f (
                    p1+(r1*cos(i*tp2/tringle2)),
                    q1+(r1*sin(i*tp2/tringle2))
                    );
    }
    glEnd ();
}
 
 
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glBegin(GL_QUADS);
        glColor3ub(0, 0, 255);
        glVertex2f(-0.05f,  0.0f);
        glVertex2f(-0.05f, -0.8f);
        glVertex2f( 0.05f, -0.8f);
        glVertex2f( 0.05f,  0.0f);
    glEnd();

    
    glPushMatrix();
        glRotatef(angle, 0.0f, 0.0f, 1.0f);

        glBegin(GL_TRIANGLES);
        glColor3ub(255,0,0);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.4f, 0.0f);
        glVertex2f(0.4f, -0.4f);
        glEnd();
        
        glBegin(GL_TRIANGLES);
        glColor3ub(255,0,0);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.0f, 0.4f);
        glVertex2f(0.4f, 0.4f);
        glEnd();
        
        glBegin(GL_TRIANGLES);
        glColor3ub(255,0,0);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(-0.4f, 0.0f);
        glVertex2f(-0.4f, 0.4f);
        glEnd();
        
        glBegin(GL_TRIANGLES);
        glColor3ub(255,0,0);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.0f, -0.4f);
        glVertex2f(-0.4f, -0.4f);
        glEnd();
        glColor3ub(255,0,0);

        
        CC(0.0, 0.0, 0.10, 255, 0, 0);

    glPopMatrix();
 
 
    glFlush();
}
void keyboard(unsigned char key, int x, int y) {
    switch(key) {
    case 'm':
        translateFlag = 1;
        break;
    case 'n':
        translateFlag = 0;
        break;
 
    case 'r':
        rotationFlag = 1;
        speed = speed + 1.0f;
        break;
 
    case 'e':
        rotationFlag = 0;
        break;
    case 'a':
        speed = speed - 1.0f;
        break;
 
    case 'z':
        scaleFlag = 1;
        break;
    case 'x':
        scaleFlag = 0;
        break;
 
 
    }
    glutPostRedisplay();
}
 
void update(int value) {
 
    if(translateFlag == 1){
        tx = tx + 0.005f;
        ty = ty + 0.005f;
 
        if(tx >= 1.5f){
            tx = -1.5f;
            ty = -1.5f;
        }
    }
    if(rotationFlag == 1){
        angle = angle + speed;
    }
 
    if(scaleFlag == 1){
        if(zoom == 1){
            scale = scale + 0.01f;
            if(scale >= 1.5){
                scale = 1.5f;
                zoom = 0;
            }
        }
        if(zoom == 0){
            scale = scale - 0.01f;
            if(scale <=.5){
                scale = 0.5f;
                zoom = 1;
            }
        }
    }
 
 
    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}
 
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("3 Transformations Demo");
 
    glClearColor(0.0, 0.0, 0.0, 1.0);
 
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    //glutIdleFunc(update); //Ideal, so fast, as much fast the CPU can do.
    glutTimerFunc(16, update, 0); //We can customize it.
    glutMainLoop();
    return 0;
}