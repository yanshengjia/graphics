#pragma once
#include "Point.h"
#include "Param.h"

class Man
{
public:
	float basic_size = 1;
	float speed = 0.5;
	Point hair_scale, head_scale, thigh_scale, body_scale, arm_scale, eye_scale, mouth_scale;
	Point head, hair, body, thighL, thighR, armL, armR, eyeL, eyeR, mouth;
	float x, y, z;
	float vangle = 0;    // speed angle
	float ltangle = -60; // left leg angle
	float rtangle = -120;// right leg angle
	float laangle = -115;// left arm angle
	float raangle = -75; // right arm angle
	bool move = false;

public:
	// Constructor
	Man()
	{
		reset();
	}
	// Reset the size of Man
	void resetSize(float new_basic)
	{
		this->basic_size = new_basic;
		reset();
	}
	// Whether Man move or not
	bool isMoving()
	{
		return move;
	}
	// Set Location for Man
	void setLocation(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
	// Redraw Man
	void reset()
	{
		// Proportional control
		head_scale = Point(0.5, 0.5, 0.75, basic_size);
		body_scale = Point(0.3, 1.25, 0.75, basic_size);
		eye_scale = Point(0.2, 0.2, 0.2, basic_size);
		mouth_scale = Point(0.2, 0.2, 0.5, basic_size);
		hair_scale = Point(head_scale.x, 0.3, head_scale.z, basic_size); // ͷ��xz��ͷ��ͬ
		thigh_scale = Point(body_scale.x, 1.4, body_scale.z / 2, basic_size); // ��x������ͬ��zΪ����һ��
		arm_scale = Point(body_scale.x, body_scale.y, 0.3, basic_size); //�ֱ�xy������ͬ

		// The relative position control
		head = Point(0, thigh_scale.y + body_scale.y + head_scale.y / 2, 0, basic_size);
		hair = Point(0, thigh_scale.y + body_scale.y + head_scale.y + hair_scale.y / 2, 0, basic_size);
		body = Point(0, thigh_scale.y + body_scale.y / 2, 0, basic_size);
		thighL = Point(0, thigh_scale.y / 2, -thigh_scale.z / 2, basic_size);
		thighR = Point(0, thigh_scale.y / 2, thigh_scale.z / 2, basic_size);
		armL = Point(0, thigh_scale.y + arm_scale.y / 2, -(arm_scale.z + body_scale.z) / 2, basic_size);
		armR = Point(0, thigh_scale.y + arm_scale.y / 2, (arm_scale.z + body_scale.z) / 2, basic_size);
		eyeL = Point(head_scale.x / 2, thigh_scale.y + body_scale.y + head_scale.y / 2, -(eye_scale.z / 2 + 0.1), basic_size);
		eyeR = Point(head_scale.x / 2, thigh_scale.y + body_scale.y + head_scale.y / 2, (eye_scale.z / 2 + 0.1), basic_size);
		mouth = Point(head_scale.x / 2, thigh_scale.y + body_scale.y + head_scale.y / 2 - 0.1, 0, basic_size);
	}
};
