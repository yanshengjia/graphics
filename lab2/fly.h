//飞机模型参数
static int xRot = 0;
static int yRot = 0;
static int zRot = 0;
static double x_air = 1.0f;
static double y_air = 1.0f;
static double z_air = 1.0f;
static double fly_distance = 20;

static float fly_speed = 0.05;
bool flying = false;
bool spining = false;

// 在 plane() 中 glPushMatrix() 之后加入
// 在按键响应函数 case 'f' 中加入 flying = true; spining = true;
void fly_spin()
{
  if(flying == true && spining == true)
	{
    zRot = (zRot - 6) % 360;
		z_air += fly_speed;
    if(z_air > fly_distance)
    {
      flying = false;
      spining = false;
    }
	}
}
