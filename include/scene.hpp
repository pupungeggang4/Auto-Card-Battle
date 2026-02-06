#pragma once
#include <includes.hpp>

class Game;

class Scene {
    public:
        virtual void loop(shared_ptr<Game>);
        virtual void render(shared_ptr<Game>);
        virtual void mouseUp(shared_ptr<Game>, sf::Vector2f, int);
        virtual void keyDown(shared_ptr<Game>, int);
};

class SceneTitle : public Scene {
    public:
        void loop(shared_ptr<Game>) override;
        void render(shared_ptr<Game>) override;
        void mouseUp(shared_ptr<Game>, sf::Vector2f, int) override;
        void keyDown(shared_ptr<Game>, int) override;
};

class SceneField : public Scene {

};

class SceneBattle : public Scene {

};
