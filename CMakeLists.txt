set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/install CACHE PATH "Installation path.")

cmake_minimum_required(VERSION 2.8.12.1)

project(yapimpl CXX)

# acmake {{{
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/acmake)
include(acmake_boost_support)
include(acmake_target_platform)
# }}}

# C++11 {{{
if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()
# }}}

# output path {{{
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
# }}}

include_directories(include)

# test {{{
option(YAPIMPL_WITH_TEST "Build tests." TRUE)
if(YAPIMPL_WITH_TEST)
    enable_testing()
    add_subdirectory(test)
endif()
# }}}

# install {{{
install(
    DIRECTORY include/
    DESTINATION include
    FILES_MATCHING PATTERN *.hpp
    )
install(
    DIRECTORY cmake/
    DESTINATION cmake
    FILES_MATCHING PATTERN *.cmake
    )
# }}}
