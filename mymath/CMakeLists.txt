# cmake_minimum_required(VERSION 3.23)

# set(project "mymath")
# project(${project})

# set(CMAKE_CXX_STANDARD 17)

# set(${project}_SOURCES
#         mymath.cpp)

# set(${project}_HEADERS
#         mymath.h)

# set(${project}_SOURCE_LIST
#         ${${project}_SOURCES}
#         ${${project}_HEADERS})

# add_library(${project}
#         STATIC
#         ${${project}_SOURCE_LIST})

#         cmake_minimum_required(VERSION 3.20)

project("lab_2")

set(CMAKE_CXX_CLANG_TIDY "clang-tidy")

set(SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Lab_2.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/main2.cpp
)

set(HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/Lab_2.hpp
)

add_executable(${CMAKE_PROJECT_NAME} ${SOURCES} ${HEADERS})
set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY CXX_STANDARD 20)
target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -Wall -Wextra -Werror -Wpedantic)

if(ENABLE_DEBUG)
    target_compile_options(${CMAKE_PROJECT_NAME} PRIVATE -g)
endif()

add_custom_target(
    clang-format
    COMMAND clang-format
    --dry-run
    -Werror
    ${SOURCES}
    ${HEADERS}
)
