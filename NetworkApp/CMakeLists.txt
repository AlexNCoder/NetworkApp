# CMakeList.txt: проект CMake для NetworkApp; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.
#add_library(MosquittoLib STATIC IMPORTED)
#set_property(TARGET MosquittoLib PROPERTY
#IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/NetworkApp/Deps/mosquitto/lib/mosquitto.lib)

add_library(MosquittoppLib STATIC IMPORTED)
set_property(TARGET MosquittoppLib PROPERTY
IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/NetworkApp/Deps/mosquitto/lib/cpp/mosquittopp.lib)

add_library(MosquittoLib STATIC IMPORTED)
set_property(TARGET MosquittoLib PROPERTY
IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/NetworkApp/Deps/mosquitto/lib/mosquitto.lib)


include_directories(${PROJECT_SOURCE_DIR}/NetworkApp/Deps/mosquitto/include)
add_executable (NetworkApp "NetworkApp.cpp" "NetworkApp.h")
target_link_libraries(NetworkApp PRIVATE MosquittoLib MosquittoppLib)


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET NetworkApp PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
