#include "../SeaMap.hpp"

#include <gtest/gtest.h>

TEST(SeaMap, CheckEmptyField) {
    std::array<sea_battle::Status, 100> data{};
    data[0] = sea_battle::Status::kExists;
    data[5] = sea_battle::Status::kExists;
    data[9] = sea_battle::Status::kExists;
    data[50] = sea_battle::Status::kExists;
    data[55] = sea_battle::Status::kExists;
    data[59] = sea_battle::Status::kExists;
    data[90] = sea_battle::Status::kExists;
    data[95] = sea_battle::Status::kExists;
    data[99] = sea_battle::Status::kExists;
    sea_battle::SeaMap seaMap(data);

    ASSERT_FALSE(seaMap.CheckEmptyField(0));
    ASSERT_FALSE(seaMap.CheckEmptyField(1));
    ASSERT_TRUE(seaMap.CheckEmptyField(2));
    ASSERT_TRUE(seaMap.CheckEmptyField(3));
    ASSERT_FALSE(seaMap.CheckEmptyField(4));
    ASSERT_FALSE(seaMap.CheckEmptyField(5));
    ASSERT_FALSE(seaMap.CheckEmptyField(6));
    ASSERT_TRUE(seaMap.CheckEmptyField(7));
    ASSERT_FALSE(seaMap.CheckEmptyField(8));
    ASSERT_FALSE(seaMap.CheckEmptyField(9));
    ASSERT_FALSE(seaMap.CheckEmptyField(10));
    ASSERT_FALSE(seaMap.CheckEmptyField(11));
    ASSERT_TRUE(seaMap.CheckEmptyField(12));
    ASSERT_TRUE(seaMap.CheckEmptyField(13));
    ASSERT_FALSE(seaMap.CheckEmptyField(14));
    ASSERT_FALSE(seaMap.CheckEmptyField(15));
    ASSERT_FALSE(seaMap.CheckEmptyField(16));
    ASSERT_TRUE(seaMap.CheckEmptyField(17));
    ASSERT_FALSE(seaMap.CheckEmptyField(18));
    ASSERT_FALSE(seaMap.CheckEmptyField(19));
    ASSERT_TRUE(seaMap.CheckEmptyField(20));
    ASSERT_TRUE(seaMap.CheckEmptyField(21));
    ASSERT_TRUE(seaMap.CheckEmptyField(22));
    ASSERT_TRUE(seaMap.CheckEmptyField(23));
    ASSERT_TRUE(seaMap.CheckEmptyField(24));
    ASSERT_TRUE(seaMap.CheckEmptyField(25));
    ASSERT_TRUE(seaMap.CheckEmptyField(26));
    ASSERT_TRUE(seaMap.CheckEmptyField(27));
    ASSERT_TRUE(seaMap.CheckEmptyField(28));
    ASSERT_TRUE(seaMap.CheckEmptyField(29));
    ASSERT_TRUE(seaMap.CheckEmptyField(30));
    ASSERT_TRUE(seaMap.CheckEmptyField(31));
    ASSERT_TRUE(seaMap.CheckEmptyField(32));
    ASSERT_TRUE(seaMap.CheckEmptyField(33));
    ASSERT_TRUE(seaMap.CheckEmptyField(34));
    ASSERT_TRUE(seaMap.CheckEmptyField(35));
    ASSERT_TRUE(seaMap.CheckEmptyField(36));
    ASSERT_TRUE(seaMap.CheckEmptyField(37));
    ASSERT_TRUE(seaMap.CheckEmptyField(38));
    ASSERT_TRUE(seaMap.CheckEmptyField(39));
    ASSERT_FALSE(seaMap.CheckEmptyField(40));
    ASSERT_FALSE(seaMap.CheckEmptyField(41));
    ASSERT_TRUE(seaMap.CheckEmptyField(42));
    ASSERT_TRUE(seaMap.CheckEmptyField(43));
    ASSERT_FALSE(seaMap.CheckEmptyField(44));
    ASSERT_FALSE(seaMap.CheckEmptyField(45));
    ASSERT_FALSE(seaMap.CheckEmptyField(46));
    ASSERT_TRUE(seaMap.CheckEmptyField(47));
    ASSERT_FALSE(seaMap.CheckEmptyField(48));
    ASSERT_FALSE(seaMap.CheckEmptyField(49));
    ASSERT_FALSE(seaMap.CheckEmptyField(50));
    ASSERT_FALSE(seaMap.CheckEmptyField(51));
    ASSERT_TRUE(seaMap.CheckEmptyField(52));
    ASSERT_TRUE(seaMap.CheckEmptyField(53));
    ASSERT_FALSE(seaMap.CheckEmptyField(54));
    ASSERT_FALSE(seaMap.CheckEmptyField(55));
    ASSERT_FALSE(seaMap.CheckEmptyField(56));
    ASSERT_TRUE(seaMap.CheckEmptyField(57));
    ASSERT_FALSE(seaMap.CheckEmptyField(58));
    ASSERT_FALSE(seaMap.CheckEmptyField(59));
    ASSERT_FALSE(seaMap.CheckEmptyField(60));
    ASSERT_FALSE(seaMap.CheckEmptyField(61));
    ASSERT_TRUE(seaMap.CheckEmptyField(62));
    ASSERT_TRUE(seaMap.CheckEmptyField(63));
    ASSERT_FALSE(seaMap.CheckEmptyField(64));
    ASSERT_FALSE(seaMap.CheckEmptyField(65));
    ASSERT_FALSE(seaMap.CheckEmptyField(66));
    ASSERT_TRUE(seaMap.CheckEmptyField(67));
    ASSERT_FALSE(seaMap.CheckEmptyField(68));
    ASSERT_FALSE(seaMap.CheckEmptyField(69));
    ASSERT_TRUE(seaMap.CheckEmptyField(70));
    ASSERT_TRUE(seaMap.CheckEmptyField(71));
    ASSERT_TRUE(seaMap.CheckEmptyField(72));
    ASSERT_TRUE(seaMap.CheckEmptyField(73));
    ASSERT_TRUE(seaMap.CheckEmptyField(74));
    ASSERT_TRUE(seaMap.CheckEmptyField(75));
    ASSERT_TRUE(seaMap.CheckEmptyField(76));
    ASSERT_TRUE(seaMap.CheckEmptyField(77));
    ASSERT_TRUE(seaMap.CheckEmptyField(78));
    ASSERT_TRUE(seaMap.CheckEmptyField(79));
    ASSERT_FALSE(seaMap.CheckEmptyField(80));
    ASSERT_FALSE(seaMap.CheckEmptyField(81));
    ASSERT_TRUE(seaMap.CheckEmptyField(82));
    ASSERT_TRUE(seaMap.CheckEmptyField(83));
    ASSERT_FALSE(seaMap.CheckEmptyField(84));
    ASSERT_FALSE(seaMap.CheckEmptyField(85));
    ASSERT_FALSE(seaMap.CheckEmptyField(86));
    ASSERT_TRUE(seaMap.CheckEmptyField(87));
    ASSERT_FALSE(seaMap.CheckEmptyField(88));
    ASSERT_FALSE(seaMap.CheckEmptyField(89));
    ASSERT_FALSE(seaMap.CheckEmptyField(90));
    ASSERT_FALSE(seaMap.CheckEmptyField(91));
    ASSERT_TRUE(seaMap.CheckEmptyField(92));
    ASSERT_TRUE(seaMap.CheckEmptyField(93));
    ASSERT_FALSE(seaMap.CheckEmptyField(94));
    ASSERT_FALSE(seaMap.CheckEmptyField(95));
    ASSERT_FALSE(seaMap.CheckEmptyField(96));
    ASSERT_TRUE(seaMap.CheckEmptyField(97));
    ASSERT_FALSE(seaMap.CheckEmptyField(98));
    ASSERT_FALSE(seaMap.CheckEmptyField(99));
}

TEST(SeaMap, CheckFieldStatus) {
    std::array<sea_battle::Status, 100> data{};
    data[0] = sea_battle::Status::kExists;
    sea_battle::SeaMap seaMap(data);
    EXPECT_EQ(sea_battle::Status::kKilled, seaMap.CheckFieldStatus(0));
    EXPECT_EQ(sea_battle::Status::kChecked, seaMap.CheckFieldStatus(5));
}

class TestRandomGenerator : public sea_battle_library::IRandomGenerator {
   public:
    TestRandomGenerator(int randomNumber) {}
    int GetNumber() override { return m_test_random_number++; }
    bool GetBoolean() override { return false; }

   private:
    int m_test_random_number = 0;
};

TEST(SeaMap, AddSeaBoat) {
    sea_battle::SeaMap seaMap(std::make_unique<TestRandomGenerator>(0));
    ASSERT_TRUE(seaMap.AddBoat(50, 1));
    ASSERT_FALSE(seaMap.AddBoat(1, 1));
}
