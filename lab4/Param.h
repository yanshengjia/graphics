#pragma once

#include <iostream>
#include <cmath>
#include <GLUT/glut.h>  // Mac OSX
//#include <gl/glut.h>  // Windows
#include "Point.h"
#include "Crawler.h"
#include "Man.h"
using namespace std;

#define DELAY 12
#define NUM_OF_LINE 32
#define BLOCK_SIZE 1
#define VIEW_SCALE 2
#define PI 3.1415926535898


// World parameter
Point center = Point(0, 0, 0);
Point lookAt = Point(5, 5, 5);
Point cameraAt = Point(5, 5, 5);
Point godAt = Point(5, 5, 5);


bool reset_god = false;
int view_person = 0;
int last_view = 0;
enum { GOD, FIRST_PERSON, THIRD_PERSON, BALL };

float near_sight = 5;
float far_sight = 100;
int scr_w;
int scr_h;

// all kinds of FLAGS
bool trackingMouse = false;
bool redrawContinue = false;
bool trackballMove = false;
bool left_forward = true;
bool right_forward = false;
bool look_from_left = true;

float angle = 0.0, axis[3], trans[3];
float lastPos[3] = { 0.0F, 0.0F, 0.0F };
int curx, cury;
int startX, startY;


Man man;
//Crawler crawler;
