#include "UI.h"

#include <string>

namespace
{
    constexpr unsigned int CharacterSize = 24;
}

UI::UI(const sf::Font& font)
    : scoreText(font, "Score: 0", CharacterSize)
    , livesText(font, "Lives: 3", CharacterSize)
{
    scoreText.setPosition({ 10.f, 10.f });
    scoreText.setFillColor(sf::Color::White);

    livesText.setPosition({ 10.f, 40.f });
    livesText.setFillColor(sf::Color::White);
}

void UI::setScore(int score)
//std::tostring--number to text or string
{
    scoreText.setString("Score: " + std::to_string(score));
}
//setstring --exisiting text object content will be updated
void UI::setLives(int lives)
{
    livesText.setString("Lives: " + std::to_string(lives));   
}

void UI::render(sf::RenderWindow& window)
{
    window.draw(scoreText);
    window.draw(livesText);
}