#pragma once
#include <includes.hpp>

class Game;
class Portal {
    public:
        sf::Texture texture;
        sf::Sprite sprite = sf::Sprite(texture);
        sf::FloatRect rect;

        Portal();
        void render(shared_ptr<Game>);
};
