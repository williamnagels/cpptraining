# C++ training exercises
The instructions in this README file assume that a variable has been defined to store the location of the training directory, as shown below:
'''
ROOT_CPPTRAINING=/home/william/cpptraining
'''
## Compile the test binaries:
1. Generate Makefiles
```
11:49 $ cmake -B $ROOT_CPPTRAINING/build/ -S $ROOT_CPPTRAINING/exercises/
-- The C compiler identification is GNU 11.4.0
-- The CXX compiler identification is GNU 11.4.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: /home/william/cpptraining/build
```
In this example the Make files are generated in directory /home/william/cpptraining/build/. The CMake file used to generated this Make file can be found in /home/william/cpptraining/exercises/
2. Build project using generated Makefiles
```
make -C $ROOT_CPPTRAINING/build
```
At this stage, the compiler may issue some warnings. These occur because the source files contain intentionally problematic code that has to be fixed as part of the exercises. Warnings are expected, but there should never be any compiler errors on a clean clone.
3. Run test binary
```
$ROOT_CPPTRAINING/strong
```
Asserts will occur with a clean checkout, but crashes or core dumps should never happen.
## Solving the exercises
1. Navigate to the folder of the module you're interested in (e.g., containers). Open the corresponding exercise file, such as containers/ex1.cpp, to start with the first exercise.
2. Look for the symbol test_1 within that file and read the associated documentation. The instructions should clarify what needs to be done. Each test file (e.g. containers/ex1.cpp) will typically contain several local symbols like test_1, test_2, etc., and one global symbol, such as cont_ex1. This global symbol is called by the test binary. You can see the global symbols needed to build each binary in the main.cpp file in each submodule.
