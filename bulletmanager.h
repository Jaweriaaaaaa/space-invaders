#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
//will manage all active bullets

#include "Bullet.h"

class BulletManager
{
public:
    explicit BulletManager(sf::Vector2u windowSize);

    void fire(sf::Vector2f spawnPosition);

    void update(float deltaTime);
    void render(sf::RenderWindow& window);

    //  CollisionManager needs to erase bullets that were hit.
    std::vector<Bullet>& getBullets();

private:
    std::vector<Bullet> bullets;
    sf::Vector2u windowSize;
};
