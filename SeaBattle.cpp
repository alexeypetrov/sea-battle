#include "Application.hpp"
#include "Game.hpp"
#include "RandomGenerator.hpp"

int main() {
    sea_battle_library::RandomGenerator::init();
    sea_battle::Game game{};
    sea_battle::Application app{"Sea battle"};
    app.run(game);

    return 0;
}
