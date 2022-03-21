#include <stdio.h>
#include <GL/glut.h>
int N=0;///一開始沒有頂點
int x[1000], y[1000];///最多能有1000個頂點
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

    N++;///多一頂點
    x[N-1]=mouseX;///最後一個新增的頂點的x座標
    y[N-1]=mouseY;///最後一個新增的頂點的y座標
    printf("按下滑鼠得新座標 %d %d\n", x[N-1], y[N-1]);

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
