#include "PlayState.h"
#include "raylib.h"
#include "iostream"
#include "Player.h"
#include "Ball.h"
#include "Rect.h"
#include "Hit.h"
#include "IGameState.h"
#include "GameStateManager.h"
#include "Game.h"
#include <string>

PlayState::PlayState(Game* app) : m_app(app)
{
}
PlayState::~PlayState()
{
}
void PlayState::Load()
{

	m_player = new Player();
	m_ball = new Ball();


	m_player->Load();
	m_ball->Load();
	//m_ball->pos.x = 300;
	//m_ball->pos.y = 200;
	//m_ball->dir.x = -1;
	//m_ball->dir.y = 0;
	//m_ball->speed = 0.1;


}
void PlayState::Unload()
{
	m_player->Unload();
	delete m_player;
	m_player = nullptr;

	m_ball->Unload();
	delete m_ball;
	m_ball = nullptr;


}


void PlayState::Update(float dt)
{
	//if (hasMainMusicPlayed == false)
	//{
	//	SetSoundVolume(music, 0.5f);
	//	PlaySound(music);
	//	hasMainMusicPlayed = true;
	//}

	if (!IsSoundPlaying(music))
	{
		SetSoundVolume(music, 0.5f);
		PlaySound(music);
	}


	m_player->Update(dt);
	m_ball->Update(dt);


	//calling variables from other classes
	auto pPos = m_player->GetPosition();

	auto bDir = m_ball->GetDirection();

	//paddle and ball collision
	if (m_ball->pos.y > pPos.y && m_ball->pos.y < pPos.y + 2.5f && m_ball->pos.x > pPos.x && m_ball->pos.x < pPos.x + 100)
	{

		m_ball->Bounce(0, 1);
		PlaySound(paddleHit);
	}

	if (m_ball->pos.y >= pPos.y && m_ball->pos.y <= pPos.y + 5)
	{
		combo = 0;
		
	}


	int ballColIndex = m_ball->pos.x / brickWidth;
	int ballRowIndex = m_ball->pos.y / brickHeight;


	//if (ballColIndex >= 0 && ballColIndex < 9 && ballRowIndex >= 0 && ballRowIndex < 20)
	//{
	//	if (gridData[ballRowIndex][ballColIndex] > 0)
	//	{
	//		gridData[ballRowIndex][ballColIndex] -= 1;
	//		brickCount -= 1;
	//	
	//
	//		m_ball->Bounce(0, 1);
	//	}
	//
	//}

	Hit lastHit;

	for (int r = 0; r < ROWS; r++)
	{
		for (int c = 0; c < COLS; c++)
		{

			int index = gridData[r][c];

			float gridYPos = r * brickHeight / 2;
			float gridXPos = c * brickWidth / 2;

			float brickYPos = r * brickHeight;
			float brickXPos = c * brickWidth;

			if (gridData[r][c] == 0)
				continue;

			float hBrickWidth = brickWidth / 2;
			float hBrickHeight = brickHeight / 2;

			Rect ballRect = m_ball->GetRect();
			Rect brickRect = Rect({ brickXPos + hBrickWidth, brickYPos + hBrickHeight, hBrickWidth, hBrickHeight });

			Hit hit = ballRect.Intersects(brickRect);

			if (hit.overLapped)
			{


				lastHit = hit;
				gridData[r][c] -= 1;
				combo += 1;
				brickCount -= 1;
				m_ball->pos.x -= lastHit.delta.x;
				m_ball->pos.y -= lastHit.delta.y;

				int brickHitCol = (hit.pos.x - hit.delta.x) / brickWidth;
				int brickHitRow = (hit.pos.y - hit.delta.y) / brickHeight;

				if (gridData[brickHitRow][brickHitCol] > 0)
				{



					///m_ball->Update(dt);
					///break;

				}


			}
		}



	}

	if (lastHit.overLapped)
	{
		PlaySound(brickHit);

		m_ball->Bounce(lastHit.normal.x, lastHit.normal.y);

		if (combo == 3)
		{
			PlaySound(amazing);
			

		}
		if (combo == 5)
		{
			PlaySound(perfect);
		

		}
	
		
	}

	if (combo < 3)
	{
		DrawText("", m_player->GetPosition().x + 25, m_player->GetPosition().y - 20, 15, WHITE);

	}
	else if (combo >= 3 && combo < 5)
	{
		DrawText("Amazing!", m_player->GetPosition().x + 25, m_player->GetPosition().y - 20, 15, WHITE);

	}
	else if (combo >= 5)
	{
		DrawText("Perfect!", m_player->GetPosition().x + 25, m_player->GetPosition().y - 20, 15, WHITE);

	}
	

	//when all bricks are destroyed
	if (brickCount <= 0)
	{
		StopSound(music);

		if (hasWonSoundPlayed == false)
		{
			hasWonSoundPlayed = true;
			PlaySound(win);
		}


		DrawText("YOU WIN", 215, 370, 30, WHITE);

		winTime += dt;


		if (winTime > 3.0f)
		{

			m_app->GetGameStateManager()->SetState("Play", nullptr);
			m_app->GetGameStateManager()->PopState();
			m_app->GetGameStateManager()->PushState("Menu");
		}

	}
	if (GetMousePosition().x > 7 && GetMousePosition().x < 25 && GetMousePosition().y > 7 && GetMousePosition().y < 25)
	{
		
		DrawRectangleLines(7, 7, 18, 18, GREEN);
		DrawText("<=", 10, 10, 17, WHITE);

		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			StopSound(music);
			PlaySound(startUp);
			m_app->GetGameStateManager()->SetState("Play", nullptr);
			m_app->GetGameStateManager()->PopState();
			m_app->GetGameStateManager()->PushState("Menu");
		}
	}
	else
	{

		DrawRectangle(7, 7, 18, 18, BLACK);
		DrawText("<=", 10, 10, 17, WHITE);
	}
}
void PlayState::Draw()
{
	ClearBackground(BLACK); 

	
	m_player->Draw();

	DrawText(std::to_string(combo).c_str(), m_player->GetPosition().x + 75, m_player->GetPosition().y + 18, 15, WHITE);
	DrawText("Combo: ", m_player->GetPosition().x + 25, m_player->GetPosition().y + 18, 15, WHITE);




	for (int r = 0; r < ROWS; r++)
	{
		for (int c = 0; c < COLS; c++)
		{

			float gridYPos = r * brickHeight;
			float gridXPos = c * brickWidth;

			int index = gridData[r][c];
			Color color = GetTileColor(index);

			DrawRectangle(gridXPos, gridYPos, brickWidth, brickHeight, color);
			if (gridData[r][c] > 0)
			{
				DrawRectangleLines(gridXPos, gridYPos, brickWidth, brickHeight, BLACK);
			}
		}

	}


	//// TEMP DEBUG DRAWING-----------------------------------------------------------
	//{
	//
	//	
	//	int ballColIndex = m_ball->pos.x / brickWidth;
	//	int ballRowIndex = m_ball->pos.y / brickHeight;
	//
	//	
	//	for (int r = 0; r < ROWS; r++)
	//	{
	//		for (int c = 0; c < COLS; c++)
	//		{
	//			int index = gridData[r][c];
	//
	//			float gridYPos = r * brickHeight / 2;
	//			float gridXPos = c * brickWidth / 2;
	//
	//			float brickYPos = r * brickHeight;
	//			float brickXPos = c * brickWidth;
	//
	//
	//			if (gridData[r][c] == 0)
	//				continue;
	//
	//			float hBrickWidth = brickWidth / 2;
	//			float hBrickHeight = brickHeight / 2;
	//
	//			Rect ballRect = m_ball->GetRect();
	//			Rect brickRect = Rect({ brickXPos + hBrickWidth, brickYPos + hBrickHeight, hBrickWidth, hBrickHeight });
	//
	//			
	//
	//
	//			Hit hit = ballRect.Intersects(brickRect);
	//
	//			if (hit.overLapped)
	//			{
	//				DrawRectanglePro(brickRect.ToRect(), { 0, 0 }, 0.0f, PURPLE);
	//
	//				
	//
	//
	//			}
	//		}
	//
	//	}
	//}
	//
	//// -----------------------------------------------------------
	m_ball->Draw();


}

Color PlayState::GetTileColor(int tileValue)
{

	switch (tileValue)
	{
	case 0: return { 255, 255, 255, 0 }; // Transparent White
	case 1: return GREEN;
	case 2: return YELLOW;
	case 3: return ORANGE;
	case 4: return RED;
	}

	return BLACK;
}





