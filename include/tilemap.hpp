#pragma once
#include <includes.hpp>

class Game;
class TileMap {
    public:
        std::vector<std::vector<int>> data;
        sf::Texture texture;
        sf::Sprite sprite = sf::Sprite(texture);
        std::unordered_map<int, sf::IntRect> texCoord = {
            {1, {{0, 0}, {40, 40}}},
            {2, {{40, 0}, {40, 40}}}
        };

        TileMap();
        void render(shared_ptr<Game>);
};
