#include "Game.hpp"
#include <cstdlib>

namespace sea_battle {
Game::Game() {
    AddFields();
    m_font_.loadFromFile("../fonts/Ubuntu-Regular.ttf");
    AddMenu("New game", kBtnNewGameX, kBtnNewGameY);
    AddMenu("Exit", kBtnExitX, kBtnExitY);
    m_player_1_.InitScorePlayer(m_font_, kScorePlayer1X, kScorePlayer1Y);
    m_player_2_.InitScorePlayer(m_font_, kScorePlayer2X, kScorePlayer2Y);
}

[[nodiscard]] auto Game::GetField1() const -> std::vector<sf::RectangleShape> {
    return m_field_1_;
}

[[nodiscard]] auto Game::GetField2() const -> std::vector<sf::RectangleShape> {
    return m_field_2_;
}

[[nodiscard]] auto Game::GetScorePlayer1() const -> sf::Text {
    return m_player_1_.GetScore();
}

[[nodiscard]] auto Game::GetScorePlayer2() const -> sf::Text {
    return m_player_2_.GetScore();
}

[[nodiscard]] auto Game::GetMenu() const -> std::vector<sf::Text> {
    return m_menu_;
}

void Game::AddFields() {
    m_field_1_.clear();
    for (int i = 0; i < kRowLength; ++i) {
        for (int j = 0; j < kColLength; ++j) {
            sf::RectangleShape box;
            box.setPosition(i * kFieldSize, j * kFieldSize);
            box.setSize(sf::Vector2f(kFieldSize, kFieldSize));
            box.setFillColor(sf::Color::White);
            box.setOutlineColor(sf::Color::Blue);
            box.setOutlineThickness(1);
            m_field_1_.push_back(box);
        }
    }
    m_field_2_.clear();
    for (int i = 0; i < kRowLength; ++i) {
        for (int j = 0; j < kColLength; ++j) {
            sf::RectangleShape box;
            box.setPosition(i * kFieldSize + kFieldSize * (kRowLength + 1),
                            j * kFieldSize);
            box.setSize(sf::Vector2f(kFieldSize, kFieldSize));
            if (m_player_2_.GetSeaMapFieldStatus(i * kRowLength + j) ==
                Status::kEmpty) {
                box.setFillColor(sf::Color::White);
            } else {
                box.setFillColor(sf::Color::Red);
            }
            box.setOutlineColor(sf::Color::Blue);
            box.setOutlineThickness(1);
            m_field_2_.push_back(box);
        }
    }
}

void Game::AddMenu(const std::string& text, int xPosition, int yPosition) {
    sf::Text menu_text;
    menu_text.setFont(m_font_);
    menu_text.setPosition(xPosition, yPosition);
    menu_text.setString(text);
    menu_text.setCharacterSize(kFontSize);
    menu_text.setFillColor(sf::Color::Green);
    m_menu_.push_back(menu_text);
}

void Game::ClickButton(int xPosition, int yPosition) {
    int num = std::lround(xPosition / kFieldSize * kRowLength) +
              std::lround(yPosition / kFieldSize);
    if (m_player_1_.GetSeaMapFieldStatus(num) == Status::kKilled ||
        m_player_1_.GetSeaMapFieldStatus(num) == Status::kChecked) {
        return;
    }
    if (m_player_1_.Fire(num) == Status::kKilled) {
        m_player_1_.IncreaseScore();
        m_field_1_[num].setFillColor(sf::Color::Black);
    } else {
        m_field_1_[num].setFillColor(sf::Color::Blue);
    }
    int random_num = 0;
    do {
        random_num = std::rand() % SeaMap::kMaxFields;
    } while (m_player_2_.GetSeaMapFieldStatus(random_num) != Status::kEmpty &&
             m_player_2_.GetSeaMapFieldStatus(random_num) != Status::kExists);
    if (m_player_2_.Fire(random_num) == Status::kKilled) {
        m_player_2_.IncreaseScore();
        m_field_2_[random_num].setFillColor(sf::Color::Black);
    } else {
        m_field_2_[random_num].setFillColor(sf::Color::Blue);
    }
}

void Game::Restart() {
    m_player_1_.Restart();
    m_player_2_.Restart();
    AddFields();
}
}  // namespace sea_battle
