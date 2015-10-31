//
//  sierpinski2D.cpp
//  sierpinski2D
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

typedef GLfloat point2[2];  //元素类型为GLfloat,元素个数为2的数组类型point2

point2 v[]={{-1.0, -0.58}, {1.0, -0.58}, {0.0, 1.15}};  //初始化三角形

int n;  //循环次数


//绘制三角形
void triangle(point2 a, point2 b, point2 c)
{
    //显示三角形
    glBegin(GL_TRIANGLES);
    glVertex2fv(a);
    glVertex2fv(b);
    glVertex2fv(c);
    glEnd();
}


//三角形细分
void divideTriangle(point2 a, point2 b, point2 c, int m)
{
    //使用顶点个数来细分三角形
    point2 v0, v1, v2;
    int j;
    if(m>0)
    {
        for(j=0; j<2; j++) v0[j]=(a[j]+b[j])/2;
        for(j=0; j<2; j++) v1[j]=(a[j]+c[j])/2;
        for(j=0; j<2; j++) v2[j]=(b[j]+c[j])/2;
        divideTriangle(a, v0, v1, m-1);
        divideTriangle(c, v1, v2, m-1);
        divideTriangle(b, v2, v0, m-1);
    }
    else(triangle(a,b,c));
    //在循环的最后画出三角形
}


//显示回调函数
void mydisplay()
{
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //清除 当前可写的颜色缓冲 深度缓冲
    divideTriangle(v[0], v[1], v[2], n);
    
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
void init()
{
    glMatrixMode(GL_PROJECTION);    //设置当前矩阵模式  GL_PROJECTION: 对投影矩阵应用随后的矩阵操作
    
    glLoadIdentity();   //重置当前指定的矩阵为单位矩阵
    
    gluOrtho2D(-2.0, 2.0, -2.0, 2.0);   //定义了一个二维图像投影矩阵
    //glOrtho(-1, 1, -1, 1, -1 , 1);    //定义了一个三维图像投影矩阵
    
    glMatrixMode(GL_MODELVIEW);     //设置当前矩阵模式  GL_MODELVIEW: 对模型视景矩阵堆栈应用随后的矩阵操作
    
    glClearColor(1.0,1.0,1.0,0.0);  //指定由glClear清除颜色缓存时所使用的红、绿、蓝和alpha值，指定值的范围固定为[0.0f，1.0f]
    
    glColor3f(0.0, 0.0, 0.0);   //颜色函数
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
    n = 6;  //循环次数
    
    glutInit(&argc, argv);  //初始化GLUT
    
    glutInitDisplayMode(GLUT_DOUBLE| GLUT_RGB | GLUT_DEPTH);
    
    glutInitWindowSize(windowWidth, windowHeight);  //设置窗口的大小
    
    GLint SCREEN_WIDTH=glutGet(GLUT_SCREEN_WIDTH);    //获取系统的宽像素
    GLint SCREEN_HEIGHT=glutGet(GLUT_SCREEN_HEIGHT);  //获取系统的高像素
    glutInitWindowPosition((SCREEN_WIDTH-windowWidth)/2,(SCREEN_HEIGHT-windowHeight)/2);    //窗口居中显示
    
    glutCreateWindow("Sierpinski 2D");   //设置窗口的名称
    
    glutIdleFunc(idle); //空闲时调用的函数
    
    glutReshapeFunc(changeSize);    //确保窗口大小改变，图形不被拉伸
    
    glutKeyboardFunc(myKey);   //设置键盘回调函数myKey
    
    glutSpecialFunc(specialKeys);    //设置键盘回调函数specialKeys
    
    glutMouseFunc(mouseClick); //鼠标点击事件
    
    glutMotionFunc(mouseMove);  //鼠标拖动事件
    
    glutDisplayFunc(mydisplay);   //设置显示回调函数mydisplay
    
    init(); //初始化属性
    
    glutMainLoop(); //进入GLUT事件处理循环，让所有的与“事件”有关的函数调用无限循环。在一个GLUT程序中，这个例程被调用一次。一旦被调用，这个程序将永远不会返回 。它将调用必要的任何已注册的回调。
    
    return 1;
}

