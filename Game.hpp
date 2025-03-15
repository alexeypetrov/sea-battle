#pragma once

#include <cmath>
#include <string>
#include "Player.hpp"

namespace sea_battle {
class Game {
   public:
    inline static const int kRowLength = 10;
    inline static const int kColLength = 10;
    inline static const int kFieldSize = 50;
    inline static const int kFontSize = 25;
    inline static const int kBtnNewGameX = 1100;
    inline static const int kBtnNewGameY = 50;
    inline static const int kBtnExitX = 1100;
    inline static const int kBtnExitY = 100;
    inline static const int kScorePlayer1X = 50;
    inline static const int kScorePlayer1Y = 550;
    inline static const int kScorePlayer2X = 600;
    inline static const int kScorePlayer2Y = 550;
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
