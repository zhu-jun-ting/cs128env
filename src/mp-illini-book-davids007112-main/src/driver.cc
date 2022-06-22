#include "illini_book.hpp"
#include "utilities.hpp"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {
  string persons = "/home/vagrant/src/mp-illini-book-davids007112-main/example/persons.csv";
  string relations = "/home/vagrant/src/mp-illini-book-davids007112-main/example/relations.csv";
  IlliniBook ib = IlliniBook(persons, relations);

  vector<int> v = ib.GetSteps(9, 1);
  for (unsigned i = 0; i < v.size(); i++) {
    cout << v[i] << " | ";
  }
  cout << endl;

  // vector<vector<int>> v = ib.Traverse(1, vector<string>{"128", "124"});

  // for (unsigned i = 0; i < v.size(); i++) {
  //   for (unsigned j = 0; j < v[i].size(); j++) {
  //     cout << v[i][j] << " | ";
  //   }
  //   cout << "\n";
  // }

  // cout << ib.ItemInVector("128", vector<string>{"128"});
  // cout << ib.GetAdjacency(1, vector<string>{"128"}).size();

  // PrintVec(ib.GetRelated(3, 2));
  // PrintVec(ib.GetRelated(1, 9));
  // cout << ib.AreRelated(1, 6, "124") << endl;
  // cout << ib.AreRelated(1, 2, "124") << endl;

  // PrintVec(ib.BFS(1));

  // cout << "---" << endl;

  // cout << ib.CountGroups() << endl;
  // cout << ib.CountGroups("128") << endl;
  // cout << ib.CountGroups("124") << endl;
  // cout << ib.CountGroups("173") << endl;
  // cout << ib.CountGroups(std::vector<std::string>{ "128", "173" }) << endl;
  // cout << ib.CountGroups(std::vector<std::string>{ "124", "128", "173" }) << endl;

  // delete ib;

}
