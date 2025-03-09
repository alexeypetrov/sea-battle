#include "Application.hpp"
#include <SFML/Window/Event.hpp>

namespace sea_battle {
Application::Application(const char* name)
    : m_window_{sf::VideoMode(1300, 800), name, sf::Style::Close} {}

void Application::Run(Game& game) {
    bool is_init = true;
    while (m_window_.isOpen()) {
        ProcessEvents(game);
        if (is_init) {
            DrawGame(game);
            is_init = false;
        }
    }
}

void Application::ProcessEvents(Game& game) {
    sf::Event event{};
    while (m_window_.pollEvent(event)) {
        if (event.type == sf::Event::EventType::Closed) {
            m_window_.close();
        }
        if (event.type == sf::Event::MouseButtonPressed &&
            event.mouseButton.button == sf::Mouse::Left) {
            if (event.mouseButton.x > 1100 && event.mouseButton.y > 50 &&
                event.mouseButton.y < 75) {
                game.Restart();
                DrawGame(game);
            }
            if (event.mouseButton.x > 1100 && event.mouseButton.y > 100 &&
                event.mouseButton.y < 125) {
                m_window_.close();
            }
            if (event.mouseButton.x < 500 && event.mouseButton.y < 500) {
                game.ClickButton(event.mouseButton.x, event.mouseButton.y);
                DrawGame(game);
            }
        }
    }
}

void Application::DrawGame(const Game& game) {
    m_window_.clear();
    for (const auto& field : game.GetField1()) {
        m_window_.draw(field);
    }
    for (const auto& field : game.GetField2()) {
        m_window_.draw(field);
    }
    for (const auto& menu : game.GetMenu()) {
        m_window_.draw(menu);
    }
    m_window_.draw(game.GetScorePlayer1());
    m_window_.draw(game.GetScorePlayer2());
    m_window_.display();
}
}  // namespace sea_battle
