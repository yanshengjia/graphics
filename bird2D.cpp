//
//  main.cpp
//  lab1_anaimal2D
//
//  Created by 严晟嘉 on 15/10/12.
//  Copyright (c) 2015年 Shengjia Yan. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <GLUT/GLUT.h>
using namespace std;


typedef GLfloat point2[2];
typedef GLfloat point3[3];
const GLfloat R = 0.5f;
const GLfloat Pi = 3.1415926536f;
point3 v[] = { { -1.0, 0 ,0},{ 0, 1 ,-1},{ 1, 0 ,0} ,{ 0, 0 ,2 } };
float nose_x=0;
point2 v2[] = { {nose_x,-0.5},{-0.1,0} ,{ 0.1,0} };
int n;
float yMove = 0;
float xMove = 0;

//设置程序的窗口大小
GLint windowWidth=500;
GLint windowHeight=500;

//获取屏幕的宽度与高度
GLint SCREEN_WIDTH=glutGet(GLUT_SCREEN_WIDTH);    //获取系统的宽像素
GLint SCREEN_HEIGHT=glutGet(GLUT_SCREEN_HEIGHT);  //获取系统的高像素


static bool flag = false;    // 点击时鼠标位置是否在图形

float red=1.0, blue=1.0, green=1.0;


void mydisplay()
{
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    int n = 10000;
    //左翅膀
    glBegin(GL_POLYGON);
    glColor3f(1,1,0);
    for (int i = 0; i < n; ++i) {
        glVertex2f(0.75 * R * cos( Pi / n*i + Pi*5/6) - 0.6 + xMove , 0.75 * R * sin( Pi / n*i + Pi*5/6) + 0.25 + yMove );
        
    }
    glEnd();
    
    //右翅膀
    glBegin(GL_POLYGON);
    glColor3f(1,1,0);
    for (int i = 0; i < n; ++i) {
        glVertex2f(0.75 * R * cos(Pi / n*i + Pi * 7 / 6) + 0.6 + xMove , 0.75 * R * sin(Pi / n*i + Pi * 7 / 6) + 0.25 + yMove );
        
    }
    glEnd();
    
    //脸轮廓
    glBegin(GL_POLYGON);
    glColor3f(238.0/255, 99.0/255, 99.0/255);
    for (int i = 0; i < n; ++i)
        glVertex2f(R*cos(2 * Pi / n*i) + xMove ,R*sin(2 * Pi / n*i) + yMove );
    glEnd();
    
    //描边
    glLineWidth(10);//设置线宽
    glEnable(GL_LINE_SMOOTH);
    glBegin(GL_POINT);
    glColor3f(0 / 255, 0 / 255, 0 / 255);
    for (int i = 0; i < n; ++i)
        glVertex2f(R*cos(2 * Pi / n*i) + xMove , R*sin(2 * Pi / n*i) + yMove );
    glEnd();
    
    
    //左眼睛
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 0);
    for (int i = 0; i < n; ++i) {
        glVertex2f(0.075*cos(2 * Pi / n*i) - 0.25 + xMove , 0.075*sin(2 * Pi / n*i) + 0.1 + yMove );
        
    }
    glEnd();
    //右眼睛
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 0);
    for (int i = 0; i < n; ++i) {
        glVertex2f(0.075*cos(2 * Pi / n*i) + 0.25 + xMove , 0.075*sin(2 * Pi / n*i) + 0.1+ yMove );
    }
    glEnd();
    
    
    //左眼珠
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    for (int i = 0; i < n; ++i) {
        glVertex2f(0.025*cos(2 * Pi / n*i) - 0.25 + xMove , 0.055*sin(2 * Pi / n*i) + 0.1 + yMove );
        
    }
    glEnd();
    //右眼珠
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    for (int i = 0; i < n; ++i) {
        glVertex2f(0.025*cos(2 * Pi / n*i) + 0.25 + xMove , 0.055*sin(2 * Pi / n*i) + 0.1 + yMove );
    }
    glEnd();
    
    //鼻子
    glBegin(GL_TRIANGLES);
    glColor3f(1,1,0);
    glVertex2f(nose_x + xMove , v2[0][1]+ yMove );
    glVertex2f(v2[1][0] + xMove , v2[1][1]+ yMove );
    glVertex2f(v2[2][0] + xMove , v2[2][1]+ yMove );
    glEnd();
    
    //glutSwapBuffers();
    glFlush();
    
}

//鼠标点击响应函数
void mouseClick(int button, int state, int xMouse, int yMouse)
{
    if( (button==GLUT_LEFT_BUTTON) && (state==GLUT_DOWN) )
    {
        // 判断鼠标位置是否在矩形中
        if( abs(xMouse)<50000 && abs(yMouse)<50000 )
        {
            cout<<"flag-true"<<endl;
            flag = true;
        }
    }
    else if( (button==GLUT_LEFT_BUTTON) && (state==GLUT_UP) )
        {
            cout<<"flag-false"<<endl;
            flag = false;
        }
}

// 鼠标移动响应函数
void mouseMove(int xMouse, int yMouse)
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    if(flag == true)
    {
        cout<<"xMouse:"<<xMouse<<" yMouse:"<<yMouse<<endl;
        
        xMove = (xMouse-250)/150.0;
        
        yMove = (250-yMouse)/150.0;
        
        
        cout<<xMove<<" "<<yMove<<endl;
        glutPostRedisplay(); // 重绘函数
    }
}

//键盘回调函数：ESC退出
void myKey(unsigned char key, int x, int y)
{
    //按1鼻子左移
    if(key == 49)
    {
        cout<<"nose->left"<<endl;
        nose_x -= 0.05;
        glutPostRedisplay();
    }
    
    //按2鼻子右移
    if(key == 50)
    {
        cout<<"nose->right"<<endl;
        nose_x += 0.05;
        glutPostRedisplay();
    }
    
    //按ESC退出
    if(key == 27)
    {
        cout<<"exit"<<endl;
        exit(0);
    }
    
    //按空格跳跃
    if(key == 32)
    {
        cout<<"jump!"<<endl;
        yMove += R;
        mydisplay();
        for(int i=0; i<100000000; i++)  ;
        yMove -= R;
        mydisplay();
    }
}

//键盘回调函数：F1 F2 F3改变颜色，UP DOWN LEFT RIGHT控制移动
void specialKeys(int key, int x, int y)
{
    switch (key)
    {
        case GLUT_KEY_LEFT:
            cout<<"left"<<endl;
            xMove -= R/4;
            glutPostRedisplay();
            break;
        case GLUT_KEY_RIGHT:
            cout<<"right"<<endl;
            xMove += R/4;
            glutPostRedisplay();
            break;
        case GLUT_KEY_UP:
            cout<<"up"<<endl;
            yMove += R/4;
            glutPostRedisplay();
            break;
        case GLUT_KEY_DOWN:
            cout<<"down"<<endl;
            yMove -= R/4;
            glutPostRedisplay();
            break;
        case GLUT_KEY_F1 :
            red = 1.0;
            green = 0.0;
            blue = 0.0;
            break;
        case GLUT_KEY_F2 :
            red = 0.0;
            green = 1.0;
            blue = 0.0;
            break;
        case GLUT_KEY_F3 :
            red = 0.0;
            green = 0.0;
            blue = 1.0;
            break;
        default:
            break;
    }
}


//属性初始化函数
void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1 , 1);
    glMatrixMode(GL_MODELVIEW);
    glClearColor(1.0,1.0,1.0,0.0);
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
            glutIdleFunc(idle);
            break;
            
        case 2:
            glutIdleFunc(NULL);
            break;
           
        case 3:
            nose_x=0.0;
            xMove=0.0;
            yMove=0.0;
            mydisplay();
            break;
            
        case 4:
            exit(0);
            break;
    }
    glutPostRedisplay();
}


int main(int argc, char ** argv)
{
    glutInit(&argc, argv);  //初始化GLUT
    
    glutInitDisplayMode(GLUT_SINGLE| GLUT_RGB | GLUT_DEPTH);
    
    glutInitWindowSize(windowWidth, windowHeight);  //设置窗口的大小
    
    GLint SCREEN_WIDTH=glutGet(GLUT_SCREEN_WIDTH);    //获取系统的宽像素
    GLint SCREEN_HEIGHT=glutGet(GLUT_SCREEN_HEIGHT);  //获取系统的高像素
    glutInitWindowPosition((SCREEN_WIDTH-windowWidth)/2,(SCREEN_HEIGHT-windowHeight)/2);    //窗口居中显示
    
    glutCreateWindow("bird");   //设置窗口的名称
    
    //设置弹出式菜单
    glutCreateMenu(menu);
    glutAddMenuEntry("start rotating", 1);
    glutAddMenuEntry("stop rotating", 2);
    glutAddMenuEntry("revoke", 3);
    glutAddMenuEntry("quit", 4);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    
    glutDisplayFunc(mydisplay);   //设置显示回调函数mydisplay
    
    glutIdleFunc(idle); //空闲时调用的函数
    
    glutReshapeFunc(changeSize);    //确保窗口大小改变，图形不被拉伸
    
    glutKeyboardFunc(myKey);   //设置键盘回调函数myKey

    glutSpecialFunc(specialKeys);    //设置键盘回调函数specialKeys
   
    glutMouseFunc(mouseClick); //鼠标点击事件
    
    glutMotionFunc(mouseMove);  //鼠标拖动事件
    
    init(); //初始化属性
    
    glutMainLoop(); //进入GLUT事件处理循环，让所有的与“事件”有关的函数调用无限循环。在一个GLUT程序中，这个例程被调用一次。一旦被调用，这个程序将永远不会返回 。它将调用必要的任何已注册的回调。
    
    return 0;
}

