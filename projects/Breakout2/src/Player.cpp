#include "raylib.h"
#include "Player.h"


void Player::Load()
{
	pos.x = 540 / 2;
	pos.y = 800 / 2 + 150 ;

	size.x = 100;
	size.y = 5;
}

void Player::Unload()
{
	
}
void Player::Update(float dt)
{
	if (IsKeyDown(KEY_LEFT) && pos.x > 0)
	{
		pos.x -= speed.y * dt;
	}
	if (IsKeyDown(KEY_RIGHT) && pos.x < (540) - 100)
	{
		pos.x += speed.y * dt;
	}

	
}
void Player::Draw()
{
	DrawRectangle(pos.x, pos.y, size.x, size.y, WHITE);

}

Vector2 Player::GetPosition()
{
	return pos;
}
