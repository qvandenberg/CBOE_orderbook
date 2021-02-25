project( bin_reader_executables )

# Include header directory for files in /src
target_include_directories(bin_reader PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)
# add_compile_options(-pthread)

# Include header-only libraries for custom static library (optional)
target_include_directories(bin_reader PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../lib/boost/include)
target_include_directories(bin_reader PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../lib/parallel_hashmap/include)
target_include_directories(bin_reader PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../lib/rangev3/include)

# Compile applications
add_executable(testapp testapp.cpp)
target_link_libraries(testapp PRIVATE bin_reader)
