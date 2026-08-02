#pragma once

#include <SFML/Graphics.hpp>

// for font loading so that we dont need to load it again n again

class AssetManager
{
public:
    AssetManager();

    const sf::Font& getFont() const;

private:
    sf::Font font;
};
