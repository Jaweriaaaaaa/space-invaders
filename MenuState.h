#pragma once

#include "GameState.h"

//here arrow keys will move between options 
//and on pressing enter it will be selected
class MenuState : public GameState
{
public:
    MenuState(Game& game, const sf::Font& font);

    void handleInput(const sf::Event& event) override;
    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;

private:
    enum class MenuOption
    {
        StartGame,
        Exit
    };

    void selectPrevious();
    void selectNext();
    void confirmSelection();
    void refreshHighlight();

    sf::Text startGameText;
    sf::Text exitText;
    MenuOption selectedOption;
};
