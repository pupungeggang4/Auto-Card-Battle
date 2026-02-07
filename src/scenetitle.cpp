#include <scene.hpp>
#include <asset.hpp>
#include <game.hpp>

SceneTitle::SceneTitle() {
    textTitle.setFont(*Font::neodgm);
    textTitle.setFillColor(sf::Color::Black);
    textTitle.setPosition({20, 20});
    textStart.setFont(*Font::neodgm);
    textStart.setFillColor(sf::Color::Black);
    textStart.setPosition({160, 180});
    textExit.setFont(*Font::neodgm);
    textExit.setFillColor(sf::Color::Black);
    textExit.setPosition({160, 260});
}

void SceneTitle::loop(shared_ptr<Game> game) {
    render(game);
}

void SceneTitle::render(shared_ptr<Game> game) {
    game->window.clear(sf::Color::White);
    game->window.draw(textTitle);
    game->window.draw(textStart);
    game->window.draw(textExit);
    game->window.display();
}

void SceneTitle::mouseUp(shared_ptr<Game> game, sf::Vector2f pos, int button) {

}

void SceneTitle::keyDown(shared_ptr<Game> game, int key) {

}