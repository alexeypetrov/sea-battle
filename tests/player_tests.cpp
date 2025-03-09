#include "../Player.hpp"
#include "../SeaMap.hpp"
#include "../lib/RandomGenerator.hpp"

#include <gtest/gtest.h>
#include <string>

class TestRandomGenerator : public sea_battle_library::IRandomGenerator {
   public:
    TestRandomGenerator(int randomNumber) {}
    int GetNumber() override { return m_test_random_number++; }
    bool GetBoolean() override { return false; }

   private:
    int m_test_random_number = 0;
};

class TestPlayer : public ::testing::Test {
   protected:
    void SetUp() {
        sf::Font font;
        font.loadFromFile("../fonts/Ubuntu-Regular.ttf");
        player.InitScorePlayer(font, 0, 0);
    }
    sea_battle::Player<TestRandomGenerator> player{};
};

TEST_F(TestPlayer, IncreaseScore) {
    std::string scoreText = player.GetScore().getString();
    EXPECT_EQ("Score: 0", scoreText);
    player.IncreaseScore();
    scoreText = player.GetScore().getString();
    EXPECT_EQ("Score: 1", scoreText);
}

TEST_F(TestPlayer, CheckWin) {
    for (int i = 0; i < 20; ++i) {
        player.IncreaseScore();
    }
    std::string scoreText = player.GetScore().getString();
    EXPECT_EQ("Score: 20 WIN!", scoreText);
}

TEST_F(TestPlayer, CheckExistsBoat) {
    EXPECT_EQ(sea_battle::Status::kExists, player.GetSeaMapFieldStatus(0));
    EXPECT_EQ(sea_battle::Status::kKilled, player.Fire(0));
    EXPECT_EQ(sea_battle::Status::kKilled, player.GetSeaMapFieldStatus(0));
}

TEST_F(TestPlayer, CheckEmptyField) {
    EXPECT_EQ(sea_battle::Status::kEmpty, player.GetSeaMapFieldStatus(1));
    EXPECT_EQ(sea_battle::Status::kChecked, player.Fire(1));
    EXPECT_EQ(sea_battle::Status::kChecked, player.GetSeaMapFieldStatus(1));
}
