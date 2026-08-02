#include "AssetManager.h"

#include <iostream>

AssetManager::AssetManager()
{
   
    if (!font.openFromFile("C:/Windows/Fonts/arial.ttf"))  //in sfml3 (loadfromfile) is font.openfromfile(path)
    {
        std::cerr << "Error: Failed to load font: C:/Windows/Fonts/arial.ttf" << std::endl;
        //error is printed on console instead of getting completetly crashed
    }
}

const sf::Font& AssetManager::getFont() const
{
    return font;
}