cmake_minimum_required(VERSION 3.10)
project(qmsgpackrpc VERSION 1.0.0.0)

include(GNUInstallDirs)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 COMPONENTS Network REQUIRED)

add_subdirectory(src)
