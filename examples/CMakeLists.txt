add_executable(window_example window_example.cxx)

target_link_libraries(window_example PRIVATE pi::WindowManager)

add_executable(input_example input_example.cxx)

target_link_libraries(input_example PRIVATE pi::WindowManager)

add_executable(display_example display_example.cxx)

target_link_libraries(display_example PRIVATE pi::WindowManager)
