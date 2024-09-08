# CMakeList.txt: проект CMake для NetworkApp; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.
if (NOT WIN32 AND NOT UNIX)
    message (FATAL_ERROR "Неизвестная система")
endif()

add_library(MosquittoLib SHARED IMPORTED)
if (WIN32)
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Deps/mosquitto/windows/include)

    set_property(TARGET MosquittoLib PROPERTY
    IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/Deps/mosquitto/windows/lib/mosquitto.dll)
    set_property(TARGET MosquittoLib PROPERTY
    IMPORTED_IMPLIB ${CMAKE_CURRENT_SOURCE_DIR}/Deps/mosquitto/windows/lib/mosquitto.lib)
elseif (UNIX AND ${CMAKE_SYSTEM} MATCHES "Linux")
    message(${CMAKE_CURRENT_SOURCE_DIR})
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Deps/mosquitto/linux/include)

    set_property(TARGET MosquittoLib PROPERTY
    IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/Deps/mosquitto/linux/lib/libmosquitto.so)
#    set_property(TARGET MosquittoLib PROPERTY
#    IMPORTED_IMPLIB ${PROJECT_SOURCE_DIR}/NetworkApp/Deps/mosquitto/linux/lib/mosquitto.lib)
endif()

add_executable (NetworkApp "NetworkApp.cpp" "NetworkApp.h")
target_link_libraries(NetworkApp PRIVATE MosquittoLib)

if (WIN32)
    file(COPY
        ${CMAKE_CURRENT_SOURCE_DIR}/Deps/mosquitto/lib/mosquitto.dll
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/)
endif()


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET NetworkApp PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
