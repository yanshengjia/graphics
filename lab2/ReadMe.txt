本程序在 OSX 10.11.1 系统下编译通过。
如果要在Windows下编译运行运行需要把当前程序中的 #include <GLUT/glut.h> 替换成 #include <gl/GLUT.h> ，再将源文件和头文件拷贝入 Visual Studio 新工程，用 Visual Studio 编译运行即可。

Mac OSX 编译运行方法：
打开终端，cd到程序所在的路径，然后在终端中输入 g++ -framework OpenGL -framework GLUT -framework Foundation 源程序.cpp -o 1，运行则输入 ./1

举个栗子：
加入现在在 User/yanshengjia/Desktop 路径下有我们的OpenGL小程序 opengl.cpp

那么我们只需要在 终端 中输入：
cd /User/yanshengjia/Desktop, 回车
g++ -framework OpenGL -framework GLUT -framework Foundation opengl.cpp -o 1, 回车
./1, 回车
这样就能成功编译运行了。


按键操作：

A:人左转
D:人右转
W:人前进
S:人后退

J:飞机沿X轴负向移动
L:飞机沿X轴正向移动
I:飞机沿Z轴负向移动
K:飞机沿Z轴正向移动
O:飞机沿Y轴正向移动
P:飞机沿Y轴负向移动

R:复位
ESC:退出
,:视角放大
.:视角缩小

UP:飞机抬头
DOWN:飞机低头
LEFT:飞机左转
RIGHT:飞机右转

Z:苦力怕绕世界坐标系Y轴逆时针转
X:苦力怕绕世界坐标系Y轴顺时针转
C:苦力怕沿世界坐标系X轴正向移动
V:苦力怕沿世界坐标系Y轴正向移动

鼠标操作：
点击左键：放大
点击右键：缩小
左键选中：转换视角

功能：

人
1.绕自身坐标系Y轴旋转
2.朝面对的方向前进，后退
3.肢体摆动，松开按键停止摆动

飞机：
1.沿世界坐标系XYZ轴运动
2.绕世界坐标系旋转
3.复位

苦力怕：
1.绕世界坐标系Y轴旋转
2.沿世界坐标轴X轴移动

其他：
初始位置在屏幕中心
设置光照模型
设置材质属性
影藏面消除
视角放大缩小
视角转换
ESC退出






