#ifndef MOCK_ADDON_GMOCK_H
#define MOCK_ADDON_GMOCK_H

#include <gmock/gmock.h>
#include "addon.h"
#include "functions.h"

class MockAddOn : public AddOn {
public:
    MOCK_METHOD(int, getRandomNumber, (), (override));
    
    // Удобный метод для настройки возвращаемого значения
    void setRandomNumberReturn(int value) {
        ON_CALL(*this, getRandomNumber()).WillByDefault(testing::Return(value));
    }
};

class MockFunc : public Func {
public:
  MOCK_METHOD(int, add, (int, int), (override));
    // Удобный метод для настройки возвращаемого значения
    void setAddReturn(int value) {
	ON_CALL(*this, add(3, 5)).WillByDefault(testing::Return(8));
    }
};

#endif
