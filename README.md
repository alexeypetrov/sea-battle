# Игра "Морской бой"
## Собрать проект для Linux

#### Установить conan:
```console
$ python3 -m venv .venv
$ source .venv/bin/activate
$ pip install conan
$ conan profile detect --force
```

#### Установить sfml 2 и gtest:
```console
$ conan install . --output-folder=build --build=missing
```

#### Сборка проекта:
```console
$ cd build
$ cmake .. -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release
$ cmake --build .
```

#### Запуск игры:
```console
$ ./sea_battle
```

#### Запуск тестов
```console
$ ./sea_battle_test
```
