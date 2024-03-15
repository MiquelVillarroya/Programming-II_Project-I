#pragma once
#include "Level.h"

enum class GameState { MAIN_MENU, PLAYING, SETTINGS, CREDITS };
enum class Cursor {PLAY, SETTINGS, CREDITS, EXIT};

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
    bool BeginPlay();
    void FinishPlay();

    bool LoadTextures();
    void UnloadTextures();

    GameState state;
    Cursor cursor;
    Level *level;
    Texture2D img_menu, img_settings, img_credits;
};