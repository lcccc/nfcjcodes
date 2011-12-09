#include <GL/glut.h>

void GLinit(){
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0,0,0,0);
}

void GLdis(){
    glBegin(GL_TRIANGLES);
        glColor3f(1,0,0);
        glVertex2f(0.0,1.0);
        glColor3f(0.0,1.0,0.0);
        glVertex2f(-1,0);
        glColor3f(0.0,0.0,1.0);
        glVertex2f(1,0);
    glEnd();
    glFlust();
}

void GLres(int w,int h)
{
    glViewport(0,10,0,10);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glTranslatef(-1.0,0,-6.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc,char ** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400,400);
    glutInitWindowPosition(200,200);
    glutCreateWindow("   Nfcj - OpenGl");
    GLinit();
    glutDisplayFunc(GLdis);
    glutReshapeFunc(GLres);
    glutMainLoop();
    return 0;
}
