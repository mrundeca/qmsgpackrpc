include_directories(../../src ${CMAKE_CURRENT_BINARY_DIR})
add_executable(tcpserver main.cpp)
target_link_libraries(tcpserver Qt5::Core Qt5::Network qmsgpackrpc)
