#include <iostream>

#include "dna_strand.hpp"
using namespace std;

int main() {
	cout << "main()" << endl;

	Node* first1 = new Node('a');
  Node* first2 = new Node('b');
  Node* first3 = new Node('a');
  Node* first4 = new Node('b');
	first1->next = first2;
  first2->next = first3;
  first3->next = first4;

	DNAstrand dna = DNAstrand(first1, first4);
	DNAstrand dna2 = DNAstrand(first1, first4);

	char pattern[] = "ba";
	// cout << (pattern[2] == '\0') << endl;
	cout << dna.CheckMatch(first2, pattern) << endl;
	// cout << "break point: " << dna.RemovePattern(pattern)->data << endl;
	// cout << "end point: " << dna.GetEndLink()->data << endl;
	dna.SpliceIn(pattern, dna2);


}