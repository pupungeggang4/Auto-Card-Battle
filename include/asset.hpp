#pragma once
#include "includes.hpp"

typedef std::unordered_map<std::string, sf::Texture> texmap;

class Font {
    public:
        static shared_ptr<sf::Font> neodgm;
};

class Img {
    public:
        static shared_ptr<texmap> texture;
        static void loadImage();
};
