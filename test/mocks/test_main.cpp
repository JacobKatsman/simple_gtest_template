#include <gmock/gmock.h>
#include "mocks/mock_addon_gmock.h"
#include "../lib/func/functions.h"

using ::testing::Return;

// Фреймворк активно использует макросы.
// В макросе TEST первый аргумент в скобках означает название группы тестов,
// объединенных общей логикой. Второй аргумент - название конкретного теста в подгруппе.

TEST(AddOnTest, AddRandomToValueWithGMock) {
    MockAddOn mockObj;
    // Настраиваем ожидание и возвращаемое значение
    EXPECT_CALL(mockObj, getRandomNumber())
        .Times(1)
        .WillOnce(Return(42));
    
    EXPECT_EQ(mockObj.addRandomToValue(50), 92);
}

TEST(AddOnTest, MultipleCalls) {
    // перебираем 3 теста (поэтому у нас проходят три теста сразу!
    MockAddOn mockObj;
    // тут собственно мокаются функции
    // эмулируем случайные значения  random   10,20,30
    EXPECT_CALL(mockObj, getRandomNumber())
        .WillOnce(Return(10))
        .WillOnce(Return(20))
        .WillOnce(Return(30));
    // тут вызываем сложение с тестовыми значениями
    EXPECT_EQ(mockObj.addRandomToValue(11), 21);
    EXPECT_EQ(mockObj.addRandomToValue(22), 42);
    EXPECT_EQ(mockObj.addRandomToValue(33), 63);
}

// просто тестируем без моков
TEST(MyMathTest, Addition) {
    // Создаем реальный объект
    Func calc; 
    // Настраиваете поведение для конкретного вызова
    EXPECT_EQ(calc.add(2, 2), 4);
    EXPECT_EQ(calc.add(3, 5), 8);
}

TEST(TestGroupName, increment_by_5)
{
  // Arrange
  int value = 100;
  int increment = 5;
  // Act
  value = value + increment;
  // Assert
  ASSERT_EQ(value, 105);
}

TEST(TestGroupName, Dummy_test_2) {
  ASSERT_TRUE('b' == 'b');
}

TEST(TestGroupName, Dummy_test_1) {
  ASSERT_TRUE(1 == 1);
}
