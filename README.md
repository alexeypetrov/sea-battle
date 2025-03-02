# Игра "Морской бой"
## Собрать проект с vcpkg для Linux

#### Установить vcpkg:
```console
$ git clone https://github.com/Microsoft/vcpkg.git
$ ./vcpkg/bootstrap-vcpkg.sh -disableMetrics
```

#### Установить sfml и gtest:
```console
$ ./vcpkg/vcpkg install sfml
$ ./vcpkg/vcpkg install gtest
```

#### Получить параметры для сборки проекта:
```console
$ ./vcpkg/vcpkg integrate install
```

#### Сборка проекта:
```console
$ cmake -B build -S . "{параметры из предыдущей команды}"
$ cmake --build build
```

#### Запуск игры:
```console
$ ./build/sea_battle
```

#### Запуск тестов
```console
$ ./build/sea_battle_test
```
