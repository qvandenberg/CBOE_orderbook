project( market_reader_executables )

# Include header directory for files in /src
target_include_directories(cboe_reader PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)

# Compile applications
add_executable(main main.cpp)
target_link_libraries(main PRIVATE cboe_reader)
