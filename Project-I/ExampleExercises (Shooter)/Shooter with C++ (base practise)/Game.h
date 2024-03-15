#pragma once
#include <raylib.h>
#include "Entity.h"

//Windows size
#define WINDOW_WIDTH    1024
#define WINDOW_HEIGHT   768

//Velocities
#define PLAYER_SPEED    8
#define SCENE_SPEED     2
#define SHOOT_SPEED     16

//Maximum number of shots on screen
#define MAX_SHOTS       32
#define MAX_SHOTS2       32

//Offset for positioning shots
#define SHOT_POS_X      29
#define SHOT_POS_Y1     3
#define SHOT_POS_Y2     59


class Game
{
public:
    Game();
    ~Game();

    bool Initialise();
    bool Update();
    void Render();
    void Cleanup();

private:
    bool LoadTextures();
    void UnloadTextures();

    Entity *Player, *Player2, *Shots[MAX_SHOTS], *Shots2[MAX_SHOTS2], *Scene;
    int idx_shot, idx_shot2;

    bool god_mode;

    Texture2D img_background;
    Texture2D img_player;
    Texture2D img_shot;
};