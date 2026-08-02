#include "MenuState.h"
#include "PlayingState.h"
#include "Game.h"

MenuState::MenuState(Game& game, const sf::Font& font)
    : GameState(game)
    , startGameText(font, "Start Game", 40)
    , exitText(font, "Exit", 40)
    , selectedOption(MenuOption::StartGame)
{
    startGameText.setPosition({ 300.f, 250.f });
    exitText.setPosition({ 300.f, 320.f });

    refreshHighlight();
}

void MenuState::handleInput(const sf::Event& event)
{
    if (const auto* keyPressed = event.getIf<sf::Event::KeyPressed>())    //in sfml it checks if event is according to its type and provide pointer
    {
        if (keyPressed->code == sf::Keyboard::Key::Up)
        {
            selectPrevious();
        }
        else if (keyPressed->code == sf::Keyboard::Key::Down)
        {
            selectNext();
        }
        else if (keyPressed->code == sf::Keyboard::Key::Enter)    ///scoped enum
        {
            confirmSelection();
        }
    }
}

void MenuState::update(float deltaTime)
{
    // The menu itself has nothing to animate yet.
    (void)deltaTime;
}

void MenuState::render(sf::RenderWindow& window)
{
    window.draw(startGameText);
    window.draw(exitText);
}

void MenuState::selectPrevious()
{
    selectedOption = MenuOption::StartGame;
    refreshHighlight();
}

void MenuState::selectNext()
{
    selectedOption = MenuOption::Exit;
    refreshHighlight();
}

void MenuState::refreshHighlight()
{
    startGameText.setFillColor(
        selectedOption == MenuOption::StartGame ? sf::Color::Yellow : sf::Color::White);

    exitText.setFillColor(
        selectedOption == MenuOption::Exit ? sf::Color::Yellow : sf::Color::White);
}

void MenuState::confirmSelection()
{
    if (selectedOption == MenuOption::Exit)
    {
        game.quit();
    }
    else if (selectedOption == MenuOption::StartGame)
    {
        game.changeState(std::make_unique<PlayingState>(game, game.getWindowSize()));
    }
}