cmake_minimum_required(VERSION 3.1)

set(CMAKE_CXX_STANDARD 20)

set(PROJECT_NAME coll-aoc-runner-Library)
set(LIBRARY_NAME coll-aoc-runner)
set(LIBRARY_HEADERS_DIR include/${LIBRARY_NAME})
set(LIBRARY_HEADERS
        ${LIBRARY_HEADERS_DIR}/aoc_day.h
        ${LIBRARY_HEADERS_DIR}/aoc_days.h
        ${LIBRARY_HEADERS_DIR}/aoc_delimiter.h
        ${LIBRARY_HEADERS_DIR}/aoc_input.h
        ${LIBRARY_HEADERS_DIR}/aoc_years.h
        ${LIBRARY_HEADERS_DIR}/aoc_runner.h
        ${LIBRARY_HEADERS_DIR}/crypto/aoc_md5.h
        ${LIBRARY_HEADERS_DIR}/string/aoc_string.h
        ${LIBRARY_HEADERS_DIR}/structures/aoc_2d_grid.h
)
set(LIBRARY_SOURCE_DIR src)
set(LIBRARY_SOURCE
        ${LIBRARY_SOURCE_DIR}/aoc_day.cpp
        ${LIBRARY_SOURCE_DIR}/aoc_days.cpp
        ${LIBRARY_SOURCE_DIR}/aoc_input.cpp
        ${LIBRARY_SOURCE_DIR}/aoc_runner.cpp
        ${LIBRARY_SOURCE_DIR}/aoc_years.cpp
)

project(${PROJECT_NAME})

include(FindPkgConfig)
pkg_check_modules(CURLPP REQUIRED curlpp)
pkg_check_modules(OPENSSL REQUIRED openssl)
pkg_check_modules(JSONCPP REQUIRED jsoncpp)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

add_library(${LIBRARY_NAME} STATIC ${LIBRARY_HEADERS} ${LIBRARY_SOURCE})

target_include_directories(${LIBRARY_NAME}
        PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/${LIBRARY_NAME}> $<INSTALL_INTERFACE:include/${LIBRARY_NAME}>
        PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/${LIBRARY_NAME}/crypto> $<INSTALL_INTERFACE:include/${LIBRARY_NAME}/crypto>
        PRIVATE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/${LIBRARY_NAME}/string> $<INSTALL_INTERFACE:include/${LIBRARY_NAME}/string>
        PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> $<INSTALL_INTERFACE:include>
)

target_link_libraries(${LIBRARY_NAME}
        ${CURLPP_LDFLAGS}
        ${OPENSSL_LIBRARIES}
        ${JSONCPP_LIBRARIES}
)
