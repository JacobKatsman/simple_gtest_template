#ifndef ADDON_H
#define ADDON_H

class AddOnInterface {
public:
    virtual ~AddOnInterface() = default;
    virtual int getRandomNumber() = 0;
};

class AddOn : public AddOnInterface {
public:
    void hwtest();

    // Новый метод 1: получение случайного числа в диапазоне от 1 до 100
    // Добавляем virtual для возможности переопределения
    int getRandomNumber ();     // ← virtual здесь
    
    // Новый метод 2: складывание случайного числа с передаваемым параметром
    int addRandomToValue(int value);

    // Виртуальный деструктор для корректного удаления через указатель на базовый класс
    // virtual ~AddOn() = default;
    
};

#endif


