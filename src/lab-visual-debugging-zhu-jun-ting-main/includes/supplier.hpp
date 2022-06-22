#ifndef SUPPLIER_HPP
#define SUPPLIER_HPP

struct Supplier {
  // The amount of money the supplier sells each food item for
  int money_per_food;

  // Default constructor
  Supplier() = default;

  // Parametrized constructor
  //
  // @param money_per_food the amount of money the
  //        supplier sells each food item for
  Supplier(int money_per_food) { this->money_per_food = money_per_food; }
};

#endif