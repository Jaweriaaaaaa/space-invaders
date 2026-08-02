#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <random>

#include "Enemy.h"
#include "EnemyBulletManager.h"

//it makes the enemy grid move together and a random shoot
class EnemyManager
{
public:
    explicit EnemyManager(sf::Vector2u windowSize);

    void update(float deltaTime);
    void render(sf::RenderWindow& window);

   
    std::vector<Enemy>& getEnemies();
    std::vector<Bullet>& getEnemyBullets();

private:
    void moveFormation(float deltaTime);
    void tryToFire(float deltaTime);

    std::vector<Enemy> enemies;
    sf::Vector2u windowSize;
    float direction; 

    EnemyBulletManager bulletManager;
    float shootTimer;
    std::mt19937 randomEngine;  //it generates a random number
};
