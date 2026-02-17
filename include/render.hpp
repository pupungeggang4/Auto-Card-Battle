#pragma once
#include "includes.hpp"

class Render {
    public:
        static void setText(sf::Text&, sf::Font&, unsigned int, sf::Color, sf::String, std::vector<float>);
        static void setRect(sf::RectangleShape&, sf::Color color, std::vector<float>);
};