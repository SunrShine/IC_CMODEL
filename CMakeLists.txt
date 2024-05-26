cmake_minimum_required(VERSION 3.16) 
project(libdramsim3_proj001)  
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 11)  

set(CMAKE_BUILD_TYPE Debug) 
if (${CMAKE_BUILD_TYPE} MATCHES "Debug" )
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g  -fsanitize=address -fno-omit-frame-pointer")
endif()
# -fsanitize=leak

find_package(Boost COMPONENTS unit_test_framework REQUIRED)


# ===---------------------------------------------------------------===
# include projs
# ===---------------------------------------------------------------===
add_subdirectory(include)


# ===---------------------------------------------------------------===
# libdramsim3
# ===---------------------------------------------------------------===
add_subdirectory(lib)




# ===---------------------------------------------------------------===
# test
# ===---------------------------------------------------------------===

if(Boost_FOUND)
MESSAGE( STATUS "Boost_INCLUDE_DIRS = ${Boost_INCLUDE_DIRS}.")
MESSAGE( STATUS "Boost_LIBRARIES = ${Boost_LIBRARIES}.")
MESSAGE( STATUS "Boost_LIB_VERSION = ${Boost_LIB_VERSION}.")


# ---------------------BaseLine Module tests----------------------------

file(GLOB tests_src "test/BaseLine/*.cc")
add_executable(TESTBaseLine_Main ${tests_src} )
target_link_libraries(TESTBaseLine_Main  ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})
# target_link_libraries(TESTBaseLine_Main )
target_include_directories(TESTBaseLine_Main PRIVATE  ${PROJECT_SOURCE_DIR}/lib/BaseLine )
target_include_directories(TESTBaseLine_Main PRIVATE  ${PROJECT_SOURCE_DIR}/include/BaseLine )

endif()
