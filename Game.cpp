#include "Game.hpp"

namespace sea_battle {
Game::Game() {
    addFields();
    m_font.loadFromFile("../fonts/Ubuntu-Regular.ttf");
    addMenu("New game", 1100, 50);
    addMenu("Exit", 1100, 100);
    m_player_1.initScorePlayer(m_font, 50, 550);
    m_player_2.initScorePlayer(m_font, 600, 550);
}

std::vector<sf::RectangleShape> Game::getField1() const {
    return m_field_1;
}

std::vector<sf::RectangleShape> Game::getField2() const {
    return m_field_2;
}

sf::Text Game::getScorePlayer1() const {
    return m_player_1.getScore();
}

sf::Text Game::getScorePlayer2() const {
    return m_player_2.getScore();
}

std::vector<sf::Text> Game::getMenu() const {
    return m_menu;
}

void Game::addFields() {
    m_field_1.clear();
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            sf::RectangleShape box;
            box.setPosition(i * 50, j * 50);
            box.setSize(sf::Vector2f(50, 50));
            box.setFillColor(sf::Color::White);
            box.setOutlineColor(sf::Color::Blue);
            box.setOutlineThickness(1);
            m_field_1.push_back(box);
        }
    }
    m_field_2.clear();
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            sf::RectangleShape box;
            box.setPosition(i * 50 + 550, j * 50);
            box.setSize(sf::Vector2f(50, 50));
            if (m_player_2.getSeaMapFieldStatus(i * 10 + j) == Status::Empty) {
                box.setFillColor(sf::Color::White);
            } else {
                box.setFillColor(sf::Color::Red);
            }
            box.setOutlineColor(sf::Color::Blue);
            box.setOutlineThickness(1);
            m_field_2.push_back(box);
        }
    }
}

void Game::addMenu(const std::string& text, int x, int y) {
    sf::Text menuText;
    menuText.setFont(m_font);
    menuText.setPosition(x, y);
    menuText.setString(text);
    menuText.setCharacterSize(25);
    menuText.setFillColor(sf::Color::Green);
    m_menu.push_back(menuText);
}

void Game::clickButton(const int x, const int y) {
    int num = std::lround(x / 50 * 10) + std::lround(y / 50);
    if (m_player_1.getSeaMapFieldStatus(num) == Status::Killed ||
        m_player_1.getSeaMapFieldStatus(num) == Status::Checked) {
        return;
    }
    if (m_player_1.fire(num) == Status::Killed) {
        m_player_1.increaseScore();
        m_field_1[num].setFillColor(sf::Color::Black);
    } else {
        m_field_1[num].setFillColor(sf::Color::Blue);
    }
    int randomNum = 0;
    do {
        randomNum = std::rand() % SeaMap::MAX_FIELDS;
    } while (m_player_2.getSeaMapFieldStatus(randomNum) != Status::Empty &&
             m_player_2.getSeaMapFieldStatus(randomNum) != Status::Exists);
    if (m_player_2.fire(randomNum) == Status::Killed) {
        m_player_2.increaseScore();
        m_field_2[randomNum].setFillColor(sf::Color::Black);
    } else {
        m_field_2[randomNum].setFillColor(sf::Color::Blue);
    }
}

void Game::restart() {
    m_player_1.restart();
    m_player_2.restart();
    addFields();
}
}  // namespace sea_battle
