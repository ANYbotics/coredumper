
add_executable(coredumper_example coredumper_example.cpp)

target_include_directories(
  coredumper_example PUBLIC
  $<BUILD_INTERFACE:${COREDUMPER_SRC_DIR}/include/>
)

target_link_libraries(coredumper_example coredumper)