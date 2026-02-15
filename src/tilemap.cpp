#include <tilemap.hpp>
#include <asset.hpp>
#include <game.hpp>

TileMap::TileMap() {
    sprite.setTexture(Img::texture->at("sprite_tile"));
}

void TileMap::render(shared_ptr<Game> game) {
    for (int i = 0; i < data.size(); i++) {
        for (int j = 0; j < data[i].size(); j++) {
            sprite.setPosition({40.f * j, 40.f * i});
            sprite.setTextureRect(texCoord[data[i][j]]);
            game->window.draw(sprite);
        }
    }
}
