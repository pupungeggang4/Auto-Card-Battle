#include <portal.hpp>
#include <asset.hpp>
#include <game.hpp>

Portal::Portal() {
    sprite.setTexture(Img::texture->at("sprite_entity"));
    sprite.setTextureRect({{0, 0}, {40, 40}});
}

void Portal::render(shared_ptr<Game> game) {
    sprite.setPosition(rect.position - rect.size / 2.f);
    game->window.draw(sprite);
}
