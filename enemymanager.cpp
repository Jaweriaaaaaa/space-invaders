#include "EnemyManager.h"

namespace
{
    constexpr int Rows = 4;
    constexpr int Columns = 8;
    constexpr float HorizontalSpacing = 60.f;
    constexpr float VerticalSpacing = 50.f;
    constexpr float StartX = 60.f;
    constexpr float StartY = 60.f;
    constexpr float HorizontalSpeed = 60.f; 
    constexpr float StepDownAmount = 20.f;
    constexpr float EnemyWidth = 40.f; 

    constexpr float ShootInterval = 1.f; // seconds between enemy shots
}

EnemyManager::EnemyManager(sf::Vector2u windowSize)
    : windowSize(windowSize)
    , direction(1.f)
    , bulletManager(windowSize)
    , shootTimer(0.f)
    , randomEngine(std::random_device{}())
{
    for (int row = 0; row < Rows; ++row)
    {
        for (int column = 0; column < Columns; ++column)
        {
            float x = StartX + static_cast<float>(column) * HorizontalSpacing;
            float y = StartY + static_cast<float>(row) * VerticalSpacing;
            enemies.emplace_back(sf::Vector2f{ x, y });
        }
    }
}

void EnemyManager::update(float deltaTime)
{
    moveFormation(deltaTime);
    tryToFire(deltaTime);
    bulletManager.update(deltaTime);
}

void EnemyManager::moveFormation(float deltaTime)
{
    float distance = HorizontalSpeed * deltaTime * direction;

    bool hitEdge = false;
    for (const Enemy& enemy : enemies)
    {
        float nextX = enemy.getPosition().x + distance;
        if (nextX < 0.f || nextX + EnemyWidth > static_cast<float>(windowSize.x))
        {
            hitEdge = true;
            break;
        }
    }

    if (hitEdge)
    {
        direction *= -1.f;

        for (Enemy& enemy : enemies)
        {
            enemy.move({ 0.f, StepDownAmount });
        }
    }
    else
    {
        for (Enemy& enemy : enemies)
        {
            enemy.move({ distance, 0.f });
        }
    }
}

void EnemyManager::tryToFire(float deltaTime)
{
    shootTimer += deltaTime;
   //accumulated time and after threshold it reset and shoot again
    if (shootTimer < ShootInterval || enemies.empty())
    {
        return;
    }

    shootTimer = 0.f;

    // Pick a random enemy from the current formation to fire the shot.
    std::uniform_int_distribution<std::size_t> distribution(0, enemies.size() - 1);
    std::size_t shooterIndex = distribution(randomEngine);

    bulletManager.fire(enemies[shooterIndex].getFirePosition());
}

void EnemyManager::render(sf::RenderWindow& window)
{
    for (Enemy& enemy : enemies)
    {
        enemy.render(window);
    }

    bulletManager.render(window);
}

std::vector<Enemy>& EnemyManager::getEnemies()
{
    return enemies;
}

std::vector<Bullet>& EnemyManager::getEnemyBullets()
{
    return bulletManager.getBullets();
}