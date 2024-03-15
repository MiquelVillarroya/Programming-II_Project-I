
#include <stdio.h>
#include <raylib.h>

//Windows size
#define WINDOW_WIDTH    1024
#define WINDOW_HEIGHT   768

//Velocities
#define PLAYER_SPEED    8
#define PLAYER_SPEED2    4

#define SCENE_SPEED     2
#define SHOOT_SPEED     16
#define SHOOT_SPEED2     8
#define ENEMY_SPEED     4


//Maximum number of shots on screen
#define MAX_SHOTS       32

//Maximum enemies on screen
#define MAX_ENEMIES     5

//Entity struct definition
typedef struct Entity {
    Vector2 pos;
    int width, height;
    int speed;
    bool is_alive;
} Entity;

//Global variables
Entity player, player2, shots[MAX_SHOTS], shots2[MAX_SHOTS], scene, enemy[MAX_ENEMIES];
int idx_shot, idx_shot2, idx_enemy;   //next free position in the shots array
bool god_mode;
Texture img_background, img_player, img_shot, img_shot2, img_enemy;

//Basic structure functions
void Setup();
bool Update();
void Render();
void Cleanup();

//Auxiliar functions
bool LoadTextures();
void UnloadTextures();

int main()
{
    Setup();
    while(!WindowShouldClose())
    {
        if(!Update()) break;
        Render();
    }
    Cleanup();

    return 0;
}

void Setup()
{
    //Initialise windows
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Spaceship: arrow keys + space, f1: god mode");

    //Load resources
    if (!LoadTextures())
    {
        printf("Failed to load textures\n");
        CloseWindow();
        return;
    }

    //Initialise player
    player.pos = { 20, WINDOW_HEIGHT / 3 };
    player.width = 104;
    player.height = 82;
    player.speed = PLAYER_SPEED;
    player.is_alive = true;

    player2.pos = { 20, WINDOW_HEIGHT / 3 * 2 };
    player2.width = 104;
    player2.height = 82;
    player2.speed = PLAYER_SPEED2;
    player2.is_alive = true;

    //Initialise shots
    idx_shot = 0;
    idx_shot2 = 0;
    
    for (int i = 0; i < MAX_SHOTS; ++i)
    {
        shots[i].is_alive = false;
        shots2[i].is_alive = false;
    }

    //Initialize enemies
    idx_enemy = 0;

    for (int i = 0; i < MAX_ENEMIES; ++i)
    {
        enemy[i].is_alive = false;
    }
    
    //Initialise scene
    scene.pos = { 0, 0 };
    scene.width = img_background.width;
    scene.height = WINDOW_HEIGHT;
    scene.speed = SCENE_SPEED;
    scene.is_alive = true;

    //Initialise control variables
    god_mode = false;

    //Set the target frame rate for the application
    SetTargetFPS(60);
}
bool LoadTextures()
{
    img_background = LoadTexture("images/background.png");
    if (img_background.id == 0) return false;
    img_player = LoadTexture("images/spaceship.png");
    if (img_player.id == 0) return false;
    img_shot = LoadTexture("images/shot.png");
    if (img_shot.id == 0) return false;
    img_shot2 = LoadTexture("images/DDefender.png");
    if (img_shot2.id == 0) return false;
    img_enemy = LoadTexture("images/enemy.png");
    if (img_enemy.id == 0) return false;

    return true;
}

bool Update()
{
    int fx = 0, fy = 0;
    int fx2 = 0, fy2 = 0;
    
    //PROCESS INPUT

    if (IsKeyDown(KEY_ESCAPE))  return false;
    if (IsKeyPressed(KEY_F1))   god_mode = !god_mode;

    if (IsKeyDown(KEY_UP))          fy = -1;
    else if (IsKeyDown(KEY_DOWN))   fy = 1;
    if (IsKeyDown(KEY_LEFT))        fx = -1;
    else if (IsKeyDown(KEY_RIGHT))  fx = 1;

    if (IsKeyDown(KEY_W))           fy2 = -1;
    else if (IsKeyDown(KEY_S))      fy2 = 1;
    if (IsKeyDown(KEY_A))           fx2 = -1;
    else if (IsKeyDown(KEY_D))      fx2 = 1;

    if (IsKeyPressed(KEY_SPACE))
    {
        shots[idx_shot].pos = { player.pos.x + 29, player.pos.y + 3 };
        shots[idx_shot].width = 56;
        shots[idx_shot].height = 20;
        shots[idx_shot].speed = 10;
        shots[idx_shot].is_alive = true;
        idx_shot++;
        idx_shot %= MAX_SHOTS;

        shots[idx_shot].pos = { player.pos.x + 29, player.pos.y + 59 };
        shots[idx_shot].width = 56;
        shots[idx_shot].height = 20;
        shots[idx_shot].speed = 10;
        shots[idx_shot].is_alive = true;
        idx_shot++;
        idx_shot %= MAX_SHOTS;
    }

    if (IsKeyPressed(KEY_LEFT_SHIFT)) {

        shots2[idx_shot2].pos = { player2.pos.x + 29, player2.pos.y + 21 };
        shots2[idx_shot2].width = 112;
        shots2[idx_shot2].height = 40;
        shots2[idx_shot2].speed = 5;
        shots2[idx_shot2].is_alive = true;
        idx_shot2++;
        idx_shot2 %= MAX_SHOTS;
    }

    //GAME LOGIC

    //Scene scroll
    scene.pos.x -= SCENE_SPEED;
    if (scene.pos.x <= -scene.width) scene.pos.x = 0;

    //Player movement
    player.pos.x += fx * PLAYER_SPEED;
    player.pos.y += fy * PLAYER_SPEED;

    player2.pos.x += fx2 * PLAYER_SPEED2;
    player2.pos.y += fy2 * PLAYER_SPEED2;


    if (player.pos.x < 0) player.pos.x = 0;
    if (player.pos.y < 0) player.pos.y = 0;
    if (player.pos.x > WINDOW_WIDTH - player.width) player.pos.x = WINDOW_WIDTH - player.width;
    if (player.pos.y > WINDOW_HEIGHT - player.height) player.pos.y = WINDOW_HEIGHT - player.height;

    if (player2.pos.x < 0) player2.pos.x = 0;
    if (player2.pos.y < 0) player2.pos.y = 0;
    if (player2.pos.x > WINDOW_WIDTH - player2.width) player2.pos.x = WINDOW_WIDTH - player2.width;
    if (player2.pos.y > WINDOW_HEIGHT - player2.height) player2.pos.y = WINDOW_HEIGHT - player2.height;

    //Shots management
    for (int i = 0; i < MAX_SHOTS; ++i)
    {
        if (shots[i].is_alive || shots2[i].is_alive)
        {
            shots[i].pos.x += SHOOT_SPEED;
            if (shots[i].pos.x > WINDOW_WIDTH)
                shots[i].is_alive = false;
            shots2[i].pos.x += SHOOT_SPEED2;
            if (shots2[i].pos.x > WINDOW_WIDTH)
                shots2[i].is_alive = false;
        }
    }

    //Enemy spawn
    if (GetRandomValue(1, 100) == 99) {
        enemy[idx_enemy].pos = {WINDOW_WIDTH - 215, (float) GetRandomValue(1, WINDOW_HEIGHT - 331)};
        enemy[idx_enemy].width = 215;
        enemy[idx_enemy].height = 331;
        enemy[idx_enemy].speed = 5;
        enemy[idx_enemy].is_alive = true;
        idx_enemy++;
        idx_enemy %= MAX_ENEMIES;
    }
    
    //Enemy movement
    for (int i = 0; i < MAX_ENEMIES; ++i)
    {
        if (enemy[i].is_alive)
        {
            enemy[i].pos.x -= ENEMY_SPEED;
            if (enemy[i].pos.x < 0)
                enemy[i].is_alive = false;
        }
    }
    return true;
}

void Render()
{
    Rectangle rect;

    BeginDrawing();
    ClearBackground(BLACK);

    //Scene
    DrawTexture(img_background, scene.pos.x, 0, WHITE);
    DrawTexture(img_background, scene.pos.x + scene.width, 0, WHITE);

    //Player
    DrawTexture(img_player, player.pos.x, player.pos.y, WHITE);
    DrawTexture(img_player, player2.pos.x, player2.pos.y, RED);

    if (god_mode)
    {
        rect = { player.pos.x, player.pos.y, (float)player.width, (float)player.height };
        DrawRectangleLinesEx(rect, 2, RED);
        rect = { player2.pos.x, player2.pos.y, (float)player2.width, (float)player2.height };
        DrawRectangleLinesEx(rect, 2, GREEN);
    }

    //Shots
    for (int i = 0; i < MAX_SHOTS; ++i)
    {
        if (shots[i].is_alive)
        {
            DrawTexture(img_shot, shots[i].pos.x, shots[i].pos.y, WHITE);

            if (god_mode)
            {
                rect = { shots[i].pos.x, shots[i].pos.y, (float)shots[i].width, (float)shots[i].height };
                DrawRectangleLinesEx(rect, 2, RED);

            }
        }
        if (shots2[i].is_alive)
        {
            DrawTexture(img_shot2, shots2[i].pos.x, shots2[i].pos.y, WHITE);

            if (god_mode)
            {
                rect = { shots2[i].pos.x, shots2[i].pos.y, (float)shots2[i].width, (float)shots2[i].height };
                DrawRectangleLinesEx(rect, 2, GREEN);
            }
        }
    }

    //Enemies

    for (int i = 0; i < MAX_ENEMIES; ++i)
    {
        if (enemy[i].is_alive)
        {
            DrawTexture(img_enemy, enemy[i].pos.x, enemy[i].pos.y, WHITE);

            if (god_mode)
            {
                rect = { enemy[i].pos.x, enemy[i].pos.y, (float)enemy[i].width, (float)enemy[i].height };
                DrawRectangleLinesEx(rect, 2, RED);

            }
        }
    }
    EndDrawing();
}

void Cleanup()
{
    UnloadTextures();
}
void UnloadTextures()
{
    UnloadTexture(img_background);
    UnloadTexture(img_player);
    UnloadTexture(img_shot);
    UnloadTexture(img_shot2);
    UnloadTexture(img_enemy);
}
