#include <field.hpp>
#include <game.hpp>
#include <tilemap.hpp>

Field::Field() {
    tilemap = make_shared<TileMap>();

}

void Field::render(shared_ptr<Game> game) {
    tilemap->render(game);
}
