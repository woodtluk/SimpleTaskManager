PROJECT(SimpleTaskManagerDoxygen)

cmake_minimum_required(VERSION 2.8)


# add a target to generate API documentation with Doxygen
find_package(Doxygen)
if(DOXYGEN_FOUND)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile @ONLY)
#add_custom_target(doc ALL # if ALL is removed from this line documentation is only build with 'make doc'
add_custom_target(doc ALL
   ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
  COMMENT "Generating API documentation with Doxygen" VERBATIM
)
ELSE(DOXYGEN_FOUND)
  MESSAGE(SEND_ERROR "Failed to find Doxygen.")
endif(DOXYGEN_FOUND)

