#pragma once
#include "IGameState.h"
#include "raylib.h"
class Game;
class Player;
class Ball;
class PlayState : public IGameState
{
public:
	PlayState(Game* app);
	virtual ~PlayState();
	virtual void Load();
	virtual void Unload();
	virtual void Update(float dt);
	virtual void Draw();
	Color GetTileColor(int tileValue);

	Sound brickHit = LoadSound("./assets/brickhit.wav");
	Sound paddleHit = LoadSound("./assets/paddlehit.wav");
	Sound win = LoadSound("./assets/win.wav");
	Sound music = LoadSound("./assets/music.mp3");
	Sound perfect = LoadSound("./assets/perfect.wav");
	Sound amazing = LoadSound("./assets/amazing.wav");
	Sound startUp = LoadSound("./assets/startup.wav");



protected:
private:
	Game* m_app;
	Player* m_player;
	Ball* m_ball;

	bool hasWonSoundPlayed = false;
	bool hasMainMusicPlayed = false;

	int brickWidth = 60;
	int brickHeight = 40;

	int combo = 0;
	
	int brickCount = 88;
	float winTime = 0.0f;

	static const int ROWS = 20;
	static const int COLS = 9;

	int gridData[ROWS][COLS] =
	{
		{0, 1, 1, 1, 1, 1, 1, 1, 0},
		{0, 2, 2, 2, 2, 2, 2, 2, 0},
		{0, 3, 3, 3, 3, 3, 3, 3, 0},
		{0, 4, 4, 4, 4, 4, 4, 4, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0},
		{2, 2, 2, 2, 2, 2, 2, 2, 2}

	};




	//int gridData[ROWS][COLS] =
	//{
	//	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	//	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	//	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	//	{0, 0, 0, 0, 0, 0, 1, 0, 0},
	//	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	//	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	//	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	//	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	//	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	//	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	//	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	//	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	//	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	//	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	//	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	//	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	//	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	//	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	//	{0, 0, 0, 0, 0, 0, 0, 0, 0},
	//	{0, 0, 0, 0, 0, 0, 0, 0, 0}
	//
	//};
};