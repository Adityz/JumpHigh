#include "Platform/Platform.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "VectorFunctions/VectorFunctions.h"
#include <filesystem>

std::vector<sf::Texture> Platform::PLATFORM_DATABASE;

void Platform::loadTextures(const std::string& path)
{
    for(auto entry : std::filesystem::directory_iterator(path))
    {
        PLATFORM_DATABASE.push_back(sf::Texture{});
        PLATFORM_DATABASE.back().loadFromFile(path + entry.path().filename().string());
    }
}

Platform::Platform(const sf::Vector2f& pos, const sf::Vector2f& boxSize, int index)
    : GameObject(pos, boxSize), _index{index}
{
    _sprite.setTexture(PLATFORM_DATABASE[index]);
    if(_index % 2 == 1)
    {
        _sprite.setOrigin(_sprite.getTexture()->getSize().x/3.5f, _sprite.getTexture()->getSize().y/2.2f);
    }
    else
    {
        _sprite.setOrigin(_sprite.getTexture()->getSize().x/9.0f, _sprite.getTexture()->getSize().y/2.2f);
    }
    _sprite.setScale(3,3);

    update();    
}

void Platform::updateBox()
{
    _box.setPosition(_position);
    
    float divide = 0.0f;

    _index % 2 ? divide = 2.3f : divide = 1.3f;
    
    sf::Vector2f size{_sprite.getTexture()->getSize().x * _sprite.getScale().x/divide, _sprite.getTexture()->getSize().y * _sprite.getScale().y/10.0f};

    _box.setSize(size);
}
