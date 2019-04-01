set(TARGET_NAME "ip_filter_test")
set(TARGET_SRC
ip_filter_test.cpp
../src/ip_filter.cpp
)
add_executable(${TARGET_NAME} ${TARGET_SRC})
set_target_properties(${TARGET_NAME} PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    #COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)
target_link_libraries(${TARGET_NAME} PRIVATE GTest::GTest GTest::Main Threads::Threads)
target_include_directories(${TARGET_NAME} PRIVATE ../src)
install(TARGETS ${TARGET_NAME} RUNTIME DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
add_test(${TARGET_NAME} ${TARGET_NAME})
add_custom_target(tests COMMAND "${CMAKE_CTEST_COMMAND} --build-and-test --build-run-dir ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")