#pragma once
#include <includes.hpp>

class Game : public std::enable_shared_from_this<Game> {
    public:
        shared_ptr<Game> self;
        sf::RenderWindow window;
        sf::Font currentFont;
        sf::Text rText = sf::Text(currentFont, "Hello", 32);
        
        Game();
        void run();
        void loop();
};