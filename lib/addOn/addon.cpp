#include "addon.h"
#include <iostream>
#include <random>
#include <chrono>

// это класс для тестирования метода сложения путем подмены метода генерации случайных чисел

#if __cplusplus >= 201103L
    // C++11 и новее - используем современный генератор
    #include <random>
    #include <chrono>
#else
    // Старый C++ - используем rand()
    #include <cstdlib>
    #include <ctime>
#endif

// отдельно выделили метод 
void AddOn::hwtest() {
    std::cout << "hello world" << std::endl;
}

int AddOn::getRandomNumber() {
#if  __cplusplus >= 201103L
    // Современный C++11 способ
    // Равномерное распределение от 1 до 100
  
    // Комбинируем random_device + chrono для надёжности
    static std::mt19937 gen(
        []() -> unsigned int {
            std::random_device rd;
            auto now = std::chrono::steady_clock::now().time_since_epoch().count();
            return static_cast<unsigned int>(rd() ^ now);  // XOR для смешивания
        }()
    );
    // Фиксированный seed - одинаковые числа при каждом запуске
    static std::uniform_int_distribution<int> dist(1, 100);

    // ОТЛАДОЧНЫЙ ВЫВОД
    int result = dist(gen);
    
    return result;
#else
    // Старый способ для C++98/03
    static bool seeded = false;
    if (!seeded) {
        srand(static_cast<unsigned int>(time(nullptr)));
        seeded = true;
    }
    return (rand() % 100) + 1;
#endif
}

int AddOn::addRandomToValue(int value) {
    int randomNum = getRandomNumber();
    std::cout << "\n Generated random number: случайное значение: " << randomNum << " + то что пришло = " << value << " результат =  " << (randomNum + value) << std::endl;
    return randomNum + value;
}
