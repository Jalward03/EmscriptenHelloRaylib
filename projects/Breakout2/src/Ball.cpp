#include "raylib.h"
#include "Ball.h"




void Ball::Load()
{
	pos.x = 540 / 2;
	pos.y = 800 / 2 - 110;
	
}

void Ball::Unload()
{

}
void Ball::Update(float dt)
{
	pos.x += dir.x *speed;
	pos.y += dir.y *speed;

	if (pos.x < 0)   dir.x = -dir.x;
	if (pos.x > 540) dir.x = -dir.x;

	if (pos.y < 0) dir.y = -dir.y;
	if (pos.y > 800) dir.y = -dir.y;
	
	
	


}
void Ball::Draw()
{
	
	DrawCircle(pos.x, pos.y, radius, WHITE);
}
//Vector2 Ball::GetPosition()
//{
//	return pos;
//}

Vector2 Ball::GetDirection()
{
	return dir;
}
//void Ball::SetDirection(float x, float y)
//{
//	dir.y = -dir.y;
//}

void Ball::Bounce(float x, float y)
{
	if (y != 0) dir.y = -dir.y; // * -y;
	if (x != 0) dir.x = -dir.x; // * -x;
	
}

Rect Ball::GetRect()
{
	return Rect({ pos.x, pos.y, radius, radius});
}

