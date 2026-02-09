#pragma once
#include <includes.hpp>

class Game;
class Tile;
class TileMap;

class Field {
    public:
        shared_ptr<TileMap> tilemap;

        Field();
        void render(shared_ptr<Game>);
};
