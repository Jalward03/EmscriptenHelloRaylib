#include "raylib.h"
#include "iostream"
#include "Rect.h"
#include "Hit.h"


Rect::Rect(Vector2 pos, Vector2 extends)
{
	Position.x = pos.x;
	Position.y = pos.y;
	Extends.x = extends.x;
	Extends.y = extends.y;
}

Rectangle Rect::ToRect()
{
	return { Position.x - Extends.x, Position.y - Extends.y, Extends.x*2, Extends.y*2 };
}
Rect::Rect(float xPos, float yPos, float hWidth, float hHeight)
{
	Position.x = xPos;
	Position.y = yPos;
	Extends.x = hWidth;
	Extends.y = hHeight;

}

bool Rect::IsPointIside(Vector2 point)
{
	return point.x > GetMin().x && point.x < GetMax().x&&
		point.y > GetMin().y && point.y < GetMax().y;
}

Hit Rect::Intersects(Vector2 point)
{
	Hit hit;
	hit.overLapped = true;

	if (!IsPointIside(point))
	{
		return hit;
	}

	Vector2 vec = { point.x - Position.x, point.y - Position.y };
	Vector2 overlap = { Extends.x - (float)abs(vec.x), Extends.y - (float)abs(vec.y) };
	if (overlap.x < overlap.y)
	{
		float xDir = vec.y < 0 ? -1 : 1;
		hit.delta.x = overlap.x * xDir;
		hit.normal.x = xDir;
		hit.pos.x = Position.x + (Extends.x * xDir);
		hit.pos.y = point.y;
	
	}
	else
	{
		float yDir = vec.y < 0 ? -1 : 1;
		hit.delta.y = overlap.y * yDir;
		hit.normal.y = yDir;
		hit.pos.y = Position.y + (Extends.y * yDir);
		hit.pos.x = point.x;

	}
	return hit;
	


	return hit;


}

Hit Rect::Intersects(Rect other)
{
	Hit hit;
	

	Vector2 vec = {other.Position.x - Position.x, other.Position.y - Position.y};
	
	float ox = (other.Extends.x + Extends.x) - abs(vec.x);
	float oy = (other.Extends.y + Extends.y) - abs(vec.y);
	Vector2 overlap = { ox, oy };


	if (overlap.x <= 0 || overlap.y <= 0)
	{
		return hit;
	}


	if (overlap.x < overlap.y)
	{
		float sx = vec.x < 0 ? -1 : 1;
		hit.delta.x = overlap.x * sx;
		hit.normal.x = sx;
		hit.pos.x = Position.x + (Extends.x * sx);
		hit.pos.y = other.Position.y;
	}
	else 
	{
		float sy = vec.y < 0 ? -1 : 1;
		hit.delta.y = overlap.y * sy;
		hit.normal.y = sy;
		hit.pos.x = other.Position.x;
		hit.pos.y = Position.y + (Extends.y * sy);

	}
	hit.overLapped = true;
	return hit;
}



