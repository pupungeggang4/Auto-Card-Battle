#include <game.hpp>
#include <asset.hpp>
#include <scene.hpp>
#include <field.hpp>

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
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 0;
    window = sf::RenderWindow(sf::VideoMode({width, height}), "Auto Card Battle", sf::State::Windowed, settings);
    UIView = sf::View({400, 300}, {800, 600});
    window.setVerticalSyncEnabled(true);
    clock = sf::Clock();
}

void Game::run() {
    self = shared_from_this();
    framePrevious = 0;
    frameCurrent = 0;
    delta = 0;

    Font::neodgm->setSmooth(false);
    rText.setFont(*Font::neodgm);
    Img::texture->emplace("sprite_tile", sf::Texture("asset/sprite/sprite_tile.png"));
    Img::texture->at("sprite_tile").setSmooth(false);

    scene = make_shared<SceneTitle>();
    field = make_shared<Field>();
    loop();
}

void Game::loop() {
    while (window.isOpen()) {
        frameCurrent = (float)clock.getElapsedTime().asSeconds();
        delta = frameCurrent - framePrevious;
        framePrevious = frameCurrent;

        handleInput();
        scene->update(self);
        window.clear(sf::Color::White);
        scene->render(self);
        window.display();
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
