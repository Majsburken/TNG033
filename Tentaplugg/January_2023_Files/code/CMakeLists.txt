cmake_minimum_required(VERSION 3.13.0...3.25.1)
project(TNG033-Exam VERSION 1.0.0 DESCRIPTION "TNG033 Exam January 2023" LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

function(enable_warnings target)
    target_compile_options(${target} PUBLIC 
        $<$<CXX_COMPILER_ID:MSVC>:/W4 /permissive->
        $<$<CXX_COMPILER_ID:AppleClang,Clang,GNU>:-Wall -Wextra>
    )
endfunction()

add_executable(exercise1 exerc1.cpp ex1_out.txt)
add_executable(exercise2 exerc2.cpp ex2_out.txt)
add_executable(exercise3 exerc3.cpp ex3_out.txt)

enable_warnings(exercise1)
enable_warnings(exercise2)
enable_warnings(exercise3)
