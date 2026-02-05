#pragma once
#include <includes.hpp>

typedef shared_ptr<std::unordered_map<std::string, sf::Texture>> texptr;

class Font {
    public:
        static shared_ptr<sf::Font> neodgm;
};

class Img {
    public:
        static shared_ptr<texptr> texture;
};