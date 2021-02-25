// Essential Catch2 headers for running tests
#include <catch2/catch.hpp>
// Class to be tested
#include "../include/TrialClass.hpp"
#include <stdio.h>


TEST_CASE("Get and set", "[TrialClass]"){
  printf("Running testcase 'Get and set'\n");
  // Create object
   TrialClass* tc = new TrialClass();

   SECTION( "Set float to x_" ) {
        double test_value = 5.0;

        tc->set_value(test_value);
        REQUIRE( tc->get_value() == test_value );
    }
}
