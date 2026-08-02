#pragma once

#include <SFML/Graphics.hpp>
//made dumb on purpose so its movement is controlled by enemy manager

class Enemy
{
public:
    explicit Enemy(sf::Vector2f position);

    void move(sf::Vector2f offset);
    void render(sf::RenderWindow& window);

    sf::Vector2f getPosition() const;
    sf::Vector2f getFirePosition() const;
    sf::FloatRect getBounds() const;   //after colliosn detection enemy will get rectangle area

private:
    sf::RectangleShape shape;
};
