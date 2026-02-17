#include "game.hpp"
#include "datafield.hpp"
#include "asset.hpp"
#include "scene.hpp"
#include "field.hpp"

Game::Game() {
    sf::err().rdbuf(NULL);
    sf::VideoMode videoMode = sf::VideoMode::getDesktopMode();
    if (videoMode.size.x >= 2560) {
        width = 1600; height = 1200;
    } else if (videoMode.size.x >= 1920) {
        width = 1200; height = 900;
    } else {
        width = 800; height = 600;
    }
    window = sf::RenderWindow(sf::VideoMode({width, height}), "Auto Card Battle");
    UIView = sf::View({400, 300}, {800, 600});
    window.setVerticalSyncEnabled(true);
    //window.setFramerateLimit(60);
    clock = sf::Clock();
}

void Game::run() {
    self = shared_from_this();
    framePrevious = 0;
    frameCurrent = 0;
    delta = 0;

    Font::neodgm->setSmooth(false);
    rText.setFont(*Font::neodgm);
    Img::loadImage();
    DataField::loadData();

    scene = make_shared<SceneTitle>();
    field = make_shared<Field>();
    field->loadField("home_town");
    loop();
}

void Game::loop() {
    while (window.isOpen()) {
        frameCurrent = (float)clock.getElapsedTime().asSeconds();
        delta = frameCurrent - framePrevious;
        framePrevious = frameCurrent;
        //std::cout << delta << std::endl;

        handleInput();
        scene->update(self);
        window.clear(sf::Color::White);
        scene->render(self);
        window.display();
    }
}

void Game::handleInput() {
    while (const std::optional event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window.close();
        }
        if (const auto* resized = event->getIf<sf::Event::Resized>()) {
            if (height != resized->size.y) {
                width = resized->size.y * 4 / 3;
                height = resized->size.y;
                window.setSize({width, height});

            } else {
                width = resized->size.x;
                height = resized->size.x * 3 / 4;
                window.setSize({width, height});
            }
        }
        if (const auto *mouse = event->getIf<sf::Event::MouseButtonReleased>()) {
            sf::Vector2f pos = (sf::Vector2f)mouse->position;
            pos.x *= 800.f / (float)width;
            pos.y *= 600.f / (float)height;
            int button = int(mouse->button);
            scene->mouseUp(self, pos, button);
        }
        if (const auto *keyDown = event->getIf<sf::Event::KeyPressed>()) {
            if (keyDown->scancode == sf::Keyboard::Scancode::Up) {
                keyPressed["up"] = true;
            }
            if (keyDown->scancode == sf::Keyboard::Scancode::Down) {
                keyPressed["down"] = true;
            }
            if (keyDown->scancode == sf::Keyboard::Scancode::Left) {
                keyPressed["left"] = true;
            }
            if (keyDown->scancode == sf::Keyboard::Scancode::Right) {
                keyPressed["right"] = true;
            }
        }
        if (const auto *keyUp = event->getIf<sf::Event::KeyReleased>()) {
            if (keyUp->scancode == sf::Keyboard::Scancode::Up) {
                keyPressed["up"] = false;
            }
            if (keyUp->scancode == sf::Keyboard::Scancode::Down) {
                keyPressed["down"] = false;
            }
            if (keyUp->scancode == sf::Keyboard::Scancode::Left) {
                keyPressed["left"] = false;
            }
            if (keyUp->scancode == sf::Keyboard::Scancode::Right) {
                keyPressed["right"] = false;
            }
        }
    }
}
