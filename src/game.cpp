#include <game.hpp>
#include <asset.hpp>

Game::Game() {
    window = sf::RenderWindow(sf::VideoMode({1280, 720}), "Auto Card Battle");
}

void Game::run() {
    self = shared_from_this();
    Font::neodgm->setSmooth(false);
    rText.setFont(*Font::neodgm);
    loop();
}

void Game::loop() {
    while (window.isOpen()) {
        handleInput();
        window.clear(sf::Color::White);
        window.display();
    }
}

void Game::handleInput() {
    while (const std::optional event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>())
            window.close();
    }
}
