cmake_minimum_required(VERSION 3.20)
project(Matrix)
set(CMAKE_CXX_STANDARD 17)
add_executable(Matrix main.cpp Matrix.h Matrix.cpp)
if (MSVC)
    target_compile_options(Matrix
            PRIVATE /W4          # warnings level
            PRIVATE /WX          # treat all warnings as errors
            )
else()
    target_compile_options(Matrix
            PRIVATE -Wall        # basic set of warnings
            PRIVATE -pedantic    # modern C++ inspections
            PRIVATE -Werror      # treat all warnings as errors
            )
endif()
