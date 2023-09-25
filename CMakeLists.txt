cmake_minimum_required(VERSION 3.1)

set(PROJECT_NAME COLLAdventOfCode)
set(SOURCE_DIR src)
set(SOURCE ${SOURCE_DIR}/main.cpp)
set(LIBRARIES_DIR libs)
set(LIBRARIES
		coll-aoc-runner
)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_THREAD_LIBS_INIT "-lpthread")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
set(CMAKE_HAVE_THREADS_LIBRARY 1)
set(CMAKE_USE_WIN32_THREADS_INIT 0)
set(CMAKE_USE_PTHREADS_INIT 1)
set(THREADS_PREFER_PTHREAD_FLAG ON)

project(${PROJECT_NAME})

# Add sources for the years
set(SOURCES_2015 src/2015/day1.h src/2015/day1.cpp src/2015/day2.h src/2015/day2.cpp src/2015/day3.h src/2015/day3.cpp src/2015/day4.h src/2015/day4.cpp src/2015/day5.h src/2015/day5.cpp src/2015/day6.h src/2015/day6.cpp src/2015/day7.h src/2015/day7.cpp src/2015/day8.h src/2015/day8.cpp src/2015/day9.h src/2015/day9.cpp src/2015/day10.h src/2015/day10.cpp src/2015/day11.h src/2015/day11.cpp src/2015/day12.h src/2015/day12.cpp src/2015/day13.h src/2015/day13.cpp src/2015/day14.h src/2015/day14.cpp src/2015/day15.h src/2015/day15.cpp src/2015/day16.h src/2015/day16.cpp src/2015/day17.h src/2015/day17.cpp src/2015/day18.h src/2015/day18.cpp src/2015/day19.h src/2015/day19.cpp src/2015/day20.h src/2015/day20.cpp src/2015/day21.h src/2015/day21.cpp src/2015/day22.h src/2015/day22.cpp src/2015/day23.h src/2015/day23.cpp src/2015/day24.h src/2015/day24.cpp src/2015/day25.h src/2015/day25.cpp src/2015/days.h)

add_executable(${PROJECT_NAME} ${SOURCE} ${SOURCES_2015})

foreach(LIBRARY ${LIBRARIES})
	add_subdirectory("${LIBRARIES_DIR}/${LIBRARY}")
endforeach(LIBRARY)

target_link_libraries(${PROJECT_NAME}
		${LIBRARIES}
)


































