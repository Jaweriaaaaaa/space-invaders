#include "BulletManager.h"

#include <algorithm>

namespace
{
    constexpr float PlayerBulletSpeed = -500.f; // negative = upward
}

BulletManager::BulletManager(sf::Vector2u windowSize)
    : windowSize(windowSize)
{
}

void BulletManager::fire(sf::Vector2f spawnPosition)
{
    bullets.emplace_back(spawnPosition, sf::Vector2f{ 0.f, PlayerBulletSpeed }); //built new object inside vector
}

void BulletManager::update(float deltaTime)
{
    for (Bullet& bullet : bullets)
    {
        bullet.update(deltaTime);
    }

    bullets.erase(
        std::remove_if(
            bullets.begin(), bullets.end(),
            [this](const Bullet& bullet) { return bullet.isOffScreen(windowSize); }),  //offscreen bullets will be removed
        bullets.end());
}

void BulletManager::render(sf::RenderWindow& window)
{
    for (Bullet& bullet : bullets)
    {
        bullet.render(window);
    }
}

std::vector<Bullet>& BulletManager::getBullets()
{
    return bullets;
}