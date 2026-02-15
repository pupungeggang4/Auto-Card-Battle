#pragma once
#include <includes.hpp>

class Game;
class Tile;
class TileMap;
class Player;
class Portal;

class Field {
    public:
        shared_ptr<TileMap> tilemap;
        std::vector<shared_ptr<Portal>> connection;
        shared_ptr<Player> player;
        std::string place = "home_town";

        Field();
        void handleTick(shared_ptr<Game>);
        void render(shared_ptr<Game>);
        void loadField(std::string);
};
