project( market_reader_executables )

# Include header directory for files in /src
target_include_directories(cboe_reader PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)

# Include header-only libraries for custom static library (optional)
target_include_directories(cboe_reader PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../lib/boost/include)

# Compile applications
add_executable(testapp testapp.cpp)
target_link_libraries(testapp PRIVATE cboe_reader)

add_executable(InstrumentRanker InstrumentRanker.cpp)
target_link_libraries(InstrumentRanker PRIVATE cboe_reader)
