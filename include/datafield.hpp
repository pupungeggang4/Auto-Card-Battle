#pragma once
#include <includes.hpp>

class DataFieldElement {
    public:
        std::vector<std::vector<int>> tile;
        std::vector<sf::Vector2f> connection;
        DataFieldElement(std::vector<std::vector<int>>, std::vector<sf::Vector2f>);
};

class DataField {
    public:
        static std::unordered_map<std::string, DataFieldElement> data;
        static void loadData();
};
