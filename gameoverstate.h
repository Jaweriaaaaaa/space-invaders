#pragma once

#include "GameState.h"


class GameOverState : public GameState
{
public:
    GameOverState(Game& game, int finalScore);

    void handleInput(const sf::Event& event) override;
    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;

private:
    sf::Text gameOverText;
    sf::Text scoreText;
    sf::Text instructionText;
};
