#include "Enemy.h"

namespace
{
    constexpr float EnemyWidth = 40.f;
    constexpr float EnemyHeight = 30.f;
}

Enemy::Enemy(sf::Vector2f position)
{
    shape.setSize({ EnemyWidth, EnemyHeight });
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(position);
}

void Enemy::move(sf::Vector2f offset)
{
    shape.move(offset);
}

void Enemy::render(sf::RenderWindow& window)
{
    window.draw(shape);
}

sf::Vector2f Enemy::getPosition() const
{
    return shape.getPosition();
}

sf::Vector2f Enemy::getFirePosition() const
{
    sf::Vector2f position = shape.getPosition();
    sf::Vector2f size = shape.getSize();
    return { position.x + size.x / 2.f, position.y + size.y };
}

sf::FloatRect Enemy::getBounds() const
{
    return shape.getGlobalBounds();
}