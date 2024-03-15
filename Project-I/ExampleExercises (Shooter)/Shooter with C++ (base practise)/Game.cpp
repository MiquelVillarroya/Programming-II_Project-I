#include "Game.h"
#include <stdio.h>

Game::Game()
{
    Player = nullptr;
    Player2 = nullptr;

    for (int i = 0; i < MAX_SHOTS; ++i)
    {
        Shots[i] = nullptr;
    }
    for (int i = 0; i < MAX_SHOTS2; ++i)
    {
        Shots2[i] = nullptr;
    }

    Scene = nullptr;

    idx_shot = 0;
    idx_shot2 = 0;

    god_mode = false;

    img_background = {};
    img_player = {};
    img_shot = {};
}
Game::~Game()
{
    if (Player != nullptr)
    {
        delete Player;
        Player = nullptr;
    }
    if (Player2 != nullptr)
    {
        delete Player2;
        Player2 = nullptr;
    }
    for (int i = 0; i < MAX_SHOTS; ++i)
    {
        if(Shots[i] != nullptr)
        {
            delete Shots[i];
            Shots[i] = nullptr;
        }
    }
    for (int i = 0; i < MAX_SHOTS2; ++i)
    {
        if (Shots2[i] != nullptr)
        {
            delete Shots2[i];
            Shots2[i] = nullptr;
        }
    }
    if (Scene != nullptr)
    {
        delete Scene;
        Scene = nullptr;
    }
}
bool Game::Initialise() {
    //Initialise windows
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Spaceship: arrow keys + space, f1: god mode");

    //Load resources
    if (!LoadTextures())
    {
        printf("Failed to load textures\n");
        Cleanup();
        return false;
    }

    //Initialise player
    Player = new Entity({ 20, WINDOW_HEIGHT / 2 }, 104, 82, PLAYER_SPEED);
    Player2 = new Entity({ WINDOW_WIDTH - 124, WINDOW_HEIGHT / 2 }, 104, 82, PLAYER_SPEED);

    if (Player == nullptr)
    {
        printf("Failed to allocate memory for Player\n");
        Cleanup();
        return false;
    }
    if (Player2 == nullptr)
    {
        printf("Failed to allocate memory for Player2\n");
        Cleanup();
        return false;
    }

    //Initialise shots
    idx_shot = 0;
    idx_shot2 = 0;

    for (int i = 0; i < MAX_SHOTS; ++i)
    {
        Shots[i] = new Entity();
        if (Shots[i] == nullptr)
        {
            printf("Failed to allocate memory for Shots[%d]\n", i);
            Cleanup();
            return false;
        }
    }
    for (int i = 0; i < MAX_SHOTS2; ++i)
    {
        Shots2[i] = new Entity();
        if (Shots2[i] == nullptr)
        {
            printf("Failed to allocate memory for Shots2[%d]\n", i);
            Cleanup();
            return false;
        }
    }
    //Initialise scene
    Scene = new Entity({ 0, 0 }, img_background.width, WINDOW_HEIGHT, SCENE_SPEED);
    if (Scene == nullptr)
    {
        printf("Failed to allocate memory for Scene\n");
        Cleanup();
        return false;
    }

    //Initialise control variables
    god_mode = false;

    //Set the target frame rate for the application
    SetTargetFPS(60);

    return true;
}

bool Game::LoadTextures()
{
    img_background = LoadTexture("images/background.png");
    if(img_background.id == 0)   return false;
    img_player = LoadTexture("images/spaceship.png");
    if (img_player.id == 0)   return false;
    img_shot = LoadTexture("images/shot.png");
    if (img_shot.id == 0)   return false;

    return true;
}

bool Game::Update()
{
    Vector2 p;
    Vector2 dir = { 0, 0 }, dir2 = { 0, 0 };

    //PROCESS INPUT

    if (IsKeyDown(KEY_ESCAPE))  return false;
    if (IsKeyPressed(KEY_F1))   god_mode = !god_mode;

    if (IsKeyDown(KEY_UP))          dir.y = -1;
    else if (IsKeyDown(KEY_DOWN))   dir.y = 1;
    if (IsKeyDown(KEY_LEFT))        dir.x = -1;
    else if (IsKeyDown(KEY_RIGHT))  dir.x = 1;

    if (IsKeyPressed(KEY_SPACE) && Player->IsAlive())
    {
        p = Player->GetPosition();

        Shots[idx_shot]->Init({ p.x + SHOT_POS_X, p.y + SHOT_POS_Y1 }, 56, 20, SHOOT_SPEED);
        idx_shot++;
        idx_shot %= MAX_SHOTS;

        Shots[idx_shot]->Init({ p.x + SHOT_POS_X, p.y + SHOT_POS_Y2 }, 56, 20, SHOOT_SPEED);
        idx_shot++;
        idx_shot %= MAX_SHOTS;
    }

    if (IsKeyDown(KEY_W))           dir2.y = -1;
    else if (IsKeyDown(KEY_S))      dir2.y = 1;
    if (IsKeyDown(KEY_A))           dir2.x = -1;
    else if (IsKeyDown(KEY_D))      dir2.x = 1;

    if (IsKeyPressed(KEY_LEFT_SHIFT && Player2->IsAlive()))
    {
        p = Player2->GetPosition();

        Shots2[idx_shot2]->Init({ p.x, p.y + SHOT_POS_Y1 }, 56, 20, SHOOT_SPEED);
        idx_shot2++;
        idx_shot2 %= MAX_SHOTS2;

        Shots2[idx_shot2]->Init({ p.x, p.y + SHOT_POS_Y2 }, 56, 20, SHOOT_SPEED);
        idx_shot2++;
        idx_shot2 %= MAX_SHOTS2;
    }

    //GAME LOGIC

    //Scene scroll
    Scene->Move({ -1, 0 });
    p = Scene->GetPosition();
    if (p.x <= -Scene->GetWidth()) Scene->SetPosition({ 0, p.y });

    //Player movement
    if (Player->IsAlive()) {
        Player->Move(dir);
    }
    if (Player2->IsAlive()) {
        Player2->Move(dir2);
    }
    Player->ClampPosition(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    Player2->ClampPosition(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

    //Shots management
    for (int i = 0; i < MAX_SHOTS; ++i)
    {
        if (Shots[i]->IsAlive())
        {
            Shots[i]->Move({ 1, 0 });
            p = Shots[i]->GetPosition();
            if (p.x > WINDOW_WIDTH)
                Shots[i]->SetAlive(false);
        }
    }

    for (int i = 0; i < MAX_SHOTS2; ++i)
    {
        if (Shots2[i]->IsAlive())
        {
            Shots2[i]->Move({ -1, 0 });
            p = Shots2[i]->GetPosition();
            if (p.x > WINDOW_WIDTH)
                Shots2[i]->SetAlive(false);
        }
    }

    //Collisions

    for (int i = 0; i < MAX_SHOTS; ++i) {
        if (Player->CheckShotCol(Shots2[i])) {
            Player->SetAlive(false);
        }

        if (Player2->CheckShotCol(Shots[i])) {
            Player2->SetAlive(false);
        }
    }
    return true;
}

void Game::Render()
{
    Rectangle rect;

    BeginDrawing();
    ClearBackground(BLACK);

    //Scene
    Scene->Render(img_background);
    Scene->Render(img_background, {(float)Scene->GetWidth(), 0});

    //Players
    if (Player->IsAlive()) {
        Player->Render(img_player);
        if (god_mode) {
            Player->RenderDebug(RED);
        }
    }
    if (Player2->IsAlive()) {
        Player2->RenderMirror(img_player, RED);
        if (god_mode) {
            Player2->RenderDebug(RED);
        }
    }

    //Shots
    for (int i = 0; i < MAX_SHOTS; ++i)
    {
        if (Shots[i]->IsAlive())
        {
            Shots[i]->Render(img_shot);
            if (god_mode)   Shots[i]->RenderDebug(RED);
        }
    }
    for (int i = 0; i < MAX_SHOTS2; ++i)
    {
        if (Shots2[i]->IsAlive())
        {
            Shots2[i]->RenderMirror(img_shot, WHITE);
            if (god_mode)   Shots2[i]->RenderDebug(RED);
        }
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
    UnloadTexture(img_background);
    UnloadTexture(img_player);
    UnloadTexture(img_shot);
}