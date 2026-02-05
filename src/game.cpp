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
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        window.clear(sf::Color::White);
        rText.setFillColor(sf::Color::Black);
        rText.setPosition({20.f, 20.f});
        window.draw(rText);
        window.display();
    }
}