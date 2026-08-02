#include "Player.h"

namespace
{
    constexpr float PlayerWidth = 50.f;
    constexpr float PlayerHeight = 20.f;
    constexpr float PlayerSpeed = 300.f;
    constexpr float BottomMargin = 30.f;
}

Player::Player(sf::Vector2u windowSize)
    : speed(PlayerSpeed)
    , windowSize(windowSize)
{
    shape.setSize({ PlayerWidth, PlayerHeight });
    shape.setFillColor(sf::Color::Green);

    float startX = (static_cast<float>(windowSize.x) - PlayerWidth) / 2.f;
    float startY = static_cast<float>(windowSize.y) - PlayerHeight - BottomMargin;
    shape.setPosition({ startX, startY });
}

void Player::update(float deltaTime)
{

    float movement = speed * deltaTime;
    //polling is importanta so as long as key is pressed ,movement continues

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        shape.move({ -movement, 0.f });
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
    {
        shape.move({ movement, 0.f });
    }

    //it is for the player position to keep iy within window
    sf::Vector2f position = shape.getPosition();
    float minX = 0.f;
    float maxX = static_cast<float>(windowSize.x) - shape.getSize().x;

    if (position.x < minX)
    {
        position.x = minX;
    }
    else if (position.x > maxX)
    {
        position.x = maxX;
    }

    shape.setPosition(position);
}

void Player::render(sf::RenderWindow& window)
{
    window.draw(shape);
}

sf::Vector2f Player::getPosition() const
{
    return shape.getPosition();
}

sf::Vector2f Player::getFirePosition() const
{
    sf::Vector2f position = shape.getPosition();
    float centerX = position.x + shape.getSize().x / 2.f;
    return { centerX, position.y };
}

sf::FloatRect Player::getBounds() const
{
    return shape.getGlobalBounds();
}