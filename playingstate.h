#pragma once

#include "GameState.h"
#include "Player.h"
#include "BulletManager.h"
#include "EnemyManager.h"
#include "CollisionManager.h"
#include "ScoreManager.h"
#include "UI.h"


class PlayingState : public GameState
{
public:
    PlayingState(Game& game, sf::Vector2u windowSize);

    void handleInput(const sf::Event& event) override;
    void update(float deltaTime) override;
    void render(sf::RenderWindow& window) override;

private:
    Player player;
    BulletManager bulletManager;
    EnemyManager enemyManager;
    CollisionManager collisionManager;
    ScoreManager scoreManager;
    UI ui;
    int lives;
};
