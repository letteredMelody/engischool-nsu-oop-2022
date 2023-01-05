cmake_minimum_required(VERSION 3.20)
project(BinaryRelation)
set(CMAKE_CXX_STANDARD 20)
add_executable(BinaryRelation main.cpp BinaryRelation.h BinaryRelationProperty.h)
if (MSVC)
    target_compile_options(BinaryRelation
            PRIVATE /W4          # warnings level
            PRIVATE /WX          # treat all warnings as errors
            )
else()
    target_compile_options(BinaryRelation
            PRIVATE -Wall        # basic set of warnings
            PRIVATE -pedantic    # modern C++ inspections
            PRIVATE -Werror      # treat all warnings as errors
            )
endif()