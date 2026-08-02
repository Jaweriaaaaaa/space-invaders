#include "GameOverState.h"
#include "Game.h"
#include "MenuState.h"

#include <string>

GameOverState::GameOverState(Game& game, int finalScore)
    : GameState(game)
    , gameOverText(game.getFont(), "Game Over", 50)
    , scoreText(game.getFont(), "Final Score: " + std::to_string(finalScore), 30)
    , instructionText(game.getFont(), "Press Enter to return to Menu", 24)
{
    gameOverText.setPosition({ 250.f, 200.f });
    gameOverText.setFillColor(sf::Color::Red);

    scoreText.setPosition({ 260.f, 280.f });
    scoreText.setFillColor(sf::Color::White);

    instructionText.setPosition({ 190.f, 340.f });
    instructionText.setFillColor(sf::Color::White);
}

void GameOverState::handleInput(const sf::Event& event)
{
    if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>())
    {
        if (keyPressed->code == sf::Keyboard::Key::Enter)
        {
            game.changeState(std::make_unique<MenuState>(game, game.getFont()));
        }
    }
}

void GameOverState::update(float deltaTime)
{
    (void)deltaTime;
}

void GameOverState::render(sf::RenderWindow& window)
{
    window.draw(gameOverText);
    window.draw(scoreText);
    window.draw(instructionText);
}