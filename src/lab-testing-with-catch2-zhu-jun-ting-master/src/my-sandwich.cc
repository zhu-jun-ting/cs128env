#include "sandwich.hpp"

using std::string;
using std::vector;

string Sandwich::toppings[5] = {"cheese", "lettuce", "tomato", "onions", "pickles"};
string Sandwich::dressings[3] = {"mayo", "mustard", "vinegar"};

bool Sandwich::AddTopping(const string& topping) {
    // This line is here to avoid the unused parameter error.
    // You can remove it if you implement this method and use
    // the topping parameter.
    (void)topping;
    return true;
}

bool Sandwich::RemoveTopping(const string& topping) {
    // This line is here to avoid the unused parameter error.
    // You can remove it if you implement this method and use
    // the topping parameter.
    (void)topping;
    return true;
}

bool Sandwich::AddDressing(const string& dressing) {
    // This line is here to avoid the unused parameter error.
    // You can remove it if you implement this method and use
    // the topping parameter.
    (void)dressing;
    return true;
}

const vector<string>& Sandwich::GetToppings() const {
    return toppings_;
}

const vector<string>& Sandwich::GetDressings() const {
    return dressings_;
}

int Sandwich::HasTopping(const string& topping) const {
    for (unsigned i = 0; i < toppings_.size(); ++i) {
        if (toppings_.at(i) == topping) {
            return (int) i;
        }
    }

    return -1;
}

int Sandwich::HasDressing(const string& dressing) const {
    for (unsigned i = 0; i < dressings_.size(); ++i) {
        if (dressings_.at(i) == dressing) {
            return (int) i;
        }
    }
    
    return -1;
}
