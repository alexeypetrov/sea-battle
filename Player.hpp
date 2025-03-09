#pragma once

#include <SFML/Graphics.hpp>
#include <cstddef>
#include <iostream>
#include <memory>
#include <mutex>
#include <string>
#include <thread>
#include "SeaMap.hpp"

namespace sea_battle {
template <typename T>
class Player {
   public:
    inline static const std::string kScoreTextPrefix{"Score: "};
    inline static const std::string kDefaultScore{"0"};
    inline static const std::string kWinTextPostfix{" WIN!"};
    static const std::size_t kMaxScore = 20;
    Player() = default;
    void Restart() {
        m_sea_map_ = m_sea_map_next_;
        std::thread prepare_sea_map([&]() {
            try {
                SeaMap sea_map(std::make_unique<T>(SeaMap::kMaxFields));
                sea_map.CreateMap();
                std::lock_guard lock(mutex_);
                m_sea_map_next_ = std::move(sea_map);
            } catch (...) {
                std::cerr << "Error generate sea map" << std::endl;
            }
        });
        prepare_sea_map.detach();
        m_score_text_.setString(kScoreTextPrefix + kDefaultScore);
        m_score_ = 0;
    }
    void IncreaseScore() {
        ++m_score_;
        std::string score_full_text =
            kScoreTextPrefix + std::to_string(m_score_);
        if (m_score_ == kMaxScore) {
            score_full_text += kWinTextPostfix;
        }
        m_score_text_.setString(score_full_text);
    }
    auto GetSeaMapFieldStatus(std::size_t index) -> Status {
        return m_sea_map_[index];
    }
    auto Fire(std::size_t index) -> Status {
        return m_sea_map_.CheckFieldStatus(index);
    }
    [[nodiscard]] auto GetScore() const -> sf::Text { return m_score_text_; }
    void InitScorePlayer(sf::Font& font, int xPosition, int yPosition) {
        m_score_text_.setFont(font);
        m_score_text_.setString(kScoreTextPrefix + kDefaultScore);
        m_score_text_.setPosition(xPosition, yPosition);
        m_score_text_.setCharacterSize(25);
        m_score_text_.setFillColor(sf::Color::Green);
    }

   private:
    SeaMap m_sea_map_{std::make_unique<T>(SeaMap::kMaxFields)};
    SeaMap m_sea_map_next_{std::make_unique<T>(SeaMap::kMaxFields)};
    int m_score_ = 0;
    sf::Text m_score_text_;
    std::mutex mutex_;
};
}  // namespace sea_battle
