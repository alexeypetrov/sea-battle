#include <iostream>
#include "Application.hpp"
#include "Game.hpp"
#include "RandomGenerator.hpp"

auto main() -> int {
    try {
        sea_battle_library::RandomGenerator::Init();
        sea_battle::Game game{};
        sea_battle::Application app{"Sea battle"};
        app.Run(game);
    } catch (...) {
        std::cerr << "Unknown error" << std::endl;
        return -1;
    }

    return 0;
}
