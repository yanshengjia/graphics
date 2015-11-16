#include "Param.h"

void init()
{
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);


	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);

	GLfloat ambientLight[] = { 1.0f, 1.0f, 1.0f, 1.0f };  // �����İ׹�
	glEnable(GL_DEPTH_TEST);    // Hidden surface removal
	glEnable(GL_CULL_FACE);        // Do not calculate inside of jet
	glFrontFace(GL_CCW);        // Counter clock-wise polygons face out

	glEnable(GL_COLOR_MATERIAL);  // ������ɫ׷��
	glEnable(GL_LIGHTING);

	//���û�ɫ����ȡ�ð�͸��Ч��
	//glBlendFunc(GL_SRC_ALPHA,GL_ONE);
	//glShadeModel(GL_SMOOTH);
	//glEnable(GL_BLEND);

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight); // ���ù���ģ��

	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);  // ������ɫ׷�ٵĲ��������Լ������ε���
}

void human()
{
	// ��
	glPushMatrix();
	glTranslatef(man.x, man.y, man.z);
	glRotatef(man.vangle, 0, 1, 0);

	////////////////////////////Hair//////////////////////////
	glColor3f(0.0f, 0.0f, 0.0f);
	glPushMatrix();
	glTranslatef(man.hair.x, man.hair.y, man.hair.z);
	glScalef(man.hair_scale.x, man.hair_scale.y, man.hair_scale.z);
	glutSolidCube(1);
	glPopMatrix();

	///////////////////////////Head////////////////////////////
	// head
	glColor3f(139.0 / 255, 115.0 / 255, 85.0 / 255);
	glPushMatrix();
	glTranslatef(man.head.x, man.head.y, man.head.z);
	glScalef(man.head_scale.x, man.head_scale.y, man.head_scale.z);
	glutSolidCube(1);
	glPopMatrix();

	// left eye
	glColor3f(0.9f, 0.9f, 0.9f);
	glPushMatrix();
	glTranslatef(man.eyeL.x, man.eyeL.y, man.eyeL.z);
	glScalef(man.eye_scale.x, man.eye_scale.y, man.eye_scale.z);
	glutSolidCube(1);
	glPopMatrix();

	// right eye
	glColor3f(0.9f, 0.9f, 0.9f);
	glPushMatrix();
	glTranslatef(man.eyeR.x, man.eyeR.y, man.eyeR.z);
	glScalef(man.eye_scale.x, man.eye_scale.y, man.eye_scale.z);
	glutSolidCube(1);
	glPopMatrix();

	// mouth
	glColor3f(1, 1, 1);
	glPushMatrix();
	glTranslatef(man.mouth.x, man.mouth.y, man.mouth.z);
	glScalef(man.mouth_scale.x, man.mouth_scale.y, man.mouth_scale.z);
	glutSolidCube(1);
	glPopMatrix();


	///////////////////////////Body////////////////////////////
	glColor3f(0.0f, 206.0 / 255, 209.0 / 255);
	glPushMatrix();
	glTranslatef(man.body.x, man.body.y, man.body.z);
	glScalef(man.body_scale.x, man.body_scale.y, man.body_scale.z);
	glutSolidCube(1);
	glPopMatrix();

	/////////////////////////Leg/////////////////////////
	//Left leg
	glColor3f(67.0 / 255, 110.0 / 255, 238.0 / 255);
	glPushMatrix();
	glTranslatef(man.thighL.x, 2 * man.thighL.y, man.thighL.z);
	glRotatef(man.ltangle, 0, 0, 1);
	glTranslatef(0, -man.thighR.y, 0);
	glScalef(man.thigh_scale.x, man.thigh_scale.y, man.thigh_scale.z);
	glutSolidCube(1);
	glPopMatrix();

	//Right leg
	glColor3f(67.0 / 255, 110.0 / 255, 238.0 / 255);
	glPushMatrix();
	glTranslatef(man.thighR.x,2 * man.thighR.y, man.thighR.z);
	glRotatef(man.rtangle, 0, 0, 1);
	glTranslatef(0, - man.thighR.y,0);
	glScalef(man.thigh_scale.x, man.thigh_scale.y, man.thigh_scale.z);
	glutSolidCube(1);
	glPopMatrix();

	///////////////////////Arm////////////////////////

	//Left Arm
	glColor3f(139.0 / 255, 115.0 / 255, 85.0 / 255);
	glPushMatrix();
	glTranslatef(man.armL.x, man.arm_scale.y / 2 + man.armL.y, man.armL.z);
	glRotatef(man.laangle, 0, 0, 1);
	glTranslatef(0, -man.arm_scale.y / 2, 0);
	glScalef(man.arm_scale.x, man.arm_scale.y, man.arm_scale.z);
	glutSolidCube(1);
	glPopMatrix();

	//Right Arm
	glColor3f(139.0 / 255, 115.0 / 255, 85.0 / 255);
	glPushMatrix();
	glTranslatef(man.armR.x, man.arm_scale.y / 2 + man.armR.y, man.armR.z);
	glRotatef(man.raangle, 0, 0, 1);
	glTranslatef(0, -man.arm_scale.y / 2, 0);
	glScalef(man.arm_scale.x, man.arm_scale.y, man.arm_scale.z);
	glutSolidCube(1);
	glPopMatrix();




	glPopMatrix();
}

void reference()
{
	glColor3f(0.0f, 0.0f, 0.0f);
	glPushMatrix();
	glScalef(1, 4, 1);
	glutSolidCube(1);
	glPopMatrix();


}

void floor()
{
	glColor3f(0.3f, 1.0f, 0.3f);
	for (int i = 0; i < NUM_OF_LINE * 2; i++)
	{
		glBegin(GL_LINES);
		glVertex3f((NUM_OF_LINE - i) * BLOCK_SIZE, 0, NUM_OF_LINE * BLOCK_SIZE);
		glVertex3f((NUM_OF_LINE - i) * BLOCK_SIZE, 0, -NUM_OF_LINE * BLOCK_SIZE);
		glVertex3f(NUM_OF_LINE * BLOCK_SIZE, 0, (NUM_OF_LINE - i) * BLOCK_SIZE);
		glVertex3f(-NUM_OF_LINE * BLOCK_SIZE, 0, (NUM_OF_LINE - i) * BLOCK_SIZE);
		glEnd();
	}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	floor();
	human();
	reference();
	//crawler();


	glutSwapBuffers();
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//gluPerspective(75.0, (GLfloat)scr_w / scr_h, near_sight, far_sight);

	if (view_person == FIRST_PERSON)
	{
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		cameraAt.x = man.x;
		cameraAt.y = man.head.y;
		cameraAt.z = man.z;

		lookAt.x = man.x + 5 * cos(man.vangle / 180.0 * PI);
		lookAt.y = man.hair.y;
		lookAt.z = man.z - 5 * sin(man.vangle / 180.0 * PI);

		gluLookAt(cameraAt.x, cameraAt.y, cameraAt.z,
			lookAt.x, lookAt.y, lookAt.z,
			0.0f, 1.0f, 0.0f);
	}
	else if(view_person == GOD)
	{
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		if (!reset_god)
		{
			cameraAt = godAt;
			lookAt.x = 0;
			lookAt.y = 0;
			lookAt.z = 0;
			reset_god = true;
		}

		gluLookAt(cameraAt.x, cameraAt.y, cameraAt.z,
			lookAt.x, lookAt.y, lookAt.z,
			0.0f, 1.0f, 0.0f);
	}
	else if(view_person == THIRD_PERSON)
	{
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		cameraAt.x = man.x - 10 * cos(man.vangle / 180.0 * PI);
		cameraAt.y = man.head.y + 10;
		cameraAt.z = man.z + 10 * sin(man.vangle / 180.0 * PI);

		lookAt.x = man.x;
		lookAt.y = man.hair.y;
		lookAt.z = man.z;

		gluLookAt(cameraAt.x, cameraAt.y, cameraAt.z,
			lookAt.x, lookAt.y, lookAt.z,
			0.0f, 1.0f, 0.0f);
	}
	else if (view_person == BALL)
	{
		if (trackballMove)
		{
			glRotatef(angle, axis[0], axis[1], axis[2]);
		}
	}

	//cout <<"x:"<< human_x <<"y:"<< human_y<<"z:"<< human_z<< endl;


}

// ����ƽ������Ӧ�������ϵ�λ�ã�����ֵ��v��
void trackball_ptov(int x, int y, int width, int height, float v[3])
{
	// ��x,yͶӰ����width��height��Χ�ڵİ�������
	float d, a;

	/// ����ϵ�任��ʵ�ֹ�һ��x��y�ķ�ΧΪ��-1,1��
	v[0] = (2.0F*x - width) / width;
	v[1] = (height - 2.0*y) / height;
	d = (float)sqrt(v[0] * v[0] + v[1] * v[1]);
	v[2] = (float)cos((PI / 2.0F) * ((d < 1.0F) ? d : 1.0F));	  // һ�ֶ�Ӧ�����������������㲻�ڰ��򸲸Ƿ�Χ�ڵ�����				
	a = 1 / (float)sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]); // ��һ��
	v[0] *= a;
	v[1] *= a;
	v[2] *= a;
}

void startMotion(int x, int y)
{
	trackingMouse = true;
	redrawContinue = false;
	startX = x; startY = y;
	curx = x; cury = y;
	trackball_ptov(x, y, scr_w, scr_h, lastPos);
	trackballMove = true;
}

void stopMotion(int x, int y)
{
	trackingMouse = false;

	//  if (startX != x || startY != y)	 // �������귢���ƶ����������Զ�ת��
	//  {
	//  	redrawContinue = true;
	//  } 
	//  else	// ��������������û���ƶ�����ֹͣ�Զ�ת��
	//  {
	angle = 0.0F;
	redrawContinue = false;
	trackballMove = false;
	//  }
}

void passiveMotion(int x, int y)
{
	man.vangle = (man.vangle - (x - scr_w / 2) / 150);
}

void refresh(int c)
{
	//center.y = -(1 - sin(-left_thigh_angle / 180.0 * PI)) * basic_size * THIGH_SCALE_X + basic_size * FOOT_SCALE_Y / 2;
	if (man.isMoving())
	{
		if (man.ltangle < -60)
		{
			left_forward = false;
		}
		else if (man.ltangle > 60)
		{
			left_forward = true;
		}
		if (man.rtangle < -60)
		{
			right_forward = false;
		}
		else if (man.rtangle > 60)
		{
			right_forward = true;
		}
		if (left_forward)
		{
			man.ltangle--;
			man.laangle++;
		}
		else
		{
			man.ltangle++;
			man.laangle--;
		}
		if (right_forward)
		{
			man.rtangle--;
			man.raangle++;
		}
		else
		{
			man.rtangle++;
			man.raangle--;
		}

	}
	else 
	{
		man.raangle = 0;
		man.laangle = 0;
		man.rtangle = 0;
		man.ltangle = 0;
	}
	glutTimerFunc(DELAY, refresh, 0);
	glutPostRedisplay();
}

void reshape(int w, int h)
{
	scr_w = w;
	scr_h = h;
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(75.0, (GLfloat)scr_w / scr_h, near_sight, far_sight);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	//�л��ӽ�
	//gluLookAt(lookatX,lookatY,lookatZ,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f);
	//gluLookAt(lookatX, lookatY, lookatZ, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
}

void mouse(int button, int state, int x, int y)
{
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		//�ӽǷŴ�
		if (state == GLUT_DOWN && near_sight * VIEW_SCALE > 5)
		{
			/*near_sight /= VIEW_SCALE;
			far_sight /= VIEW_SCALE;*/
			cameraAt.x /= VIEW_SCALE;
			cameraAt.y /= VIEW_SCALE;
			cameraAt.z /= VIEW_SCALE;

			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(35.0, (float)scr_w / scr_h, near_sight, far_sight);
			//glMatrixMode(GL_MODELVIEW);
			//glLoadIdentity();
			//gluLookAt(lookatX * view_stretch, lookatY * view_stretch, lookatZ * view_stretch, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
		}
		break;
	case GLUT_RIGHT_BUTTON:
		// �ӽ�����
		if (state == GLUT_DOWN && far_sight / VIEW_SCALE <1000)
		{
			/*near_sight *= VIEW_SCALE;
			far_sight *= VIEW_SCALE;*/
			cameraAt.x *= VIEW_SCALE;
			cameraAt.y *= VIEW_SCALE;
			cameraAt.z *= VIEW_SCALE;

			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(35.0, (float)scr_w / scr_h, near_sight, far_sight);
			//glMatrixMode(GL_MODELVIEW);
			//glLoadIdentity();
			//gluLookAt(lookatX * view_stretch, lookatY * view_stretch, lookatZ * view_stretch, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
		}
		break;
	}
}

void mouseButton(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
		switch (state)
		{
		case GLUT_DOWN:
			y = scr_h - y;
			startMotion(x, y);
			break;
		case GLUT_UP:
			stopMotion(x, y);
			break;
		}
}

// �����ƶ��ص�����
void mouseMotion(int x, int y)
{
	float curPos[3], dx, dy, dz;

	trackball_ptov(x, y, scr_w, scr_h, curPos);

	if (trackingMouse)
	{
		// ����������
		dx = curPos[0] - lastPos[0];
		dy = curPos[1] - lastPos[1];
		dz = curPos[2] - lastPos[2];

		// ���߲���ͬʱΪ0�������൱��û��
		if (dx || dy || dz)
		{
			// ������ת�Ƕȣ���ת�Ƕ���sin�ǶȽ���
			angle = 90.0F * sqrt(dx*dx + dy*dy + dz*dz);

			// �����������õ���ת��
			axis[0] = lastPos[1] * curPos[2] - lastPos[2] * curPos[1];
			axis[1] = lastPos[2] * curPos[0] - lastPos[0] * curPos[2];
			axis[2] = lastPos[0] * curPos[1] - lastPos[1] * curPos[0];

			// ������λ������
			lastPos[0] = curPos[0];
			lastPos[1] = curPos[1];
			lastPos[2] = curPos[2];
		}
	}
	glutPostRedisplay();
}
// ���лص�����
void idle()
{
	// �������귢���ƶ����������Զ�ת��
	if (redrawContinue) glutPostRedisplay();
}
// ��������
void control(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'a':
		man.move = true;
		man.x -= man.speed * sin(man.vangle / 180 * PI);
		man.z -= man.speed * cos(man.vangle / 180 * PI);
		break;
	case 'd':
		man.move = true;
		man.x += man.speed * sin(man.vangle / 180 * PI);
		man.z += man.speed * cos(man.vangle / 180 * PI);
		break;
	case 'w':
		man.move = true;
		man.x += man.speed * cos(man.vangle / 180 * PI);
		man.z -= man.speed * sin(man.vangle / 180 * PI);
		break;
	case 's':
		man.move = true;
		man.x -= man.speed * cos(man.vangle / 180 * PI);
		man.z += man.speed * sin(man.vangle / 180 * PI);
		break;
	case 'h':
		reset_god = false;
		if (view_person >= 2)
		{
			view_person = 0;
		}
		else
		{
			view_person++;
			switch(view_person)
			{
				case 0:
					cout<<"上帝视角"<<endl;
					break;
				case 1:
					cout<<"第一视角"<<endl;
					break;
				case 2:
					cout<<"第三视角"<<endl;
					break;
				default:
					break;
			}
		}
		break;
	case 'r':
		cout<<"Roll!"<<endl;
		if (view_person != 3)
		{
			last_view = view_person;
			view_person = 3;
		}
		else
		{
			view_person = last_view;
		}
		break;
	case 27:
		exit(0);
	default:
		break;
	}

}
// �����ɿ�
void controlup(unsigned char key, int x, int y)
{
	switch (key) {
	case 'w':
		man.move = false;
		break;
	case 's':
		man.move = false;
		break;
	case 'a':
		man.move = false;
		break;
	case 'd':
		man.move = false;
		break;
	}
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	// 设置程序的窗口大小
  	GLint windowWidth = 600;
  	GLint windowHeight = 600;
  	glutInitWindowSize(windowWidth, windowHeight);
	  
	// 获取屏幕的宽和高
  	GLint SCREEN_WIDTH=glutGet(GLUT_SCREEN_WIDTH);    
  	GLint SCREEN_HEIGHT=glutGet(GLUT_SCREEN_HEIGHT);  
  	glutInitWindowPosition((SCREEN_WIDTH-windowWidth)/2,(SCREEN_HEIGHT-windowHeight)/2);
	  
	glutCreateWindow("Roaming");
	init();
	refresh(0);

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutPassiveMotionFunc(passiveMotion);
	//glutSpecialFunc(SpecialKeys);
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMotion);
	glutKeyboardUpFunc(controlup);
	glutKeyboardFunc(control);
	//glutIdleFunc(idle);
	//glutSetCursor

	glutMainLoop();
	return 0;
}