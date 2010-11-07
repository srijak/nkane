file(GLOB_RECURSE TEST_SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cc *.h) 

link_directories(${_ROOT_FOLDER}/lib)
add_executable (unittests ${TEST_SRCS})
target_link_libraries(unittests gtest gtest_main ${PROJECT_NAME})

add_custom_target(test "${_ROOT_FOLDER}/bin/unittests" DEPENDS unittests)
