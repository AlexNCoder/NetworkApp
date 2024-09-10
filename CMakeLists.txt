cmake_minimum_required (VERSION 3.7)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("NetworkApps")

# Подключение зависимостей
include(cmake/libdeps.cmake)

# Включите подпроекты.
add_subdirectory ("NetworkAppClient")
add_subdirectory ("NetworkAppPseudoServer")