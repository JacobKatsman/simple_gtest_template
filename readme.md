GTest Фреймворк https://github.com/google/googletest/tree/main 
активно использует макросы.
В макросе TEST первый аргумент в скобках означает название группы тестов,
объединенных общей логикой. Второй аргумент - название конкретного теста в подгруппе.
```bash
sudo apt update
sudo apt install build-essential cmake libgtest-dev libtbb-dev libgmock-dev 
Создайте папку сборки: mkdir build && cd build
```

```bash
Сконфигурируйте проект: cmake ..
```
Две точки рядом с cmake означают, что нужно искать файл сценария CMakeLists.txt в родительском каталоге.
Эта команда сгенерирует набор инструкций для компиляции и сборки библиотек gtest и gmock. После чего останется выполнить:
```bash
sudo make
Скомпилируйте: make
Запустите тесты: ./run_tests
```

 или так:

 ```bash
 # Из корневой директории проекта (где лежит CMakeLists.txt)
 mkdir -p build
 cd build
 cmake ..              # .. указывает на родительскую папку с исходниками
 cmake --build .
 ```

 ```bash
 # Или из любой папки:
 cmake -S /путь/к/проекту -B /путь/к/проекту/build
 cmake --build /путь/к/проекту/build
```
