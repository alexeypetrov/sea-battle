#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include "Game.hpp"

namespace sea_battle {
class Application {
   public:
    inline static const int kMapSize = 500;
    explicit Application(const char* name);
    void Run(Game& game);

   private:
    void ProcessEvents(Game& game);
    void DrawGame(const Game& game);
    sf::RenderWindow m_window_;
};
}  // namespace sea_battle
