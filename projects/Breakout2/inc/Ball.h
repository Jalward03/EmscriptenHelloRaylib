#pragma once
#include "Rect.h"

class Ball
{
public:
    Vector2 dir = { 0.707f, 0.707f };
    float speed = 480.0f;
    Vector2 pos = { 0, 0 };

public:
    void Load();
    void Unload();
    void Update(float dt);
    void Draw();
    // Vector2 GetPosition();
    Rect GetRect();


    Vector2 GetDirection();
   // void SetDirection(float x, float y);

    void Bounce(float x, float y);

protected:
private:

    
    
    float radius = 5.0f;
   
};
