cmake_minimum_required(VERSION 2.6)
project(encontrar2quesomamx)

include_directories(.)
file(GLOB core_LIB_SOURCES ./*.cpp)
file(GLOB coreLIB_HEADERS ./*.h)
add_executable(encontrar2quesomamx ${core_LIB_SOURCES} ${core_LIB_HEADERS})

install(TARGETS encontrar2quesomamx RUNTIME DESTINATION bin)
