include_directories(../../src ${CMAKE_CURRENT_BINARY_DIR})
add_executable(tcpclient main.cpp)
target_link_libraries(tcpclient Qt5::Core Qt5::Network)
