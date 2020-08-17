# Install script for directory: /home/qi/ws_MutiFingerHand/src/MutiFingerHand_Qi_URDF

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/qi/ws_MutiFingerHand/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
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

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/qi/ws_MutiFingerHand/build/MutiFingerHand_Qi_URDF/catkin_generated/installspace/MutiFingerHand_Qi_URDF.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/MutiFingerHand_Qi_URDF/cmake" TYPE FILE FILES
    "/home/qi/ws_MutiFingerHand/build/MutiFingerHand_Qi_URDF/catkin_generated/installspace/MutiFingerHand_Qi_URDFConfig.cmake"
    "/home/qi/ws_MutiFingerHand/build/MutiFingerHand_Qi_URDF/catkin_generated/installspace/MutiFingerHand_Qi_URDFConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/MutiFingerHand_Qi_URDF" TYPE FILE FILES "/home/qi/ws_MutiFingerHand/src/MutiFingerHand_Qi_URDF/package.xml")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/MutiFingerHand_Qi_URDF/config" TYPE DIRECTORY FILES "/home/qi/ws_MutiFingerHand/src/MutiFingerHand_Qi_URDF/config/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/MutiFingerHand_Qi_URDF/launch" TYPE DIRECTORY FILES "/home/qi/ws_MutiFingerHand/src/MutiFingerHand_Qi_URDF/launch/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/MutiFingerHand_Qi_URDF/meshes" TYPE DIRECTORY FILES "/home/qi/ws_MutiFingerHand/src/MutiFingerHand_Qi_URDF/meshes/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/MutiFingerHand_Qi_URDF/urdf" TYPE DIRECTORY FILES "/home/qi/ws_MutiFingerHand/src/MutiFingerHand_Qi_URDF/urdf/")
endif()

