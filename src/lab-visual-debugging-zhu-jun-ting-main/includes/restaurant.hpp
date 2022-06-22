#ifndef RESTAURANT_HPP
#define RESTAURANT_HPP

#include "customer.hpp"
#include "supplier.hpp"

class Restaurant {
    public:
    // Default constructor 
    Restaurant() = default;

    // Parametrized constructor
    // 
    // @param food_left the amount of food this restaurant has left
    // @param cost_per_food the cost of each item of food
    // @param money the amount of money this restaurant has left
    Restaurant(int food_left, int cost_per_food, int money);

    // Sets the supplier for the restaurant as a shallow copy
    // 
    // @param supplier the supplier for this restaurant
    void SetSupplier(Supplier& supplier);

    // If there is enough food for customer and customer has enough
    // money to pay for it, then charges the customer and gives them
    // the food
    //
    // @param customer the customer to be processed
    // @return true if the customer was successfully processed, false otherwise
    bool ProcessCustomer(Customer& customer);

    // If money_to_spend is less than or equal to the funds of the
    // restaurant, then restocks food_left_ by the amount of food the
    // restaurant can afford from their supplier
    //
    // @return the number food units purchased, -1 if the budget 
    //         is larger than the amount of funds the restaurant has
    int Restock(int money_to_spend);

    // Displays money_ and food_left_ in the restaurant
    void DisplayDetails() const;

    // Getter for money_
    //
    // @return the restaurant's funds
    int GetMoney() const;

    // Getter for food_left_
    //
    // @return the units of food that the restaurant has left
    int GetFoodLeft() const;

    private:
    int food_left_;
    int cost_per_food_;
    int money_;
    Supplier supplier_;
};

#endif