#include <includes.hpp>
#include <game.hpp>
#include <asset.hpp>

int main()
{
    shared_ptr<Game> game = make_shared<Game>();
    game->run();
    Font::neodgm.reset();
    Img::texture.reset();
    return 0;
}