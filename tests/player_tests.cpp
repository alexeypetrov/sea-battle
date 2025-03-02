#include "../Player.hpp"
#include "../SeaMap.hpp"
#include "../lib/RandomGenerator.hpp"

#include <gtest/gtest.h>
#include <string>

class TestRandomGenerator : public sea_battle_library::IRandomGenerator {
   public:
    TestRandomGenerator(int randomNumber) {}
    int getNumber() override { return m_test_random_number++; }
    bool getBoolean() override { return false; }

   private:
    int m_test_random_number = 0;
};

class TestPlayer : public ::testing::Test {
   protected:
    void SetUp() {
        sf::Font font;
        font.loadFromFile("../fonts/Ubuntu-Regular.ttf");
        player.initScorePlayer(font, 0, 0);
    }
    sea_battle::Player<TestRandomGenerator> player{};
};

TEST_F(TestPlayer, IncreaseScore) {
    std::string scoreText = player.getScore().getString();
    EXPECT_EQ("Score: 0", scoreText);
    player.increaseScore();
    scoreText = player.getScore().getString();
    EXPECT_EQ("Score: 1", scoreText);
}

TEST_F(TestPlayer, CheckWin) {
    for (int i = 0; i < 20; ++i) {
        player.increaseScore();
    }
    std::string scoreText = player.getScore().getString();
    EXPECT_EQ("Score: 20 WIN!", scoreText);
}

TEST_F(TestPlayer, CheckExistsBoat) {
    EXPECT_EQ(sea_battle::Status::Exists, player.getSeaMapFieldStatus(0));
    EXPECT_EQ(sea_battle::Status::Killed, player.fire(0));
    EXPECT_EQ(sea_battle::Status::Killed, player.getSeaMapFieldStatus(0));
}

TEST_F(TestPlayer, CheckEmptyField) {
    EXPECT_EQ(sea_battle::Status::Empty, player.getSeaMapFieldStatus(1));
    EXPECT_EQ(sea_battle::Status::Checked, player.fire(1));
    EXPECT_EQ(sea_battle::Status::Checked, player.getSeaMapFieldStatus(1));
}
