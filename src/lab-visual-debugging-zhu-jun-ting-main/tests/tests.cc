#ifndef CATCH_CONFIG_MAIN
#  define CATCH_CONFIG_MAIN
#endif
#include "catch.hpp"
#include "customer.hpp"
#include "restaurant.hpp"
#include "supplier.hpp"

TEST_CASE("process rich customer, enough food", "[ProcessCustomer]") {
  Customer c(2, 10000);
  Supplier s(5);
  Restaurant r(10, 20, 0);
  r.SetSupplier(s);

  bool processed = r.ProcessCustomer(c);
  REQUIRE(processed);
  REQUIRE(c.money == 9960);
  REQUIRE(r.GetFoodLeft() == 8);
  REQUIRE(r.GetMoney() == 40);
}

TEST_CASE("process rich customer, not enough food", "[ProcessCustomer]") {
  Customer c(2, 10000);
  Supplier s(5);
  Restaurant r(1, 20, 0);
  r.SetSupplier(s);

  bool processed = r.ProcessCustomer(c);
  REQUIRE_FALSE(processed);
  REQUIRE(c.money == 10000);
  REQUIRE(r.GetFoodLeft() == 1);
  REQUIRE(r.GetMoney() == 0);
}

TEST_CASE("process poor customer, enough food", "[ProcessCustomer]") {
  Customer c(2, 10);
  Supplier s(5);
  Restaurant r(10, 20, 0);
  r.SetSupplier(s);

  bool processed = r.ProcessCustomer(c);
  REQUIRE_FALSE(processed);
  REQUIRE(c.money == 10);
  REQUIRE(r.GetFoodLeft() == 10);
  REQUIRE(r.GetMoney() == 0);
}

TEST_CASE("over-budget restock", "[Restock]") {
  Supplier s(5);
  Restaurant r(8, 20, 40);
  r.SetSupplier(s);

  int food_units_bought = r.Restock(60);
  REQUIRE(food_units_bought == -1);
  REQUIRE(r.GetFoodLeft() == 8);
  REQUIRE(r.GetMoney() == 40);
}

TEST_CASE("budget below supplier's cost per food", "[Restock]") {
  Supplier s(5);
  Restaurant r(8, 20, 40);
  r.SetSupplier(s);

  int food_units_bought = r.Restock(4);
  REQUIRE(food_units_bought == 0);
  REQUIRE(r.GetFoodLeft() == 8);
  REQUIRE(r.GetMoney() == 40);
}

TEST_CASE("successful restock", "[Restock]") {
  Supplier s(5);
  Restaurant r(8, 20, 40);
  r.SetSupplier(s);

  int food_units_bought = r.Restock(12);
  REQUIRE(food_units_bought == 2);
  REQUIRE(r.GetFoodLeft() == 10);
  REQUIRE(r.GetMoney() == 30);
}