#pragma once
#include <iostream>


class Bricks
{
public:
	void Load();
	void Unload();
	void Update(float dt);
	void Draw();
	int GetBrickWidth();
	int GetBrickHeight();
	int GetGrid();



protected:
private:


	int brickWidth = 90;
	int brickHeight = 40;


	static const int ROWS = 20;
	static const int COLS = 6;

	int GridData[ROWS][COLS] =
	{
		{0, 1, 1, 1, 1, 0},
		{0, 2, 2, 2, 2, 0},
		{0, 3, 3, 3, 3, 0},
		{0, 4, 4, 4, 4, 0},
		{0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0},
		{0, 4, 4, 4, 4, 0},
		{0, 3, 3, 3, 3, 0},
		{0, 2, 2, 2, 2, 0},
		{0, 1, 1, 1, 1, 0}

	};
	//int RowCount = 6;





};