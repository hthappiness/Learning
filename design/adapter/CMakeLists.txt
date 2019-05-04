option (TEST_MACRO  
        "Test the use of macro" ON)

#传参仍然使用的是gcc那一套，-D
if (TEST_MACRO)
add_definitions(-DTEST_MACRO)
endif()

add_executable(adapter main.cpp)

install (TARGETS adapter DESTINATION bin)

# add the MathFunctions library?
#
#if (USE_MYMATH)
#  include_directories ("${PROJECT_SOURCE_DIR}/MathFunctions")
#  add_subdirectory (MathFunctions)
#  set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
#endif (USE_MYMATH)
#target_link_libraries (adapter  ${EXTRA_LIBS})