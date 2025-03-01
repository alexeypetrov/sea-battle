#include "Application.hpp"
#include <SFML/Window/Event.hpp>

namespace sea_battle {
Application::Application(const char* name)
    : m_window{sf::VideoMode(1300, 800), name, sf::Style::Close} {}

void Application::run(Game& game) {
    bool isInit = true;
    while (m_window.isOpen()) {
        processEvents(game);
        if (isInit) {
            drawGame(game);
            isInit = false;
        }
    }
}

void Application::processEvents(Game& game) {
    sf::Event event{};
    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::EventType::Closed) {
            m_window.close();
        }
        if (event.type == sf::Event::MouseButtonPressed &&
            event.mouseButton.button == sf::Mouse::Left) {
            if (event.mouseButton.x > 1100 && event.mouseButton.y > 50 &&
                event.mouseButton.y < 75) {
                game.restart();
                drawGame(game);
            }
            if (event.mouseButton.x > 1100 && event.mouseButton.y > 100 &&
                event.mouseButton.y < 125) {
                m_window.close();
            }
            if (event.mouseButton.x < 500 && event.mouseButton.y < 500) {
                game.clickButton(event.mouseButton.x, event.mouseButton.y);
                drawGame(game);
            }
        }
    }
}

void Application::drawGame(const Game& game) {
    m_window.clear();
    for (const auto& field : game.getField1()) {
        m_window.draw(field);
    }
    for (const auto& field : game.getField2()) {
        m_window.draw(field);
    }
    for (const auto& menu : game.getMenu()) {
        m_window.draw(menu);
    }
    m_window.draw(game.getScorePlayer1());
    m_window.draw(game.getScorePlayer2());
    m_window.display();
}
}  // namespace sea_battle
