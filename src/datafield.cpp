#include "datafield.hpp"

std::unordered_map<std::string, DataFieldElement> DataField::data = {};

DataFieldElement::DataFieldElement(std::vector<std::vector<int>> tile, std::vector<sf::Vector2f> connection) {
    this->tile = tile;
    this->connection = connection;
}

void DataField::loadData() {
    std::vector<std::vector<std::string>> loadPair = {
        {"home_town", "data/home_town.txt"}
    };
    for (int i = 0; i < loadPair.size(); i++) {
        std::string path = loadPair[i][1];
        std::ifstream file(path);
        std::istringstream iss;
        std::vector<std::vector<int>> tile = {};
        std::vector<sf::Vector2f> connection = {};
        std::string line = "";

        int row, col;
        getline(file, line);
        iss.seekg(0);
        iss.clear();
        iss.str(line);
        iss >> row >> col;

        for (int j = 0; j < row; j++) {
            std::vector<int> tmpTile = {};
            std::getline(file, line);
            iss.seekg(0);
            iss.clear();
            iss.str(line);
            for (int k = 0; k < col; k++) {
                int tile;
                iss >> tile;
                tmpTile.push_back(tile);
            }
            tile.push_back(tmpTile);
        }

        std::getline(file, line);
        iss.seekg(0);
        iss.clear();
        iss.str(line);

        float num = 0;
        std::vector<float> tmpConnection = {};
        while (iss >> num) {
            tmpConnection.push_back(num);
        }
        for (int j = 0; j < tmpConnection.size() - 1; j += 2) {
            sf::Vector2f tmpPos = sf::Vector2f({tmpConnection[j], tmpConnection[j + 1]});
            connection.push_back(tmpPos);
        }
        DataFieldElement tmpData = DataFieldElement(tile, connection);
        DataField::data.emplace(loadPair[i][0], tmpData);
        file.close();
    }
}
