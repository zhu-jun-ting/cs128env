#include "restaurant.hpp"

#include <iostream>

Restaurant::Restaurant(int food_left, int cost_per_food, int money) {
  food_left_ = food_left;
  cost_per_food_ = cost_per_food;
  money_ = money;
}

void Restaurant::SetSupplier(Supplier& supplier) { supplier_ = supplier; }

bool Restaurant::ProcessCustomer(Customer& customer) {
  int cost_for_customer = customer.food_needed * cost_per_food_;
  if (customer.money < cost_for_customer ||
      GetFoodLeft() < customer.food_needed) {
    return false;
  }

  food_left_ -= customer.food_needed;
  money_ += cost_for_customer;
  customer.money -= cost_for_customer;

  return true;
}

int Restaurant::Restock(int money_to_spend) {
  if (money_to_spend > money_) {
    return -1;
  }

  int afforded_food_units = money_to_spend / supplier_.money_per_food;
  int money_spent = afforded_food_units * supplier_.money_per_food;

  food_left_ += afforded_food_units;
  money_ -= money_spent;

  return afforded_food_units;
}

void Restaurant::DisplayDetails() const {
  std::cout << "We currently have:" << std::endl;
  std::cout << food_left_ << " food items" << std::endl;
  std::cout << money_ << " dollars" << std::endl << std::endl;
}

int Restaurant::GetMoney() const { return money_; }

int Restaurant::GetFoodLeft() const { return food_left_; }