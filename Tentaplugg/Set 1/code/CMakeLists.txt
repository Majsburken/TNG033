cmake_minimum_required(VERSION 3.13.0...3.28)
project(TNG033-Set-1 VERSION 1.0.0 DESCRIPTION "TNG033 Set of Exercises 1" LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

function(enable_warnings target)
target_compile_options(${target} PUBLIC 
        $<$<CXX_COMPILER_ID:MSVC>:
            /W4                 # Enable the highest warning level
            /w44388             # eneble 'signed/unsigned mismatch' '(off by default)
            /we4715             # turn 'not all control paths return a value' into a compile error
            /permissive-        # Stick to the standard
            >
        $<$<CXX_COMPILER_ID:AppleClang,Clang,GNU>:-Wall -Wextra -Wconversion>
)
endfunction()


add_executable(Exerc1 exerc1.cpp)
add_executable(Exerc2 exerc2.cpp)
add_executable(Exerc3 exerc3.cpp)
add_executable(Exerc4 list.h list.cpp main.cpp)

enable_warnings(Exerc1)
enable_warnings(Exerc2)
enable_warnings(Exerc3)
enable_warnings(Exerc4)