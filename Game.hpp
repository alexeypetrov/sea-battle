#pragma once

#include <cmath>
#include <string>
#include "Player.hpp"
#include "SeaMap.hpp"

namespace sea_battle {
class Game {
   public:
    Game();
    [[nodiscard]] auto GetField1() const -> std::vector<sf::RectangleShape>;
    [[nodiscard]] auto GetField2() const -> std::vector<sf::RectangleShape>;
    [[nodiscard]] auto GetScorePlayer1() const -> sf::Text;
    [[nodiscard]] auto GetScorePlayer2() const -> sf::Text;
    [[nodiscard]] auto GetMenu() const -> std::vector<sf::Text>;
    void ClickButton(int xPosition, int yPosition);
    void Restart();

   private:
    void AddMenu(const std::string& text, int xPosition, int yPosition);
    void AddFields();
    std::vector<sf::RectangleShape> m_field_1_;
    std::vector<sf::RectangleShape> m_field_2_;
    std::vector<sf::Text> m_menu_;
    sf::Font m_font_;
    Player<sea_battle_library::RandomGenerator> m_player_1_{};
    Player<sea_battle_library::RandomGenerator> m_player_2_{};
};
}  // namespace sea_battle
