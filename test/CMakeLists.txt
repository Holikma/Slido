cmake_minimum_required(VERSION 3.8)

set(This Average_Tests)

set(Sources
    Average_Tests.cpp
)

add_executable(${This} ${Sources})
target_link_libraries(${This} PUBLIC
    gtest_main
    Average
)

add_test(
    NAME ${This}
    COMMAND ${This}
)