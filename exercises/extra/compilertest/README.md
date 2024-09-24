This CMake project includes tools to verify if your environment is capable of compiling all exercises. The key requirement is your compiler's support for C++20 features.
- For GCC, you need at least version 10.1.
- For Clang, the minimum supported version is 11.
If your current setup doesn't meet these requirements, or if you're using an older version of Clang/GCC and don't want to modify your system, there’s an Alpine-based Docker container provided
that includes the correct GCC version. This is also a handy solution if you're using Windows or need a clean, isolated environment for building.
If you use the container, its best to volume mount the compilertest sources using -v start-up parameter.
