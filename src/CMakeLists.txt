# Extract the qmake executable location
get_target_property(QT5_QMAKE_EXECUTABLE Qt5::qmake IMPORTED_LOCATION)
# Ask Qt5 where is sysroot
execute_process(COMMAND ${QT5_QMAKE_EXECUTABLE} -query QT_SYSROOT
    OUTPUT_VARIABLE qt_sysroot_dir OUTPUT_STRIP_TRAILING_WHITESPACE)
file(TO_CMAKE_PATH "${qt_sysroot_dir}" qt_sysroot_dir)
set(QT_SYSROOT_DIR ${qt_sysroot_dir} CACHE PATH
    "The location of the Qt sysroot" FORCE)
# Ask Qt5 where to put the translations
execute_process(COMMAND ${QT5_QMAKE_EXECUTABLE} -query QT_INSTALL_TRANSLATIONS
OUTPUT_VARIABLE qt_translations_dir OUTPUT_STRIP_TRAILING_WHITESPACE )
# make sure we have / and not \ as qmake gives on windows
file(TO_CMAKE_PATH "${qt_translations_dir}" qt_translations_dir)
string(REPLACE "${QT_SYSROOT_DIR}" "" qt_translations_dir "${qt_translations_dir}")
set(QT_TRANSLATIONS_DIR ${qt_translations_dir} CACHE PATH
    "The location of the Qt translations" FORCE)
add_definitions(
    -DPROJECT_NAME="${PROJECT_NAME}"
    -DQT_TRANSLATIONS_DIR="${QT_TRANSLATIONS_DIR}")

set(SOURCES
    error.cpp
    message.cpp
    servicesocket.cpp
    service.cpp
    server.cpp
    tcpserver.cpp
    pendingcall.cpp
    abstractsocket.cpp
    client.cpp)

add_library(qmsgpackrpc SHARED ${SOURCES})

target_link_libraries(qmsgpackrpc qmsgpack Qt5::Network)

install(TARGETS qmsgpackrpc
    DESTINATION ${CMAKE_INSTALL_LIBDIR})
