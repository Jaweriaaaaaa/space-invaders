#include "EnemyBulletManager.h"

#include <algorithm>

namespace
{
    constexpr float EnemyBulletSpeed = 300.f; // positive = downward
}

EnemyBulletManager::EnemyBulletManager(sf::Vector2u windowSize)
    : windowSize(windowSize)
{
}

void EnemyBulletManager::fire(sf::Vector2f spawnPosition)
{
    bullets.emplace_back(spawnPosition, sf::Vector2f{ 0.f, EnemyBulletSpeed });
}

void EnemyBulletManager::update(float deltaTime)
{
    for (Bullet& bullet : bullets)
    {
        bullet.update(deltaTime);
    }

    bullets.erase(
        std::remove_if(
            bullets.begin(), bullets.end(),
            [this](const Bullet& bullet) { return bullet.isOffScreen(windowSize); }),
        bullets.end());
}

void EnemyBulletManager::render(sf::RenderWindow& window)
{
    for (Bullet& bullet : bullets)
    {
        bullet.render(window);
    }
}

std::vector<Bullet>& EnemyBulletManager::getBullets()
{
    return bullets;
}