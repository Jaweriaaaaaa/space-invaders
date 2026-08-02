#pragma once

#include <SFML/Graphics.hpp>

class Game;

class GameState
{
public:
    explicit GameState(Game& game) // refrence memeber 
        : game(game)
    {
    }

    virtual ~GameState() = default;
    //these are abstract functions,only those who will inherit this class can implement them 
    virtual void handleInput(const sf::Event& event) = 0;
    virtual void update(float deltaTime) = 0;
    virtual void render(sf::RenderWindow& window) = 0;

protected:
    
    Game& game;
};
