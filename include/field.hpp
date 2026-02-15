#pragma once
#include <includes.hpp>

class Game;
class Tile;
class TileMap;
class Player;

class Field {
    public:
        shared_ptr<TileMap> tilemap;
        shared_ptr<Player> player;
        std::string place = "home_town";

        Field();
        void handleTick(shared_ptr<Game>);
        void render(shared_ptr<Game>);
        void loadField(std::string);
};
