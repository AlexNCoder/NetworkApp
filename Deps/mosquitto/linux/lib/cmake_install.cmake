# Install script for directory: /home/alexneurocoder/Projects/C++/Test4Job/2024/9/LaserSystems/mosquitto-2.0.18/lib

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmosquitto.so.2.0.18"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmosquitto.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmosquitto.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES
    "/home/alexneurocoder/Projects/C++/Test4Job/2024/9/LaserSystems/build-mosquitto-2.0.18-Desktop-u041eu0442u043bu0430u0434u043au0430/lib/libmosquitto.so.2.0.18"
    "/home/alexneurocoder/Projects/C++/Test4Job/2024/9/LaserSystems/build-mosquitto-2.0.18-Desktop-u041eu0442u043bu0430u0434u043au0430/lib/libmosquitto.so.1"
    "/home/alexneurocoder/Projects/C++/Test4Job/2024/9/LaserSystems/build-mosquitto-2.0.18-Desktop-u041eu0442u043bu0430u0434u043au0430/lib/libmosquitto.so"
    )
  foreach(file
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmosquitto.so.2.0.18"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmosquitto.so.1"
      "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmosquitto.so"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHANGE
           FILE "${file}"
           OLD_RPATH "/home/alexneurocoder/Projects/C++/Test4Job/2024/9/LaserSystems/mosquitto-2.0.18/lib:"
           NEW_RPATH "")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES "/home/alexneurocoder/Projects/C++/Test4Job/2024/9/LaserSystems/mosquitto-2.0.18/lib/../include/mosquitto.h")
endif()

if("${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES "/home/alexneurocoder/Projects/C++/Test4Job/2024/9/LaserSystems/mosquitto-2.0.18/lib/../include/mqtt_protocol.h")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/alexneurocoder/Projects/C++/Test4Job/2024/9/LaserSystems/build-mosquitto-2.0.18-Desktop-u041eu0442u043bu0430u0434u043au0430/lib/cpp/cmake_install.cmake")

endif()

