#pragma once


class Player 
{
public:
     void Load();
     void Unload();
     void Update(float dt);
     void Draw();
     Vector2 GetPosition();


protected:
private:

    Vector2 pos = { 0, 0 };
    Vector2 size = { 0, 0 };
    Vector2 speed = { 0, 600.0f };
    int lives = 3;
    
};
