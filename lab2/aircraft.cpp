//Aircraft
//created by yanshengjia
//2015.11.1


#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GLUT/glut.h>  // Mac OSX
//#include <gl/glut.h>  // Windows
using namespace std;


//旋转参数
static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;

bool flag = false;  //鼠标选中标志

//显示回调函数
void mydisplay(void)
{
  // 用当前清除颜色清除窗口
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // 保留矩阵状态并旋转
  glPushMatrix();
    glRotatef(xRot, 1.0f, 0.0f, 0.0f);  // 绕X轴旋转
    glRotatef(yRot, 0.0f, 1.0f, 0.0f);  // 绕Y轴旋转

    glBegin(GL_TRIANGLES);

      // 机头
      glColor3f(0.79f, 0.08f, 0.14f);  // 深红
      glVertex3f(-15.0f, 0.0f, 30.0f);
      glVertex3f(15.0f, 0.0f, 30.0f);
      glVertex3f(0.0f, 0.0f, 60.0f);

      glColor3f(0.97f, 0.29f, 0.30f);  // 粉红
      glVertex3f(-15.0f, 0.0f, 30.0f);
      glVertex3f(0.0f, 0.0f, 60.0f);
      glVertex3f(0.0f, 15.0f, 30.0f);

      glColor3f(1.0f, 0.51f, 0.0f);  // 橘黄
      glVertex3f(0.0f, 0.0f, 60.0f);
      glVertex3f(15.0f, 0.0f, 30.0f);
      glVertex3f(0.0f, 15.0f, 30.0f);

      // 机身
      glColor3f(0.0f, 1.0f, 0.0f);  // 亮绿
      glVertex3f(-15.0f, 0.0f, 30.0f);
      glVertex3f(0.0f, 15.0f, 30.0f);
      glVertex3f(0.0f, 0.0f, -53.0f);

      glColor3f(1.0f, 1.0f, 0.0f);  // 明黄
      glVertex3f(0.0f, 15.0f, 30.0f);
      glVertex3f(15.0f, 0.0f, 30.0f);
      glVertex3f(0.0f, 0.0f, -53.0f);

      glColor3f(0.73f, 0.0f, 0.57f);  // 紫色
      glVertex3f(15.0f, 0.0f, 30.0f);
      glVertex3f(-15.0f, 0.0f, 30.0f);
      glVertex3f(0.0f, 0.0f, -53.0f);

      // 机尾巴
      glColor3f(0.79f, 0.08f, 0.14f);  // 深红
      glVertex3f(0.0f, 0.0f, -53.0f);
      glVertex3f(0.0f, 0.0f, -70.0f);
      glVertex3f(0.0f, 15.0f, -70.0f);

      glColor3f(0.97f, 0.29f, 0.30f);  // 粉红
      glVertex3f(-15.0f, 0.0f, -70.0f);
      glVertex3f(0.0f, 0.0f, -53.0f);
      glVertex3f(0.0f, 0.0f, -70.0f);

      glColor3f(1.0f, 0.51f, 0.0f);  // 橘黄
      glVertex3f(15.0f, 0.0f, -70.0f);
      glVertex3f(0.0f, 0.0f, -70.0f);
      glVertex3f(0.0f, 0.0f, -53.0f);

      // 由于背面被消除，背面再画一次
      glColor3f(0.73f, 0.0f, 0.57f);  // 紫色
      glVertex3f(0.0f, 0.0f, -70.0f);
      glVertex3f(0.0f, 0.0f, -53.0f);
      glVertex3f(0.0f, 15.0f, -70.0f);


      glColor3f(1.0f, 1.0f, 0.0f);  // 明黄
      glVertex3f(0.0f, 0.0f, -53.0f);
      glVertex3f(-15.0f, 0.0f, -70.0f);
      glVertex3f(0.0f, 0.0f, -70.0f);

      glColor3f(1.0f, 1.0f, 0.0f);  // 明黄
      glVertex3f(0.0f, 0.0f, -70.0f);
      glVertex3f(15.0f, 0.0f, -70.0f);
      glVertex3f(0.0f, 0.0f, -53.0f);

      // 机翼下侧面
      glColor3ub(158,196,246);  // 紫蓝
      glVertex3f(0.0f,2.0f,27.0f);
      glVertex3f(-60.0f, 2.0f, -8.0f);
      glVertex3f(60.0f, 2.0f, -8.0f);

      // 左翼
      glColor3f(0.2f, 0.08f, 0.69f);  // 深蓝
      glVertex3f(60.0f, 2.0f, -8.0f);
      glVertex3f(0.0f, 7.0f, -8.0f);
      glVertex3f(0.0f,2.0f,27.0f);

      // 右翼
      glColor3f(0.2f, 0.08f, 0.69f);  // 深蓝
      glVertex3f(0.0f,2.0f,27.0f);
      glVertex3f(0.0f, 7.0f, -8.0f);
      glVertex3f(-60.0f, 2.0f, -8.0f);

      // 机翼后侧面
      glColor3ub(192,192,192);
      glVertex3f(60.0f, 2.0f, -8.0f);
      glVertex3f(-60.0f, 2.0f, -8.0f);
      glVertex3f(0.0f,7.0f,-8.0f);

    glEnd();
  glPopMatrix();

  glutSwapBuffers();
}


// ASCII码按键回调函数
void myKey(unsigned char key, int x, int y)
{
    // 按ESC退出
    if(key == 27)
    {
        cout<<"exit"<<endl;
        exit(0);
    }
}


// 特殊按键回调函数
void SpecialKeys(int key, int x, int y)
{
  if(key == GLUT_KEY_UP)
    xRot-= 5.0f;

  if(key == GLUT_KEY_DOWN)
    xRot += 5.0f;

  if(key == GLUT_KEY_LEFT)
    yRot -= 5.0f;

  if(key == GLUT_KEY_RIGHT)
    yRot += 5.0f;

  if(key > 356.0f)
    xRot = 0.0f;

  if(key < -1.0f)
    xRot = 355.0f;

  if(key > 356.0f)
    yRot = 0.0f;

  if(key < -1.0f)
    yRot = 355.0f;

  // 刷新窗口
  glutPostRedisplay();
}


//鼠标点击回调函数
void mouseClick(int button, int state, int xMouse, int yMouse)
{
    if( (button==GLUT_LEFT_BUTTON) && (state==GLUT_DOWN) )
    {
        // 判断鼠标位置是否在图形中

        // 选中图形才能拖动
        if(xMouse<50000 && yMouse<50000)      // 在窗口中都能拖动
        //if( (xMouse-250)/250.0-(xMove-R)>=0 && (xMouse-250)/250.0-(xMove-R)<=2*R && (250-yMouse)/250.0-(yMove-R)>=0 && (250-yMouse)/250.0-(yMove-R)<=2*R )
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

        glutPostRedisplay(); // 重绘函数
    }
}


//窗口拉伸 图形不变形
void reshape(int w, int h)
{
  GLfloat nRange = 80.0f;
  // Prevent a divide by zero
  if(h == 0)
    h = 1;

  // Set Viewport to window dimensions
  glViewport(0, 0, w, h);

  // Reset coordinate system
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  // Establish clipping volume (left, right, bottom, top, near, far)
  if (w <= h)
    glOrtho (-nRange, nRange, -nRange*h/w, nRange*h/w, -nRange, nRange);
  else
    glOrtho (-nRange*w/h, nRange*w/h, -nRange, nRange, -nRange, nRange);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

// 空闲回调函数
void idle()
{
    glutPostRedisplay();
}


// 着色环境初始化
void myInit()
{
  //GLfloat ambientLight[] = {0.5f, 0.5f, 0.5f, 1.0f};
  GLfloat ambientLight[] = {1.0f, 1.0f, 1.0f, 1.0f};  // 明亮的白光
  glEnable(GL_DEPTH_TEST);    // Hidden surface removal
  glEnable(GL_CULL_FACE);        // Do not calculate inside of jet
  glFrontFace(GL_CCW);        // Counter clock-wise polygons face out

  glEnable(GL_COLOR_MATERIAL);  // 开启颜色追踪
  glEnable(GL_LIGHTING);

  // 设置混色函数取得半透明效果
  // glBlendFunc(GL_SRC_ALPHA,GL_ONE);
  // glShadeModel(GL_SMOOTH);
  // glEnable(GL_BLEND);

  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight); // 设置光照模型

  glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);  // 设置颜色追踪的材料属性以及多边形的面

  glClearColor(0.745f, 1.0f, 0.973f, 0.0f); // 背景天蓝色
}


// 主函数
int main(int argc, char* argv[])
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

  // 设置程序的窗口大小
  GLint windowWidth = 800;
  GLint windowHeight = 600;
  glutInitWindowSize(windowWidth, windowHeight);

  // 获取屏幕的宽和高
  GLint SCREEN_WIDTH=glutGet(GLUT_SCREEN_WIDTH);
  GLint SCREEN_HEIGHT=glutGet(GLUT_SCREEN_HEIGHT);

  glutInitWindowPosition((SCREEN_WIDTH-windowWidth)/2,(SCREEN_HEIGHT-windowHeight)/2);

  glutCreateWindow("Aircraft");
  glutIdleFunc(idle);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(myKey);
  glutSpecialFunc(SpecialKeys);
  glutMouseFunc(mouseClick);
  glutMotionFunc(mouseMove);
  glutDisplayFunc(mydisplay);
  myInit();
  glutMainLoop();

  return 0;
}
