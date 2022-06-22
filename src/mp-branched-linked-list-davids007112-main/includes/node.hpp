#ifndef NODE_HPP
#define NODE_HPP

// This is called forward declaration.
class BLL;
// Do not erase.

// Definition of node provided to you
struct Node {
  Node() = default;                  // NOLINT
  Node(char value): data_(value) {}  // NOLINT

  char data_ = '\0';           // NOLINT
  Node* next_node_ = nullptr;  // NOLINT
  BLL* next_bll_ = nullptr;    // NOLINT
};

#endif