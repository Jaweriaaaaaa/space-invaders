#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

#include "AssetManager.h"

class GameState;


class Game
{
public:
    Game();
    ~Game();

    void run();

   
    void changeState(std::unique_ptr<GameState> newState);  //smart pointer ,so ne need to use new/del operator

    
    void quit();

    sf::Vector2u getWindowSize() const;
    const sf::Font& getFont() const;

private:
    void processEvents();
    void update(float deltaTime);  
    void render();

    sf::RenderWindow window;
    AssetManager assetManager;
    std::unique_ptr<GameState> currentState;  

   //it will prevent from suddent switch in playingstate
    std::unique_ptr<GameState> pendingState;
};
