#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void setup(){
    // backgrouning the screen
    glClearColor(0.0, 0.0, 0.0, 1.0);
    // make the coord width and height 20 in scale
    gluOrtho2D(-10.0, 10.0, -10.0, 10.0);
}

void display(){
    // clearing the buffer screen in memory
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();//load identity matrix
    glColor3f(0.0, 1.0, 0.1);
//   glTranslatef(0.0f,0.0f,4.0f);//move forward 4 units
    glPointSize(10.0f);//set point size to 10 pixels
    glBegin(GL_POINTS); //starts drawing of points
        glVertex3f(1.0f,1.0f,0.0f);//upper-right corner
        glVertex3f(-1.0f,-1.0f,0.0f);//lower-left corner
    glEnd();//end drawing of points
    glFlush();
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(200, 100);
    glutInitWindowSize(400, 300);
    glutCreateWindow("Hello World");
    glutDisplayFunc(display);

    setup();
    glutMainLoop();

    return 0;
}
