#pragma once

#include <cmath>
#include <cstdlib>
#include <ctime>

namespace sea_battle_library {
class IRandomGenerator {
   public:
    IRandomGenerator() = default;
    IRandomGenerator(const IRandomGenerator& other) = default;
    IRandomGenerator& operator=(const IRandomGenerator& other) = default;
    IRandomGenerator(IRandomGenerator&& other) = default;
    IRandomGenerator& operator=(IRandomGenerator&& other) = default;
    virtual ~IRandomGenerator() {}
    virtual int getNumber() = 0;
    virtual bool getBoolean() = 0;
};

class RandomGenerator : public IRandomGenerator {
   public:
    RandomGenerator(int maxNumber) : m_max_random_number{maxNumber} {}
    static void init();
    int getNumber() override;
    bool getBoolean() override;

   private:
    int m_max_random_number{0};
};
}  // namespace sea_battle_library
