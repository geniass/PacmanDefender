#include "PauseScreen.h"
#include <iostream>
#include <memory>
#include "GameScreen.h"
#include "GameWorldScreen.h"

#include <SFML/Graphics.hpp>

PauseScreen::PauseScreen(GameWorldScreen* gameWorldScreen) : _gameWorldScreen{gameWorldScreen}
{
}

shared_ptr<GameScreen> PauseScreen::run(sf::RenderWindow &window)
{
    sf::Event Event;
    bool Running = true;
    sf::Texture Texture;
    sf::Sprite Sprite;
    sf::Font Font;
    sf::Text QuitText;
    sf::Text ContinueText;
    sf::Text* selectedText = &ContinueText;

    if (!Texture.loadFromFile("resources/pacman.png"))
    {
        std::cerr << "Error loading presentation.gif" << std::endl;
        return nullptr;
    }

    Sprite.setTexture(Texture);
    if (!Font.loadFromFile("resources/sansation.ttf"))
    {
        std::cerr << "Error loading verdanab.ttf" << std::endl;
        return nullptr;
    }

    QuitText.setFont(Font);
    QuitText.setCharacterSize(20);
    QuitText.setString("Exit");
    QuitText.setPosition({ 280.f, 220.f });

    ContinueText.setFont(Font);
    ContinueText.setCharacterSize(20);
    ContinueText.setString("Continue");
    ContinueText.setPosition({ 280.f, 160.f });

    while (Running)
    {
        while (window.pollEvent(Event))
        {
            if (Event.type == sf::Event::Closed)
            {
                _gameWorldScreen->quit();
                return nullptr;
            }
            if (Event.type == sf::Event::KeyPressed)
            {
                switch (Event.key.code)
                {
                case sf::Keyboard::Up:
                    selectedText = &ContinueText;
                    break;
                case sf::Keyboard::Down:
                    selectedText = &QuitText;
                    break;
                case sf::Keyboard::Return:
                    if (selectedText == &ContinueText)
                    {
                        cout << "Continue" << endl;
                        return nullptr;
                    }
                    else
                    {
                        // quit selected
                        _gameWorldScreen->quit();
                        return nullptr;
                    }
                    break;
                default:
                    break;
                }
            }
        }
        if (selectedText == &ContinueText)
        {
            QuitText.setColor(sf::Color(255, 255, 255, 255));
            ContinueText.setColor(sf::Color(255, 0, 0, 255));
        }
        else
        {
            QuitText.setColor(sf::Color(255, 0, 0, 255));
            ContinueText.setColor(sf::Color(255, 255, 255, 255));
        }

        window.clear();
        window.draw(Sprite);
        window.draw(ContinueText);
        window.draw(QuitText);
        window.display();
    }

    return nullptr;
}
