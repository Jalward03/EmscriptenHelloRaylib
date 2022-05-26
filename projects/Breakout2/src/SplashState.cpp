#include "SplashState.h"
#include "raylib.h"
#include "Game.h"
#include "GameStateManager.h"
#include <iostream>

SplashState::SplashState(Game* app) : m_app(app)
{
}
SplashState::~SplashState()
{
}
void SplashState::Load()
{

    InitAudioDevice();
      

  
}
void SplashState::Unload()
{
   
}
void SplashState::Update(float dt)
{
    

    m_timer += dt;
    if (m_timer > 2.0f)
    {
        m_app->GetGameStateManager()->SetState("Splash", nullptr);
        m_app->GetGameStateManager()->PopState();
        m_app->GetGameStateManager()->PushState("Menu");

        PlaySound(startUp);
    }
}
void SplashState::Draw()
{
    ClearBackground(BLACK);
    DrawText("JTA", 230, 340, 40, WHITE);
    DrawText("GAMES", 200, 380, 40, WHITE);

}