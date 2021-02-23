#ifdef __APPLE__
#else
#include <GL/glut.h>
#endif
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>

void display(void)
{
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,300.0,0.0,300.0);
};

void setPixel (GLint xCoordinate, GLint yCoordinate)
{
    glBegin (GL_POINTS);
    glVertex2i (xCoordinate, yCoordinate);
    glEnd();
    glFlush();
};

void lineBres (GLint x0, GLint y0, GLint xEnd, GLint yEnd)
{
    GLint dx = (float) fabs ((float) xEnd - x0);
    GLint dy = (float) fabs ((float) yEnd - y0);
    GLint p = 2*dy-dx;
    GLint twoDy = 2*dy;
    GLint twoDyMinusDx = 2*(dy-dx);
    GLint x,y;

    if(x0 > xEnd){
        x=xEnd;
        y=yEnd;
        xEnd=x;
    }
    else{
        x=x0;
        y=y0;
    }

    setPixel(x,y);
    while(x<xEnd){
        x++;
        if(p<0){
            p+=twoDy;
        }
        else{
            y++;
            p+=twoDyMinusDx;
        }
        setPixel(x,y);
    }
};

void garis (void)
{
    glClear (GL_COLOR_BUFFER_BIT);

    glColor3f(1.0,0.0,0.0);
    glPointSize(4.0);
    GLint x0 = 50;
    GLint y0 = 50;
    GLint xEnd = 150;
    GLint yEnd = 50;
    lineBres(x0,y0,xEnd,yEnd);

    glColor3f(0.0,1.0,0.0);
    glPointSize(4.0);
    GLint x1 = 50;
    GLint y1 = 100;
    GLint x2 = 150;
    GLint y2 = 100;
    lineBres(x1,y1,x2,y2);

    glColor3f(0.0,0.0,1.0);
    glPointSize(4.0);
    GLint x3 = 50;
    GLint y3 = 150;
    GLint x4 = 150;
    GLint y4 = 150;
    lineBres(x3,y3,x4,y4);
};

int main(int argc, char** argv)
{

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(400,400);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Contoh Garis");
    display();
    glutDisplayFunc(garis);
    glutMainLoop();

    return 0;
}
