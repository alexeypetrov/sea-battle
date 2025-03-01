#include "SeaMap.hpp"
#include <iostream>
#include <vector>

namespace sea_battle {
SeaMap::SeaMap(
    std::unique_ptr<sea_battle_library::IRandomGenerator>&& randomGenerator) {
    random_generator = std::move(randomGenerator);
    createMap();
}
SeaMap& SeaMap::operator=(const SeaMap& other) {
    m_data = other.m_data;
    return *this;
};
SeaMap& SeaMap::operator=(SeaMap&& other) noexcept {
    if (this != &other) {
        m_data = other.m_data;
    }
    return *this;
};
void SeaMap::createMap() {
    for (int i = 0; i < MAX_FIELDS; ++i) {
        m_data[i] = Status::Empty;
    }
    generate();
}

Status SeaMap::checkFieldStatus(int position) {
    if (m_data[position] == Status::Exists) {
        m_data[position] = Status::Killed;
    }
    if (m_data[position] == Status::Empty) {
        m_data[position] = Status::Checked;
    }
    return m_data[position];
}

Status SeaMap::operator[](size_t i) const {
    return m_data[i];
}

void SeaMap::generate() {
    for (const Boat& boat : m_boats) {
        for (int i = 0; i < boat.count; ++i) {
            bool isNotSet = true;
            do {
                int position = random_generator->getNumber();
                if (SeaMap::addBoat(position, boat.length)) {
                    isNotSet = false;
                }
            } while (isNotSet);
        }
    }
}

bool SeaMap::addBoat(int position, int boatLength) {
    int stepX = (position % ROW_LENGTH > ROW_LENGTH / 2) ? -1 : 1;
    int stepY =
        (position % MAX_FIELDS > MAX_FIELDS / 2) ? -ROW_LENGTH : ROW_LENGTH;
    int step = random_generator->getBoolean() ? stepX : stepY;
    std::vector<int> checkPositions;
    do {
        if (!SeaMap::checkEmptyField(position)) {
            return false;
        }
        checkPositions.push_back(position);
        position += step;
        --boatLength;
    } while (boatLength > 0);
    for (auto cp : checkPositions) {
        m_data[cp] = Status::Exists;
    }

    return true;
}

bool SeaMap::checkEmptyField(int position) {
    int leftPosition = position - 1;
    if (position % ROW_LENGTH == 0) {
        leftPosition = position;
    }
    int rightPosition = position + 1;
    if (position % ROW_LENGTH == ROW_LENGTH - 1) {
        rightPosition = position;
    }
    int topPosition = -ROW_LENGTH;
    if (position < ROW_LENGTH) {
        topPosition = 0;
    }
    int bottomPosition = ROW_LENGTH;
    if (position > MAX_FIELDS - ROW_LENGTH) {
        bottomPosition = 0;
    }
    for (int i = leftPosition; i <= rightPosition; ++i) {
        for (int j = i + topPosition; j <= i + bottomPosition;
             j = j + ROW_LENGTH) {
            if (m_data[j] != Status::Empty) {
                return false;
            }
        }
    }
    return true;
}
}  // namespace sea_battle
