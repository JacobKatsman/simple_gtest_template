#include <gtest/gtest.h>
#include "functions.h"

using namespace testing;

class VerbosePrinter : public EmptyTestEventListener {

    const char* COLOR_RED   = "\033[1;31m";
    const char* COLOR_GREEN = "\033[1;32m";
    const char* COLOR_RESET = "\033[0m";
   
    // Вызывается после завершения каждого теста
    void OnTestEnd(const TestInfo& test_info) override {

	  if (test_info.result()->Passed()) {
            // Зеленый [ PASSED ]
            std::cout << COLOR_GREEN << "[ PASSED ] " << COLOR_RESET 
                      << test_info.test_case_name() << "." << test_info.name() << std::endl;
        } else if (test_info.result()->Failed()) {
            // Красный [ FAILED ]
            std::cout << COLOR_RED << "[ FAILED ] " << COLOR_RESET 
                      << test_info.test_case_name() << "." << test_info.name() << std::endl;
        }

	
    }
};

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    // Добавляем слушатель
    TestEventListeners& listeners = UnitTest::GetInstance()->listeners();
    // Удаляем стандартный принтер (который выводит лишнюю информацию)
    delete listeners.Release(listeners.default_result_printer());   
    listeners.Append(new VerbosePrinter);
      
    testing::GTEST_FLAG(print_time) = true; 
    return RUN_ALL_TESTS();
}
