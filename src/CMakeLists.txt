file(GLOB_RECURSE SRCS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cc *.h)

include_directories ("${_ROOT_FOLDER}/include")

add_library (slib STATIC ${SRCS})
target_link_libraries(slib event)
set_target_properties(slib PROPERTIES VERSION "${_VERSION_MAJOR}.${_VERSION_MINOR}" OUTPUT_NAME ${PROJECT_NAME} CLEAN_DIRECT_OUTPUT 1)

install_targets(/lib slib)
