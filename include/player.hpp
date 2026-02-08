#pragma once
#include <includes.hpp>

class Card;
class Player {
    public:
        sf::FloatRect rect;
        sf::Texture texture;
        sf::Sprite sprite = sf::Sprite(texture);
        std::vector<shared_ptr<Card>> deck;
        Player();
};
