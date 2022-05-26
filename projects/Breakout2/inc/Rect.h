#pragma once
#include "raylib.h"
#include "Hit.h"


class Rect
{
public:
	Rect(Vector2 pos, Vector2 extends);
	Rect(float xPos, float yPos, float hWidth, float hHeight);
	bool IsPointIside(Vector2 point);
	Hit Intersects(Vector2 point);
	Rectangle ToRect();
	Hit Intersects(Rect other);

protected:
private:

	Vector2 Position = { 0, 0 };
	Vector2 Extends = { 0.5f, 0.5f };

	Vector2 GetMin()
	{
		return { Position.x - Extends.x,  Position.y - Extends.y };
	}

	Vector2 GetMax()
	{
		return { Position.x + Extends.x,  Position.y + Extends.y };
	}


	Vector2 GetSize()
	{
		return { Position.x * 2, Position.y * 2 };
	}



};
