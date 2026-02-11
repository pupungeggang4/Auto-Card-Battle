#include <scene.hpp>

#include <field.hpp>
#include <game.hpp>

SceneField::SceneField() {

}

void SceneField::update(shared_ptr<Game> game) {
    game->field->handleTick(game);
}

void SceneField::render(shared_ptr<Game> game) {
    game->window.setView(game->UIView);
    game->field->render(game);
}

void SceneField::mouseUp(shared_ptr<Game> game, sf::Vector2f pos, int button) {

}

void SceneField::keyDown(shared_ptr<Game> game, int key) {

}
