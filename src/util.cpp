#include <util.hpp>
#include <game.hpp>
#include <scene.hpp>

void Util::changeScene(shared_ptr<Game> game, std::string scene) {
    if (scene == "title") {
        game->scene = make_shared<SceneTitle>();
    } else if (scene == "field") {
        game->scene = make_shared<SceneField>();
    } else if (scene == "battle") {
        game->scene = make_shared<SceneBattle>();
    }
}
