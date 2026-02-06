#include <game.hpp>
#include <asset.hpp>

Game::Game() {
    sf::err().rdbuf(NULL);
    sf::VideoMode videoMode = sf::VideoMode::getDesktopMode();
    if (videoMode.size.x > 2560) {
        width = 2560; height = 1440;
    } else if (videoMode.size.x > 2000) {
        width = 1920; height = 1080;
    } else {
        width = 1280; height = 720;
    }
    window = sf::RenderWindow(sf::VideoMode({width, height}), "Auto Card Battle");
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
