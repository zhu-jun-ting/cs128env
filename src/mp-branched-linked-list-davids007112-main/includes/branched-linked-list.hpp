#ifndef BRANCHED_LINKED_LIST_HPP
#define BRANCHED_LINKED_LIST_HPP

#include <cstddef>
#include <stdexcept>
#include <string>

#include "node.hpp"

class BLL {
public:
  BLL();
  BLL(const BLL& to_copy);
  ~BLL();

  // BLL& operator=(const BLL& rhs);
  Node* PushBack(char dat);
  char GetAt(size_t idx) const;
  // void SetAt(size_t idx, char dat);
  void Join(size_t idx, BLL* list);
  // std::string ToString() const;
  size_t Size() const;
  Node* GetHead() { return head_; };
  void Clear();

private:
  Node* head_;
  bool IsBLLAcyclic() const;
  Node* GetNodeAt(size_t idx) const;
};

Node* GetNext(Node*& cur);

#endif
