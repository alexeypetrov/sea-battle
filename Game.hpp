#pragma once

#include "Player.hpp"
#include "SeaMap.hpp"

#include <cmath>

namespace sea_battle {
class Game {
   public:
    Game();
    std::vector<sf::RectangleShape> getField1() const;
    std::vector<sf::RectangleShape> getField2() const;
    sf::Text getScorePlayer1() const;
    sf::Text getScorePlayer2() const;
    std::vector<sf::Text> getMenu() const;
    void clickButton(const int x, const int y);
    void restart();

   private:
    void addMenu(const std::string& text, int x, int y);
    void addFields();
    std::vector<sf::RectangleShape> m_field_1;
    std::vector<sf::RectangleShape> m_field_2;
    std::vector<sf::Text> m_menu;
    sf::Font m_font;
    Player<sea_battle_library::RandomGenerator> m_player_1{};
    Player<sea_battle_library::RandomGenerator> m_player_2{};
};
}  // namespace sea_battle
