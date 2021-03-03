
# Add all source files in directory
target_sources(cboe_reader
    PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/RecorderManager.cpp
    ${CMAKE_CURRENT_LIST_DIR}/InstrumentRecorder.cpp
    ${CMAKE_CURRENT_LIST_DIR}/InstrumentRanker.cpp
    ${CMAKE_CURRENT_LIST_DIR}/Order.cpp
)
