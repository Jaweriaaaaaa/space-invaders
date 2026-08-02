#pragma once

#include <SFML/Graphics.hpp>
//for player movement or rendering
class Player
{
public:
    explicit Player(sf::Vector2u windowSize);

    void update(float deltaTime);
    void render(sf::RenderWindow& window);

    sf::Vector2f getPosition() const;
    sf::Vector2f getFirePosition() const;
    sf::FloatRect getBounds() const;

private:
    sf::RectangleShape shape;
    float speed;
    sf::Vector2u windowSize;
};
