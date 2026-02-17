#include "player.hpp"
#include "asset.hpp"
#include "game.hpp"

Player::Player() {
    sprite.setTexture(Img::texture->at("sprite_player"));
}

void Player::handleTick(shared_ptr<Game> game) {
    move(game);
}

void Player::move(shared_ptr<Game> game) {
    bool moving = false;
    if (game->keyPressed["up"] == true) {
        moving = true;
        rect.position.y += -speed * game->delta;
        animState = "moving_up";
    }
    if (game->keyPressed["down"] == true) {
        moving = true;
        rect.position.y += speed * game->delta;
        animState = "moving_down";
    }
    if (game->keyPressed["left"] == true) {
        moving = true;
        rect.position.x += -speed * game->delta;
        animState = "moving_left";
    }
    if (game->keyPressed["right"] == true) {
        moving = true;
        rect.position.x += speed * game->delta;
        animState = "moving_right";
    }
    if (moving == false) {
        if (animState == "moving_up") {
            animState = "idle_up";
        }
        if (animState == "moving_down") {
            animState = "idle_down";
        }
        if (animState == "moving_left") {
            animState = "idle_left";
        }
        if (animState == "moving_right") {
            animState = "idle_right";
        }
    }
}

void Player::render(shared_ptr<Game> game) {
    frameTime += game->delta;
    frameCurrent = int(frameTime / frameInterval) % texCoord[animState].size();
    sprite.setPosition(rect.position - rect.size / 2.f);
    sprite.setTextureRect(texCoord[animState][frameCurrent]);
    game->window.draw(sprite);
}
