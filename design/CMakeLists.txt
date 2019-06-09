cmake_minimum_required (VERSION 2.6)
project (Design)

#The version number

set (Design_VERSION_MAJOR 1)
set (Design_VERSION_MINOR 0)

# configure a header file to pass some of the CMake settings 
# to the source code
#configure_file (
#	"${PROJECT_SOURCE_DIR}"
#	"${PROJECT_BINARY_DIR}"
#	)
	
#add the binary tree to the search path for include files
#so that we will find the header
#include_directories("${PROJECT_BINARY_DIR}")

# add the executable
#add_executable()

SET(CMAKE_C_COMPIILER)
add_compile_options(-std=c++11)

message("-- system arch:  ${CMAKE_SYSTEM_PROCESSOR}")
message("-- output path:  ${PROJECT_OUTPUT_DIR}")

add_subdirectory(adapter)
add_subdirectory(bridge)
add_subdirectory(builder)
add_subdirectory(command)
add_subdirectory(decorator)
add_subdirectory(factory)
add_subdirectory(observer)
add_subdirectory(facade)


#set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
#target_link_libraries (Tutorial  ${EXTRA_LIBS})
