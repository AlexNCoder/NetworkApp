

# Создание приложения
add_executable (NetworkApp "NetworkApp.cpp" "NetworkApp.h")
target_link_libraries(NetworkApp PUBLIC MosquittoLib)

# Копирование dll
if (WIN32)
    file(COPY
        ${CMAKE_HOME_DIRECTORY}/Deps/mosquitto/windows/lib/mosquitto.dll
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)
endif()

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET NetworkApp PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавить тесты