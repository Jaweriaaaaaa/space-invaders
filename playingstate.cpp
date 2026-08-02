#include "PlayingState.h"
#include "GameOverState.h"
#include "Game.h"

namespace
{
    constexpr int StartingLives = 3;
    constexpr int PointsPerEnemy = 10;
}

PlayingState::PlayingState(Game& game, sf::Vector2u windowSize)
    : GameState(game)
    , player(windowSize)
    , bulletManager(windowSize)
    , enemyManager(windowSize)
    , ui(game.getFont())
    , lives(StartingLives)
{
    ui.setLives(lives);
}

void PlayingState::handleInput(const sf::Event& event)
{
    
    if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>())
    {
        if (keyPressed->code == sf::Keyboard::Key::Space)
        {
            bulletManager.fire(player.getFirePosition());
        }
    }
}

void PlayingState::update(float deltaTime)
{
    player.update(deltaTime);
    bulletManager.update(deltaTime);
    enemyManager.update(deltaTime);

    CollisionResult result = collisionManager.checkCollisions(player, bulletManager, enemyManager);

    if (result.enemiesDestroyed > 0)
    {
        scoreManager.addPoints(result.enemiesDestroyed * PointsPerEnemy);
        ui.setScore(scoreManager.getScore());
    }

    if (result.playerWasHit)
    {
        lives -= 1;
        ui.setLives(lives);

        if (lives <= 0)
        {
            int finalScore = scoreManager.getScore();
            game.changeState(std::make_unique<GameOverState>(game, finalScore));
        }
    }
}

void PlayingState::render(sf::RenderWindow& window)
{
    player.render(window);
    bulletManager.render(window);
    enemyManager.render(window);
    ui.render(window);
}