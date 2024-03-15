#include "Entity.h"

Entity::Entity()
{
    pos = {0, 0};
    width = 0;
    height = 0;
    speed = 0;
    is_alive = false;
}
Entity::Entity(Vector2 p, int w, int h, int s)
{
    pos = p;
    width = w;
    height = h;
    speed = s;
    is_alive = true;
}
Entity::~Entity()
{
}
void Entity::Init(Vector2 p, int w, int h, int s)
{
    pos = p;
    width = w;
    height = h;
    speed = s;
    is_alive = true;
}
void Entity::SetPosition(Vector2 p)
{
    pos = p;
}
void Entity::SetAlive(bool b)
{
    is_alive = b;
}
void Entity::Move(Vector2 dir)
{
    pos.x += dir.x * speed;
    pos.y += dir.y * speed;
}
void Entity::ClampPosition(int x1, int y1, int x2, int y2)
{
    if (pos.x < x1)                 pos.x = x1;
    else if (pos.x > x2 - width)    pos.x = x2 - width;

    if (pos.y < y1)                 pos.y = y1;
    else if (pos.y > y2 - height)   pos.y = y2 - height;
}
Vector2 Entity::GetPosition() const
{
    return pos;
}
int Entity::GetWidth() const
{
    return width;
}
int Entity::GetHeight() const
{
    return height;
}
bool Entity::IsAlive() const
{
    return is_alive;
}
void Entity::Render(Texture img) const
{
    DrawTexture(img, pos.x, pos.y, WHITE);
}
void Entity::Render(Texture img, Vector2 offset) const
{
    DrawTexture(img, pos.x + offset.x, pos.y + offset.y, WHITE);
}
void Entity::RenderDebug(Color col) const
{
    Rectangle rect = {pos.x, pos.y, (float)width, (float)height};
    DrawRectangleLinesEx(rect, 2, col);
}
void Entity::RenderMirror(Texture img, Color col)const
{
    Rectangle r1, r2;
    r1 = { 0, 0, -(float) width, (float) height};
    r2 = { pos.x, pos.y, (float)width, (float) height};
    DrawTexturePro(img, r1, r2, { 0, 0 }, 0, col);

}
bool Entity::CheckShotCol(Entity* shot) const {
    Rectangle r1, r2;
    r1 = {pos.x, pos.y, (float) width, (float) height};
    r2 = {shot->GetPosition().x, shot->GetPosition().y, (float) shot->GetWidth(), (float) shot->GetHeight()};
    return CheckCollisionRecs(r1, r2);
}
