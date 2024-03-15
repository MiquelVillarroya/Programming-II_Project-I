#pragma once
#include "raylib.h"

class Entity
{
public:
    Entity();
    Entity(Vector2 p, int w, int h, int s);
    ~Entity();

    void Init(Vector2 p, int w, int h, int s);
    void SetPosition(Vector2 p);
    void SetAlive(bool b);
    
    //Update position according to the given direction and current speed
    void Move(Vector2 dir);
    
    //Update position within the given limits
    void ClampPosition(int x1, int y1, int x2, int y2);
    
    Vector2 GetPosition() const;
    int GetWidth() const;
    int GetHeight() const;
    bool IsAlive() const;

    void Render(Texture img) const;
    void Render(Texture img, Vector2 offset) const;
    void RenderDebug(Color col) const;
    void RenderMirror(Texture img, Color col) const;

    bool CheckShotCol(Entity* shot) const;

private:
    Vector2 pos;
    int width, height;
    int speed;
    bool is_alive;
};