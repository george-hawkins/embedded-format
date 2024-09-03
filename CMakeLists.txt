cmake_minimum_required(VERSION 3.22)

project(embedded_format)

set(CMAKE_CXX_STANDARD 23)

include(FetchContent)

FetchContent_Declare(
    NamedType
    GIT_REPOSITORY https://github.com/joboccara/NamedType.git
    GIT_TAG 76668ab
)

FetchContent_MakeAvailable(NamedType)

FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt.git
    GIT_TAG 894b71d
)

FetchContent_MakeAvailable(fmt)

target_compile_definitions(
    fmt
    PUBLIC FMT_STATIC_THOUSANDS_SEPARATOR='.'
    PUBLIC FMT_USE_FLOAT=0
    PUBLIC FMT_USE_DOUBLE=0
    PUBLIC FMT_USE_LONG_DOUBLE=0
    PUBLIC FMT_USE_FLOAT128=0
)


set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
set(BUILD_SHARED_LIBS OFF)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(experiment experiment.cpp)
target_link_libraries(
    experiment
    PRIVATE NamedType
    PRIVATE fmt
)
