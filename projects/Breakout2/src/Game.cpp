#include "Game.h"
#include "raylib.h"

#include "IGameState.h"
#include "SplashState.h"
#include "PlayState.h"
#include "ControlsState.h"
#include "MenuState.h"
#include "GameStateManager.h"

Game::Game()
{

}

Game::~Game()
{

}

void Game::Load()
{
    m_gameStateManager = new GameStateManager();
    m_gameStateManager->SetState("Splash", new SplashState(this)); //Load();
    m_gameStateManager->SetState("Menu", new MenuState(this)); //Load();
    m_gameStateManager->SetState("Play", new PlayState(this)); //Load();
    m_gameStateManager->SetState("Controls", new ControlsState(this));
    m_gameStateManager->PushState("Splash");
}

void Game::UnLoad()
{

}

void Game::Update()
{
    float deltaTime = GetFrameTime();
    m_gameStateManager->Update(deltaTime);
}

void Game::Draw()
{
    BeginDrawing();
    ClearBackground(RAYWHITE);
    m_gameStateManager->Draw();
    EndDrawing();
}

