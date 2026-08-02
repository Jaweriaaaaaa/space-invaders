#include "ScoreManager.h"

void ScoreManager::addPoints(int points)
{
    score += points;
}

int ScoreManager::getScore() const
{
    return score;
}