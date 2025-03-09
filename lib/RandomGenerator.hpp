#pragma once

#include <cmath>
#include <cstdlib>
#include <ctime>

namespace sea_battle_library {
class IRandomGenerator {
   public:
    IRandomGenerator() = default;
    IRandomGenerator(const IRandomGenerator& other) = default;
    auto operator=(const IRandomGenerator& other) -> IRandomGenerator& =
                                                         default;
    IRandomGenerator(IRandomGenerator&& other) = default;
    auto operator=(IRandomGenerator&& other) -> IRandomGenerator& = default;
    virtual ~IRandomGenerator() = default;
    virtual auto GetNumber() -> int = 0;
    virtual auto GetBoolean() -> bool = 0;
};

class RandomGenerator : public IRandomGenerator {
   public:
    explicit RandomGenerator(int maxNumber) : m_max_random_number_{maxNumber} {}
    static void Init();
    auto GetNumber() -> int override;
    auto GetBoolean() -> bool override;

   private:
    int m_max_random_number_{0};
};
}  // namespace sea_battle_library
