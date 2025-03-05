cmake_minimum_required(VERSION 3.23)

project("lab2")

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Lab_2_pers.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Werror -Wpedantic)

target_link_libraries(${PROJECT_NAME} mymath)
