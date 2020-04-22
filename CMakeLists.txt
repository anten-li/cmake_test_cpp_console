# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("CMake_test")

STRING(COMPARE EQUAL ${CMAKE_BUILD_TYPE} "Release" isRelease)
if(isRelease)
	set(CMAKE_CXX_FLAGS_RELEASE "/O2 /DNDEBUG")
	SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /NODEFAULTLIB /ENTRY:main /MANIFEST:NO")
endif()

# Include sub-projects.
add_subdirectory ("CMake_test")
