#pragma once

#include <SFML/Graphics.hpp>

// A single projectile. Used for both player bullets (moving upward) and
// enemy bullets (moving downward) the direction is just the sign of

class Bullet
{
public:
    Bullet(sf::Vector2f startPosition, sf::Vector2f velocity);

    void update(float deltaTime);
    void render(sf::RenderWindow& window);

    sf::FloatRect getBounds() const;
    bool isOffScreen(sf::Vector2u windowSize) const; //check bullet out of screen and removes em from memory

private:
    sf::RectangleShape shape;
    sf::Vector2f velocity;
};
