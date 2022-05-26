#include "MenuState.h"
#include "raylib.h"
#include "Game.h"
#include "GameStateManager.h"
#include "iostream"
#include "PlayState.h"
#include "ControlsState.h"


MenuState::MenuState(Game* app) : m_app(app)
{
}
MenuState::~MenuState()
{
}
void MenuState::Load()
{
	
	

}
void MenuState::Unload()
{

}
void MenuState::Update(float dt)
{

	//Play hover and click
	if (GetMousePosition().x > 10 && GetMousePosition().x < 530 && GetMousePosition().y > 235 && GetMousePosition().y < 295)
	{
		DrawRectangle(10, 235, 520, 60, LIME);
		DrawText("PLAY", 230, 250, 30, BLACK);



		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			m_app->GetGameStateManager()->PopState();

			m_app->GetGameStateManager()->SetState("Play", new PlayState(m_app));
			m_app->GetGameStateManager()->PushState("Play");
			PlaySound(playGame);
		}

	}
	else
	{
		DrawRectangle(10, 235, 520, 60, BLACK);
		DrawText("PLAY", 230, 250, 30, WHITE);

	}
	//controls hover and click

	if (GetMousePosition().x > 10 && GetMousePosition().x < 530 && GetMousePosition().y > 325 && GetMousePosition().y < 385)
	{
		DrawRectangle(10, 325, 520, 60, LIME);
		DrawText("CONTROLS", 217, 345, 20, BLACK);


		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			m_app->GetGameStateManager()->PopState();

			m_app->GetGameStateManager()->SetState("Controls", new ControlsState(m_app));
			m_app->GetGameStateManager()->PushState("Controls");

		}

	}
	else 
	{
		DrawRectangle(10, 325, 520, 60, BLACK);
		DrawText("CONTROLS", 217, 345, 20, WHITE);

	}
}
void MenuState::Draw()
{


	ClearBackground(BLACK);
	DrawText("BREAKOUT", 140, 150, 50, WHITE);
	//DrawRectangle(10, 325, 520, 60, BLACK);



}




