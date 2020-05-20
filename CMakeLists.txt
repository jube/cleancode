cmake_minimum_required(VERSION 3.10)

project(CLEANCODE
  LANGUAGES CXX
)

add_executable(cleancode
  cleancode.cc
)

target_compile_options(cleancode
  PRIVATE
    "-Wall" "-Wextra" "-g" "-O2"
)

target_compile_features(cleancode
  PUBLIC
    cxx_std_17
)

set_target_properties(cleancode
  PROPERTIES
    CXX_EXTENSIONS OFF
)

install(
  TARGETS cleancode
  RUNTIME DESTINATION bin
)
