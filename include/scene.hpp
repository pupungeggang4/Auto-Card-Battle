#pragma once
#include "includes.hpp"

class Game;

class Scene {
    public:
        Scene();
        virtual void update(shared_ptr<Game>);
        virtual void render(shared_ptr<Game>);
        virtual void mouseUp(shared_ptr<Game>, sf::Vector2f, int);
        virtual void keyDown(shared_ptr<Game>, int);
};

class SceneTitle : public Scene {
    public:
        sf::Font currentFont;
        sf::Text textTitle = sf::Text(currentFont, "Auto Card Battle", 32);
        sf::Text textStart = sf::Text(currentFont, "Start Game", 32);
        sf::Text textExit = sf::Text(currentFont, "Exit", 32);
        sf::RectangleShape buttonStart, buttonExit;
        SceneTitle();
        void update(shared_ptr<Game>) override;
        void render(shared_ptr<Game>) override;
        void mouseUp(shared_ptr<Game>, sf::Vector2f, int) override;
        void keyDown(shared_ptr<Game>, int) override;
};

class SceneField : public Scene {
    public:
        SceneField();
        void update(shared_ptr<Game>) override;
        void render(shared_ptr<Game>) override;
        void mouseUp(shared_ptr<Game>, sf::Vector2f, int) override;
        void keyDown(shared_ptr<Game>, int) override;
};

class SceneBattle : public Scene {
    public:
        SceneBattle();
        void update(shared_ptr<Game>) override;
        void render(shared_ptr<Game>) override;
        void mouseUp(shared_ptr<Game>, sf::Vector2f, int) override;
        void keyDown(shared_ptr<Game>, int) override;
};
