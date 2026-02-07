#include <game.hpp>
#include <asset.hpp>
#include <scene.hpp>

Game::Game() {
    sf::err().rdbuf(NULL);
    sf::VideoMode videoMode = sf::VideoMode::getDesktopMode();
    if (videoMode.size.x > 2560) {
        width = 1600; height = 1200;
    } else if (videoMode.size.x > 2000) {
        width = 1200; height = 900;
    } else {
        width = 800; height = 600;
    }
    window = sf::RenderWindow(sf::VideoMode({width, height}), "Auto Card Battle");
    UIView = sf::View({400, 300}, {800, 600});
    window.setView(UIView);
}

void Game::run() {
    self = shared_from_this();
    Font::neodgm->setSmooth(false);
    rText.setFont(*Font::neodgm);
    scene = make_shared<SceneTitle>();
    loop();
}

void Game::loop() {
    while (window.isOpen()) {
        handleInput();
        scene->loop(self);
    }
}

void Game::handleInput() {
    while (const std::optional event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>())
            window.close();
        if (const auto *mouse = event->getIf<sf::Event::MouseButtonReleased>()) {
            sf::Vector2f pos = (sf::Vector2f)mouse->position;
            pos.x *= 800.f / (float)width;
            pos.y *= 600.f / (float)height;
            int button = int(mouse->button);
            scene->mouseUp(self, pos, button);
        }
    }
}
