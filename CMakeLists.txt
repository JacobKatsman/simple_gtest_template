cmake_minimum_required(VERSION 3.10)
project(MyUnitTests LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Не используем find_package для GTest, а подключаем вручную
find_library(GTEST_LIB gtest REQUIRED)
find_library(GTEST_MAIN_LIB gtest_main REQUIRED)
find_library(GMOCK_LIB gmock REQUIRED)
find_library(GMOCK_MAIN_LIB gmock_main REQUIRED)


# 1. Находим пакет потоков (pthreads в Linux)
find_package(Threads REQUIRED)

# 2. Находим GTest
find_package(GTest REQUIRED)

# Добавляем поддиректорию с классом
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/addOn)

# Добавляем поддиректорию с классом
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/lib/func)

# ... в секции, где вы создаёте исполняемый файл, например:
add_executable(run_tests 
    test_main.cpp
    test/mocks/test_main.cpp
    lib/func/functions.cpp
)

message(STATUS "CMAKE_CURRENT_SOURCE_DIR = ${CMAKE_CURRENT_SOURCE_DIR}")

# 3. Линуем правильно: 
# Используем GTest::gtest_main (автоматически добавит main, если он не прописан в коде)
# И переменную Threads::Threads

# Линкуем напрямую с библиотеками
target_link_libraries(run_tests 
    PRIVATE
        addon_lib
	addon_func_lib
        ${GTEST_LIB}
        ${GTEST_MAIN_LIB}
	${GMOCK_LIB}
        ${GMOCK_MAIN_LIB}
        Threads::Threads
)


# Если нужно, добавляем путь для include (чтобы видеть addon.h)
target_include_directories(run_tests PRIVATE
   ${CMAKE_CURRENT_SOURCE_DIR}/test
   ${CMAKE_CURRENT_SOURCE_DIR}/lib/addOn
   ${CMAKE_CURRENT_SOURCE_DIR}/lib/func)
