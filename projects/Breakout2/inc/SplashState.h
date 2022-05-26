#pragma once
#include "IGameState.h"
#include "raylib.h"
class Game;
class SplashState : public IGameState
{
public:
    SplashState(Game* app);
    virtual ~SplashState();
    virtual void Load();
    virtual void Unload();
    virtual void Update(float dt);
    virtual void Draw();

    Sound startUp = LoadSound("./Sounds/startup.wav");

protected:
private:
    Game* m_app;
  
    float m_timer = 0.0f;
};