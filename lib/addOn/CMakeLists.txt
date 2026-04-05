# Создаём статическую библиотеку из класса-заглушки
add_library(addon_lib STATIC
    addon.cpp
    addon.h
)

# Указываем пути для include (если нужны дополнительные)
target_include_directories(addon_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Можно указать стандарт C++, если нужно
# target_compile_features(addon_lib PUBLIC cxx_std_17)