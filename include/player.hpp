#pragma once
#include "includes.hpp"

class Game;
class Card;
class Player {
    public:
        sf::Texture texture;
        sf::Sprite sprite = sf::Sprite(texture);
        std::unordered_map<std::string, std::vector<sf::IntRect>> texCoord = {
            { "idle_down", {{{0, 0}, {40, 40}}, {{40, 0}, {40, 40}}, {{80, 0}, {40, 40}}, {{120, 0}, {40, 40}}} },
            { "idle_up", {{{0, 40}, {40, 40}}, {{40, 40}, {40, 40}}, {{80, 40}, {40, 40}}, {{120, 40}, {40, 40}}} },
            { "idle_left", {{{0, 80}, {40, 40}}, {{40, 80}, {40, 40}}, {{80, 80}, {40, 40}}, {{120, 80}, {40, 40}}} },
            { "idle_right", {{{0, 120}, {40, 40}}, {{40, 120}, {40, 40}}, {{80, 120}, {40, 40}}, {{120, 120}, {40, 40}}} },
            { "moving_down", {{{160, 0}, {40, 40}}, {{200, 0}, {40, 40}}, {{240, 0}, {40, 40}}, {{280, 0}, {40, 40}}} },
            { "moving_up", {{{160, 40}, {40, 40}}, {{200, 40}, {40, 40}}, {{240, 40}, {40, 40}}, {{280, 40}, {40, 40}}} },
            { "moving_left", {{{160, 80}, {40, 40}}, {{200, 80}, {40, 40}}, {{240, 80}, {40, 40}}, {{280, 80}, {40, 40}}} },
            { "moving_right", {{{160, 120}, {40, 40}}, {{200, 120}, {40, 40}}, {{240, 120}, {40, 40}}, {{280, 120}, {40, 40}}} },
        };
        std::string animState = "idle_left";
        float frameTime = 0, frameInterval = 0.2;
        int frameCurrent = 0;

        sf::FloatRect rect = sf::FloatRect({400.f, 300.f}, {40.f, 40.f});
        float speed = 200.f;

        std::vector<shared_ptr<Card>> deck;

        Player();
        void handleTick(shared_ptr<Game>);
        void move(shared_ptr<Game>);
        void render(shared_ptr<Game>);
};
