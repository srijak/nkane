file(GLOB_RECURSE SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cc *.h)

include_directories (${_ROOT_FOLDER}/include)
link_directories(${_ROOT_FOLDER}/lib)

add_executable (nkane-demo ${SRCS})
target_link_libraries(nkane-demo event nkane)

install_targets(/bin nkane-demo)
