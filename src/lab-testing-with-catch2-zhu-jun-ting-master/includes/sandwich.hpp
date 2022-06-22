#ifndef SANDWICH_HPP
#define SANDWICH_HPP

#include <string>
#include <vector>

class Sandwich {
public:
    // toppings = ["cheese", "lettuce", "tomato", "onions", "pickles"]
    static std::string toppings[5];
    // dressings = ["mayo", "mustard", "vinegar"]
    static std::string dressings[3];

    // default constructor
    //
    // private vectors toppings_ and dressings_ should both be initialized
    // to empty vectors
    Sandwich() = default;

    // adds topping to the sandwich. Toppings can be added in any order, but
    // a sandwich is not allowed to have more than one "cheese"
    //
    // @param topping string representation of topping to be added, assume it
    //  is present in the class toppings array
    // @return true if the topping is successfully added, false otherwise
    bool AddTopping(const std::string& topping);

    // removes a topping from the sandwich. Toppings can ONLY be removed
    // before any sauces are added.
    //
    // @param topping string representation of topping to be removed, assume
    //  it is present in the class toppings array
    // @return true if the topping is successfully removed, false otherwise
    //  (including if the topping is not present)
    bool RemoveTopping(const std::string& topping);

    // adds a dressing to a sandwich. A sandwich can have no more than one of
    // each dressing. Since we don't just want soggy bread, a dressing can't
    // be added until there is at least one topping.
    //
    // @param dressing string representation of dressing to be added, assume
    //  it is present in the class dressings array
    // @return true if the dressing is added, false otherwise
    bool AddDressing(const std::string& dressing);

    // retrieves a const reference to the private toppings_ vector (caller
    // cannot modify the vector)
    //
    // @return const reference to the vector toppings_
    const std::vector<std::string>& GetToppings() const;

    // retrieves a const reference to the private dressings_ vector (caller
    // cannot modify the vector)
    //
    // @return const reference to the vector dressings_
    const std::vector<std::string>& GetDressings() const;

private:
    int HasTopping(const std::string& topping) const;
    int HasDressing(const std::string& dressing) const;

    std::vector<std::string> toppings_;
    std::vector<std::string> dressings_;
};

#endif