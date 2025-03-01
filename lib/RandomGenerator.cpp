#include "RandomGenerator.hpp"

namespace sea_battle_library {
void RandomGenerator::init() {
    std::srand(std::time(nullptr));
}

int RandomGenerator::getNumber() {
    return std::rand() % m_max_random_number;
}

bool RandomGenerator::getBoolean() {
    return std::rand() % 2 == 0;
}
}  // namespace sea_battle_library
