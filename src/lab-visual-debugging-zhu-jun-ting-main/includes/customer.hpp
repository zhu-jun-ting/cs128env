#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

struct Customer {
  // The number of food units the customer wants
  int food_needed;

  // The money the customer wants to spend
  int money;

  // Default constructor
  Customer() = default;

  // Parametrized constructor
  //
  // @param the number of food units the customer wants
  // @param the money the customer wants to spend
  Customer(int food_needed, int money) {
    this->food_needed = food_needed;
    this->money = money;
  }
};

#endif