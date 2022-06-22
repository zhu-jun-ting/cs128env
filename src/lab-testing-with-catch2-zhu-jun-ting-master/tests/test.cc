#ifndef CATCH_CONFIG_MAIN
#define CATCH_CONFIG_MAIN
#endif
#include <catch/catch.hpp>

#include <vector>
#include <string>
#include <iostream>

#include "sandwich.hpp"

using std::string;
using std::vector;

// A helper method for you to visualize what the contents of a vector are. You
// are welcome to modify this method or create additional helper methods.
//
// Example usage:
//  vector<string> my_vec;
//  my_vec.push_back("hello");
//  my_vec.push_back("world"):
//  PrintVector(my_vec);
// Prints:
//  [hello, world]
void PrintVector(const vector<string>& vec) {
    std::cout << "[";
    bool first = true;
    for (const auto& it : vec) {
        if (!first) {
            std::cout << ", ";
        } else {
            first = false;
        }

        std::cout << it;
    }

    std::cout << "]" << std::endl;
}

bool HasElement(const vector<string>& vec, const string& element) {
    for (const auto& it: vec) {
        if (it == element) {
            return true;
        }
    }
    return false;
}

bool HasDuplicate(const vector<string>& vec) {
    for (unsigned long i = 0; i < vec.size() - 1; i++) {
        for (unsigned long j = i + 1; j < vec.size(); j++) {
            if (vec.at(i) == vec.at(j)) {
                return true;
            }
        }
    }
    return false;
}

TEST_CASE("Sandwich::AddTopping test", "[AddTopping]") {
    // your tests for Sandwich::AddTopping here
    Sandwich sw = Sandwich();

    // add a topping of lettuce:
    bool added = sw.AddTopping("lettuce");
    SECTION("should successfully add a topping of lettuce") {
        REQUIRE(added);
    }

    // no duplication of cheese
    bool cheese_1 = sw.AddTopping("cheese");
    bool cheese_2 = sw.AddTopping("cheese");
    SECTION("should not add two cheese") {
        REQUIRE_FALSE(cheese_2);
    }   
    
}

TEST_CASE("Sandwich::RemoveTopping test", "[RemoveTopping]") {
    // your tests for Sandwich::RemoveTopping here
    Sandwich sw = Sandwich();

    // should successfully remove a topping only when dressing is empty
    sw.AddTopping("lettuce");
    bool removed = sw.RemoveTopping("lettuce");
    bool empty_dressing = sw.GetDressings().empty();
    SECTION("should remove a exsisting topping when dressing empty") {
        REQUIRE(removed);
        REQUIRE(empty_dressing);
    } 

    // should not remove when have dressing
    sw.AddTopping("lettuce");
    sw.AddDressing("mayo");
    bool removed_has_dressing = sw.RemoveTopping("lettuce");
    SECTION("should not remove when have dressing") {
        REQUIRE_FALSE(removed_has_dressing);
    }

    // should not remove not-exsisting topping
    Sandwich sw1 = Sandwich();
    bool removed_noexsist_topping = sw1.RemoveTopping("tomato");
    // bool removed_noexsist_topping_fake = sw.RemoveTopping("tomato_fake");
    SECTION("should not remove not-exsisting topping") {
        REQUIRE_FALSE(removed_noexsist_topping);
        // REQUIRE_FALSE(removed_noexsist_topping_fake);
    }
    
}

TEST_CASE("Sandwich::AddDressing test", "[AddDressing]") {
    // your tests for Sandwich::AddDressing here
    Sandwich sw = Sandwich();

    // should add topping simple case
    sw.AddTopping("lettuce");
    bool added_dressing = sw.AddDressing("mayo");
    SECTION("should add dressing in simple case") {
        REQUIRE(added_dressing);
    }

    // should no more than 1 of each dressing
    bool added_2nd_mayo = sw.AddDressing("mayo");
    SECTION("can't have more than one mayo") {
        REQUIRE_FALSE(added_2nd_mayo);
        // REQUIRE(HasDuplicate(sw.GetDressings()));
    }

    // can't add dressing if no topping
    Sandwich sw1 = Sandwich();
    bool added_dressing_no_topping = sw1.AddDressing("mayo");
    SECTION("can't add dressing if no topping") {
        REQUIRE_FALSE(added_dressing_no_topping);
    }

}
