//
//  sierpinski3D.cpp
//  sierpinski3D
//
//  Created by 严晟嘉 on 15/10/12.
//  Copyright (c) 2015年 Shengjia Yan. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// #include <GL/glew.h>
// #include <GLFW/glfw3.h>
#include <GLUT/GLUT.h>
using namespace std;


//设置程序的窗口大小
GLint windowWidth=500;
GLint windowHeight=500;

//获取屏幕的宽度与高度
GLint SCREEN_WIDTH=glutGet(GLUT_SCREEN_WIDTH);    //获取系统的宽像素
GLint SCREEN_HEIGHT=glutGet(GLUT_SCREEN_HEIGHT);  //获取系统的高像素

typedef GLfloat point3[3];  //元素类型为GLfloat,元素个数为3的数组类型point3

point3 v[]={{0.0, 0.0, 1.0}, {0.0, 0.942809, -0.33333},
	{-0.816497, -0.471405, -0.333333}, {0.816497, -0.471405, -0.333333}};  //初始化三角形

point3 colors[] = {{1, 1, 0}, {0, 0, 0},
                    {238.0/255, 99.0/255, 99.0/255}, {238/255, 236/255, 193/255}};

int n;  //循环次数


//绘制三角形
void triangle(point3 a, point3 b, point3 c)
{
    //显示三角形
    glVertex3fv(a);
    glVertex3fv(b);
    glVertex3fv(c);
}

//绘制四面体
void tetra(point3 a, point3 b, point3 c, point3 d)
{
    glColor3fv(colors[0]);
    triangle(a, b, c);
    glColor3fv(colors[1]);
    triangle(a, c, d);
    glColor3fv(colors[2]);
    triangle(a, d, b);
    glColor3fv(colors[3]);
    triangle(b, d, c);
}


//三角形细分
void divide_tetra(point3 a, point3 b, point3 c, point3 d, int m)
{
    point3 mid[6];
    int j;
    if(m>0)
    {
        //计算6个中点
        for(j=0; j<3; j++) mid[0][j]=(a[j]+b[j])/2;
        for(j=0; j<3; j++) mid[1][j]=(a[j]+c[j])/2;
        for(j=0; j<3; j++) mid[2][j]=(a[j]+d[j])/2;
        for(j=0; j<3; j++) mid[3][j]=(b[j]+c[j])/2;
        for(j=0; j<3; j++) mid[4][j]=(c[j]+d[j])/2;
        for(j=0; j<3; j++) mid[5][j]=(b[j]+d[j])/2;

        //通过细分绘制四面体

        divide_tetra(a, mid[0], mid[1], mid[2], m-1);
        divide_tetra(mid[0], b, mid[3], mid[5], m-1);
        divide_tetra(mid[1], mid[3], c, mid[4], m-1);
        divide_tetra(mid[2], mid[4], d, mid[5], m-1);

    }
    else(tetra(a,b,c,d)); //最后绘制四面体
}

//显示回调函数
void mydisplay()
{
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //清除 当前可写的颜色缓冲 深度缓冲
    glBegin(GL_TRIANGLES);
    divide_tetra(v[0], v[1], v[2], v[3], n);
    glEnd();
    
    glutSwapBuffers();  //双缓冲
    //glFlush();    //单缓冲
    
}

//鼠标点击响应函数
void mouseClick(int button, int state, int xMouse, int yMouse)
{
    
}

// 鼠标移动响应函数
void mouseMove(int xMouse, int yMouse)
{
    
    
}

//键盘回调函数：处理键盘上可以用ascii码表示的键按下的事件
void myKey(unsigned char key, int x, int y)
{
    //按ESC退出
    if(key == 27)
    {
        cout<<"exit"<<endl;
        exit(0);
    }
    
    
}

//键盘回调函数：处理一些特殊键(如：F1,F2,etc)按下的事件
void specialKeys(int key, int x, int y)
{
    switch (key)
    {
        case GLUT_KEY_LEFT:
            
            break;
        case GLUT_KEY_RIGHT:
            
            break;
        case GLUT_KEY_UP:
            
            break;
        case GLUT_KEY_DOWN:
            
            break;
        case GLUT_KEY_F1 :
            
            break;
        case GLUT_KEY_F2 :
            
            break;
        case GLUT_KEY_F3 :
            
            break;
        default:
            break;
    }
}


//属性初始化函数
void myInit()
{
    glMatrixMode(GL_PROJECTION);    //设置当前矩阵模式  GL_PROJECTION: 对投影矩阵应用随后的矩阵操作
    
    glLoadIdentity();   //重置当前指定的矩阵为单位矩阵
    
    gluOrtho2D(-2.0, 2.0, -2.0, 2.0);   //定义了一个二维图像投影矩阵
    //glOrtho(-1, 1, -1, 1, -1 , 1);    //定义了一个三维图像投影矩阵
    
    glMatrixMode(GL_MODELVIEW);     //设置当前矩阵模式  GL_MODELVIEW: 对模型视景矩阵堆栈应用随后的矩阵操作
    
    glClearColor(1.0,1.0,1.0,0.0);  //指定由glClear清除颜色缓存时所使用的红、绿、蓝和alpha值，指定值的范围固定为[0.0f，1.0f]
    
    glColor3f(0.0, 0.0, 0.0);   //颜色函数
    
    glEnable(GL_DEPTH_TEST);    //启用深度测试 根据坐标的远近自动隐藏被遮住的图形
}


//窗口大小改变响应函数
void changeSize(int w, int h)
{
    //防止除数即高度为0
    if(h == 0)  h = 1;
    
    float ratio = 1.0* w / h;
    
    // 单位化投影矩阵
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    // 设置视口大小为增个窗口大小
    glViewport(0, 0, w, h);
    
    // 设置正确的投影矩阵
    gluPerspective(45,ratio,1,1000);
    //下面是设置模型视图矩阵
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0,0.0,5.0, 0.0,0.0,-1.0,0.0f,1.0f,0.0f);
}


//空闲回调函数
void idle()
{
    glutPostRedisplay();
}


//菜单函数
void menu(int id)
{
    switch(id)
    {
        case 1:
            
            break;
            
        case 2:
            
            break;
            
        case 3:
            
            
            break;
            
        case 4:
            exit(0);
            break;
    }
    glutPostRedisplay();
}


int main(int argc, char ** argv)
{
    n = 2;  //循环次数
    
    glutInit(&argc, argv);  //初始化GLUT
    
    glutInitDisplayMode(GLUT_DOUBLE| GLUT_RGB | GLUT_DEPTH);
    
    glutInitWindowSize(windowWidth, windowHeight);  //设置窗口的大小
    
    GLint SCREEN_WIDTH=glutGet(GLUT_SCREEN_WIDTH);    //获取系统的宽像素
    GLint SCREEN_HEIGHT=glutGet(GLUT_SCREEN_HEIGHT);  //获取系统的高像素
    glutInitWindowPosition((SCREEN_WIDTH-windowWidth)/2,(SCREEN_HEIGHT-windowHeight)/2);    //窗口居中显示
    
    glutCreateWindow("Sierpinski 3D");   //设置窗口的名称
    
    glutIdleFunc(idle); //空闲时调用的函数
    
    glutReshapeFunc(changeSize);    //确保窗口大小改变，图形不被拉伸
    
    glutKeyboardFunc(myKey);   //设置键盘回调函数myKey
    
    glutSpecialFunc(specialKeys);    //设置键盘回调函数specialKeys
    
    glutMouseFunc(mouseClick); //鼠标点击事件
    
    glutMotionFunc(mouseMove);  //鼠标拖动事件
    
    glutDisplayFunc(mydisplay);   //设置显示回调函数mydisplay
    
    myInit(); //初始化属性
    
    glutMainLoop(); //进入GLUT事件处理循环，让所有的与“事件”有关的函数调用无限循环。在一个GLUT程序中，这个例程被调用一次。一旦被调用，这个程序将永远不会返回 。它将调用必要的任何已注册的回调。
    
    return 1;
}

