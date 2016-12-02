/*本代码实现了DDA Algorithm 与 Bresenham Algorithm
 *运行环境：OSX 10.11.6   zsh + g++ 7.3.0 + vim 8.0 + OpenGL
 *
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <map>
#include <stack>
#include <set>
#include <ctime>
#include <GLUT/glut.h>

typedef long long ll;

//步距
const int D = 1;
//起点与终点
int ax, ay, bx, by;

//取整函数
inline int _round(double a){
    return (int)(a + 0.5);
}

inline void drawAPoint(int x, int y){
    glBegin(GL_POINTS);
        glVertex2i(x, y);
    glEnd();
    return;
}

void init(){
    glClearColor(1.0, 1.0, 1.0, 0.0);

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 200.0, 0.0, 150.0);
    return;
}

void lineSegment(){
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.0, 0.0, 0.0);
    for(int i = 0; i < 300; i += D){
        glBegin(GL_LINES);
           glVertex2i(i, 0);
           glVertex2i(i, 400);
        glEnd();
    }
    for(int i = 0; i < 400; i += D){
        glBegin(GL_LINES);
           glVertex2i(0, i);
           glVertex2i(400, i);
        glEnd();
    }

    //DDA
    glColor3f(1.0, 0.0, 0.0);
    int dx = bx - ax;
    int dy = by - ay;
    int steps = std::max(abs(dx), abs(dy));
    double deltax = (double)(dx) / (double)(steps);
    double deltay = (double)(dy) / (double)(steps);

    double x, y;
    glBegin(GL_LINE_LOOP);
    drawAPoint(_round(x) * D, _round(y) * D);
    for(int i = 0; i < steps; ++i){
        x += deltax;
        y += deltay;
        drawAPoint(_round(x) * D, _round(y) * D);
    }
    glEnd();

    //Bresenham
    glColor3f(0.0, 1.0, 0.0);

    dx = abs(bx - ax);
    dy = abs(by - ay);
    int p = 2 * dy - dx;
    int twoDy = 2 * dy, twoDyMinusDx = 2 * (dy - dx);
    if(ax > bx){
        x = bx;
        y = by;
        bx = ax;
    }else{
        x = ax;
        y = by;
    }
    
    glBegin(GL_LINE_LOOP);
    drawAPoint(x * D, y * D);
    while(x < bx){
        ++x;
        if(p < 0){
            p += twoDy;
        }else{
            ++y;
            p += twoDyMinusDx;
        }
        drawAPoint(_round(x) * D, _round(y) * D);
    }
    glEnd();

    glFlush();
    return;
}

int main(int argc, char *argv[]){

    std::cin >> ax >> ay >> bx >> by;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 100);
    glutInitWindowSize(300, 400);
    glutCreateWindow("DDA by ZhaoYue");

    init();
    glutDisplayFunc(lineSegment);
    glutMainLoop();

    return 0;
}
