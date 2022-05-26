#pragma once
#include "IGameState.h"
#include "raylib.h"
class Game;
class MenuState : public IGameState
{
public:
    MenuState(Game* app);
    virtual ~MenuState();
    virtual void Load();
    virtual void Unload();
    virtual void Update(float dt);
    virtual void Draw();
    
    Sound playGame = LoadSound("./Sounds/playgame.wav");

protected:
private:
    Game* m_app;


};