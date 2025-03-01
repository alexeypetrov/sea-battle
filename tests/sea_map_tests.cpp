#include "../SeaMap.hpp"

#include <gtest/gtest.h>

TEST(SeaMap, CheckEmptyField) {
    std::array<sea_battle::Status, 100> data{};
    data[0] = sea_battle::Status::Exists;
    data[5] = sea_battle::Status::Exists;
    data[9] = sea_battle::Status::Exists;
    data[50] = sea_battle::Status::Exists;
    data[55] = sea_battle::Status::Exists;
    data[59] = sea_battle::Status::Exists;
    data[90] = sea_battle::Status::Exists;
    data[95] = sea_battle::Status::Exists;
    data[99] = sea_battle::Status::Exists;
    sea_battle::SeaMap seaMap(data);

    ASSERT_FALSE(seaMap.checkEmptyField(0));
    ASSERT_FALSE(seaMap.checkEmptyField(1));
    ASSERT_TRUE(seaMap.checkEmptyField(2));
    ASSERT_TRUE(seaMap.checkEmptyField(3));
    ASSERT_FALSE(seaMap.checkEmptyField(4));
    ASSERT_FALSE(seaMap.checkEmptyField(5));
    ASSERT_FALSE(seaMap.checkEmptyField(6));
    ASSERT_TRUE(seaMap.checkEmptyField(7));
    ASSERT_FALSE(seaMap.checkEmptyField(8));
    ASSERT_FALSE(seaMap.checkEmptyField(9));
    ASSERT_FALSE(seaMap.checkEmptyField(10));
    ASSERT_FALSE(seaMap.checkEmptyField(11));
    ASSERT_TRUE(seaMap.checkEmptyField(12));
    ASSERT_TRUE(seaMap.checkEmptyField(13));
    ASSERT_FALSE(seaMap.checkEmptyField(14));
    ASSERT_FALSE(seaMap.checkEmptyField(15));
    ASSERT_FALSE(seaMap.checkEmptyField(16));
    ASSERT_TRUE(seaMap.checkEmptyField(17));
    ASSERT_FALSE(seaMap.checkEmptyField(18));
    ASSERT_FALSE(seaMap.checkEmptyField(19));
    ASSERT_TRUE(seaMap.checkEmptyField(20));
    ASSERT_TRUE(seaMap.checkEmptyField(21));
    ASSERT_TRUE(seaMap.checkEmptyField(22));
    ASSERT_TRUE(seaMap.checkEmptyField(23));
    ASSERT_TRUE(seaMap.checkEmptyField(24));
    ASSERT_TRUE(seaMap.checkEmptyField(25));
    ASSERT_TRUE(seaMap.checkEmptyField(26));
    ASSERT_TRUE(seaMap.checkEmptyField(27));
    ASSERT_TRUE(seaMap.checkEmptyField(28));
    ASSERT_TRUE(seaMap.checkEmptyField(29));
    ASSERT_TRUE(seaMap.checkEmptyField(30));
    ASSERT_TRUE(seaMap.checkEmptyField(31));
    ASSERT_TRUE(seaMap.checkEmptyField(32));
    ASSERT_TRUE(seaMap.checkEmptyField(33));
    ASSERT_TRUE(seaMap.checkEmptyField(34));
    ASSERT_TRUE(seaMap.checkEmptyField(35));
    ASSERT_TRUE(seaMap.checkEmptyField(36));
    ASSERT_TRUE(seaMap.checkEmptyField(37));
    ASSERT_TRUE(seaMap.checkEmptyField(38));
    ASSERT_TRUE(seaMap.checkEmptyField(39));
    ASSERT_FALSE(seaMap.checkEmptyField(40));
    ASSERT_FALSE(seaMap.checkEmptyField(41));
    ASSERT_TRUE(seaMap.checkEmptyField(42));
    ASSERT_TRUE(seaMap.checkEmptyField(43));
    ASSERT_FALSE(seaMap.checkEmptyField(44));
    ASSERT_FALSE(seaMap.checkEmptyField(45));
    ASSERT_FALSE(seaMap.checkEmptyField(46));
    ASSERT_TRUE(seaMap.checkEmptyField(47));
    ASSERT_FALSE(seaMap.checkEmptyField(48));
    ASSERT_FALSE(seaMap.checkEmptyField(49));
    ASSERT_FALSE(seaMap.checkEmptyField(50));
    ASSERT_FALSE(seaMap.checkEmptyField(51));
    ASSERT_TRUE(seaMap.checkEmptyField(52));
    ASSERT_TRUE(seaMap.checkEmptyField(53));
    ASSERT_FALSE(seaMap.checkEmptyField(54));
    ASSERT_FALSE(seaMap.checkEmptyField(55));
    ASSERT_FALSE(seaMap.checkEmptyField(56));
    ASSERT_TRUE(seaMap.checkEmptyField(57));
    ASSERT_FALSE(seaMap.checkEmptyField(58));
    ASSERT_FALSE(seaMap.checkEmptyField(59));
    ASSERT_FALSE(seaMap.checkEmptyField(60));
    ASSERT_FALSE(seaMap.checkEmptyField(61));
    ASSERT_TRUE(seaMap.checkEmptyField(62));
    ASSERT_TRUE(seaMap.checkEmptyField(63));
    ASSERT_FALSE(seaMap.checkEmptyField(64));
    ASSERT_FALSE(seaMap.checkEmptyField(65));
    ASSERT_FALSE(seaMap.checkEmptyField(66));
    ASSERT_TRUE(seaMap.checkEmptyField(67));
    ASSERT_FALSE(seaMap.checkEmptyField(68));
    ASSERT_FALSE(seaMap.checkEmptyField(69));
    ASSERT_TRUE(seaMap.checkEmptyField(70));
    ASSERT_TRUE(seaMap.checkEmptyField(71));
    ASSERT_TRUE(seaMap.checkEmptyField(72));
    ASSERT_TRUE(seaMap.checkEmptyField(73));
    ASSERT_TRUE(seaMap.checkEmptyField(74));
    ASSERT_TRUE(seaMap.checkEmptyField(75));
    ASSERT_TRUE(seaMap.checkEmptyField(76));
    ASSERT_TRUE(seaMap.checkEmptyField(77));
    ASSERT_TRUE(seaMap.checkEmptyField(78));
    ASSERT_TRUE(seaMap.checkEmptyField(79));
    ASSERT_FALSE(seaMap.checkEmptyField(80));
    ASSERT_FALSE(seaMap.checkEmptyField(81));
    ASSERT_TRUE(seaMap.checkEmptyField(82));
    ASSERT_TRUE(seaMap.checkEmptyField(83));
    ASSERT_FALSE(seaMap.checkEmptyField(84));
    ASSERT_FALSE(seaMap.checkEmptyField(85));
    ASSERT_FALSE(seaMap.checkEmptyField(86));
    ASSERT_TRUE(seaMap.checkEmptyField(87));
    ASSERT_FALSE(seaMap.checkEmptyField(88));
    ASSERT_FALSE(seaMap.checkEmptyField(89));
    ASSERT_FALSE(seaMap.checkEmptyField(90));
    ASSERT_FALSE(seaMap.checkEmptyField(91));
    ASSERT_TRUE(seaMap.checkEmptyField(92));
    ASSERT_TRUE(seaMap.checkEmptyField(93));
    ASSERT_FALSE(seaMap.checkEmptyField(94));
    ASSERT_FALSE(seaMap.checkEmptyField(95));
    ASSERT_FALSE(seaMap.checkEmptyField(96));
    ASSERT_TRUE(seaMap.checkEmptyField(97));
    ASSERT_FALSE(seaMap.checkEmptyField(98));
    ASSERT_FALSE(seaMap.checkEmptyField(99));
}

TEST(SeaMap, CheckFieldStatus) {
    std::array<sea_battle::Status, 100> data{};
    data[0] = sea_battle::Status::Exists;
    sea_battle::SeaMap seaMap(data);
    EXPECT_EQ(sea_battle::Status::Killed, seaMap.checkFieldStatus(0));
    EXPECT_EQ(sea_battle::Status::Checked, seaMap.checkFieldStatus(5));
}

class TestRandomGenerator : public sea_battle_library::IRandomGenerator {
   public:
    TestRandomGenerator(int randomNumber) {}
    int getNumber() override { return m_test_random_number++; }
    bool getBoolean() override { return false; }

   private:
    int m_test_random_number = 0;
};

TEST(SeaMap, AddSeaBoat) {
    sea_battle::SeaMap seaMap(std::make_unique<TestRandomGenerator>(0));
    ASSERT_TRUE(seaMap.addBoat(50, 1));
    ASSERT_FALSE(seaMap.addBoat(1, 1));
}
