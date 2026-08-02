#pragma once

#include "Player.h"
#include "BulletManager.h"
#include "EnemyManager.h"
//bullets and enemies and players overlap is detected 


struct CollisionResult
{
    bool playerWasHit = false;
    int enemiesDestroyed = 0;
};


class CollisionManager
{
public:
    CollisionResult checkCollisions(Player& player, BulletManager& playerBullets, EnemyManager& enemyManager);
};
