#pragma once
#include "IGameState.h"
class Game;
class ControlsState : public IGameState
{
public:
    ControlsState(Game* app);
    virtual ~ControlsState();
    virtual void Load();
    virtual void Unload();
    virtual void Update(float dt);
    virtual void Draw();

protected:
private:
    Game* m_app;


};