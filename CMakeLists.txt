cmake_minimum_required(VERSION 3.20)
project(frediff C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(vendor/cjson)

add_executable(diff
  src/main.c
  src/diff.c
  src/ses.c
  src/find_middle.c
)

target_link_libraries(diff PRIVATE cjson)

target_include_directories(diff PRIVATE
  vendor/cjson
)
