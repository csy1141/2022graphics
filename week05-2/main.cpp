#include <stdio.h>
#include <GL/glut.h>
int N=0;///�@�}�l�S�����I
int x[1000], y[1000];///�̦h�঳1000�ӳ��I
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_LINE_LOOP);
    for(int i=0; i<N; i++){
        glVertex2f((x[i]-150)/150.0, -(y[i]-150)/150.0);
    }
    glEnd();
    glutSwapBuffers();
}
void motion(int mouseX, int mouseY)
{

    N++;///�h�@���I
    x[N-1]=mouseX;///�̫�@�ӷs�W�����I��x�y��
    y[N-1]=mouseY;///�̫�@�ӷs�W�����I��y�y��
    printf("���U�ƹ��o�s�y�� %d %d\n", x[N-1], y[N-1]);

    display();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week05");
    glutDisplayFunc(display);
    glutMotionFunc(motion);
    glutMainLoop();
}
