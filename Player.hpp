#pragma once

#include <SFML/Graphics.hpp>
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
    inline static const std::string SCORE_TEXT_PREFIX{"Score: "};
    inline static const std::string DEFAULT_SCORE{"0"};
    inline static const std::string WIN_TEXT_POSTFIX{" WIN!"};
    static const size_t MAX_SCORE = 20;
    Player() = default;
    void restart() {
        m_sea_map = m_sea_map_next;
        std::thread prepareSeaMap([&]() {
            try {
                SeaMap seaMap(std::make_unique<T>(SeaMap::MAX_FIELDS));
                seaMap.createMap();
                std::lock_guard l(mutex);
                m_sea_map_next = std::move(seaMap);
            } catch (...) {
                std::cerr << "Error generate sea map" << std::endl;
            }
        });
        prepareSeaMap.detach();
        m_score_text.setString(SCORE_TEXT_PREFIX + DEFAULT_SCORE);
        m_score = 0;
    }
    void increaseScore() {
        ++m_score;
        std::string scoreFullText = SCORE_TEXT_PREFIX + std::to_string(m_score);
        if (m_score == MAX_SCORE) {
            scoreFullText += WIN_TEXT_POSTFIX;
        }
        m_score_text.setString(scoreFullText);
    }
    Status getSeaMapFieldStatus(size_t i) { return m_sea_map[i]; }
    Status fire(size_t i) { return m_sea_map.checkFieldStatus(i); }
    sf::Text getScore() const { return m_score_text; }
    void initScorePlayer(sf::Font& font, int x, int y) {
        m_score_text.setFont(font);
        m_score_text.setString(SCORE_TEXT_PREFIX + DEFAULT_SCORE);
        m_score_text.setPosition(x, y);
        m_score_text.setCharacterSize(25);
        m_score_text.setFillColor(sf::Color::Green);
    }

   private:
    SeaMap m_sea_map{std::make_unique<T>(SeaMap::MAX_FIELDS)};
    SeaMap m_sea_map_next{std::make_unique<T>(SeaMap::MAX_FIELDS)};
    int m_score = 0;
    sf::Text m_score_text;
    std::mutex mutex;
};
}  // namespace sea_battle
