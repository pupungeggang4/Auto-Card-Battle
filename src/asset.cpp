#include <asset.hpp>

shared_ptr<sf::Font> Font::neodgm = make_shared<sf::Font>("asset/font/neodgm.ttf");
shared_ptr<texmap> Img::texture = make_shared<texmap>();

void Img::loadImage() {
    texture->emplace("sprite_tile", sf::Texture("asset/sprite/sprite_tile.png"));
    texture->emplace("sprite_player", sf::Texture("asset/sprite/sprite_player.png"));
}
