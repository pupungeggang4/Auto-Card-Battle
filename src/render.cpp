#include "render.hpp"

void Render::setText(sf::Text& text, sf::Font& font, unsigned int size, sf::Color color, sf::String str, std::vector<float> pos) {
    text.setFont(font);
    text.setCharacterSize(size);
    text.setPosition({pos[0], pos[1]});
    text.setFillColor(color);
    text.setString(str);
}

void Render::setRect(sf::RectangleShape& rs, sf::Color color, std::vector<float> rect) {
    rs.setPosition({rect[0], rect[1]});
    rs.setFillColor(color);
    rs.setSize({rect[2], rect[3]});
}