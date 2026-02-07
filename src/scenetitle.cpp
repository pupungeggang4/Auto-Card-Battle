#include <scene.hpp>
#include <asset.hpp>
#include <render.hpp>
#include <ui.hpp>
#include <game.hpp>

SceneTitle::SceneTitle() {
    Render::setText(textTitle, *Font::neodgm, 32, sf::Color::Black, "Auto Card Battle", UI::UITitle["text_title"]);
    Render::setText(textStart, *Font::neodgm, 32, sf::Color::Black, "Start Game", UI::UITitle["text_start"]);
    Render::setText(textExit, *Font::neodgm, 32, sf::Color::Black, "Exit", UI::UITitle["text_exit"]);
    Render::setRect(buttonStart, sf::Color::Yellow, UI::UITitle["button_start"]);
    Render::setRect(buttonExit, sf::Color::Cyan, UI::UITitle["button_exit"]);
}

void SceneTitle::loop(shared_ptr<Game> game) {
    render(game);
}

void SceneTitle::render(shared_ptr<Game> game) {
    game->window.clear(sf::Color::White);
    game->window.draw(textTitle);
    game->window.draw(buttonStart);
    game->window.draw(textStart);
    game->window.draw(buttonExit);
    game->window.draw(textExit);
    game->window.display();
}

void SceneTitle::mouseUp(shared_ptr<Game> game, sf::Vector2f pos, int button) {

}

void SceneTitle::keyDown(shared_ptr<Game> game, int key) {

}