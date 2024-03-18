#pragma once
#include <raylib.h>
#include "TileMap.h"

class Scene
{
public:
    Scene();
    ~Scene();

    AppStatus Init();
    void HandleInputPlayer();
    void Update();
    void Render();
    void Release();

private:
    AppStatus LoadLevel(int stage);
    
    TileMap *level;
};

