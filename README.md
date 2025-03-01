# Игра "Морской бой"
## Собрать проект с vcpkg для Linux

Установить vcpkg:

git clone https://github.com/Microsoft/vcpkg.git


Установить sfml и gtest:

./vcpkg/vcpkg install sfml

./vcpkg/vcpkg install gtest


Получить параметры для сборки проекта:

./vcpkg/vcpkg integrate install


Сборка проекта:

cmake -B build -S . "{параметры из предыдущей команды}"

cmake --build build


## Запуск игры:

./build/sea_battle

## Запуск тестов

./build/sea_battle_test
