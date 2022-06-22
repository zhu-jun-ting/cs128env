#include <iostream>

#include "restaurant.hpp"

using std::cout;
using std::endl;

//
// If you fixed your bugs, main should run successfully and all your tests
// should pass. Feel free to play around with the code! :D
//
int main() {
  cout << "------------------------------" << endl;
  cout << "| Welcome to our restaurant! |" << endl;
  cout << "------------------------------" << endl;

  Restaurant restaurant(0, 20, 100);
  Supplier s(5);
  restaurant.SetSupplier(s);
  restaurant.DisplayDetails();

  cout << "Let's restock on our food!" << endl << endl;
  restaurant.Restock(20);
  restaurant.DisplayDetails();

  Customer rich_customer(2, 1000);
  bool processed_rich = restaurant.ProcessCustomer(rich_customer);

  if (processed_rich) {
    cout << "We successfully serviced a new customer!" << endl << endl;
  } else {
    cout << "Oh no! We don't have enough food for a customer, so they went "
            "away :(";
    cout << endl << endl;
  }

  restaurant.DisplayDetails();

  Customer poor_customer(2, 5);
  bool processed_poor = restaurant.ProcessCustomer(poor_customer);

  if (processed_poor) {
    cout << "We just gave a customer free food" << endl << endl;
  } else {
    cout << "A customer didn't have enough money, so they were turned away";
    cout << endl << endl;
  }

  return 0;
}
