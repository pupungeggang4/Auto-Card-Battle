#include <field.hpp>
#include <datafield.hpp>
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

void Field::loadField(std::string place) {
    tilemap->data = {};
    DataFieldElement& e = DataField::data.at(place);
    for (int i = 0; i < e.tile.size(); i++) {
        std::vector<int> tmpData = {};
        for (int j = 0; j < e.tile[i].size(); j++) {
            tmpData.push_back(e.tile[i][j]);
        }
        tilemap->data.push_back(tmpData);
    }
}
