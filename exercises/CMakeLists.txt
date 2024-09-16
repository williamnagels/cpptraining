cmake_minimum_required (VERSION 3.0)

project (cpptraining)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include_directories(global)

set(MOVE_SOURCES 
	referencesemantics/main.cpp 
	referencesemantics/ex1.cpp 
	referencesemantics/ex2.cpp 
	referencesemantics/ex3.cpp
	referencesemantics/ex4.cpp
	referencesemantics/ex5.cpp)
add_executable(reference ${COMMON_SOURCES} ${MOVE_SOURCES})
target_compile_options(reference PRIVATE -Wall -Wextra -Wpedantic)

set(VALUE_SOURCES 
	valuesemantics/main.cpp 
	valuesemantics/ex1.cpp 
	valuesemantics/ex2.cpp 
	valuesemantics/ex3.cpp)
add_executable(value ${COMMON_SOURCES} ${VALUE_SOURCES})
target_compile_options(value PRIVATE -Wall -Wextra -Wpedantic)

set(STRONG_SOURCES 
	strongtypes/main.cpp 
	strongtypes/ex1.cpp
	strongtypes/ex2.cpp
	strongtypes/ex3.cpp)
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
