#include "Game.h"
#include "GameState.h"
#include "MenuState.h"

Game::Game()
    : window(sf::VideoMode({ 800u, 600u }), "Space Invaders")
{
    window.setFramerateLimit(60);

    currentState = std::make_unique<MenuState>(*this, assetManager.getFont());
}


Game::~Game() = default;

void Game::run()
{
    sf::Clock clock;

    while (window.isOpen())
    {
        float deltaTime = clock.restart().asSeconds(); // it will make sure the movement speed is independent of whether computor is slow or fast

        processEvents();

        
        if (pendingState)
        {
            currentState = std::move(pendingState);
        }

        update(deltaTime);
        render();
    }
}

void Game::processEvents()
{
    while (const std::optional event = window.pollEvent()) //in sfml3 it will take out or return pending events
    {
        if (event->is<sf::Event::Closed>())
        {
            window.close();
        }

        currentState->handleInput(*event);
    }
}

void Game::update(float deltaTime)
{
    currentState->update(deltaTime);
}

void Game::render()
{
    window.clear(sf::Color::Black);
    currentState->render(window);
    window.display();
}

void Game::changeState(std::unique_ptr<GameState> newState)
{
    pendingState = std::move(newState);
}

void Game::quit()
{
    window.close();
}

sf::Vector2u Game::getWindowSize() const
{
    return window.getSize();
}

const sf::Font& Game::getFont() const
{
    return assetManager.getFont();
}