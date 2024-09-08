# CMakeList.txt: проект CMake для NetworkApp; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.
include_directories(${PROJECT_SOURCE_DIR}/NetworkApp/Deps/mosquitto/include)

add_library(MosquittoLib SHARED IMPORTED)
if (WIN32)
    set_property(TARGET MosquittoLib PROPERTY
    IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/NetworkApp/Deps/mosquitto/lib/mosquitto.dll)
#elseif (LINUX)
    #set_property(TARGET MosquittoLib PROPERTY
    #IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/NetworkApp/Deps/mosquitto/lib/mosquitto.so)
endif()

set_property(TARGET MosquittoLib PROPERTY
IMPORTED_IMPLIB ${PROJECT_SOURCE_DIR}/NetworkApp/Deps/mosquitto/lib/mosquitto.lib)

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
