#include "Game.h"
#include "Globals.h"
#include <stdio.h>

Game::Game()
{
    state = GameState::MAIN_MENU;
    
    level = nullptr;
    img_menu = {};
    img_settings = {};
    img_credits = {};
    cursor = Cursor::PLAY;
}
Game::~Game()
{
    if (level != nullptr)
    {
        level->Release();
        delete level;
        level = nullptr;
    }
}
bool Game::Initialise()
{
    //Initialise windows
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Spaceship: arrow keys + space, f1: god mode");

    //Load resources
    if (!LoadTextures())
    {
        LOG("Failed to load textures");
        return false;
    }

    //Set the target frame rate for the application
    SetTargetFPS(60);

    return true;
}
bool Game::LoadTextures()
{
    img_menu = LoadTexture("images/menu.png");
    if(img_menu.id == 0)  
    {
        LOG("Failed to load texture images/menu.png");
        return false;
    }
    img_settings = LoadTexture("images/settings.png");
    if (img_settings.id == 0)
    {
        LOG("Failed to load texture images/settings.png");
        return false;
    }
    img_credits = LoadTexture("images/credits.png");
    if (img_credits.id == 0)
    {
        LOG("Failed to load texture images/credits.png");
        return false;
    }
    return true;
}
bool Game::BeginPlay()
{
    level = new Level(WINDOW_WIDTH, WINDOW_HEIGHT);
    if (level == nullptr)
    {
        LOG("Failed to allocate memory for Level");
        return false;
    }
    if (!level->Init())
    {
        LOG("Failed to initialise Level");
        return false;
    }

    return true;
}
void Game::FinishPlay()
{
    level->Release();
    delete level;
    level = nullptr;
}
bool Game::Update()
{
    switch (state)
    {
        case GameState::MAIN_MENU: 
            if (IsKeyPressed(KEY_ESCAPE)) return false;
            if (IsKeyPressed(KEY_UP)) {
                switch (cursor)
                {
                case Cursor::SETTINGS: cursor = Cursor::PLAY; break;
                case Cursor::CREDITS: cursor = Cursor::SETTINGS; break;
                case Cursor::EXIT: cursor = Cursor::CREDITS; break;
                }

            }
            else if (IsKeyPressed(KEY_DOWN)) {
                switch (cursor)
                {
                case Cursor::PLAY: cursor = Cursor::SETTINGS; break;
                case Cursor::SETTINGS: cursor = Cursor::CREDITS; break;
                case Cursor::CREDITS: cursor = Cursor::EXIT; break;
                }
            }
            if (IsKeyPressed(KEY_SPACE))
            {
                if(!BeginPlay()) return false;
                switch (cursor) {
   
                case Cursor::PLAY:
                    state = GameState::PLAYING;
                    break;
                case Cursor::SETTINGS:
                    state = GameState::SETTINGS;
                    break;
                case Cursor::CREDITS:
                    state = GameState::CREDITS;
                    break;
                case Cursor::EXIT:
                    return false;
                }
            }
            break;

        case GameState::PLAYING:  
            if (IsKeyPressed(KEY_ESCAPE))
            {
                FinishPlay();
                state = GameState::MAIN_MENU;
            }
            else
            {
                //Process Input
                level->HandleInputPlayer();
                //Game logic
                level->Update();
            }
            break;
        case GameState::SETTINGS:
            if (IsKeyPressed(KEY_ESCAPE))
            {
                FinishPlay();
                state = GameState::MAIN_MENU;
            }
            break;
        case GameState::CREDITS:
            if (IsKeyPressed(KEY_ESCAPE))
            {
                FinishPlay();
                state = GameState::MAIN_MENU;
            }
            break;
    }
    return true;
}
void Game::Render()
{
    BeginDrawing();
    ClearBackground(BLACK);

    switch (state)
    {
        case GameState::MAIN_MENU:
            //Background image
            DrawTexture(img_menu, 0, 0, WHITE);
            //Cursor
            DrawRectangle(BUTTON_PLAY_POS_X, BUTTON_PLAY_POS_Y + CURSOR_DISPLACEMENT * (int) cursor, CURSOR_WIDTH, CURSOR_HEIGHT, CURSOR_COLOR);
            break;

        case GameState::PLAYING:
            level->Render();
            break;

        case GameState::SETTINGS:
            //Settings image
            DrawTexture(img_settings, 0, 0, WHITE);
            break;

        case GameState::CREDITS:
            //Credits image
            DrawTexture(img_credits, 0, 0, WHITE);
            break;
    }
    
    EndDrawing();
}
void Game::Cleanup()
{
    UnloadTextures();
    CloseWindow();
}
void Game::UnloadTextures()
{
    UnloadTexture(img_menu);
    UnloadTexture(img_settings);
    UnloadTexture(img_credits);
}