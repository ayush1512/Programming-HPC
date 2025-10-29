cmake_minimum_required(VERSION 3.16)
project(OpenMPTest CXX)

# Use Homebrew LLVM/Clang explicitly
set(CMAKE_C_COMPILER "/opt/homebrew/opt/llvm/bin/clang")
set(CMAKE_CXX_COMPILER "/opt/homebrew/opt/llvm/bin/clang++")

# Tell CMake where to find OpenMP from Homebrew
set(OpenMP_C_FLAGS "-Xpreprocessor -fopenmp -I/opt/homebrew/opt/libomp/include")
set(OpenMP_C_LIB_NAMES "omp")
set(OpenMP_omp_LIBRARY "/opt/homebrew/opt/libomp/lib/libomp.dylib")
set(OpenMP_CXX_FLAGS "${OpenMP_C_FLAGS}")
set(OpenMP_CXX_LIB_NAMES "${OpenMP_C_LIB_NAMES}")
set(OpenMP_omp_LIBRARY "${OpenMP_omp_LIBRARY}")

find_package(OpenMP REQUIRED)

add_executable(OpenMPTest main.cpp)
target_link_libraries(OpenMPTest PUBLIC OpenMP::OpenMP_CXX)./OpenMPTest