#include "Bullet.h"

namespace
{
    constexpr float BulletWidth = 4.f;
    constexpr float BulletHeight = 12.f;
}

Bullet::Bullet(sf::Vector2f startPosition, sf::Vector2f velocity)
    : velocity(velocity)
{
    shape.setSize({ BulletWidth, BulletHeight });
    shape.setFillColor(sf::Color::White);

    // Center the bullet horizontally on the spawn position, rather than
    // spawning from its top-left corner.
    shape.setPosition({ startPosition.x - BulletWidth / 2.f, startPosition.y });
}

void Bullet::update(float deltaTime)
{
    shape.move(velocity * deltaTime);
}

void Bullet::render(sf::RenderWindow& window)
{
    window.draw(shape);
}

sf::FloatRect Bullet::getBounds() const
{
    return shape.getGlobalBounds();
}

bool Bullet::isOffScreen(sf::Vector2u windowSize) const
{
    sf::Vector2f position = shape.getPosition();

    return position.y + shape.getSize().y < 0.f
        || position.y > static_cast<float>(windowSize.y);
}