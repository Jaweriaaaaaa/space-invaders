#include "CollisionManager.h"

CollisionResult CollisionManager::checkCollisions(Player& player, BulletManager& playerBullets, EnemyManager& enemyManager)
{
    CollisionResult result;

    std::vector<Bullet>& bullets = playerBullets.getBullets();
    std::vector<Enemy>& enemies = enemyManager.getEnemies();

    // Player bullets vs enemies.
    for (auto bulletIt = bullets.begin(); bulletIt != bullets.end(); )
    {
        bool bulletHitSomething = false;

        for (auto enemyIt = enemies.begin(); enemyIt != enemies.end(); ++enemyIt)
        {
            if (bulletIt->getBounds().findIntersection(enemyIt->getBounds()).has_value())
            {
                enemies.erase(enemyIt);
                bulletIt = bullets.erase(bulletIt);
                bulletHitSomething = true;
                result.enemiesDestroyed += 1;
                break;
            }
        }

        if (!bulletHitSomething)
        {
            ++bulletIt;
        }
    }

    // Enemy bullets vs the player.
    std::vector<Bullet>& enemyBullets = enemyManager.getEnemyBullets();

    for (auto bulletIt = enemyBullets.begin(); bulletIt != enemyBullets.end(); )
    {
        if (bulletIt->getBounds().findIntersection(player.getBounds()).has_value())
        {
            bulletIt = enemyBullets.erase(bulletIt);
            result.playerWasHit = true;
        }
        else
        {
            ++bulletIt;
        }
    }

    return result;
}