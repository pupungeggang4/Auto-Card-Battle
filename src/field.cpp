#include <field.hpp>
#include <game.hpp>
#include <tilemap.hpp>
#include <player.hpp>

Field::Field() {
    tilemap = make_shared<TileMap>();
    player = make_shared<Player>();
}

void Field::handleTick(shared_ptr<Game> game) {
    player->handleTick(game);
}

void Field::render(shared_ptr<Game> game) {
    tilemap->render(game);
    player->render(game);
}
