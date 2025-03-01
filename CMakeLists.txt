cmake_minimum_required(VERSION 3.7.2)
project(sea_battle)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib)

add_executable(sea_battle
    SeaBattle.cpp
    SeaMap.cpp
    Application.cpp
    Game.cpp
    fonts/Ubuntu-Regular.ttf
)
add_executable(sea_battle_test
    tests/player_tests.cpp
    tests/sea_map_tests.cpp
    SeaMap.cpp
    fonts/Ubuntu-Regular.ttf
)

find_package(GTest CONFIG REQUIRED)
find_package(SFML COMPONENTS graphics CONFIG REQUIRED)

target_link_libraries(sea_battle sfml-graphics seaBattleLib)
target_link_libraries(sea_battle_test PRIVATE GTest::gtest GTest::gtest_main sfml-graphics seaBattleLib)

target_include_directories(sea_battle PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib)
target_include_directories(sea_battle_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/lib)

target_compile_options(sea_battle PRIVATE -Wall -Wextra -Wpedantic)

find_program(CLANG_FORMAT "clang-format")
if (CLANG_FORMAT)
    set(SOURCES
        SeaBattle.cpp
        SeaMap.cpp
        SeaMap.hpp
        Player.hpp
        Application.cpp
        Application.hpp
        Game.cpp
        Game.hpp
        lib/RandomGenerator.cpp
        lib/RandomGenerator.hpp
        tests/player_tests.cpp
        tests/sea_map_tests.cpp
    )
    execute_process(
        COMMAND ${CLANG_FORMAT} -i ${SOURCES}
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
    )
endif()
