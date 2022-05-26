#include "MenuState.h"
#include "raylib.h"
#include "Game.h"
#include "GameStateManager.h"
#include "iostream"
#include "ControlsState.h"
#include "IGameState.h"


ControlsState::ControlsState(Game* app) : m_app(app)
{
}
ControlsState::~ControlsState()
{
}
void ControlsState::Load()
{

}
void ControlsState::Unload()
{

}
void ControlsState::Update(float dt)
{

	if (GetMousePosition().x > 10 && GetMousePosition().x < 530 && GetMousePosition().y > 325 && GetMousePosition().y < 385)
	{
		DrawRectangle(10, 325, 520, 60, LIME);
		DrawText("BACK", 245, 345, 20, BLACK);



		if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			m_app->GetGameStateManager()->PopState();

			m_app->GetGameStateManager()->SetState("Menu", new MenuState(m_app));
			m_app->GetGameStateManager()->PushState("Menu");

		}

	}
	else
	{
		DrawRectangle(10, 325, 520, 60, BLACK);
		DrawText("BACK", 245, 345, 20, WHITE);

	}
}
void ControlsState::Draw()
{


	ClearBackground(BLACK);
	DrawText("CONTROLS", 140, 150, 50, WHITE);
	//DrawRectangle(10, 235, 520, 60, BLACK);
	DrawText("<- -> TO MOVE", 170, 250, 30, WHITE);



}




