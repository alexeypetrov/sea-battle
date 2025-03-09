#include "RandomGenerator.hpp"

namespace sea_battle_library {
void RandomGenerator::Init() {
    std::srand(std::time(nullptr));
}

auto RandomGenerator::GetNumber() -> int {
    return std::rand() % m_max_random_number_;
}

auto RandomGenerator::GetBoolean() -> bool {
    return std::rand() % 2 == 0;
}
}  // namespace sea_battle_library
