#include <iostream>

#include "circular-linked-list.hpp"

using namespace std;

int main() {
	CircularLinkedList<int> cll = CircularLinkedList<int>();
	// cll.InsertInOrder(5);
	// cll.InsertInOrder(6);
	// cll.InsertInOrder(7);
	// cll.InsertInOrder(3);
	cll.Reverse();
	// cll.InsertInOrder(4);
	cll.Reverse();
	cout << cll << endl;

	// CircularLinkedList<int> cl;
	// cl = cll;	
	// cout << cl << endl;
}
