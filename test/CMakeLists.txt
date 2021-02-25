add_executable("main_test")

set(TARGET_SOURCES
    "main_test.cpp"
    "trial_class_test.cpp"
)

#list(TRANSFORM TARGET_SOURCES PREPEND "${PROJECT_SOURCE_DIR}/test/")
target_sources("main_test" PUBLIC ${TARGET_SOURCES})

target_link_libraries("main_test" PUBLIC "mainlib")
target_include_directories("main_test" PUBLIC "${PROJECT_SOURCE_DIR}/include")
target_include_directories("main_test" PUBLIC "${PROJECT_SOURCE_DIR}/extern/include")
