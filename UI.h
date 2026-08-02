#pragma once

#include <SFML/Graphics.hpp>

//will display score and remaining lives on screen


class UI
{
public:
    explicit UI(const sf::Font& font);

    void setScore(int score);
    void setLives(int lives);

    void render(sf::RenderWindow& window);

private:
    sf::Text scoreText;
    sf::Text livesText;
};
