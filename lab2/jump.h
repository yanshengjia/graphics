// 跳跃参数
float human_y = 0;
bool jumping = false;
bool falling = false;
float jump_speed = 0.3;
float fall_speed = 0.3;
static float max_height = 1.5;
static float ground_height = 0.00;

// 在 human() 中 glPushMatrix() 之后加入
// 在按键响应函数 case 32 中加入 jumping = true;
void jump_fall()
{
  if(jumping == true && human_y < max_height && falling == false)
	{
		human_y += jump_speed;
		jump_speed -= 0.05;
		if(jump_speed <= 0)
		{
			falling = true;
			jumping = false;
			jump_speed = 0.3;
		}
	}

	if(falling == true)
	{
		human_y -= fall_speed;
		fall_speed += 0.05;
		if(human_y - 0.05 <= ground_height)
		{
			fall_speed = 0.3;
			falling = false;
		}
	}
}
