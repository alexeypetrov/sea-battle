#pragma once

#include <SFML/Graphics/RenderWindow.hpp>
#include "Game.hpp"

namespace sea_battle {
class Application {
   public:
    Application(const char* name);
    void run(Game& game);

   private:
    void processEvents(Game& game);
    void drawGame(const Game& game);

   private:
    sf::RenderWindow m_window;
};
}  // namespace sea_battle
