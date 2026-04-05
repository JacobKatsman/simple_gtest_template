#ifndef MOCK_ADDON_H
#define MOCK_ADDON_H

#include "../lib/addOn/addon.h"
#include "../lib/func/functions.h"
#include <gmock/gmock.h>

class MockAddOn : public AddOn {
public:
    // Устанавливаем фиксированное значение
    void setFixedRandomValue(int value) { fixedRandomValue_ = value; }
    
    //Для Google Mock
    MOCK_METHOD(int, getRandomNumber, (), (override));
    
private:
    int fixedRandomValue_ = 42;
};

class MockFunc : public Func {
public:
    MOCK_METHOD(int, add, (int, int), (override));
};

#endif


