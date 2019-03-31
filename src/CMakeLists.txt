configure_file(version.h.in ${CMAKE_CURRENT_SOURCE_DIR}/version.h)

set(BIN_SRC 
main.cpp
ip_filter.cpp
)

add_executable(${PROJECT_NAME} ${BIN_SRC})
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)