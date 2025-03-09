#pragma once

#include <array>
#include <cstdint>
#include <ctime>
#include <memory>
#include "RandomGenerator.hpp"

namespace sea_battle {
struct Boat {
    int length;
    int count;
};
enum class Status : std::uint8_t {
    kEmpty = 0,
    kChecked = 1,
    kExists = 2,
    kKilled = 3,
};
class SeaMap {
   public:
    inline static const int kMaxFields = 100;
    inline static const int kRowLength = 10;
    SeaMap() = default;
    SeaMap(const SeaMap& other) = default;
    SeaMap(SeaMap&& other) noexcept = default;
    explicit SeaMap(std::unique_ptr<sea_battle_library::IRandomGenerator>&&
                        randomGenerator);
    explicit SeaMap(const std::array<Status, kMaxFields>& data)
        : m_data_{data} {};
    ~SeaMap() = default;
    auto operator=(const SeaMap& other) -> SeaMap&;
    auto operator=(SeaMap&& other) noexcept -> SeaMap&;
    void CreateMap();
    auto AddBoat(int position, int boatLength) -> bool;
    auto CheckEmptyField(int position) -> bool;
    auto CheckFieldStatus(int position) -> Status;
    auto operator[](size_t index) const -> Status;

   private:
    void Generate();
    std::array<Status, kMaxFields> m_data_;
    std::array<Boat, 4> m_boats_{Boat{1, 4}, Boat{2, 3}, Boat{3, 2},
                                 Boat{4, 1}};
    std::unique_ptr<sea_battle_library::IRandomGenerator> random_generator_;
};
}  // namespace sea_battle
