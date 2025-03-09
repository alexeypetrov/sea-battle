#include "SeaMap.hpp"
#include <cstddef>
#include <vector>

namespace sea_battle {
SeaMap::SeaMap(
    std::unique_ptr<sea_battle_library::IRandomGenerator>&& randomGenerator) {
    random_generator_ = std::move(randomGenerator);
    CreateMap();
}
auto SeaMap::operator=(const SeaMap& other) -> SeaMap& {
    m_data_ = other.m_data_;
    return *this;
};
auto SeaMap::operator=(SeaMap&& other) noexcept -> SeaMap& {
    if (this != &other) {
        m_data_ = other.m_data_;
    }
    return *this;
};
void SeaMap::CreateMap() {
    for (int i = 0; i < kMaxFields; ++i) {
        m_data_[i] = Status::kEmpty;
    }
    Generate();
}

auto SeaMap::CheckFieldStatus(int position) -> Status {
    if (m_data_[position] == Status::kExists) {
        m_data_[position] = Status::kKilled;
    }
    if (m_data_[position] == Status::kEmpty) {
        m_data_[position] = Status::kChecked;
    }
    return m_data_[position];
}

auto SeaMap::operator[](size_t index) const -> Status {
    return m_data_[index];
}

void SeaMap::Generate() {
    for (const Boat& boat : m_boats_) {
        for (int i = 0; i < boat.count; ++i) {
            bool isNotSet = true;
            do {
                int position = random_generator_->GetNumber();
                if (SeaMap::AddBoat(position, boat.length)) {
                    isNotSet = false;
                }
            } while (isNotSet);
        }
    }
}

auto SeaMap::AddBoat(int position, int boatLength) -> bool {
    const int step_x = (position % kRowLength > kRowLength / 2) ? -1 : 1;
    const int step_y =
        (position % kMaxFields > kMaxFields / 2) ? -kRowLength : kRowLength;
    const int step = random_generator_->GetBoolean() ? step_x : step_y;
    std::vector<int> check_positions;
    do {
        if (!SeaMap::CheckEmptyField(position)) {
            return false;
        }
        check_positions.push_back(position);
        position += step;
        --boatLength;
    } while (boatLength > 0);
    for (auto cp : check_positions) {
        m_data_[cp] = Status::kExists;
    }

    return true;
}

auto SeaMap::CheckEmptyField(int position) -> bool {
    int left_position = position - 1;
    if (position % kRowLength == 0) {
        left_position = position;
    }
    int right_position = position + 1;
    if (position % kRowLength == kRowLength - 1) {
        right_position = position;
    }
    int top_position = -kRowLength;
    if (position < kRowLength) {
        top_position = 0;
    }
    int bottom_position = kRowLength;
    if (position > kMaxFields - kRowLength) {
        bottom_position = 0;
    }
    for (int i = left_position; i <= right_position; ++i) {
        for (int j = i + top_position; j <= i + bottom_position;
             j = j + kRowLength) {
            if (m_data_[j] != Status::kEmpty) {
                return false;
            }
        }
    }
    return true;
}
}  // namespace sea_battle
