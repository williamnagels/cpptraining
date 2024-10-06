cmake_minimum_required (VERSION 3.0)

project (cpptraining)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include_directories(global)

set(COMPILE_TIME_POLYMORPHISM_SOURCES 
	compile_time_polymorphism/main.cpp 
	compile_time_polymorphism/ex1.cpp 
	compile_time_polymorphism/ex2.cpp 
	compile_time_polymorphism/ex3.cpp)
add_executable(compile_time_polymorphism ${COMMON_SOURCES} ${COMPILE_TIME_POLYMORPHISM_SOURCES})
target_compile_options(compile_time_polymorphism PRIVATE -Wall -Wextra -Wpedantic)

set(MOVE_SOURCES 
	reference_semantics/main.cpp 
	reference_semantics/ex1.cpp 
	reference_semantics/ex2.cpp 
	reference_semantics/ex3.cpp
	reference_semantics/ex4.cpp
	reference_semantics/ex5.cpp)
add_executable(reference ${COMMON_SOURCES} ${MOVE_SOURCES})
target_compile_options(reference PRIVATE -Wall -Wextra -Wpedantic)

set(VALUE_SOURCES 
	value_semantics/main.cpp 
	value_semantics/ex1.cpp 
	value_semantics/ex2.cpp 
	value_semantics/ex3.cpp)
add_executable(value ${COMMON_SOURCES} ${VALUE_SOURCES})
target_compile_options(value PRIVATE -Wall -Wextra -Wpedantic)

set(STRONG_SOURCES 
	strong_types/main.cpp 
	strong_types/ex1.cpp
	strong_types/ex2.cpp
	strong_types/ex3.cpp)
add_executable(strong ${COMMON_SOURCES} ${STRONG_SOURCES})
target_compile_options(strong PRIVATE -Wall -Wextra -Wpedantic)

set(CONT_SOURCES 
	containers/main.cpp 
	containers/ex1.cpp 
	containers/ex2.cpp 
	containers/ex3.cpp
	containers/ex4.cpp
	containers/ex5.cpp
	containers/ex6.cpp
	containers/ex7.cpp
	containers/ex8.cpp
	containers/ex9.cpp)
add_executable(containers ${COMMON_SOURCES} ${CONT_SOURCES})
target_compile_options(containers PRIVATE -Wall -Wextra -Wpedantic)
