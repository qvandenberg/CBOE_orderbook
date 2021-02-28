project(market_reader_source)

# All sources that also need to be tested in unit tests go into a static library
add_library(cboe_reader STATIC "")

# Add all subfolders with source code
add_subdirectory(io)
add_subdirectory(recorder)
add_subdirectory(messages)
add_subdirectory(util)

# Include header directory for files in /src
target_include_directories(cboe_reader PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../include)

# Include header-only libraries for custom static library
target_include_directories(cboe_reader PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../lib/boost/include)
