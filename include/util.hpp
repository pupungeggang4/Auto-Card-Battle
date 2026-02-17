#pragma once
#include "includes.hpp"

class Game;
class Scene;

class Util {
    public:
        static void changeScene(shared_ptr<Game>, std::string);
};
