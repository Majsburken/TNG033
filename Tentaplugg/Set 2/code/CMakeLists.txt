cmake_minimum_required(VERSION 3.13.0...3.28)
project(TNG033-Set-2 VERSION 1.0.0 DESCRIPTION "TNG033 Set of Exercises 2" LANGUAGES CXX)
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
			/fsanitize=address  # Enable the Address Sanatizer, helps finding bugs at runtime
            >
        $<$<CXX_COMPILER_ID:AppleClang,Clang,GNU>:-Wall -Wextra -Wconversion>
    )
    set_target_properties(${target} PROPERTIES 
        XCODE_GENERATE_SCHEME ON
        XCODE_SCHEME_ADDRESS_SANITIZER ON
        XCODE_SCHEME_ADDRESS_SANITIZER_USE_AFTER_RETURN ON
        XCODE_SCHEME_MALLOC_SCRIBBLE ON
        XCODE_SCHEME_UNDEFINED_BEHAVIOUR_SANITIZER ON
        XCODE_SCHEME_UNDEFINED_BEHAVIOUR_SANITIZER_STOP ON
    )
	 target_link_options(${target} PUBLIC 
         $<$<CXX_COMPILER_ID:MSVC>:/INCREMENTAL:NO> # Cant use incremental with asan
    )
endfunction()

add_executable(Exerc1 exerc1.cpp)
add_executable(Exerc2a exerc2a.cpp)
add_executable(Exerc2b exerc2b.cpp)
add_executable(Exerc3 exerc3.cpp)
add_executable(Exerc4 exerc4.cpp)
add_executable(Exerc5a exerc5a.cpp)
add_executable(Exerc5b exerc5b.cpp)

enable_warnings(Exerc1)
enable_warnings(Exerc2a)
enable_warnings(Exerc2b)
enable_warnings(Exerc3)
enable_warnings(Exerc4)
enable_warnings(Exerc5a)
enable_warnings(Exerc5b)