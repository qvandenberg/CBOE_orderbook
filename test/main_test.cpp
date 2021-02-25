#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <stdio.h>

TEST_CASE("1: All test cases reside in other .cpp files (empty)",
          "[multi-file:1]") {
            printf("Running test case in main_test.cpp\n");
          }
