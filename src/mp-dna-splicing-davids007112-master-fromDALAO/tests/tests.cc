#ifndef CATCH_CONFIG_MAIN
#  define CATCH_CONFIG_MAIN
#endif

#include <catch/catch.hpp>

TEST_CASE("Does nothing", "[does-nothing]") { REQUIRE(true == true); }