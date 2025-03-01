#pragma once

#include <array>
#include <cstdlib>
#include <ctime>
#include <map>
#include <memory>
#include "RandomGenerator.hpp"

namespace sea_battle {
struct Boat {
    int length;
    int count;
};
enum class Status {
    Empty = 0,
    Checked = 1,
    Exists = 2,
    Killed = 3,
};
class SeaMap {
   public:
    inline static const int MAX_FIELDS = 100;
    inline static const int ROW_LENGTH = 10;
    SeaMap() = default;
    SeaMap(const SeaMap& other) = default;
    SeaMap(SeaMap&& other) noexcept = default;
    SeaMap(std::unique_ptr<sea_battle_library::IRandomGenerator>&&
               randomGenerator);
    SeaMap(const std::array<Status, MAX_FIELDS>& data) : m_data{data} {};
    ~SeaMap() = default;
    SeaMap& operator=(const SeaMap& other);
    SeaMap& operator=(SeaMap&& other) noexcept;
    void createMap();
    bool addBoat(int position, int boatLength);
    bool checkEmptyField(int position);
    Status checkFieldStatus(int position);
    Status operator[](size_t i) const;

   private:
    void generate();
    std::array<Status, MAX_FIELDS> m_data;
    std::array<Boat, 4> m_boats{Boat{1, 4}, Boat{2, 3}, Boat{3, 2}, Boat{4, 1}};
    std::unique_ptr<sea_battle_library::IRandomGenerator> random_generator;
};
}  // namespace sea_battle
