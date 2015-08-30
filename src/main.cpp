#include "Game.h"
#include "GameScreen.h"
#include "MainMenuScreen.h"
#include <memory>

int main()
{
    Game game;
    shared_ptr<GameScreen> ptr = make_shared<MainMenuScreen>();
    game.addScreen(ptr);
    game.gameLoop();
}
