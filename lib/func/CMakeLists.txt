# Создаём статическую библиотеку из класса-заглушки
add_library(addon_func_lib STATIC
    functions.cpp
    functions.h
)

# Указываем пути для include (если нужны дополнительные)
target_include_directories(addon_func_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Можно указать стандарт C++, если нужно
# target_compile_features(addon_func_lib PUBLIC cxx_std_17)