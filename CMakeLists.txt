# CMakeList.txt: файл проекта CMake верхнего уровня; проведите глобальную конфигурацию
# и включите сюда подпроекты.
#
cmake_minimum_required (VERSION 3.7)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("NetworkApp")


# Подключение mosquitto
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
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Deps/mosquitto/linux/include)

    set_property(TARGET MosquittoLib PROPERTY
    IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/Deps/mosquitto/linux/lib/libmosquitto.so)
endif()

# Включите подпроекты.
add_subdirectory ("NetworkApp")
