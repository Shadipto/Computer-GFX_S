#define GL_SILENCE_DEPRECATION
#include<bits/stdc++.h>

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