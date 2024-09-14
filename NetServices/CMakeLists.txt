project(MosquittoConnect)

# Сбор исходников
file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "*.cpp")

# Создание библиотеки
add_library (${PROJECT_NAME} STATIC ${SOURCES})

# Добавление заголовоч.файлов
target_include_directories(${PROJECT_NAME} PUBLIC src)

# Подключение mosquitto
target_link_libraries(${PROJECT_NAME} PUBLIC MosquittoLib)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавить тесты