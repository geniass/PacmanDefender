#include "Game.h"
#include "GameScreen.h"
#include "GameWorldScreen.h"
#include <memory>

int main()
{
    Game game;
    shared_ptr<GameScreen> ptr = make_shared<GameWorldScreen>();
    game.addScreen(ptr);
    game.gameLoop();
}
