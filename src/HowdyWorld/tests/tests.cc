#ifndef CATCH_CONFIG_MAIN
#  define CATCH_CONFIG_MAIN
#endif

#include <catch/catch.hpp>
#include <string>

#include "utilities.hpp"

TEST_CASE("Howdy()", "[howdy]") {
  SECTION("Howdy, Michael!") {
    std::string result = Howdy("Michael");
    REQUIRE(result == "Howdy, Michael!");
  }

  SECTION("Howdy, Adarsh!") {
    std::string result = Howdy("Adarsh");
    REQUIRE(result == "Howdy, Adarsh!");
  }
}
