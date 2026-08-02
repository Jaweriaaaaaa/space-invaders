#pragma once


class ScoreManager
{
public:
    void addPoints(int points);
    int getScore() const;

private:
    int score = 0;
};
