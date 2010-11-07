
CMAKE_MINIMUM_REQUIRED (VERSION 2.8.0)
PROJECT (nkane)

set (_VERSION_MAJOR 0)
set (_VERSION_MINOR 1)
set (_ROOT_FOLDER ${PROJECT_SOURCE_DIR})

set (EXECUTABLE_OUTPUT_PATH "${_ROOT_FOLDER}/bin")
set (LIBRARY_OUTPUT_PATH "${_ROOT_FOLDER}/lib")

include_directories ("${_ROOT_FOLDER}/include")
add_subdirectory(src)
add_subdirectory(test)

INSTALL(DIRECTORY "${_ROOT_FOLDER}/include/${PROJECT_NAME}" DESTINATION "include")

