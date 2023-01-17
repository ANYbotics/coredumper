set(LIBRARY_NAME coredumper)

add_library(
  ${LIBRARY_NAME}
  coredumper.c
  thread_lister.c
  elfcore.cc
  linuxthreads.cc
  )

target_include_directories(
  ${LIBRARY_NAME} PUBLIC
  $<BUILD_INTERFACE:${COREDUMPER_SRC_DIR}/include/>
  $<INSTALL_INTERFACE:include>
  )

set_target_properties(
  ${LIBRARY_NAME} PROPERTIES PUBLIC_HEADER
  "../include/coredumper/coredumper.h"
  )

target_link_libraries(${LIBRARY_NAME} ${CMAKE_THREAD_LIBS_INIT})

export(TARGETS ${LIBRARY_NAME} FILE "${LIBRARY_NAME}.cmake")

set(INCLUDE_INSTALL_DIR include/${LIBRARY_NAME})
set(LIB_INSTALL_DIR lib)

install(
  TARGETS ${LIBRARY_NAME}
  EXPORT ${LIBRARY_NAME}
  ARCHIVE DESTINATION ${LIB_INSTALL_DIR}
  PUBLIC_HEADER DESTINATION ${INCLUDE_INSTALL_DIR}
  LIBRARY DESTINATION ${LIB_INSTALL_DIR})
install(EXPORT ${LIBRARY_NAME} DESTINATION cmake)

include(CMakePackageConfigHelpers)
configure_package_config_file(${LIBRARY_NAME}Config.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/${LIBRARY_NAME}Config.cmake
  INSTALL_DESTINATION ${LIB_INSTALL_DIR}/${LIBRARY_NAME}/cmake
  PATH_VARS INCLUDE_INSTALL_DIR)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${LIBRARY_NAME}Config.cmake
  DESTINATION ${LIB_INSTALL_DIR}/${LIBRARY_NAME}/cmake)