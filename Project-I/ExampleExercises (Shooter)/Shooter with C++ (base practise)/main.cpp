
#include "Game.h"

int main()
{
    Game game;
    if (!game.Initialise())
        return -1;

    while (!WindowShouldClose())
    {
        if(!game.Update()) break;
        game.Render();
    }

    game.Cleanup();
    return 0;
}
