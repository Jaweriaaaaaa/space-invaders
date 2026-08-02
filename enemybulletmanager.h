#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Bullet.h"


class EnemyBulletManager
{
public:
    explicit EnemyBulletManager(sf::Vector2u windowSize);

    void fire(sf::Vector2f spawnPosition);

    void update(float deltaTime);
    void render(sf::RenderWindow& window);

    std::vector<Bullet>& getBullets();

private:
    std::vector<Bullet> bullets;
    sf::Vector2u windowSize;
};
