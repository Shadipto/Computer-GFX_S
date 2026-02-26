#define GL_SILENCE_DEPRECATION 
#include<iostream>
#include<cstdio>
#include<cmath>

#ifdef __APPLE__
    #include <OpenGL/gl.h>
    #include <GLUT/glut.h>
#elif defined(_WIN32) || defined(_WIN64)
    #include <windows.h>
    #include <GL/gl.h>
    #include <GL/glut.h>
    #include <bits/stdc++.h>
#else
    #include <GL/gl.h>
    #include <GL/glut.h>
#endif

#define PI 3.141516

void display() {
    glClear(GL_COLOR_BUFFER_BIT);	// Clear the color buffer (background)
    int i;
    GLfloat p1 = 0.75f; 	//Value of x
    GLfloat q1 = 0.85f; 	//Value of y
    GLfloat r1 = 0.05f;	//Radius
    int tringle2 = 40;	//Number of Triangle (More value means more smooth edge)

    GLfloat tp2 =2.0f * PI;

    glBegin (GL_TRIANGLE_FAN);
    // yellow color
        glColor3ub (255, 255, 0); 
        glVertex2f (p1,q1);
        for(i = 0; i <= tringle2; i++)
        {
            glVertex2f (p1+(r1*cos(i*tp2/tringle2)), q1+(r1*sin(i*tp2/tringle2)));
        }
    glEnd ();

    glFlush();  // Render now
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);		// Initialize GLUT
    glutInitWindowSize(1000, 1000);   // Set the window's initial width & height
    glutCreateWindow("Circle"); 	// Create a window with the given title
    glutDisplayFunc(display); 	// Register display callback handler for window re-paint
    glutMainLoop();           	
    return 0;
}
