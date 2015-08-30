#include "MainMenuScreen.h"
#include <iostream>
#include <memory>
#include "GameScreen.h"
#include "GameWorldScreen.h"

#include <SFML/Graphics.hpp>

MainMenuScreen::MainMenuScreen()
{
}

shared_ptr<GameScreen> MainMenuScreen::run(sf::RenderWindow &window)
{
    sf::Event Event;
    bool Running = true;
    sf::Texture Texture;
    sf::Sprite Sprite;
    sf::Font Font;
    sf::Text PlayText;
    sf::Text QuitText;
    sf::Text ContinueText;
    sf::Text* selectedText = &PlayText;

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

    PlayText.setFont(Font);
    PlayText.setCharacterSize(20);
    PlayText.setString("Play");
    PlayText.setPosition({ 280.f, 160.f });

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
                return nullptr;
            }
            if (Event.type == sf::Event::KeyPressed)
            {
                switch (Event.key.code)
                {
                case sf::Keyboard::Up:
                    selectedText = &PlayText;
                    break;
                case sf::Keyboard::Down:
                    selectedText = &QuitText;
                    break;
                case sf::Keyboard::Return:
                    if (selectedText == &PlayText)
                    {
                        if (playing) {
                            cout << "Continue" << endl;
                            return nullptr;
                        }

                        playing = true;
                        return make_shared<GameWorldScreen>();
                    }
                    else
                    {
                        return nullptr;
                    }
                    break;
                default:
                    break;
                }
            }
        }
        if (selectedText == &PlayText)
        {
            PlayText.setColor(sf::Color(255, 0, 0, 255));
            QuitText.setColor(sf::Color(255, 255, 255, 255));
            ContinueText.setColor(sf::Color(255, 0, 0, 255));
        }
        else
        {
            PlayText.setColor(sf::Color(255, 255, 255, 255));
            QuitText.setColor(sf::Color(255, 0, 0, 255));
            ContinueText.setColor(sf::Color(255, 255, 255, 255));
        }

        window.clear();
        window.draw(Sprite);
            if (playing)
            {
                window.draw(ContinueText);
            }
            else
            {
                window.draw(PlayText);
            }
            window.draw(QuitText);
        window.display();
    }

    return nullptr;
}
