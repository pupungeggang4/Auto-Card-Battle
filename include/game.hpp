#pragma once
#include <includes.hpp>

class Scene;

class Game : public std::enable_shared_from_this<Game> {
    public:
        shared_ptr<Game> self;
        sf::RenderWindow window; sf::View UIView;
        sf::Font currentFont;
        sf::Text rText = sf::Text(currentFont, "Hello", 32);
        unsigned int width, height;
        sf::Clock clock; float frameCurrent, framePrevious, delta;

        shared_ptr<Scene> scene;
        std::unordered_map<std::string, bool> keyPressed = {
            {"left", false}, {"right", false}, {"up", false}, {"down", false}
        };
        std::string state = "";
        bool menu = false;

        Game();
        void run();
        void loop();
        void handleInput();
};
